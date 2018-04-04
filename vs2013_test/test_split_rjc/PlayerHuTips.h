/********************************************************************
	created:	pino
	file base:	CPlayerHuTips
	author:		pino	
	purpose:	�齫������ʾ�㷨
*********************************************************************/

#ifndef __CPLAYER_HUTIPS_H__
#define __CPLAYER_HUTIPS_H__
#include <map>
#include <string>
#include <vector>
#include <list>

#include "Define.h"
#include "CMD_Mj.h"
#include "HuTipsMJ.h"


using namespace std;

class CPlayerHuTips
{
public:
	CPlayerHuTips(CHuTipsMJ* pAlgor);
	~CPlayerHuTips();

public:
	//��Ϸ��ʼ����
	void GameBeginClear();
	//��ʼ������
	void initData(std::list<BYTE> &handMjList, std::vector<MJCPGNode> &vecMJCPGList);
	
	//����������
	void SetNaiZiCard(BYTE byCard)	{m_byNaiZiCard = byCard;}
	BYTE GetNaiZiCard()				{return m_byNaiZiCard;}
	
	//����Ƿ�����
	bool CheckMyCanTing_14(bool bAllResult = true);	
	bool CheckMyCanTing_13(stCardData &stData, int num = 0);
	bool CheckMyCanTing_13_HuTips(stCardData &stData, stHuData stHuInfo[10]);
	bool JustTryDianHu(stCardData stData, BYTE byMJCard, BYTE byNaiziCard, vector<stNodeMJ> &vecNodeOut);	
	//���ú�����ʾ��Ϣ
	vector<stHuTips> CheckMyCanTing_HuTips(stCardData &stCardShow, bool bUseCun=true);

	//�������
	bool IsMENQING();
	//����Ƿ����ָ�������ַ�
	bool isHaveSpecialCard(stCardData &stData);
	//��黨ɫ����
	BYTE getCardColorNum(stCardData &stData, BYTE byNaiZiCard=0);
	//����Ƿ���һɫ
	bool isQingYiSe(stCardData &stData, BYTE byNaiZiCard=0);
	//����Ƿ��һɫ
	bool isChouYiSe(stCardData &stData, BYTE byNaiZiCard=0);
	//����Ƿ���һ����
	bool isHaveYiLong(stCardData &stData);
	//����Ƿ���Ʈ��(������)
	bool isPiaoHu(vector<stNodeMJ> vctTemp);
	//����Ƿ���վ�������壩
	bool isZhanLi();
	//�õ��ԶԺ�������
	int  getDuiDuiHuType(vector<stNodeMJ> vctTemp);
	//�õ��к�����
	int  getJiaHuType(vector<stNodeMJ> &vctNodeOut, BYTE byCard);
	bool isJiaHu();	
	//���ͷ���
	int getCardsTypeFlag(BYTE byCard, vector<stNodeMJ> &vctTemp, bool isZhiMo);
	//�õ���ǰ���ͷ�
	int getPerByHuFlag(int nHuFlag);
	//�õ���ǰ�����ַ���
	std::string getStringByData(stCardData &stData);
	//ˢ��ʣ��������
	void refreshLeftCardsNum(stHuTips &stHu, stCardData &stCardShow);

public:
	map<stKey, stAnswer>		m_mapHuanCun;

private:
	stCardData				m_stCardData;		//��������
	std::vector<stNodeMJ>	m_vecNodeMJ;		//�������б�
	vector<BYTE>			m_vctUnlockCards;	//��ʱ�������б�
	

	CHuTipsMJ*				m_pAlgorithm;
	BYTE					m_byNaiZiCard;		//������
};

#endif  //__CPLAYER_H__