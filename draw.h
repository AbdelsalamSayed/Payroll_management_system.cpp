#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdio>
using namespace std;

constexpr int Width = 40;
constexpr int Hhight = 1;
constexpr int Bhight = 30;


inline string arrows = "arrows";
inline string normal = "normal";
inline string wrap = "wrap";
//====================COLORS====================

constexpr int back = 4;
constexpr int Bback = 10;
constexpr int font = 3;
constexpr int Bfont = 9;
#define reset printf("\033[0m")
#define black(x) printf("\033[%d0m",x)
#define red(x) printf("\033[%d1m",x)
#define green(x) printf("\033[%d2m",x)
#define yellow(x) printf("\033[%d33m",x)
#define blue(x) printf("\033[%d4m",x)
#define purple(x) printf("\033[%d5m",x)
#define wblue(x) printf("\033[%d6m",x)
#define white(x) printf("\033[%d7m",x)
#define fcolor(x,y,z) printf("\033[38;2;%d;%d;%dm",x,y,z)
#define bcolor(x,y,z) printf("\033[48;2;%d;%d;%dm",x,y,z)
#define invert printf("\033[7m")


//====================CURSOR====================
#define move(x,y) printf("\033[%d;%dH", x +2, y+1)
#define moveU(x) printf("\033[%dA",x)
#define moveD(x) printf("\033[%dB",x)
#define moveR(x) printf("\033[%dC",x)
#define moveL(x) printf("\033[%dD",x)
#define cls printf("\033[2J\033[H")
#define clsL printf("\033[2K")
#define saveL printf("\033[s")
#define gotoL printf("\033[u")
#define Nline(x) printf("\033[%dE",x)
#define Lline(x) printf("\033[%dF",x)
#define scrolloff printf("\033[?1049h")
#define scrollon printf("\033[?1049l")
#define scroll(x,y) printf("\033[%d;%dr",x,y)
#define hideC printf("\033[?25l")
#define showC printf("\033[?25h")
//#define center(x) ((Width-x.length())/2)+1

#define center(x) (((int)Width - (int)x.length()) / 2) + 1

//====================FONTS====================
#define bold printf("\033[1m")
#define italic printf("\033[3m")
#define blink printf("\033[6m")


//====================FRAME====================

inline void frame(int h, int w) {

	char x = (char)218;
	char y = (char)196;
	char z = (char)191;
	char j = (char)179;
	char t = (char)192;
	char m = (char)217;

	std::string W(w, y);

	printf("%c%s%c", x, W.c_str(), z);
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(1);
		printf("%c", j);
	}
	moveD(1);
	moveL(w + 2);
	printf("%c%s%c", t, W.c_str(), m);
	moveL(w + 2);
	for (int i = 0;i < h;i++) {
		moveU(1);
		printf("%c", j);
		moveL(1);
	}


}

inline void Sframe(int q,int e,int h, int w) {

	char x = (char)218;
	char y = (char)196;
	char z = (char)191;
	char j = (char)179;
	char t = (char)192;
	char m = (char)217;
	move(q - 4, e);
	std::string W(w, y);
	std::string s(w, ' ');

	printf("%c%s%c", x, W.c_str(), z);
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(w+2);
		printf("%c%s%c", j, s.c_str(), j);
	}
	moveD(1);
	moveL(w + 2);
	printf("%c%s%c", t, W.c_str(), m);
	


}
