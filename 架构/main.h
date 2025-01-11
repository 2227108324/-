#pragma once
#include<iostream>
#include<cstdio>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<string>
#include<mmsyscom.h>
#pragma comment(lib,"winmm.lib")


extern int map[20][15][17];//无法破环的墙和地图边界 0  | 可破坏的物品  1|  空地 2 

extern ExMessage msg;//外接设备信息，键盘鼠标
struct User {
	//基本信息
	bool isLoad; //是否登录信息判断(未登录为0，已登录为1)
	int id;//账号
	std::string username;//自定义游戏名称
	std::string password;//密码
};

struct Tool {
	std::string toolname;//道具名称
	int index;//道具对应图片
	int x, y;//生成坐标
	int  weight, lenth;//未拾取碰撞箱
};

//角色属性
struct Character {

	int x, y;//角色的像素坐标  
	int weight, lenth;//角色的宽度（x）与长度（y） 用于碰撞箱
	int score; //游戏得分
	int speed; //移动速度
	int tool[2];//道具栏
};
//游戏属性
struct gameAttributes {
	int PlayerCnt;//玩家数量
	int map;//地图序号
	int lever;//关卡
	Character Player1,Player2;
	int time;
};
//配置信息
struct Config {
	int view;//界面切换
	bool bgm;//背景音乐开关
	bool sound;//音效开关
	int FPS;//帧率
};



/*================================================================================================*/
/*==========================================view==================================================*/


/*=========常用工具============*/
class botton {
public:
	int x, y, w, h;
	botton(int x, int y, int w, int h);//初始化按钮的值
	bool isArea(ExMessage& msg);//判断鼠标位置是否在按钮内
	void showBotton(ExMessage& msg, const char* text);//展示按钮，接触变色
	bool isBTCLK(ExMessage& msg);//判断是否按下按键
};

void textOut(int x);//打印整型数字
void textOut(double x);//打印浮点型数字
/*=============================*/


/*
 菜单界面  
 功能：
   通过改变
	展示菜单界面	
	开始游戏		
	游戏说明	点击进入游戏说明页面
	游戏设置	点击进入游戏设置页面
	退出游戏	点击即可退出游戏
 

 参数 void
 返回值 void
*/
void menuView();

/*
 登录界面
 功能：
	输入：账号和密码
	若用户名存在密码错误或用户名不存在，提示用户名不存在或密码错误
	可以进入注册界面 和忘记密码界面 和返回主菜单界面
	登录成功直接返回主菜单
 参数 user
 返回值 void
*/
void signInView();

/*
注册界面
 输入用户名和密码   账号ID（系统自动提供）
 密码长度限制
 注册成功直接返回主菜单
 参数user
 返回值 void
*/
void registerView();

/*
游戏设置界面
 可开关音效和音乐
 返回主菜单
 参数Config config
 返回值 void
*/
void setGameView();

/*
模式选择界面
 地图选择
 游玩人数选择
 关卡数选择
 参数gameAttributes
 返回值 void
*/

void gameChooseView();

/*
游戏界面
 玩家信息展示
 while（游戏结束判断）{
	计时 移动 计分 道具的使用 人物的移动动画效果播放
   暂停界面 返回
 }
 游戏结束界面
  参数gameAttributes
 返回值 void
*/
void gameView();

/*
根据游戏结束的判断结果打印不同的内容，并提供返回主菜单，下一关，重新开始等按钮
需要用到isGameEnd()
参数 
返回值 void
*/
void endView();


/*================================================================================================*/
/*===========================================logic================================================*/


/*
（登录）
判断账号密码数据库存在性
参数 user
返回值  账号不存在0 账号存在密码错误1 密码正确2  
*/
int checkIDPW(User& user);
/*
 （注册）
 判断密码合理（密码长度8~16位 ）
 参数 user 
 放回值 密码合理返回1 否则返回 0
*/
bool checkPWRight();

/*
设置背景音乐
参数 音乐路径 是否重复播放 音量默认值
返回值void
*/

void playBackGroundMusic(const char* music, bool repeat = false, int volume = -1);

/*
（设置）
开启和关闭音乐 根据不同的界面播放不同的背景音乐
需要使用 playBackGroundMusic函数
参数 config
返回值 void

*/
void setBGM(Config& config);

/*
 （游戏）
 人物移动 
 利用碰撞箱检测函数
 参数 ExMessage msg
 返回值void
*/
void move(ExMessage msg);

/*
 碰撞箱检测
 根据角色的碰撞箱和地图中的障碍物或道具进行碰撞箱检测
 参数 Character 
 返回值 bool
*/
bool checkCollision();

/*
炸弹的放置 定时时爆炸
*/
void bomb();



/*
计时器
参数void
放回值 int
*/
int timepiece();

/*
游戏结束判断
时间结束返回1  玩家i得分满足条件返回i
参数  gameAttributes
返回值 int 
*/
int isGameEnd(int time);

/*================================================================================================*/
