#ifndef __MJ_HUTIPS_H__
#define __MJ_HUTIPS_H__

#include <map>
#include "Define.h"
#include "DefineHuTip.h"

/********************************************************************
	created:	pino
	file base:	CHuTipsMJ
	author:		pino	
	purpose:	�齫�����߼��㷨
*********************************************************************/

class CHuTipsMJ
{
public:	
	CHuTipsMJ():m_nPlayMode(0){}

	//��ʼ��
	void init();	
	//��������ɾ��һ������
	bool Remove(stCardData &stData,BYTE* byDelList, BYTE iNum);
	//������е���
	BYTE RandAllCard(BYTE iCard[], BYTE iCardCount);
	//�Ƿ�λ�Ƿ���ai������
	bool IsInvalideIndex(BYTE bAICard); 
	//�õ���Ϸ���ݵĻ�ɫ
	BYTE GetCardCor(BYTE bGameCard);
	//�õ��齫�Ƶ��Ƶ�
	BYTE GetCardVal(BYTE bGameCard);
	
	//-----------------------------------------------------------
	//----------------�齫�߼��㷨-------------------------------
	//Ͷ����
	BYTE GetDiceVal();

	//����Ƿ����
	bool CheckCanPeng(stCardData &stData, BYTE byPengCard);  

	//������ܹ� ����
	bool CheckCanVisbleGang(stCardData &stData,BYTE byGangCard);

	//������ܹ� ����
	vector<stNodeMJ> CheckSelfHiddenGang(stCardData &stData);

	//������ܹ� �����
	vector<stNodeMJ> CheckSelfGangSpecial(stCardData &stData);

	//��ȡ����ܽṹ
	bool getGangNodeSpecial(BYTE byCards[3], stNodeMJ &outNode);
	bool getGangNodeSpecial_4(BYTE byCards[4], stNodeMJ &outNode);

	//
	bool getSpecialNode(stCardData &stData, BYTE byCardVal[], BYTE num, stNodeMJ &stNodeOut);
	
	//��ĳ���ƽ��в���
	bool CheckBuGang(std::vector<stNodeMJ> &vctNodeSave, BYTE byCurHandPai);
	//��ĳ���ƽ�������ܲ���
	bool CheckBuGang_Spe(std::vector<stNodeMJ> &vctNodeSave, BYTE byCurHandPai);

    //��������ܷ񲹸�
	vector<BYTE> CheckSelfBuGang(stCardData stData, std::vector<stNodeMJ> &vctNodeSave);
	//��������ܷ�����ܲ���
	vector<BYTE> CheckSelfBuGang_Spe(stCardData stData, std::vector<stNodeMJ> &vctNodeSave);
	
	//���ں�
	//bool CheckWin_Dian(stCardData stData, std::vector<stNodeMJ>& vctNodeOut,BYTE byOutCard,BYTE byNaiziCard, map<stKey, stAnswer> &mapHuanCun);
	bool CheckWin_Dian(stCardData &stData, BYTE byNaiziCard);

	//��-��С��
	bool CheckWin_7XiaoDui(stCardData stData, std::vector<stNodeMJ>& vctNodeOut, BYTE byOutCard, BYTE byNaiziCard);

	//������-��ͨ��
	bool CheckWin_ZiMo_Normal(stCardData stData,std::vector<stNodeMJ>& vctNodeOut, BYTE byNaiziCard);

	//
	bool CanWin(stCardData &stData, stAnswer& stResult, BYTE byIndexNaiZi=INVALID_VAL, int nFlag=0);
	bool CanWin2(stCardData &stData, BYTE byIndexNaiZi);

	// ������ʱ������ɫ�������
	bool CanWin_Do(stCardData &stData);
	bool ColorMatch(stColorData &stData, int nFlag=0);
	// ������ʱ������ɫ�������
	bool CanWin_Do_Nai(stCardData &stData, BYTE byIndexNaiZi = INVALID_VAL);
	bool CanWin_Do_Nai2(stCardData &stData, stAnswer& stResult, BYTE byIndexNaiZi, map<stKey, stAnswer> &mapHuanCun);
	bool ColorMatch2(stColorData &stData, int nFlag=0, BYTE byCardNaiZi = INVALID_VAL, BYTE byNumNaiZi = 0);
  
	// ��������Ƿ���԰�ĳ���ƴ�����������ϱ����������Ʋ��ܳ�������ʧ��
	bool CheckCanPlay(stCardData &stData, BYTE byCard);   

	vector<BYTE> getCardList(stNodeMJ &stNode);
	// �����淨ģʽ enPlayMode
	void setPlayMode(BYTE byMode);
	// ��ȡ�Ƿ���ĳģʽ
	bool isHaveMode(BYTE byFlag);
	
private:   
	BYTE			m_nPlayMode;	// enPlayMode
	map<int, BYTE>	m_mapGangSp;	// �����
};

#endif