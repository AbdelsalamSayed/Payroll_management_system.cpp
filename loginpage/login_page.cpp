#include "login_page.h"

int emailbarL = 41;
string domain = "@example.ecu";
int edomain = (centerN(emailbarL) + (emailbarL - domain.length()));
string loginSTR = "Welcome to our system pleas login";

void loginpage() {
	string emailinput;
	
	move(13, centerS(loginSTR));
	cout << loginSTR;
	move(15, centerN(emailbarL));
	black(back);
	
	Sframe(1, emailbarL);
	move(16, edomain);
	cout << domain;
	
	do {
		showC;
		move(16, centerN(emailbarL) + 1);
		emailinput = write_frame(emailbarL - domain.length() - 2, normal);

		if (emailinput == "esc") { break; }

	} while (true);
	hideC;
}