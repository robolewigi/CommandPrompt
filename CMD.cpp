//square character = 219
//yellow text = SetConsoleTextAttribute(handle,14);

#include "CMD.h"
#include <windows.h>
     
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

game game1;
entity entity1;

<details>
   COORD GetConsoleWindowSize() {
                  CONSOLE_SCREEN_BUFFER_INFO csbi;
                  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                  return csbi.dwSize;
              }
     
   
        void game::ShowConsoleCursor(bool showFlag)
        {
	 CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(handle, &cursorInfo);
}

    void game::begin(){   system("COLOR 17");
     COORD initialSize = GetConsoleWindowSize();
        system("MODE 111,111");

               ShowConsoleCursor(false);

        }
 

    void game::update(int x)    {
        switch(x){    case 0:  
        keyInput();
        entity1.update();
           SetConsoleCursorPosition(handle, {0,1});
    std::cout <<frames; 
    //        SetConsoleCursorPosition(handle, {0,0});
    //std::cout <<currentSize.X<<"/"<<currentSize.Y; 


   SetConsoleCursorPosition(handle, {0,0});
      GetDesktopResolution(horizontal, vertical);
   std::cout << horizontal << '/' << vertical;
    SetConsoleTextAttribute(handle,BACKGROUND_BLUE);
       break;   case 1:
      currentSize = GetConsoleWindowSize();
       if (currentSize.X != initialSize.X || currentSize.Y != initialSize.Y) {
      // console window has been resized
      
      // update the initial size for the next check
      initialSize = currentSize;
       break;
        }}
}
  
   void entity::update(){
     
     if (nLoc[0]!=loc[0]||nLoc[1]!=loc[1]){
    SetConsoleCursorPosition(handle, { (short)(loc[0]),(short)(loc[1]) });
   std::cout << " ";
   loc[0]=max(min(nLoc[0],resolution[0]-1),1);
    loc[1]=max(min(nLoc[1],resolution[1]-1),1);
   nLoc[0]=loc[0];   nLoc[1]=loc[1];
          SetConsoleCursorPosition(handle, { (short)(loc[0]),(short)(loc[1]) });
   SetConsoleTextAttribute(handle,4);
       std::cout << (unsigned char)219; 
     }
}
   
              void keyInput(){
       if(GetKeyState('W') & 0x8000){   
   entity1.nLoc[1]-=1;
       }  
       if(GetKeyState('S') & 0x8000){   
     entity1.nLoc[1]+=1;
    }
          if(GetKeyState('D') & 0x8000){   
     entity1.nLoc[0]+=1;
      }  
       if(GetKeyState('A') & 0x8000){   
   entity1.nLoc[0]-=1;
    } 
             }
           
void fpsTick(int x){
    switch (x){// your main loop. could also be the idle() function in glut or whatever
    case 0://start of update
    current_ticks = clock();
    break;
    case 1://end of update

    delta = clock() - current_ticks; //the time, in ms, that took to render the scene
    if(delta > 0)
        frames = CLOCKS_PER_SEC / delta;
    totalTicks+=delta;
    break;}
}

void delayManager()
{bool hit=false;
if (totalTicks>=delay)
{delay+=10; int horizontal = 0;
   int vertical = 0;
game1.update(0);}
if(totalTicks>=delay1)
{delay1+=1000;  game1.update(1);
}
if(hit){delayManager();}
}

int main(){
        // Set the screen buffer size
    COORD newSize;
    newSize.X = 100;  // Set the width of the buffer
    newSize.Y = 40;   // Set the height of the buffer
    SetConsoleScreenBufferSize(handle, newSize);
       // Set the window size
    SMALL_RECT rect;
    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = 39;  // Set the height of the window (0-based index)
    rect.Right = 99;   // Set the width of the window (0-based index)
    SetConsoleWindowInfo(handle, TRUE, &rect);
  game1.begin();


while(1)
{ 
          
    fpsTick(0);
  delayManager();
   fpsTick(1);
   //SetConsoleCursorPosition(handle, { 0,0 });
   //std::cout << (float)delta;
  
}
    return 0;
}
</details>
