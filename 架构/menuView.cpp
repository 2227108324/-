#include"main.h"
extern Config config;
extern ExMessage msg;
void menuView() {
	IMAGE img_menubk;
	loadimage(&img_menubk, "images/menubk.jpg");
	putimage(0, 0, &img_menubk);
	botton b1(300, 300, 200, 50);
	BeginBatchDraw();
	b1.showBotton(msg,"¿ªÊ¼ÓÎÏ·");
	EndBatchDraw();
	
}

