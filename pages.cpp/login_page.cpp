#include "../pages.H/login_page.h"

void loginpage_ui() {
	loginSTR = "Welcome back!";
	loginSTR2 = "Please use your employee Email";
	loginSTR3 = "to securely access your payroll dashboard";
	domain = "username@example.ecu";
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	body();
	draw_logo(2);
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
	fcolor(main_boxborder_color);
	Dframe(1, emailbarL);
	domain = "username@example.ecu";
	move(16, edomain);
	fcolor("80;80;80");
	cout << domain;

	bcolor(main_back_color);
	move(20, centerS(help));
	cout << help;
	bcolor(main_boxback_color);
	fcolor(write_font_color);
	move(21, centerN(13));
	bcolor(button_color);
	fcolor(button_border_color);
	Dframe(1, 13);
	fcolor(button_font_color);
	move(22, centerN(4));
	cout << "Login";
}

void loginpage() {
	loginpage_ui();
	string email;
	
	string functions = "start";
	do {
		
		
		int index;
		
		if (functions == "start") {
			position = 1;
			email = "";
			saveL;
			bcolor(main_boxback_color);
			fcolor(write_font_color);
			move(21, centerN(13));
			bcolor(button_color);
			fcolor(button_border_color);
			Dframe(1, 13);
			fcolor(button_font_color);
			move(22, centerN(4));
			cout << "Login";
			gotoL;
			bcolor(main_boxback_color);
			move(16, edomain);
			clearL(emailbarL - 1);
			fcolor("80;80;80");
			cout << domain;
			moveL(domain.length());
			fcolor(main_font_color);
			move(16, centerN(emailbarL) + 2);
		}

		write_frame(emailbarL - 2, _email, email, functions);


		if ((functions == "down" || functions == "tab") && position == 1) {
			hideC;
			saveL;
			move(21, centerN(13));
			bcolor(hoverd_button_color);
			fcolor(hoverd_border_color);
			Dframe(1, 13);
			fcolor(hoverd_font_color);
			move(22, centerN(4));
			cout << "Login";
			position = 2;
			buttons(functions="login");

		}
		if ((functions == "up" || functions == "tab" )&& position == 2) {

			bcolor(main_boxback_color);
			fcolor(write_font_color);
			move(21, centerN(13));
			bcolor(button_color);
			fcolor(button_border_color);
			Dframe(1, 13);
			fcolor(button_font_color);
			move(22, centerN(4));
			cout << "Login";
			position = 1;
			gotoL;
		}
		if (functions == "enter"&&!email.empty()) {
			functions = "start";
			index = sys.current_user_id(email);
			if (index == -1) {
				string error0 = "Email not registered in the system.\a";
				string error1 = "Please contact HR";
				bcolor(main_back_color);
				move(18, 1);
				clearL(Width - 2);
				move(19, 1);
				clearL(Width - 2);
				red(font);
				move(18, centerS(error0));
				cout << error0;
				move(19, centerS(error1));
				cout << error1;
				fcolor(main_font_color);

			}
			else {
				employee& current_user = sys.get_employee_by_email(email);
				if (current_user.get_locked() == true) {
					string error0 = "Email not registered in the system.\a";
					string error1 = "Please contact HR";
					bcolor(main_back_color);
					move(18, 1);
					clearL(Width - 2);
					move(19, 1);
					clearL(Width - 2);
					red(font);
					move(18, centerS(error0));
					cout << error0;
					move(19, centerS(error1));
					cout << error1;
					fcolor(main_font_color);
				}
				else {
					break;
				}
			}
		}
	
	} while (true);

		
		pass_page(email);

}