#pragma once

#include <list>
#include <vector>
#include "CMD_Mj.h"
#include "DefineHuTip.h"

//#define TOTAL_MJ_CARD_NUM    108               //�齫�Ƶ�������
#define TOTAL_DICE_NUM        2                //���ӵĸ���
 
//�齫�ƶ���
enum E_TYPE_MJ_KIND
{
	MJ_TYPE_FLOER_KIND_WAN = 0,  //��
	MJ_TYPE_FLOER_KIND_TONG,     //Ͳ
	MJ_TYPE_FLOER_KIND_TIAO,     //��
	MJ_TYPE_FLOER_KIND_DXNB,     //�����ϱ�
	MJ_TYPE_FLOER_KIND_ZFB,      //�з���

	MJ_TYPE_FLOER_TOTAL
};

//����������ֵ
static const BYTE s_arrayCardType[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x41																//�з���
};

//3,4��תת�齫
static const BYTE arryAllMj_ZZ_4[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//��
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//��
	0x41
};

////2��תת�齫  test
//static const BYTE arryAllMj_ZZ_2[] = 
//{
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
//	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
//	0x41, 0x42, 0x43,                                                   //�з���
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
//	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
//	0x41, 0x42, 0x43,                                                   //�з���
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
//	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
//	0x41, 0x42, 0x43,                                                   //�з���
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
//	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
//	0x41, 0x42, 0x43,                                                   //�з���
//	0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41
//};

//2��תת�齫
static const BYTE arryAllMj_ZZ_2[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
	0x41, 0x42, 0x43,                                                   //�з���

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
	0x41, 0x42, 0x43,                                                   //�з���
	
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
	0x41, 0x42, 0x43,                                                   //�з���

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//��
	0x31, 0x32, 0x33, 0x34,                                             //�����ϱ�
	0x41, 0x42, 0x43                                                    //�з���
};

//�����ܽڵ�
struct MJCPGNode
{
	BYTE byBlockCardType; //����������  �ο�BLOCK_CARD_TYPE
	BYTE bySeat;          //�����ܵĶ���
	BYTE byOutCard;       //�����ܱ��˵�������
	BYTE byMjCard[4];     //��������
};

//һ��������
enum BLOCK_CARD_TYPE
{	
	BLOCK_NULL	 = 0,				//��
	BLOCK_DUIZI,                    //����
	BLOCK_SUN_CHI,					//˳�� ���� ���� �ṹ
	BLOCK_KEZI_PENG,				//���� ���� ���� �ṹ,3����ͬ
	BLOCK_GANG_DIAN,   				//����--���,4����ͬ
	BLOCK_GANG_BU,   				//����--����,4����ͬ
	BLOCK_GANG_AN ,					//����--����,4����ͬ
};

//��ǰ����״̬
enum E_CUR_SEAT_OP_STATUS
{
	TSEAT_STATUS_OP_ING = 0,                 //���ڲ�����
	TSEAT_STATUS_WAIT_OTHER_OP_MYOUT_CARD,   //�Լ�������,�ȴ�������Ҳ���(�ҳ����������˿��ܳ�����)
	TSEAT_STATUS_WAIT_OTHER_OP_MYGANG_CARD,  //�ȴ�������� �� �Ҳ��ܵ��ƽ��в���
	TSEAT_STATUS_OP_COMPLETE   //�������
};

//��Ϸ�е���ʱ����
enum E_DJS_GAME_PLAYING
{
	EGPDJS_NO        = 0,    //û�е���ʱ
	EGPDJS_TOUSHAIZI,        //Ͷ���ӵ���ʱ
	EGPDJS_FAPAI,            //���Ƶ���ʱ
	EGPDJS_OUTCARD,          //���Ƶ���ʱ
	EGPDJS_WAIT_OTHERCHOOSE, //�ȴ������˲�������ʱ
	EGPDJS_ZHUANIAO,         //ץ�񵹼�ʱ
	EGPDJS_WAITEND,          //�ȴ����㵹��ʱ
};

//��ɳ����---�齫ץ���� ,��Ӧm_unOpt2
enum E_CSHZ_MJ_OPTION4_ZHUANIAO 
{
	E_CSHZ_MJ_OP4_NIAO_NO = 0,  //��
	E_CSHZ_MJ_OP4_NIAO2   = 1,  //2����
	E_CSHZ_MJ_OP4_NIAO3   = 2,  //3����
	E_CSHZ_MJ_OP4_NIAO4   = 3,  //4����
	E_CSHZ_MJ_OP4_NIAO6   = 4,  //6����

	E_CSHZ_MJ_OP4_NIAO_MAX
};

enum E_CSHZ_MJ_OPTION2_GANG
{
	E_CSHZ_MJ_OP2_GANG_NO = 0,		//��
	E_CSHZ_MJ_OP2_GANG_1 = 0x01,	//�ɹ��󲹸�
	E_CSHZ_MJ_OP2_GANG_2 = 0x02,	//�������󲹸�
	E_CSHZ_MJ_OP2_GANG_MAX
};

enum E_CSHZ_MJ_OPTION3_HU_NIAO
{
	E_CSHZ_MJ_OP3_HU_NIAO_NO = 0,	//��
	E_CSHZ_MJ_OP3_HU_NIAO_1 = 1,	//û���м�1��
	E_CSHZ_MJ_OP3_HU_NIAO_2 = 2,	//û���м�2��
	E_CSHZ_MJ_OP3_HU_NIAO_MAX
};

//����������Ĳ���
struct SERVER_SAVE_USER_OPERATE
{
	DWORD                dwEnableAction;  //�ܲ����Ķ���  �ο�E_ACTION_TYPE 

	BYTE                 byOutMjSeatNo;   //Ŀ����λ�� , ���ԡ�������ܡ����ں� ˭����
	BYTE                 byOutMj;         //Ŀ����λ�����齫

	std::vector<stOpCardList> vecCardList;

public:
	SERVER_SAVE_USER_OPERATE()
	{
		ClearData();
	}

	void ClearData()
	{
		dwEnableAction = 0;
		byOutMjSeatNo  = 0;
		byOutMj        = 0;
		vecCardList.clear();
	}
};