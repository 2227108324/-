#pragma once
#include<iostream>
#include<cstdio>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<string>
#include<mmsyscom.h>
#pragma comment(lib,"winmm.lib")


extern int map[20][15][17];//�޷��ƻ���ǽ�͵�ͼ�߽� 0  | ���ƻ�����Ʒ  1|  �յ� 2 

extern ExMessage msg;//����豸��Ϣ���������
struct User {
	//������Ϣ
	bool isLoad; //�Ƿ��¼��Ϣ�ж�(δ��¼Ϊ0���ѵ�¼Ϊ1)
	int id;//�˺�
	std::string username;//�Զ�����Ϸ����
	std::string password;//����
};

struct Tool {
	std::string toolname;//��������
	int index;//���߶�ӦͼƬ
	int x, y;//��������
	int  weight, lenth;//δʰȡ��ײ��
};

//��ɫ����
struct Character {

	int x, y;//��ɫ����������  
	int weight, lenth;//��ɫ�Ŀ�ȣ�x���볤�ȣ�y�� ������ײ��
	int score; //��Ϸ�÷�
	int speed; //�ƶ��ٶ�
	int tool[2];//������
};
//��Ϸ����
struct gameAttributes {
	int PlayerCnt;//�������
	int map;//��ͼ���
	int lever;//�ؿ�
	Character Player1,Player2;
	int time;
};
//������Ϣ
struct Config {
	int view;//�����л�
	bool bgm;//�������ֿ���
	bool sound;//��Ч����
	int FPS;//֡��
};



/*================================================================================================*/
/*==========================================view==================================================*/


/*=========���ù���============*/
class botton {
public:
	int x, y, w, h;
	botton(int x, int y, int w, int h);//��ʼ����ť��ֵ
	bool isArea(ExMessage& msg);//�ж����λ���Ƿ��ڰ�ť��
	void showBotton(ExMessage& msg, const char* text);//չʾ��ť���Ӵ���ɫ
	bool isBTCLK(ExMessage& msg);//�ж��Ƿ��°���
};

void textOut(int x);//��ӡ��������
void textOut(double x);//��ӡ����������
/*=============================*/


/*
 �˵�����  
 ���ܣ�
   ͨ���ı�
	չʾ�˵�����	
	��ʼ��Ϸ		
	��Ϸ˵��	���������Ϸ˵��ҳ��
	��Ϸ����	���������Ϸ����ҳ��
	�˳���Ϸ	��������˳���Ϸ
 

 ���� void
 ����ֵ void
*/
void menuView();

/*
 ��¼����
 ���ܣ�
	���룺�˺ź�����
	���û����������������û��������ڣ���ʾ�û��������ڻ��������
	���Խ���ע����� ������������� �ͷ������˵�����
	��¼�ɹ�ֱ�ӷ������˵�
 ���� user
 ����ֵ void
*/
void signInView();

/*
ע�����
 �����û���������   �˺�ID��ϵͳ�Զ��ṩ��
 ���볤������
 ע��ɹ�ֱ�ӷ������˵�
 ����user
 ����ֵ void
*/
void registerView();

/*
��Ϸ���ý���
 �ɿ�����Ч������
 �������˵�
 ����Config config
 ����ֵ void
*/
void setGameView();

/*
ģʽѡ�����
 ��ͼѡ��
 ��������ѡ��
 �ؿ���ѡ��
 ����gameAttributes
 ����ֵ void
*/

void gameChooseView();

/*
��Ϸ����
 �����Ϣչʾ
 while����Ϸ�����жϣ�{
	��ʱ �ƶ� �Ʒ� ���ߵ�ʹ�� ������ƶ�����Ч������
   ��ͣ���� ����
 }
 ��Ϸ��������
  ����gameAttributes
 ����ֵ void
*/
void gameView();

/*
������Ϸ�������жϽ����ӡ��ͬ�����ݣ����ṩ�������˵�����һ�أ����¿�ʼ�Ȱ�ť
��Ҫ�õ�isGameEnd()
���� 
����ֵ void
*/
void endView();


/*================================================================================================*/
/*===========================================logic================================================*/


/*
����¼��
�ж��˺��������ݿ������
���� user
����ֵ  �˺Ų�����0 �˺Ŵ����������1 ������ȷ2  
*/
int checkIDPW(User& user);
/*
 ��ע�ᣩ
 �ж�����������볤��8~16λ ��
 ���� user 
 �Ż�ֵ ���������1 ���򷵻� 0
*/
bool checkPWRight();

/*
���ñ�������
���� ����·�� �Ƿ��ظ����� ����Ĭ��ֵ
����ֵvoid
*/

void playBackGroundMusic(const char* music, bool repeat = false, int volume = -1);

/*
�����ã�
�����͹ر����� ���ݲ�ͬ�Ľ��沥�Ų�ͬ�ı�������
��Ҫʹ�� playBackGroundMusic����
���� config
����ֵ void

*/
void setBGM(Config& config);

/*
 ����Ϸ��
 �����ƶ� 
 ������ײ���⺯��
 ���� ExMessage msg
 ����ֵvoid
*/
void move(ExMessage msg);

/*
 ��ײ����
 ���ݽ�ɫ����ײ��͵�ͼ�е��ϰ������߽�����ײ����
 ���� Character 
 ����ֵ bool
*/
bool checkCollision();

/*
ը���ķ��� ��ʱʱ��ը
*/
void bomb();



/*
��ʱ��
����void
�Ż�ֵ int
*/
int timepiece();

/*
��Ϸ�����ж�
ʱ���������1  ���i�÷�������������i
����  gameAttributes
����ֵ int 
*/
int isGameEnd(int time);

/*================================================================================================*/
