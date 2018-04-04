#ifndef CMD_SHOWHAND_HEAD_FILE
#define CMD_SHOWHAND_HEAD_FILE

#include <windows.h>

#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
//�����궨��
#define GAME_NAME						"��ɳ����"      //��Ϸ����
#define GAME_ID						    142             //��ϷID
#define GAME_PLAYER						4				//��Ϸ����

//�汾����
#define GAME_MAX_VER					1				//������߰汾
#define GAME_LESS_VER					1				//������Ͱ汾
#define GAME_CHANGE_VER					0				//�޸İ汾


//////////////////////////////////////////////////////////////////////////

#define	HAND_MJ_MAX						14              //���������ֵ
#define OUTCARD_COUNT_MAX               30              //�������ֵ
#define MAX_ZHUANIAO_COUNT              10              //���ץ����
#define MAX_MJ_TOTAL_COUTN              112             //�齫�����

#define SCORE_MAX_COUNT                 20              //���������


//��Ϸ״̬����
#define GS_WAIT_SETGAME					0				//�ȴ���������״̬   GameStation_2
#define GS_WAIT_ARGEE					1				//�ȴ�ͬ������       GameStation_2
#define GS_NT_TOUZEZI					20				//ׯ��������״̬     GameStation_3
#define GS_SEND_CARD					21				//����״̬           GameStation_4
#define GS_PLAY_GAME					22				//��Ϸ��״̬         GameStation_5
//#define GS_GAME_JIESUAN					23				//����״̬           GameStation_6
#define GS_WAIT_NEXT				    24				//�ȴ���һ�̿�ʼ     GameStation_6

#define MAX_TALK_LEN			        500				///����������ݳ���
#define GAME_NICK_LEN                   20              ///��Ϸ�ǳƳ���

#define  ASS_MAIN_GAME                  180  			///< ��Ϸר����Ϣ��ID

#define  ASS_GM_AGREE_GAME				1			    ///< ͬ����Ϸ

///�û�ͬ��ṹ
struct MSG_GR_R_UserAgree
{
	BYTE								bDeskNO;		///��Ϸ����
	BYTE								bDeskStation;	///λ�ú���
	BYTE								bAgreeGame;		///ͬ���־
};


#define ASS_GM_GAME_STATION				2		///��Ϸ״̬
/********************************************************************************/
//������չö��
enum E_LS_CONFIG_TYPE
{
	ECFGTYPE_LAIZICARD = 0, //������ֵ
};

//����������              v2.1
enum E_HU_MAIN_SERVER_CARD_TYPE
{
	EHU_MAIN_TYPE_NO  = 0              ,    //��
	EHU_MAIN_TYPE_PINGHU       = 0x0001,    //ƽ��
	EHU_MAIN_TYPE_PENPENHU     = 0x0002,    //������
	EHU_MAIN_TYPE_QINYISE      = 0x0004,    //��һɫ
	EHU_MAIN_TYPE_QIXIAODUI    = 0x0008,    //��С��
	EHU_MAIN_TYPE_HAOQIDUI     = 0x0010,    //���߶�
	EHU_MAIN_TYPE_SHISANYAO    = 0x0020,    //ʮ����

	EHU_MAIN_TYPE_QIDADUI      = 0x0040,    //�ߴ��    v2.5
	EHU_MAIN_TYPE_CHAOHAOQIDUI = 0x0080,    //�����߶�  v2.5

	EHU_MAIN_TYPE_MAX
};

//��Ϸ״̬���ݰ�	�� �ȴ���������״̬ ��
struct GameStation_1
{
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ  
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE             

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�
};

//��Ϸ״̬���ݰ�	�� �ȴ�ͬ������ ��
struct GameStation_2
{
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE   

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�

	bool                bIsAgree[GAME_PLAYER];          //ͬ����
};

//��Ϸ״̬���ݰ�	�� ׯ��������״̬ ��
struct GameStation_3
{
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE   

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�

	BYTE                bySatrtIndex;                   //�齫����ʼλ��
	BYTE                byEndIndex;                     //�齫�ս���λ��
	int                 iLeftMjCount;                   //ʣ���齫��
};

//��Ϸ״̬���ݰ�	�� ����״̬ ��
struct GameStation_4
{
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE   

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�

	BYTE                byDicePoint[2];                 //���ӵ���
	BYTE                bySatrtIndex;                   //�齫����ʼλ��
	BYTE                byEndIndex;                     //�齫�ս���λ��
	int                 iLeftMjCount;                   //ʣ���齫��
};

//��Ϸ״̬���ݰ�	�� ��Ϸ��״̬ ��
struct GameStation_5
{	
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE   

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�

	BYTE                byDicePoint[2];                 //���ӵ���
	BYTE                bySatrtIndex;                   //�齫����ʼλ��
	BYTE                byEndIndex;                     //�齫�ս���λ��
	int                 iLeftMjCount;                   //ʣ���齫��

	//����ʱ
	BYTE                bySeatNo;                       //��ʱ��ָ����λ��
	int                 iDjsTimes;                      //��ʱ������ʱ����

	//��
	BYTE                byPengCardList[GAME_PLAYER][4];    //�����б�
	BYTE                byMingGangCardList[GAME_PLAYER][4];//�������б�
	BYTE                byAnGangCardList[GAME_PLAYER][4];  //�������б�
	BYTE                byChiList[GAME_PLAYER][4][3];      //�����б�

	BYTE                byOtherSeatMjCount[GAME_PLAYER];   //���������������
	BYTE                byMyHandMjs[HAND_MJ_MAX];          //�Լ������齫

	BYTE                byOutCardList[MAX_MJ_TOTAL_COUTN]; //��ҳ�����
	BYTE                byCurMjShowSeat;                   //��ǰ�����齫��ͷ��ʾ���,255��ʾû�м�ͷָ��
	BYTE                byCurOperateStation;               //��ǰ����λ��
	BYTE                byCurOpStatus;                     //��ǰ����״̬,0���ڳ����У�1������ɣ��ȴ�������Ҳ���(�����������˳�����)
};

#define ASS_GM_NORMAL_TALK				4									///��ͨ����
///����ṹ 
struct MSG_GR_RS_NormalTalk
{
	COLORREF							crColor;							///������ɫ
	SHORT								iLength;							///��Ϣ����
	LONG								dwSendID;							///�û� ID
	LONG								dwTargetID;							///Ŀ�� ID
	int									nDefaultIndex;						///=0����������ݣ�>0��ѡ�������
	char								szMessage[MAX_TALK_LEN+1];			///��������
};


#define ASS_NOTIFY_USER_NET_CUT  		5									///֪ͨ����
///֪ͨ���� 
struct MSG_NOTIFY_USER_NET_CUT
{
	BYTE				 byNetCutSeatNo;				 //������λ��
	bool                 bIsNetCut;                      //�Ƿ����
};


//��Ϸ��ʼ
#define SUB_S_GAME_START				0x201									//��Ϸ��ʼ
struct CMD_S_GameStart
{
	BYTE				 byBankerSeatNo;				 //ׯ����λ��
	int                  iTotalRound;                    //����Ϸ����
	int                  iLeftRound;                     //ʣ����پ�

	BYTE                 byDicePoint[2];                 //���ӵ���
	BYTE                 byStartSeat;                    //���ļҿ�ʼץ��
	BYTE                 byStartPos;                     //���Ķտ�ʼץ��
	int                  iLeftMjCount;                   //ʣ���齫��
};

////Ͷ����
//#define SUB_S_GAME_START				0x202									//Ͷ����
//struct CMD_S_CASE_DICE
//{
//	BYTE byDicePoint[2];//���ӵ���
//	BYTE byDiceStep;    //�ڼ���������
//	BYTE byBankPos;     //ׯ�ҵ�λ��
//	BYTE byStartSeat;  //���ļҿ�ʼץ��
//	BYTE byStartPos;   //���Ķտ�ʼץ��
//};

//�����齫
#define SUB_S_SEND_MJ					0x203							    //����
struct CMD_S_SendMj
{
	BYTE				  byMjs[HAND_MJ_MAX];				     //�������齫��
	BYTE				  byMjCount;							 //�齫��Ŀ
	BYTE				  byBankerSeatNo;				         //ׯ����λ��

	BYTE                  bySatrtIndex;                          //�齫����ʼλ��
	BYTE                  byEndIndex;                            //�齫�ս���λ��
	int                   iLeftMjCount;                          //ʣ���齫��
};

//�û�����
//������->�ͻ��� �㲥��
#define SUB_S_TOUCH_MJ					0x204							    //�û�����
struct CMD_S_TouchMj
{
	BYTE				   byTouchMj;							   //�����齫 ����������ֵΪ0
	BYTE				   byCurUserSeatNo;   					   //��ǰ���λ��
	BYTE                   bySatrtIndex;                           //�齫����ʼλ��
	BYTE                   byEndIndex;                             //�齫�ս���λ��
	int                    iLeftMjCount;                           //ʣ���齫��
};

//��Ҳ�������
enum E_ACTION_TYPE
{
	EACTION_OUTCARD   = 0x0001, //����
	EACTION_CHI_LEFT  = 0x0002, //����--���(@**)
	EACTION_CHI_MID   = 0x0004, //����--�г�(*@*)
	EACTION_CHI_RIGHT = 0x0008, //����--�ҳ�(**@)
	EACTION_PENG      = 0x0010, //����
	EACTION_GANG_DIAN = 0x0020, //��--���
	EACTION_GANG_BU   = 0x0040, //��--����
	EACTION_GANG_AN   = 0x0080, //��--����
	EACTION_HU_ZIMO   = 0x0100, //��--����
	EACTION_HU_DIAN   = 0x0200, //��--���ں�
	EACTION_GIVEUP    = 0x0400, //��(����)
};

//���ƶ������� ��غ�     v2.1
enum E_HU_CARD_EXTENDS_TYPE  
{
	EHUEXTENDS_TYPE_NO   = 0           ,  //��
	EHUEXTENDS_TYPE_QIDUI	   = 0x0001,  //�߶�
	EHUEXTENDS_TYPE_GANG_HUA   = 0x0002,  //���ϻ�
	EHUEXTENDS_TYPE_SIHONGZHONG= 0x0004,  //�ĺ���
	EHUEXTENDS_TYPE_GANG_PAO   = 0x0008,  //������
	EHUEXTENDS_TYPE_QIANGGANGHU= 0x0020,  //���ܺ�
	EHUEXTENDS_TYPE_TIAN       = 0x0040,  //���
	EHUEXTENDS_TYPE_DI         = 0x0080,  //�غ�
	EHUEXTENDS_MEN_QING        = 0x0100,  //�Ƿ�����
};

//���б�����
enum E_CARD_LIST_TYPE
{
	ECARDLISTTYPE_CHI  = 0 , //��
	ECARDLISTTYPE_PENG ,     //��
	ECARDLISTTYPE_GANG_DIAN ,//��--���
	ECARDLISTTYPE_GANG_BU ,  //��--����
	ECARDLISTTYPE_GANG_AN ,  //��--����
};

//������Ӧ�����б�
struct stOpCardList
{
	BYTE                 byCardltType;    //���б�����   �ο�E_CARD_LIST_TYPE
	BYTE	             byCard[4];       //�ܲ����Ķ�����Ӧ�����б� , ���(2��һ��)�����ܡ����ܵ�
};

//������֪ͨ��Ҳ���
//�����->�ͻ��� 
#define SUB_S_NOTIFY_USER_OPERATE      0x205   				//֪ͨ��ҽ��в���
struct CMD_S_NOTIFY_USER_OPERATE
{
	DWORD                dwEnableAction;  //�ܲ����Ķ���  �ο�E_ACTION_TYPE 

	BYTE                 byOutMjSeatNo;   //Ŀ����λ�� , ���ԡ�������ܡ����ں� ˭����
	BYTE                 byOutMj;         //Ŀ����λ�����齫

	BYTE	             byCardNum;       //�ܲ����Ķ�����Ӧ��������
	stOpCardList         lsCardInfo[1];   //���б�
};

//��ҽ��в���
//�ͻ���->����� 
#define SUB_C_USER_DO_ACTION	        0x106   			//��ҽ��в���
struct CMD_C_USER_DO_ACTION
{
	DWORD   dwAction;        //����  �ο�E_ACTION_TYPE 

	BYTE	byCardNum;       //������Ӧ��������
	BYTE	byCard[4];       //������Ӧ�����б� ,���� �����ơ��Ե��ơ��ܵ��ơ�������
};

//����й�
//�ͻ���->����� 
#define SUB_C_USER_TUOGUAN	        0x108   			//�й�
struct CMD_C_USER_TUOGUAN
{
	byte							byIsTuoGuan;							//�Ƿ��й�
};

//��Ҳ���ʧ��
//�����->�ͻ��� 
#define SUB_S_USER_ACTION_R_FAIL	    0x206   			//��Ҳ���ʧ�� ����
struct CMD_S_USER_ACTION_R_FAIL
{
	int iCode;            //������
};
//������:
#define ERR_ACTION_CODE_WAIT_OTHER_OPERATE      1           //�ȴ�������Ҳ���

//��Ҳ����ɹ�,�㲥��Ҳ����������
//�����->�ͻ��� �㲥��
#define SUB_S_USER_ACTION_R_SUCC	    0x207   			//��Ҳ����ɹ� ����
struct CMD_S_USER_ACTION_R_SUCC
{
	BYTE	bySeatNo;        //������λ��
	DWORD   dwAction;        //����  �ο�E_ACTION_TYPE 

	BYTE    byOutMjSetaNo;   //Ŀ����λ�� , ���ԡ�������ܡ����ں� ˭����
	BYTE    byOutMj;         //Ŀ����λ�����齫

	BYTE    bySatrtIndex;    //�齫����ʼλ��
	BYTE    byEndIndex;      //�齫�ս���λ��
	int     iLeftMjCount;    //ʣ���齫��

	BYTE	byCardNum;       //������Ӧ��������
	BYTE	byCard[4];       //������Ӧ�����б�
};


//////////////////////////////////////////////////////////////////////////
//��Ϸ����
#define SUB_S_GAME_END           	    0x209   			//��Ϸ����

//�����������
enum E_CALC_SCORE_TYPE
{
	ECSCORE_HU_ZIMO = 0 , //������
	ECSCORE_DIAN_PAO    , //����
	ECSCORE_JIE_PAO     , //����
	ECSCORE_DIAN_GANG   , //���
	ECSCORE_JIE_GANG    , //�Ӹ�
	ECSCORE_AN_GANG     , //����
	ECSCORE_BU_GANG     , //����
	ECSCORE_ZHONG_NIAO  , //����
	ECSCORE_BEI_QGANG   , //������
	ECSCORE_QGANG_HU    , //���ܺ�
};

struct stZhuaNiaoCard
{
	BYTE    byNiaoMj;              //ץ����
	BYTE    byIsZhongNiao;         //�Ƿ�����  1��,0��
	BYTE    bySeatNo;              //����λ��
};

//һ����Ӯ������Ϣ
struct stOneUserEndInfo
{
	int    iCurTotalPan;         //����������
	INT64  iCurTotalMoney;       //��������Ӯ����
	INT64  iCurGangMoney;        //���ָܶ��ٷ���    v2.2
	INT64  iCurHuMoney;          //���ֺ����ٷ���    v2.2
	INT64  iCurNiaoMoney;        //����������ٷ���  v2.2
	INT64  iTotalMoney;          //��ǰ���ٶ�
	int    iTax;                 //��˰

	BYTE   byPengCardList[4];    //�����б�
	BYTE   byMingGangCardList[4];//�������б�
	BYTE   byAnGangCardList[4];  //�������б�
	BYTE   byChiList[4][3];      //�����б�
	BYTE   byHandMjs[HAND_MJ_MAX];  //�����齫 ,������Һ����� �����һ����

	char   szUserNick[GAME_NICK_LEN];//�û��ǳ�

	BYTE   byLsDetailCount[SCORE_MAX_COUNT]; //�������Ͷ�Ӧ�ĸ���,�±�ο� E_CALC_SCORE_TYPE
	
	DWORD  dwHuExtendsType;      //���ƶ�������--��غ�, �ο�E_HU_CARD_EXTENDS_TYPE   v2.1
}; 

//һ����Ӯ������Ϣ
struct stOneUserEndInfo_double
{
	double lfCurTotalMoney;       //��������Ӯ����
	double lfCurGangMoney;        //���ָܶ��ٷ���    v2.2
	double lfCurHuMoney;          //���ֺ����ٷ���    v2.2
	double lfCurNiaoMoney;        //����������ٷ���  v2.2
};

struct CMD_S_GameEnd
{
	BYTE                            byIsLiuJu;                //�Ƿ����� 1��,0��
	BYTE				            byBankerSeatNo;			  //ׯ����λ��
	BYTE                            byZhuaNiaoSeatNo;         //ץ����λ��
	stOneUserEndInfo                userDetail[GAME_PLAYER];

	BYTE                            byZhuaNiaoCount;                //ץ���齫��
	stZhuaNiaoCard                  lsZhuaNiao[MAX_ZHUANIAO_COUNT]; //ץ�����б� 
};
//////////////////////////////////////////////////////////////////////////

//��ʱ��
//�����->�ͻ���
#define SUB_S_NOTIFY_TIME	            0x210   		 	//��ʱ��
struct CMD_S_NOTIFY_TIME
{
	BYTE                            bySeatNo;               //��ʱ��ָ����λ��
	int                             iDjsTimes;              //��ʱ������ʱ����
};

//֪ͨ�ܺ������б�  v2.1
//�����->�ͻ���
#define SUB_S_NOTIFY_CAN_HU_CARDS       0x211   		 	//֪ͨ�ܺ�����
struct CMD_S_NOTIFY_CAN_HU_CARDS
{
	BYTE                            byCanHuCards[28];       //�ܺ������б�
};

//��������ܶ����Ƹܺ�2���������Ĳ���
//������->�ͻ��� �㲥��
#define SUB_S_NOTIFY_USER_TUOGUAN			0x217									//�йܹ㲥
struct CMD_S_NOTIFY_USER_TUOGUAN
{
	byte				byUserTuoGuan[GAME_PLAYER];			//
};

//��Ϸ״̬���ݰ�	�� ����״̬  ��
struct GameStation_6
{
	BYTE				bStation;						//��Ϸ״̬
	BYTE				iVersion;						//��Ϸ�汾��
	BYTE				iVersion2;						//��Ϸ�汾��

	//������Ϣ  
	int                 iLsConfig[10];                  //�����б�Ԥ������ ,����E_LS_CONFIG_TYPE 

	//��Ϸ��Ϣ
	BYTE				byBankerSeatNo;				    //ׯ����λ��
	int                 iTotalRound;                    //����Ϸ����
	int                 iLeftRound;                     //ʣ����پ�

	bool                bIsAgree[GAME_PLAYER];          //ͬ����

	CMD_S_GameEnd       sGameEndInfo;                   //������Ϣ
};

#pragma pack(1)

#endif