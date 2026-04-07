#include "login_page.h"

int emailbarL = 41;
string domain = "@example.ecu";
int edomain = (centerN(emailbarL) + (emailbarL - domain.length()));
string loginSTR = "Welcome back!";
string loginSTR2 = "Please use your employee Email";
string loginSTR3 = "to securely access your payroll dashboard";


void loginpage() {
	string emailinput;
	
	move(2, centerN(40));
	blink;
	draw_logo();
	reset;
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	move(10, centerS(loginSTR));
	fcolor(main_font_color);
	cout << loginSTR;
	move(11, centerS(loginSTR2));
	cout << loginSTR2;
	move(12, centerS(loginSTR3));
	cout << loginSTR3;
	move(15, centerN(emailbarL));
	bcolor(main_boxback_color);
	Sframe(1, emailbarL);
	move(16, edomain);
	fcolor("80;80;80");
	cout << domain;
	string help = "For help contact HR";
	bcolor(main_back_color);
	move(19, centerS(help));
	cout << help;
	bcolor(main_boxback_color);
	fcolor(write_font_color);
	move(21,centerN(13));
	bcolor(botton_color);
	fcolor(botton_border_color);
	Sframe(1, 13);
	fcolor(botton_font_color);
	move(22, centerN(4));
	cout << "Login";
	
	do {
		showC;
		move(16, centerN(emailbarL) + 1);
		emailinput = write_frame(emailbarL - domain.length() - 2, normal);

		if (emailinput == "esc") { break; }
		else if (emailinput == "down") {
			move(21, centerN(13));
			bcolor(hoverd_botton_color);
			fcolor(hoverd_border_color);
			Sframe(1, 13);
			fcolor(hoverd_font_color);
			move(22, centerN(4));
			cout << "Login";
		}

	} while (true);
	hideC;
}