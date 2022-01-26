#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<string>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define COUNT 148
using namespace std;
int main(void)
{
	char FileName[128];
	IMAGE image[COUNT];
	cout << "Ô¤ÏÈ¼ÓÔØÖÐ¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·¡·" << endl;
	for (int i = 1; i <= COUNT; i++) {
		sprintf_s(FileName, "E:\\images\\_%04d_Í¼²ã-%d.jpg", COUNT - i, i);
		loadimage(&image[i-1], FileName);
	}
	
	mciSendString("play ¼«ÀÖ¾»ÍÁ.mp3 repeat", 0, 0, 0);
	initgraph(800, 450);
	while (1) {
		for (int i = 0; i < COUNT; i++) {
			putimage(0, 0, &image[i]);
			//loadimage(0, "E:\\images\\%04d_Í¼²ã%d.jpg",COUNT-i,i);
			//sprintf_s(FileName, "E:\\images\\_%04d_Í¼²ã-%d.jpg", COUNT - i, i);
			//loadimage(0, image[]);
			Sleep(75);
		}
	}
	
	
	closegraph();
	system("pause");
	return 0;
}
