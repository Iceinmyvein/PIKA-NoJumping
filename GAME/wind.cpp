#include <stdio.h>
#include <string>
#include "SDL.h"
#undef main
using namespace std;
static const int    wind_widt = 1024;               //窗口宽度
static const int    wind_high = 768;                //窗口高度
static const char*  wind_title="测试工程";           //窗口标题
static SDL_Window*  wind_main=nullptr;              //中心窗口
static SDL_Surface* wind_scrn=nullptr;
static SDL_Surface* wind_test=nullptr;
static SDL_Renderer*wind_rend=nullptr;
int main_init()
{
     /*------------------------------创建窗口------------------------------*/
    if(SDL_Init(SDL_INIT_VIDEO)<0) return false;    //创建失败
    wind_main=SDL_CreateWindow(wind_title,          //窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//垂直位置
                            SDL_WINDOWPOS_UNDEFINED,//水平位置
                            wind_widt,              //窗口宽度
                            wind_high,              //窗口高度
                            SDL_WINDOW_SHOWN      );//显示窗口
    if(wind_main==nullptr)          return false;   //创建失败
    wind_scrn=SDL_GetWindowSurface(wind_main);      //获取界面
                                    return true;
}

void main_exit()
{
    /*------------------------------退出程序------------------------------*/
    SDL_FreeSurface(wind_test);                     //释放空间
    SDL_DestroyWindow(wind_main);                   //销毁窗口
    SDL_Quit();                                     //退出SDL
    wind_main = nullptr;
    wind_test = nullptr;
    wind_scrn = nullptr;
}

int main_test()
{
                                                    //获取窗口
    wind_scrn=SDL_GetWindowSurface(wind_main);      //加载图片
   wind_test = SDL_LoadBMP("../ASSE/test.bmp");     //加载图片
    if( wind_test == nullptr ) return false;        //无法打开

    //下面函数的参数分别为
    //SDL_Surface* src
    //const SDL_Rect* srcrect
    //SDL_Surface* dst
    //SDL_Rect* dstrect
SDL_BlitSurface(wind_test,nullptr,wind_scrn,nullptr);//界面复制
    SDL_UpdateWindowSurface(wind_main);              //更新显示
    SDL_Delay(2000);                                 //延时关闭
    return true;
}

int main_rend()
{
    SDL_Init(SDL_INIT_VIDEO);
    wind_rend = SDL_CreateRenderer(wind_main, -1, 0);
    SDL_SetRenderDrawColor(wind_rend, 0, 255, 0, 255);
    SDL_RenderClear(wind_rend);
    SDL_RenderPresent(wind_rend);
    SDL_Delay(3000);
    if (wind_rend) {SDL_DestroyRenderer(wind_rend);}
    return true;
}
