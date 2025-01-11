#include"main.h"
extern Config config = {};
extern User user = {};
extern ExMessage msg = {};
int main() {
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	config.view = 0;

	while (1) {
		switch (config.view)
		{
		case 0:
			menuView();
		case 1:
			//setGameView();
			break;
		case 2:
			//signInView();
			break;
		case 3:
			//registerView();
			break;
		case 4:			
			//gameChooseView();
			break;
		case 5:
			//gameView();
			break;
		case 6:
			//endView();
			break;
		case 7:
			exit(0);

		default:
			break;
		}
	}
	
	return 0;
}
