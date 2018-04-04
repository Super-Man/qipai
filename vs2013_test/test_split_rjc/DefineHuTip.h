#pragma once

#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;

#pragma pack(1)

#define INVALID_VAL						0xFF			//�Ƿ�����
#define MAX_TOTAL_TYPE					34				//�齫������
#define MIN_HU_HUAN_CUN					5				//��С���泤��

enum enPlayMode
{
	enPlayMode_ZhuangFen,		//ׯ���
	enPlayMode_7Dui,			//�ɺ��߶�
	enPlayMode_NaiZi,			//��������
	enPlayMode_Max,
};

//������ʾ���
enum enCountFlag
{
	enCountFlag_7Dui		= 0x0001,
	enCountFlag_KeZiFirst	= 0x0002,
	enCountFlag_13Lan		= 0x0004,
};

//һ��������
enum BLOCK_TYPE_HU
{	
	BLOCK_22 = 1,				    //����
	BLOCK_234,						//˳�� ���� ���� �ṹ
	BLOCK_222,						//���� ���� ���� �ṹ, 3����ͬ
	BLOCK_2222_DIAN,   				//����--���,4����ͬ
	BLOCK_2222_BU,   				//����--����,4����ͬ
	BLOCK_2222_AN ,					//����--����,4����ͬ	
	BLOCK_MAX,
};

#define	 MAX_COUNT_FLAG_NUM				100
enum enBlockLev
{
	enBlockLev_Null,	
	enBlockLev_222,
	enBlockLev_234,
};

#define MAX_VAL_NUM						9
//�齫��ɫ�����ࣩ����
enum enColorMJ
{
	enColorMJ_WAN = 0,  //��
	enColorMJ_TONG,     //Ͳ
	enColorMJ_TIAO,     //��
	enColorMJ_FenZi,    //�硢�� ��
	enColorMJ_Max,
};
//////////////////////////////////////////////////////////////
//����������ֵ
static const BYTE s_HuCardType[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x31, 0x32, 0x33, 0x34,                                             //��������
	0x41, 0x42, 0x43,                                                   //�з���
};

//////////////////////////////////////////////////////////////
//����ֵ�õ�����ֵ
inline BYTE getIndexByVal(BYTE byCard)
{
	BYTE cor = byCard / 0x10;
	BYTE val = byCard % 0x10;

	BYTE byIndex = INVALID_VAL;
	if (cor < 3)	
	{
		if (val > 0 && val <= 9) 
			byIndex = (cor)*9 + val-1;
	}
	else if (cor == 3)	
	{
		if (val > 0 && val <= 4) 
			byIndex = 27 + val-1;
	}
	else if (cor == 4)	
	{
		if (val > 0 && val <= 3)		// val==4ʱ��byIndex = 34 ��ʾ��������
			byIndex = 27 + 4 + val-1;
	}		
	return byIndex;	
}
//������ֵ�õ���ֵ
inline BYTE getValByIndex(BYTE byIndex)
{
	if (byIndex < MAX_TOTAL_TYPE)
	{
		return s_HuCardType[byIndex];
	}
	return INVALID_VAL;
}
//���Ƿ��ǺϷ���ֵ
inline bool IsValidCard(BYTE bCard)
{	
	return getIndexByVal(bCard) != INVALID_VAL;
}
//�õ�����KEY
inline int  getKey(vector<BYTE> vctCard)
{		
	vctCard.resize(4);
	sort(vctCard.begin(), vctCard.end());
//	reverse(vctCard.begin(), vctCard.end());
	return *(int*)(&vctCard[0]);
}
// ȡ�ü�ʱ
// inline DWORD GetTickCount()
// {
// 	struct timespec ts;
// 	clock_gettime(CLOCK_MONOTONIC, &ts);
// 	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
// }
// ΢�루���롢΢�롢���룩
// inline DWORD GetTickCountUs()
// {
// 	struct timespec ts;
// 	clock_gettime(CLOCK_MONOTONIC, &ts);
// 	return (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
// }
// �ַ�ת��
inline char getCharFlag(BYTE byIndex)
{
	static const char s_HuCardFlag[MAX_TOTAL_TYPE+1] = 
	{
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',				//��
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',				//��
		'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',				//��
		'J', 'K', 'L', 'M',
		'O', 'P', 'Q', '\0'
	};
	if (byIndex < MAX_TOTAL_TYPE)
	{
		return s_HuCardFlag[byIndex];
	}
	return INVALID_VAL;
}

//////////////////////////////////////////////////////////////
struct stHuData
{
	BYTE	byCardHu;
	BYTE	byNum;
	int		nVal;
};
struct stHuTips
{
	BYTE		byCardOut;
	stHuData	stData[10];

	stHuTips()
	{
		memset(this, 0, sizeof(*this));
	}
	stHuTips(BYTE byOut)
	{
		memset(this, 0, sizeof(*this));
		byCardOut = byOut;
	}
	stHuTips(const stHuTips& stTemp)
	{
		memcpy(this, &stTemp, sizeof(stHuTips));
	}
};

// ����ܵ�����
struct stCardInfo
{
	BYTE				byCard;		//��ֵ
	BYTE				byNum;		//����

	stCardInfo(BYTE card, BYTE num)
	{
		byCard = card;
		byNum  = byNum;
	}
	stCardInfo(){ memset(this, 0, sizeof(*this)); }
};

//�����ܽڵ�
struct stNodeMJ
{
	BYTE		byType;							//����������  �ο� BLOCK_CARD_TYPE	
	BYTE		byCardNum[MAX_TOTAL_TYPE];		//��������(����������Ų�ͬ����)	

	stNodeMJ() { memset(this, 0, sizeof(*this)); }

	BYTE getCardNum()
	{
		BYTE byNum = 0;
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)	
		{
			byNum += byCardNum[i];	
		}
		return byNum;
	}
	BYTE getCardType()
	{
		BYTE byNum = 0;
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)	
		{
			if (byCardNum[i] > 0) 
				++byNum;
		}
		return byNum;
	}
	void addCardInfo(BYTE byIndex, BYTE num)
	{
		byCardNum[byIndex] += num;
	}
	void delCardInfo(BYTE byIndex)		// ֻ��ɾһ���Ƶ�����
	{
		if (byCardNum[byIndex] > 0)
			--byCardNum[byIndex];
	}
	BYTE delCardAll(BYTE byIndex)
	{
		int num = byCardNum[byIndex];
		byCardNum[byIndex] = 0;
		return num;
	}
	bool isHaveCard(BYTE byIndex)
	{
		return byCardNum[byIndex] > 0;
	}
	std::vector<BYTE> getVecData()
	{
		std::vector<BYTE> vctOut;
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)
		{
			for (BYTE n=0; n<byCardNum[i]; ++n)
			{
				vctOut.push_back(getValByIndex(i));
			}
		}
		return vctOut;
	}
	void printNode()
	{
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)
		{			
			cout<<hex<<(int)getValByIndex(i)<<" : "<<(int)byCardNum[i]<<'\t';
		}
		cout<<endl;
	}
};

struct stKey
{
	BYTE byNum;
	BYTE byData[14];

	stKey() { memset(this, 0, sizeof(*this)); }
	stKey(const stKey &t) {memcpy(this, &t, sizeof(*this));}

	void append(BYTE num, BYTE val)
	{
		if (num > 0 && byNum+num <= 14)
			memset(&byData[byNum], val, num);
		byNum +=num;
	}
	string getString()
	{
		string strOut;
		for (BYTE i=0; i<byNum; ++i)
			strOut.append(1, getCharFlag(byData[i]));

		return strOut;
	}

	bool operator<(const stKey &t) const
	{
		if (t.byNum == byNum)
		{
			for (BYTE i=0; i<byNum; ++i)
			{
				if (byData[i] != t.byData[i])
					return byData[i] < t.byData[i];
			}
			return false;
		}
		return byNum < t.byNum;
	}
	bool operator==(const stKey &t) const
	{
		if (t.byNum == byNum)
		{
			for (BYTE i=0; i<byNum; ++i)
			{
				if (byData[i] != t.byData[i])
					return false;
			}
			return true;
		}
		return false;
	}
	stKey & operator=(const stKey &t)
	{
		memcpy(this, &t, sizeof(stKey));
		return *this;
	}
};

struct stColorData
{
	BYTE	byCorType;					// enColorMJ
	BYTE	byNum;						// ������
	BYTE	byCount[MAX_VAL_NUM];		// ͳ������

	stColorData(){memset(this, 0, sizeof(*this));}
	stKey getStringKey(BYTE byNaiIndex, BYTE byNum)
	{
		stKey strOut;
		int nMax = byCorType >= enColorMJ_FenZi ? 7 : 9;
		for (int i=0; i<nMax; ++i)
		{
			if (byCount[i] > 0)
				strOut.append(byCount[i], byCorType*9+i+1);
				//strOut.append(byCount[i], getCharFlag(byCorType*9+i));
		}
		if (byNaiIndex != INVALID_VAL && byNum > 0)
			strOut.append(byNum, INVALID_VAL);

		return strOut;
	}
};

struct stCardData
{
	BYTE	byCardCount[MAX_TOTAL_TYPE];		// ͳ������
	BYTE	byNum;								// ����
	BYTE	byHuCard;							// ���������ƣ�������;��

	stCardData()
	{
		memset(this, 0, sizeof(*this));
	}
	stCardData(BYTE byCards[], BYTE num)
	{
		memset(this, 0, sizeof(*this));
		addCard2(byCards, num);
	}

	void clear()
	{
		memset(this, 0, sizeof(*this));
	}
	void getCardsData(BYTE byCardOut[], BYTE num, bool bAddHuCard = false)
	{
		BYTE byIndex = 0;
		for (int i=0; i<MAX_TOTAL_TYPE; ++i)
		{
			if (byCardCount[i] > 0 && byCardCount[i]+byIndex <= num)
			{
				memset(byCardOut+byIndex, getValByIndex(i), byCardCount[i]);
				byIndex += byCardCount[i];
			}
		}
		if (bAddHuCard && byHuCard != 0 && byIndex<num)
		{
			byCardOut[byIndex] = byHuCard;			
		}
	}	
	void addCard2(BYTE byCards[], BYTE num)
	{
		byNum = num;
		for (int i=0; i<num; ++i)
		{
			++byCardCount[byCards[i]];
		}
	}	
	bool addCard(BYTE byCards[], BYTE num)
	{
		if (num <= 0 ) 
			return false;

		BYTE	byNumTemp = byNum;
		BYTE	byCardTemp[MAX_TOTAL_TYPE] = {};
		memcpy(byCardTemp, byCardCount, MAX_TOTAL_TYPE);
		for (int i=0; i<num; ++i)
		{
			BYTE byIndex = getIndexByVal(byCards[i]);
			if (byIndex < MAX_TOTAL_TYPE)
			{
				++byCardTemp[byIndex];
				++byNumTemp;
			}
			else
			{
				return false;
			}
		}
		memcpy(byCardCount, byCardTemp, MAX_TOTAL_TYPE);
		byNum = byNumTemp;
		return true;
	}
	bool DelCard(BYTE byCards[], BYTE num)
	{
		if (num <= 0 || num > byNum) 
			return false;

		BYTE	byNumTemp = byNum;
		BYTE	byCardTemp[MAX_TOTAL_TYPE] = {};
		memcpy(byCardTemp, byCardCount, MAX_TOTAL_TYPE);
		for (int i=0; i<num; ++i)
		{
			BYTE byIndex = getIndexByVal(byCards[i]);
			if (byIndex < MAX_TOTAL_TYPE && byCardTemp[byIndex] > 0)
			{
				--byCardTemp[byIndex];
				--byNumTemp;
			}
			else
			{
				return false;
			}
		}
		memcpy(byCardCount, byCardTemp, MAX_TOTAL_TYPE);
		byNum = byNumTemp;
		return true;
	}
	bool addCard(BYTE byCard, BYTE num)
	{
		BYTE byIndex = getIndexByVal(byCard);
		if (byIndex < MAX_TOTAL_TYPE)
		{
			//			if (num + byCardCount[byIndex] <= 4)
			{
				byCardCount[byIndex] += num;
				byNum += num;
				return true;
			}
		}		
		return false;
	}
	bool DelCard(BYTE byCard, BYTE num)
	{
		if (num <= 0 || num > byNum) 
			return false;

		BYTE byIndex = getIndexByVal(byCard);
		if (byIndex < MAX_TOTAL_TYPE)
		{
			if (num <= byCardCount[byIndex])
			{
				byCardCount[byIndex] -= num;
				byNum -= num;
				return true;
			}
		}		
		return false;
	}
	bool addCard(stNodeMJ stNode)
	{
		return true;
	}
	bool DelCard(stNodeMJ stNode)
	{	
		return true;
	}
};

struct stAnswer
{
	BYTE		nNum;
	stNodeMJ	stNode[5];	//���5��

	stAnswer()
	{
		memset(this, 0, sizeof(*this));
	}
	stAnswer(vector<stNodeMJ> &vctIn)
	{
		memset(this, 0, sizeof(*this));
		nNum = min(5, (int)vctIn.size());
		memcpy(stNode, &vctIn[0], nNum*sizeof(stNodeMJ));
	}
	stAnswer(const stAnswer &stTemp)
	{
		memcpy(this, &stTemp, sizeof(stAnswer));
	}

	bool addNode(stNodeMJ &nodeTemp)
	{
		if (nNum < 5)
		{
			stNode[nNum] = nodeTemp;
			++nNum;
			return true;
		}
		return false;
	}
	bool addNode(stAnswer &answerTemp)
	{
		if (answerTemp.nNum == 0 || nNum + answerTemp.nNum > 5)
			return false;

		memcpy(&stNode[nNum], answerTemp.stNode, sizeof(stNodeMJ)*answerTemp.nNum);
		nNum += answerTemp.nNum;
		return true;
	}
	bool delNode()
	{
		if (nNum > 0)
		{
			--nNum;
			//memset(&stNode[nNum], 0, sizeof(MJCPGNode));
			return true;
		}
		return false;
	}

	void getVctNode(vector<stNodeMJ> &vctOut)
	{
		memcpy(&vctOut[0], stNode, nNum*sizeof(stNodeMJ));
	};

	stAnswer & operator=(const stAnswer &t)
	{
		memcpy(this, &t, sizeof(stAnswer));
		return *this;
	}
};

//////////////////////////////////////////////////////////////
//��������ʱ�����б� + ������ʾ [ ��̬������Ϣ��sizeof(CMD_S_TingLock_HuTips)+byUnlockNum*sizeof(stHuTips) ]
#define SUB_S_TING_LOCK_HUTIPS			212							 //����ʱδ�����б�
struct CMD_S_TingLock_HuTips
{
	BYTE				  byUnlockNum;								 //δ��������
};
//stHuTips			  stHuInfo[13];									 //byUnlockNum�����Ʒ�ʽ


#pragma pack(1)