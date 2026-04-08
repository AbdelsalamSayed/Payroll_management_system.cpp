#include "login_page.h"
string help = "For help contact HR";
int emailbarL = 41;

int edomain = (centerN(emailbarL) + 2);
string loginSTR = "Welcome back!";
string loginSTR2 = "Please use your employee Email";
string loginSTR3 = "to securely access your payroll dashboard";
void loginpage_ui() {
	move(2, centerN(40));
	blink;
	fcolor("100;210;255");
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

	bcolor(main_back_color);
	move(20, centerS(help));
	cout << help;
	bcolor(main_boxback_color);
	fcolor(write_font_color);
	move(21, centerN(13));
	bcolor(botton_color);
	fcolor(botton_border_color);
	Sframe(1, 13);
	fcolor(botton_font_color);
	move(22, centerN(4));
	cout << "Login";
}

string loginpage() {
	string input,functions;
	
	loginpage_ui();
	move(16, centerN(emailbarL) + 2);
	showC;
	
	
	do {
		bcolor(main_boxback_color);
		fcolor(write_font_color);
		write_frame(emailbarL - 2,email, input, functions);
		

		if (functions == "down" && position == 1) {
			hideC;
			move(21, centerN(13));
			bcolor(hoverd_botton_color);
			fcolor(hoverd_border_color);
			Sframe(1, 13);
			fcolor(hoverd_font_color);
			move(22, centerN(4));
			cout << "Login";
			position = 2;
			bottons(functions);
			
		}
		if (functions == "up" && position == 2){

			showC;
			bcolor(main_boxback_color);
			fcolor(write_font_color);
			move(21, centerN(13));
			bcolor(botton_color);
			fcolor(botton_border_color);
			Sframe(1, 13);
			fcolor(botton_font_color);
			move(22, centerN(4));
			cout << "Login";
			position = 1;
			move(16, centerN(emailbarL) + 2 + input.length());
		}
		

	} while (functions != "enter");
	return input;
	
	hideC;
}