#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "windows.h"
#include <conio.h>
 
int depth=2000;
 
void main(int argc, char* argv[])
{
    float cr, ci, zr, zi, tmp;
    HWND wnd=GetConsoleWindow();
    HDC dc=GetDC(wnd);
    int k;
 
    for(int n=1; n<10000; n+=100)
    {
        for(int i=-320;i<321;i++)
        {
            ci=((float)i)/320.0;
            for(int j=-380;j<161;j++)
            {
                cr=((float)j)/240.0;
                zi=zr=0.0;
                for(k=0;k<depth;k++)    
                {
                    tmp=zr*zr-zi*zi;
                    zi=2*zr*zi+ci;
                    zr=tmp+cr;
                    if (zr*zr+zi*zi>1.0E16) break;
                }
                if (k<depth)
                    SetPixel(dc, j+380, i+320, k*3*n);
                else SetPixel(dc, j+380, i+320, 0);
            }
        }
        if(_kbhit()) break;
    }
 
    while(!_kbhit()) ;
}
