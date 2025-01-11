#include"main.h"
botton::botton(int x, int y, int w, int h) {
	this->x = x; this->y = y;
	this->w = w; this->h = h;
}
void botton::showBotton(ExMessage& msg,const char* text) {
	if (isArea(msg)) {
		setfillcolor(RGB(0, 174, 236));
	}
	else {
		setfillcolor(RGB(97, 102, 109));
	}
	fillroundrect(this->x, this->y, this->x + this->w, this->y + this->h, 5, 5);
	int hspace = (this->w - textwidth(text)) / 2;
	int vspace = (this->h - textheight(text)) / 2;
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(x + hspace, y + vspace, text);

}
bool botton::isArea(ExMessage& msg) {
	if (msg.x > this->x && msg.x<this->x + this->w && msg.y>this->y && msg.y < this->y + this->h) {
		return true;
	}
	return false;

}
bool botton::isBTCLK(ExMessage& msg) {
	if (msg.message == WM_LBUTTONDOWN && isArea(msg)) {
		msg.message = 0;
		return true;
	}
		msg.message = 0;
	return false;
}