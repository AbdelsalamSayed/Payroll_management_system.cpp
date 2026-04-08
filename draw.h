#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

constexpr int Width = 45;
constexpr int Hhight = 1;
constexpr int Bhight = 30;
inline string main_back_color = "10;25;41";
inline string main_boxback_color = "20;35;60";
inline string main_bordr_color = "70;85;105";
inline string main_font_color = "200;200;200";
inline string write_font_color = "255;255;255";
inline string botton_color = "30;41;59";
inline string botton_border_color = "51;65;85";
inline string botton_font_color = "148;163;184";
inline string hoverd_botton_color = "10;110;255";
inline string hoverd_border_color = "125;211;252";
inline string hoverd_font_color = "255;255;255";

inline string normal = "normal";
inline string wrap = "wrap";
inline string email = "email";
inline string pass = "pass";
//====================COLORS====================

constexpr int back = 4;
constexpr int Bback = 10;
constexpr int font = 3;
constexpr int Bfont = 9;
#define reset cout<<"\033[0m"
#define black(x) cout<<"\033["<<"0m"
#define red(x) cout<<"\033["<<x<<"1m"
#define green(x) cout<<"\033["<<x<<"2m"
#define yellow(x) cout<<"\033["<<x<<"3m"
#define blue(x) cout<<"\033[<<"x<<"4m"
#define purple(x) cout<<"\033["<<x<<"5m"
#define wblue(x) cout<<"\033["<<x<<"6m"
#define white(x) cout<<"\033["<<x<<"7m"
#define fcolor(x) cout<<"\033[38;2;"<<x<<"m"
#define bcolor(x) cout<<"\033[48;2;"<<x<<"m"
#define invert cout<<"\033[7m"


//====================CURSOR====================
#define move(x,y) cout<<"\033["<<x+2<<";"<<y+1<<"H"
#define moveU(x) cout<<"\033["<<x<<"A"
#define moveD(x) cout<<"\033["<<x<<"B"
#define moveR(x) cout<<"\033["<<x<<"C"
#define moveL(x) cout<<"\033["<<x<<"D"
#define cls cout<<"\033[2J\033[H"
#define clsL cout<<"\033[2K"
#define saveL cout<<"\033[s"
#define gotoL cout<<"\033[u"
#define Nline(x) cout<<"\033["<<x<<"E"
#define Lline(x) cout<<"\033["<<x<<"F"
#define scrolloff cout<<"\033[?1049h"
#define scrollon cout<<"\033[?1049l"
#define scroll(x,y) cout<<"\033["<<x<<";"<<y<<"r"
#define hideC cout<<"\033[?25l"
#define showC cout<<"\033[?25h"
#define centerN(x) (((Width - x)+1) / 2)
#define centerS(x) (((int)Width - (int)x.length()) / 2) + 1

//====================FONTS====================
#define bold cout<<"\033[1m"
#define italic cout<<"\033[3m"
#define blink cout<<"\033[6m"


//====================FRAME====================

inline void frame(int h, int w) {

	char x = (char)218;
	char y = (char)196;
	char z = (char)191;
	char j = (char)179;
	char t = (char)192;
	char m = (char)217;

	std::string W(w, y);

	cout<<x<<W<<z;
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(1);
		cout<<j;
	}
	moveD(1);
	moveL(w + 2);
	cout<<t<<W<<m;
	moveL(w + 2);
	for (int i = 0;i < h;i++) {
		moveU(1);
		cout<<j;
		moveL(1);
	}


}

inline void Sframe(int h, int w) {

	char x = (char)218;
	char y = (char)196;
	char z = (char)191;
	char j = (char)179;
	char t = (char)192;
	char m = (char)217;
	
	std::string W(w, y);
	std::string s(w, ' ');

	cout<<x<<W<<z;
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(w+2);
		cout<<j<<s<<j;
	}
	moveD(1);
	moveL(w + 2);
	cout<<t<<W<<m;
	


}

inline void clearL(int x) {
	string spaces = string(x, ' ');
	cout << spaces;
	moveL(x);
}


inline void draw_logo() {
	string a,b,c,d,e;
	a = "    _____________________________    ____";
	b = "   /   ________/   _________/   /   /   /";
	c = "  /   _____/  /   /        /   /   /   / ";
	d = " /   /_______/   /________/   /___/   /  ";
	e = "/___________/\\___________/\\__________/   ";

	cout << a;
	moveD(1);
	moveL(a.length());
	cout << b;
	moveD(1);
	moveL(b.length());
	cout << c;
	moveD(1);
	moveL(c.length());
	cout << d;
	moveD(1);
	moveL(d.length());
	cout << e;
}