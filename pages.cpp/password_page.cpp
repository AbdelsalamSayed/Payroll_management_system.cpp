#include "../pages.H/password_page.h"



void passpage_ui(string email) {
	loginSTR = "Welcome!";
	loginSTR2 = email;
	domain = "Password";
	loginSTR3 = "Enter Your Password ";
	string loginSTR4 = "to securely access your payroll dashboard";
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
	move(13, centerS(loginSTR4));
	cout << loginSTR4;
	move(15, centerN(emailbarL));
	fcolor(main_boxborder_color);
	bcolor(main_boxback_color);
	Dframe(1, emailbarL);
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


void pass_page(string email) {
	passpage_ui(email);
	string input, functions="start";
	
	do {
		position = 1;
		if (functions == "esc") { loginpage(); }
		if (functions == "start") {
			input = "";
			bcolor(main_boxback_color);
			move(16, edomain);
			clearL(emailbarL - 1);
			fcolor("80;80;80");
			cout << domain;
			moveL(domain.length());
			fcolor(main_font_color);
			move(21, centerN(13));
			bcolor(button_color);
			fcolor(button_border_color);
			Dframe(1, 13);
			fcolor(button_font_color);
			move(22, centerN(4));
			cout << "Login";
			move(16, centerN(emailbarL) + 2 + input.length());
			bcolor(main_boxback_color);
			fcolor(write_font_color);
			
		}
		write_frame(emailbarL - 2, pass, input, functions);
		
		if ((functions == "down" || functions == "tab" )&& position == 1) {
			saveL;
			move(21, centerN(13));
			bcolor(hoverd_button_color);
			fcolor(hoverd_border_color);
			Dframe(1, 13);
			fcolor(hoverd_font_color);
			move(22, centerN(4));
			cout << "Login";
			position = 2;
			buttons(functions="pass");
		}
		if ((functions == "up" || functions == "tab") && position == 2) {
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
		if (functions == "enter") {
			functions = "start";
			employee& current_user = sys.get_employee_by_email(email);
			if (current_user.get_pass() != input && try_num > 0 && try_count > 0 && !input.empty()) {
				try_count--;
				bcolor(main_back_color);
				move(18, 1);
				clearL(Width - 2);
				string error = "Incorrect password you have " + to_string(try_count) + " more try";
				red(font);
				move(18, centerS(error));
				cout << error;
				fcolor(main_font_color);
			}
			else if (current_user.get_pass() != input && try_count == 0) {
				
				try_count = try_num;
				if (current_user.get_role() != roles[0]) {
					current_user.set_locked(true);
				}
				loginpage_ui();
				string error0 = "Your account has been locked.";
				string error1 = "Please contact HR to unlock it.";
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
				loginpage();
			}
			else if (current_user.get_pass() == input && current_user.get_email() == email) {
				break;
			}
		}
	} while (true);
	employee& current_user = sys.get_employee_by_email(email);
	if (current_user.get_role() == roles[0]) {
		system_admin_pages(current_user);
	}
	else if (current_user.get_role() == roles[1]) {
		
	}
	else if (current_user.get_role() == roles[2]) {
		
	}
	else if (current_user.get_role() == roles[3]) {

	}
}