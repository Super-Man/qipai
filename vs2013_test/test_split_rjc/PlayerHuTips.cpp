#include "PlayerHuTips.h"

CPlayerHuTips::CPlayerHuTips(CHuTipsMJ* pAlgor): m_pAlgorithm(pAlgor)
{
	m_byNaiZiCard = INVALID_VAL;
	GameBeginClear();
}

CPlayerHuTips::~CPlayerHuTips()
{
}

//��Ϸ��ʼ����
void CPlayerHuTips::GameBeginClear()
{
	m_stCardData.clear();
	m_vctUnlockCards.clear();

//	MYLOG_DEBUG(logger,"pino_log GameBeginClear map.size = %d", m_mapHuanCun.size());	
// 	map<stKey, stAnswer>::iterator iter = m_mapHuanCun.begin();
// 	for (; iter != m_mapHuanCun.end(); ++iter)
// 	{
// 		stKey stKeyTemp = iter->first;
// 		string strTemp = stKeyTemp.getString();
// 		MYLOG_DEBUG(logger,"pino_log GameBeginClear iter.first=%s num=%d", strTemp.c_str(), iter->second.nNum);	
// 	}
	m_mapHuanCun.clear();
}
//��ʼ������
void CPlayerHuTips::initData(std::list<BYTE> &handMjList, std::vector<MJCPGNode> &vecMJCPGList)
{
	m_vecNodeMJ.clear();
	memset(&m_stCardData, 0, sizeof(stCardData));

	std::list<BYTE>::iterator iter = handMjList.begin();
	for (; iter != handMjList.end(); ++iter)
	{
		m_stCardData.addCard(*iter, 1);
	}
	for (size_t i=0; i<vecMJCPGList.size(); ++i)
	{
		stNodeMJ stTemp;
		stTemp.byType = vecMJCPGList[i].byBlockCardType;
		for (int n=0; n<4; ++n)
		{
			if (vecMJCPGList[i].byMjCard[n] > 0)
				stTemp.addCardInfo(vecMJCPGList[i].byMjCard[n], 1);
		}
		m_vecNodeMJ.push_back(stTemp);
	}
}


bool CPlayerHuTips::CheckMyCanTing_14(bool bAllResult/*true*/)
{
	if (m_stCardData.byNum + m_vecNodeMJ.size()*3 != 14)
		return false;

	m_vctUnlockCards.clear();
	for (int i=0; i<MAX_TOTAL_TYPE; ++i)
	{
		if (m_stCardData.byCardCount[i] > 0)
		{
			stCardData stTemp = m_stCardData;
			stTemp.DelCard(getValByIndex(i), 1);
			if (CheckMyCanTing_13(stTemp))
			{			
				if (!bAllResult)		// �ҵ�һ���⣬���ƿ���
					return true;
				m_vctUnlockCards.push_back(getValByIndex(i));
			}
		}
	}		
	return m_vctUnlockCards.size() > 0;
}

vector<stHuTips> CPlayerHuTips::CheckMyCanTing_HuTips(stCardData &stCardShow, bool bUseCun/*true*/)
{	
	vector<stHuTips> vctHuShow;
	if (m_stCardData.byNum + m_vecNodeMJ.size()*3 != 14)
		return vctHuShow;
			
	int nFindNum	= 0;
	int nNewNum		= 0;
	for (int i=0; i<MAX_TOTAL_TYPE; ++i)
	{
		if (m_stCardData.byCardCount[i] > 0)
		{
			vector<stNodeMJ> vecNodeOut;
			stHuTips stHu(getValByIndex(i));
			
			stCardData stTemp = m_stCardData;
			stTemp.DelCard(getValByIndex(i), 1);

			if (CheckMyCanTing_13_HuTips(stTemp, stHu.stData))
			{			
				refreshLeftCardsNum(stHu, stCardShow);
				vctHuShow.push_back(stHu);
				++nNewNum;	
			}			
		}		
	}	
	return vctHuShow;
}

bool CPlayerHuTips::CheckMyCanTing_13(stCardData &stData, int num/*0*/)
{
	if (stData.byNum + m_vecNodeMJ.size()*3 + num != 13)
		return false;

	stCardData stDataTemp = stData;
	for (size_t n=0; n<m_vecNodeMJ.size(); ++n)
		stDataTemp.addCard(m_vecNodeMJ[n]);

	vector<stNodeMJ> vecNodeOut;
//	if (isHaveSpecialCard(stData))
	{
		BYTE byNaiziCard = GetNaiZiCard();
		if (IsValidCard(byNaiziCard) == false)
		{
			for (int i=0; i<MAX_TOTAL_TYPE; ++i)
			{	
				if (stDataTemp.byCardCount[i] == 0)
				{
					byNaiziCard = getValByIndex(i);
					break;
				}
			}	
		}					
		if( JustTryDianHu(stData, byNaiziCard, byNaiziCard, vecNodeOut))
			return true;
	}
// 	else
// 	{
// 		size_t i = 0;
// 		BYTE byCardNeed[] = {0x01, 0x11, 0x21, 0x09, 0x19, 0x29}; //1��9
// 		for (; i<sizeof(byCardNeed); ++i)
// 		{
// 			if( JustTryDianHu(stData, byCardNeed[i], true, m_byNaiZiCard, vecNodeOut))		
// 				return true;
// 		}		
// 	}
	return false;
}

bool CPlayerHuTips::CheckMyCanTing_13_HuTips(stCardData &stData, stHuData stHuInfo[10])
{
	bool bSuc = false;
	if (stData.byNum + m_vecNodeMJ.size()*3 != 13)
		return false;

	int num = 0;
	vector<stNodeMJ> vecNodeOut;
//	if (isHaveSpecialCard(stData))
	{		
		int  nValMax = 0;
		bool bAddNaiZi = false;
		BYTE byNaiZiCard = GetNaiZiCard();
		BYTE byNaiZiIndex = getIndexByVal(byNaiZiCard);
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)
		{	
			vector<BYTE> vctTemp;
			vctTemp.push_back(i);
			if (i < 27)
			{
				if (i-1 >= 0)
					vctTemp.push_back(i-1);
				if (i+1 < 27)
					vctTemp.push_back(i+1);
			}
			bool bFlag = false;
			for (size_t m=0; m<vctTemp.size(); ++m)
			{					
				BYTE indexFalg = vctTemp[m];
				if (indexFalg != byNaiZiIndex && stData.byCardCount[indexFalg] > 0)
				{
					bFlag = true;
					break;
				}
			}
				
			if(bFlag && JustTryDianHu(stData, getValByIndex(i), byNaiZiCard, vecNodeOut))
			{
				int nHuFlag = getCardsTypeFlag(stHuInfo[num].byCardHu, vecNodeOut, false);
				stHuInfo[num].byCardHu = getValByIndex(i);
				stHuInfo[num].nVal = getPerByHuFlag(nHuFlag);
				nValMax = max(nValMax, stHuInfo[num].nVal);
				if (byNaiZiCard == getValByIndex(i))
					bAddNaiZi = true;
				++num;
				if (num >= 9) break;
			}
		}
		if (num>0 && !bAddNaiZi && byNaiZiCard != INVALID_VAL)
		{
			stHuInfo[num].byCardHu = byNaiZiCard;
			stHuInfo[num].nVal = nValMax;
			++num;
		}
	}
	return num > 0;
}

bool CPlayerHuTips::JustTryDianHu(stCardData stData, BYTE byMJCard, BYTE byNaiziCard, vector<stNodeMJ> &vecNodeOut)
{
	//�Ƿ���С�Ӻ�
//	vecNodeOut.clear();
//	if ( m_pAlgorithm->isHaveMode(enPlayMode_7Dui) && m_pAlgorithm->CheckWin_7XiaoDui(stData, vecNodeOut, byMJCard, byNaiziCard))
//	{
//		stData.addCard(byMJCard, 1);		
//		return getCardColorNum(stData, byNaiziCard) < 3;	
//		return true;
//	}
	stData.addCard(byMJCard, 1);
	return m_pAlgorithm->CheckWin_Dian(stData, byNaiziCard);
}

bool CPlayerHuTips::isJiaHu()
{
	return false;
}

int CPlayerHuTips::getJiaHuType(vector<stNodeMJ> &vctNodeOut, BYTE byCard)
{	
	return 0;
}

bool CPlayerHuTips::IsMENQING()
{
	for(size_t i = 0; i < m_vecNodeMJ.size(); i++)
	{
		if (BLOCK_2222_AN == m_vecNodeMJ[i].byType)
			continue;
		else
			return false;
	}	
	return true;
}

//����Ƿ����ָ�������ַ�
bool CPlayerHuTips::isHaveSpecialCard(stCardData &stData)
{
	stCardData stDataTemp = stData;
	for (size_t i=0; i<m_vecNodeMJ.size(); ++i)	
		stDataTemp.addCard(m_vecNodeMJ[i]);

	static BYTE s_byCardNeed[] = {0x01, 0x11, 0x21, 0x09, 0x19, 0x29, 0x31, 0x32, 0x33, 0x34, 0x41, 0x42, 0x43}; //1��9�����������з���
	for (size_t i=0; i<sizeof(s_byCardNeed); ++i)
	{
		if (stDataTemp.byCardCount[getIndexByVal(s_byCardNeed[i])] > 0)
		{
			return true;
		}
	}	
	return false;
}

BYTE CPlayerHuTips::getCardColorNum(stCardData &stData, BYTE byNaiZiCard)
{
	stCardData stDataTemp = stData;
	for (size_t i=0; i<m_vecNodeMJ.size(); ++i)	
		stDataTemp.addCard(m_vecNodeMJ[i]);

	BYTE byNum = 0;
	for (BYTE cor = 0; cor<3; ++cor)
	{
		for (BYTE val=0; val<9; ++val)
		{
			if (stDataTemp.byCardCount[cor*9+val] > 0 && getIndexByVal(byNaiZiCard) != cor*9+val)
			{
				++byNum;
				break;
			}
		}
	}
	return byNum;
}
//����Ƿ���һɫ
bool CPlayerHuTips::isQingYiSe(stCardData &stData, BYTE byNaiZiCard)
{
	stCardData stDataTemp = stData;
	for (size_t i=0; i<m_vecNodeMJ.size(); ++i)	
		stDataTemp.addCard(m_vecNodeMJ[i]);
	// �����з�����
	for (int i=27; i<MAX_TOTAL_TYPE; ++i)
	{
		if (stDataTemp.byCardCount[i] > 0)
		{
			return false;
		}
	}
	return getCardColorNum(stData, byNaiZiCard) == 1;
}

//����Ƿ��һɫ
bool CPlayerHuTips::isChouYiSe(stCardData &stData, BYTE byNaiZiCard/*0*/)
{
	stCardData stDataTemp = stData;
	for (size_t i=0; i<m_vecNodeMJ.size(); ++i)	
		stDataTemp.addCard(m_vecNodeMJ[i]);

	// ��������
	int nNum = 0;
	for (int i=27; i<MAX_TOTAL_TYPE; ++i)
	{
		nNum += stDataTemp.byCardCount[i];
	}
	return getCardColorNum(stData, byNaiZiCard) == 1 && nNum > 0;
}

//����Ƿ���һ����
bool CPlayerHuTips::isHaveYiLong(stCardData &stData)
{	
	for (BYTE cor = 0; cor<3; ++cor)
	{
		BYTE byNum = 0;
		for (BYTE val=0; val<9; ++val)
		{
			if (stData.byCardCount[cor*9+val] > 0)
				++byNum;
		}
		if (byNum == 9)
			return true;
	}
	return false;
}

//����Ƿ���Ʈ��
bool CPlayerHuTips::isPiaoHu(vector<stNodeMJ> vctNote)
{
	vctNote.insert(vctNote.end(), m_vecNodeMJ.begin(), m_vecNodeMJ.end());

	BYTE byJiangNum = 0;
	for (size_t i=0; i<vctNote.size(); ++i)
	{
		if (vctNote[i].byType == BLOCK_234)
		{
			return false;
		}
		else if (vctNote[i].byType == BLOCK_22)
		{
			++byJiangNum;
		}
	}
	return byJiangNum == 1;
}

//����Ƿ���վ�������壩
bool CPlayerHuTips::isZhanLi()
{
	int nNodeNum = 0;
	for (size_t i=0; i<m_vecNodeMJ.size(); ++i)
	{
		if (m_vecNodeMJ[i].byType == BLOCK_2222_AN )
		{
			continue;
		}		
		++nNodeNum;
	}
	return nNodeNum == 0;
}

//�õ��ԶԺ�������
int CPlayerHuTips::getDuiDuiHuType(vector<stNodeMJ> vctTemp)
{	
	return 0;
}

//���ͷ���
int CPlayerHuTips::getCardsTypeFlag(BYTE byCard, vector<stNodeMJ> &vecNodeOut, bool isZhiMo)
{
	int nHuFlag = 1;
	return nHuFlag;
}

//�õ���ǰ���ͱ���
int CPlayerHuTips::getPerByHuFlag(int nHuFlag)
{
	if (nHuFlag <= 0)
		return 0;
		
	return 1;
}

//�õ���ǰ�����ַ���
std::string CPlayerHuTips::getStringByData(stCardData &stData)
{
	std::string strOut;
	BYTE byNaiIndex = getIndexByVal(m_byNaiZiCard);
	for (int i=0; i<MAX_TOTAL_TYPE; ++i)
	{		
		if (byNaiIndex != i && stData.byCardCount[i] > 0)
		{
			char chrTemp[64] = {0};
			memset(chrTemp, getCharFlag(i), stData.byCardCount[i]);			
			strOut.append(chrTemp, stData.byCardCount[i]);
		}
	}

	if (byNaiIndex != INVALID_VAL && stData.byCardCount[byNaiIndex] > 0)
	{
		char chrTemp[14] = {0};
		memset(chrTemp, INVALID_VAL, stData.byCardCount[byNaiIndex]);
		strOut.append(chrTemp, stData.byCardCount[byNaiIndex]);
	}
	return strOut;
}

void CPlayerHuTips::refreshLeftCardsNum(stHuTips &stHu, stCardData &stCardShow)
{
	// ˢ��ʣ������
	for (int n=0; n<10; ++n)
	{
		if (stHu.stData[n].byCardHu == 0)
			break;

		int nAll = 4;
// 		if (stHu.stData[n].byCardHu == m_byNaiZiCard)	// �����齫��������һ��
// 			nAll = 3;

		BYTE byIndex = getIndexByVal(stHu.stData[n].byCardHu);
		stHu.stData[n].byNum = max(0, nAll - stCardShow.byCardCount[byIndex] - m_stCardData.byCardCount[byIndex]);					
	}
}