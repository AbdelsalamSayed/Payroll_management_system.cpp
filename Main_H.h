#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <fstream>
using namespace std;


inline char double1 = (char)201; // ╔
inline char double2 = (char)205; // ═
inline char double3 = (char)187; // ╗

inline char double4 = (char)186; // ║

inline char double5 = (char)200; // ╚
inline char double6 = (char)188; // ╝
inline char double7 = (char)202; // ╩ 
inline char double8 = (char)203; // ╦

inline char double9 = (char)204; // ╠

inline char double10 = (char)185;// ╣

inline char double11 = (char)206;// ╬
//===============================================
inline char single1 = (char)218; // ┌
inline char single2 = (char)196; // ─
inline char single3 = (char)191; // ┐

inline char single4 = (char)179; // │ 

inline char single5 = (char)192; // └ 
inline char single6 = (char)217; // ┘ 



inline const int try_num = 10;
inline int try_count = try_num;
inline const string roles[4] = {"system_admin","comp_admin","staff"};

constexpr int Width = 45;
constexpr int Hhight = 1;
constexpr int Bhight = 30;
inline string main_boxborder_color = "129;129;129";
inline string main_back_color = "10;25;41";
inline string main_boxback_color = "20;35;60";
inline string main_bordr_color = "70;85;105";
inline string main_font_color = "200;200;200";
inline string write_font_color = "255;255;255";
inline string button_color = "30;41;59";
inline string button_border_color = "51;65;85";
inline string button_font_color = "148;163;184";
inline string hoverd_button_color = "10;110;255";
inline string hoverd_border_color = "125;211;252";
inline string hoverd_font_color = "255;255;255";


inline string normal = "normal";
inline string wrap = "wrap";
inline string _email = "email";
inline string pass = "pass";
inline string _pass = "_pass";
inline string Cid = "id";
inline string notinput = "notinput";
//====================COLORS====================

constexpr int back = 4;
constexpr int Bback = 10;
constexpr int font = 3;
constexpr int Bfont = 9;
#define reset cout<<"\033[0m"
#define black(x) cout<<"\033["<<x<<"0m"
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
#define hoverd_button fcolor(hoverd_border_color);bcolor(hoverd_button_color)
#define non_hoverd_button fcolor(button_border_color);bcolor(button_color)
#define main_colors bcolor(main_back_color);fcolor(main_font_color);


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
#define centerLN(x,y,z) (((y-(x+(int)z.length()))/2)+x)
#define centerS(x) (((int)Width - (int)x.length()) / 2) + 1

//====================FONTS====================
#define bold cout<<"\033[1m"
#define italic cout<<"\033[3m"
#define blink cout<<"\033[6m"
#define nonblink cout<<"\033[25m"


//====================FRAME====================

inline void frame(int h, int w) {


	std::string W(w, single2);
	std::string s(w, ' ');

	cout << single1 << W << single3;
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(w + 2);
		cout << single4 << s << single4;
	}
	moveD(1);
	moveL(w + 2);
	cout << single5 << W << single6;


}

inline void f3frame(int h, int w1, int w2, int w3,int w4, int num) {
	std::string W1(w1, double2);
	std::string W2(w2, double2);
	std::string W3(w3, double2);
	std::string W4(w4, double2);


	std::string s1(w1, ' ');
	std::string s2(w2, ' ');
	std::string s3(w3, ' ');
	std::string s4(w4, ' ');

	if (num == 1) {

		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double9 << W1 << double8;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W2 << double8<< W2 << double8 << W4 << double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + +w4 + 5);
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4 << s1 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
			cout << s2 << double4 << s3 << double4<< s4 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + +w4 + 5);
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double5 << W1 << double7;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W2 << double7 << W3 << double7<< W4 << double6;


	}
	else if (num == 2) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double8 << W2 << double8;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W3 << double8 <<W4<< double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + +w4 + 5);
			cout << double4 << s1;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4 << s2 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
			cout << s3 << double4<< s4 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + +w4 + 5);
		cout << double5 << W1;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double7 << W2 << double7;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W3 << double7 << W4 << double6;
	}
	else if (num == 3) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1<<double8 << W2 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double8<< W3 << double8;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W4 << double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + +w4 + 5);
			cout << double4 << s1 << double4 << s2 ;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);


			cout << double4<< s3 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
			cout << s4 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + +w4 + 5);
		cout << double5 << W1<< double7 << W2 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double7<< W3 << double6;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W4 << double6;

	}
	else if (num == 4) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1<<double8 << W2 << double8<< W3 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double8 << W4 << double10;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + +w4 + 5);
			cout << double4 << s1 << double4 << s2 << double4<< s3 ;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4 << s4 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
		}
		moveD(1);
		moveL(w1 + w2 + w3 + +w4 + 5);
		cout << double5 << W1<< double7 << W2 << double7<< W3 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double7 << W4 << double6;
		bcolor(main_back_color);
		fcolor(main_bordr_color);

	}
}
inline void f3frame(int h, int w1, int w2, int w3, int num) {
	std::string W1(w1, double2);
	std::string W2(w2, double2);
	std::string W3(w3, double2);
	

	std::string s1(w1, ' ');
	std::string s2(w2, ' ');
	std::string s3(w3, ' ');
	
	if (num == 0) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1 << double8;
		cout << W2 << double8<< W3 << double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + 5);
			cout << double4 << s1 << double4;
			cout << s2 << double4 << s3 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + 5);
		cout << double5 << W1 << double7;
		cout << W2 << double7 << W3 <<  double6;


	}
	else if (num == 1) {

		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double9 << W1 << double8;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W2 << double8<< W3 << double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + 5);
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4 << s1 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
			cout << s2 << double4 << s3 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + 5);
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double5 << W1 << double7;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W2 << double7 << W3 <<  double6;


	}
	else if (num == 2) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double8 << W2 << double8;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W3 << double10;
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + 5);
			cout << double4 << s1;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4 << s2 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
			cout << s3 << double4;
		}
		moveD(1);
		moveL(w1 + w2 + w3 + 5);
		cout << double5 << W1;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double7 << W2 << double7;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << W3 << double6;
	}
	else if (num == 3) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1<<double8 << W2 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double8<< W3 << double10;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + 5);
			cout << double4 << s1 << double4 << s2 ;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4<< s3 << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
		}
		moveD(1);
		moveL(w1 + w2 + w3 + 5);
		cout << double5 << W1<< double7 << W2 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double7<< W3 << double6;
		bcolor(main_back_color);
		fcolor(main_bordr_color);

	}
	else if (num == 4) {

		bcolor(main_back_color);
		fcolor(main_bordr_color);
		cout << double9 << W1<<double8 << W2 << double8<< W3 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double10;
		bcolor(main_back_color);
		fcolor(main_bordr_color);
		for (int i = 0;i < h;i++) {
			moveD(1);
			moveL(w1 + w2 + w3 + 5);
			cout << double4 << s1 << double4 << s2 << double4<< s3 ;
			fcolor(hoverd_border_color);
			bcolor(hoverd_button_color);
			cout << double4;
			bcolor(main_back_color);
			fcolor(main_bordr_color);
		}
		moveD(1);
		moveL(w1 + w2 + w3 + 5);
		cout << double5 << W1<< double7 << W2 << double7<< W3 ;
		fcolor(hoverd_border_color);
		bcolor(hoverd_button_color);
		cout << double6;
		bcolor(main_back_color);
		fcolor(main_bordr_color);

	}
}

inline void f2frame(int h, int w1, int w2) {


	std::string W1(w1, double2);
	std::string W2(w2, double2);
	

	std::string s1(w1, ' ');
	std::string s2(w2, ' ');
	

	cout << double9 << W1 << double8 << W2 << double10;
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(w1 + w2 + 3);
		cout << double4 << s1 << double4 << s2 << double4;
	}
	moveD(1);
	moveL(w1 + w2 + 3);
	cout << double5 << W1 << double7 << W2 << double6;


}

inline void Dframe(int h, int w) {
	
	std::string W(w, double2);
	std::string s(w, ' ');

	cout << double1 << W << double3;
	for (int i = 0;i < h;i++) {
		moveD(1);
		moveL(w + 2);
		cout << double4 << s << double4;
	}
	moveD(1);
	moveL(w + 2);
	cout << double5 << W << double6;


}

inline void clearL(int x) {
	string spaces = string(x, ' ');
	cout << spaces;
	moveL(x);
}


inline void draw_logo(int x) {
	string a,b,c,d,e,f;
	a = "     ____________ ____________ ____    ____";
	b = "    /   ________//   ________//   /   /   /";
	f = "   /   /____    /   /        /   /   /   / ";
	c = "  /   _____/   /   /        /   /   /   /  ";
	d = " /   /_______ /   /_______ /   /___/   /   ";
	e = "/___________/ \\__________/ \\__________/   ";
	blink;
	fcolor("100;210;255");
	move(x, centerN(42));
	cout << a;
	moveD(1);
	moveL(a.length());
	cout << b;
	moveD(1);
	moveL(b.length());
	cout << f;
	moveD(1);
	moveL(f.length());
	cout << c;
	moveD(1);
	moveL(c.length());
	cout << d;
	moveD(1);
	moveL(d.length());
	cout << e;
	reset;
}



