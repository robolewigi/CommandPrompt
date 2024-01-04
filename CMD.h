#pragma once
#include <iostream>
#include <algorithm>
#include <windows.h>

#define forr(x,y) for (int i=x; i<y; i++)

int resolution[2],screen[2];
HWND hwnd;
clock_t current_ticks,delta;
clock_t frames = 1;
 long delay,delay1;
double totalTicks;
void delayManger();
COORD initialSize,currentSize;
void GetDesktopResolution(int& horizontal, int& vertical);       int horizontal = 0;
   int vertical = 0;
CONSOLE_SCREEN_BUFFER_INFO screenBuffer;

struct game{
	void ShowConsoleCursor(bool showFlag);
	void begin();
	 void update(int x);

};
void keyInput();
struct entity{
    int loc[2];
            int nLoc[2]={7,7};
void update(); 
};
 
