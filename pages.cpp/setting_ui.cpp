#include "../pages.H/system_admin.h"

void super_setting_ui(employee& current_user) {
	main_ui("Setting", 4);
	string functions;
	int position = 0;
	hoverd_button;
	move(5, 7);
	Dframe(1, 31);
	move(6, centerLN(9, 38, ((string)"Change  system status")));
	fcolor(hoverd_font_color);
	cout << "Change  system status";
	move(9, 7);
	non_hoverd_button;
	Dframe(1, 31);
	move(13, 7);
	Dframe(1, 31);
	move(10, centerLN(8, 39, ((string)"Change password")));
	fcolor(main_font_color);
	cout << "Change password";
	move(14, centerLN(8, 39, ((string)"Log out")));
	cout << "Log out";
	position = 1;
	functions = "";
	do {
		buttons(functions = "super_admin");
		if (functions == "esc") { system_admin_pages(current_user); }
		if (((functions == "tab" || functions == "up") && position == 4)) {
			hoverd_button;
			move(5, 7);
			Dframe(1, 31);
			move(6, centerLN(9, 38, ((string)"Change  system status")));
			fcolor(hoverd_font_color);
			cout << "Change  system status";
			move(9, 7);
			non_hoverd_button;
			Dframe(1, 31);
			move(13, 7);
			Dframe(1, 31);
			move(10, centerLN(8, 39, ((string)"Change password")));
			fcolor(main_font_color);
			cout << "Change password";
			move(14, centerLN(8, 39, ((string)"Log out")));
			cout << "Log out";
			position = 1;
			functions = "";
		}
		else if ((functions == "tab" || functions == "down") && position == 2 || ((functions == "tab" || functions == "down") && position == 4)) {
			non_hoverd_button;
			move(5, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(6, centerLN(9, 38, ((string)"Change  system status")));
			cout << "Change  system status";
			non_hoverd_button;
			move(9, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(10, centerLN(8, 39, ((string)"Change password")));
			cout << "Change password";
			hoverd_button;
			move(13, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(14, centerLN(8, 39, ((string)"Log out")));
			cout << "Log out";
			position = 3;
			functions = "";

		}
		else if (((functions == "tab" || functions == "up") && position == 2)) {
			hoverd_button;
			move(5, 7);
			Dframe(1, 31);
			move(6, centerLN(9, 38, ((string)"Change  system status")));
			fcolor(hoverd_font_color);
			cout << "Change  system status";
			move(9, 7);
			non_hoverd_button;
			Dframe(1, 31);
			move(13, 7);
			Dframe(1, 31);
			move(10, centerLN(8, 39, ((string)"Change password")));
			fcolor(main_font_color);
			cout << "Change password";
			move(14, centerLN(8, 39, ((string)"Log out")));
			cout << "Log out";
			position = 1;
			functions = "";
		}
		else if (((functions == "tab" || functions == "down") && position == 1) || ((functions == "tab" || functions == "up") && position == 3)) {
			non_hoverd_button;
			move(5, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(6, centerLN(9, 38, ((string)"Change  system status")));
			cout << "Change  system status";
			hoverd_button;
			move(9, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(10, centerLN(8, 39, ((string)"Change password")));
			cout << "Change password";
			non_hoverd_button;
			move(13, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(14, centerLN(8, 39, ((string)"Log out")));
			cout << "Log out";
			if (position == 1) {
				position = 2;
			}
			else {
				position = 4;
			}
			functions = "";
		}
		else if (functions == "enter" && position == 1) {
			change_sys_status(current_user);
			functions = "";
		}
		else if (functions == "enter" && position == 2) {
			change_pass_page(current_user);
			functions = "";
		}
		else if (functions == "enter" && position == 3) {
			position = 1;
			move(11, centerN(21));
			white(back);
			red(font);
			Dframe(8, 21);
			string error = "Do you want to Logout";
			move(13, centerLN(13, 33, error));
			fcolor("0;0;0");
			cout << "\a" << error;
			move(16, centerN(5));
			moveR(6);
			Dframe(1, 5);
			move(17, centerN(5));
			moveR(8);
			cout << "No";
			move(16, centerN(5));
			moveL(6);
			red(back);
			Dframe(1, 5);
			move(17, centerN(5));
			moveL(4);
			cout << "Yes";
			white(back);
			do {
				buttons(functions = "super_admin");
				if ((functions == "right" || functions == "tab") && position == 1) {
					white(back);
					move(16, centerN(5));
					moveL(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					red(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					position = 2;
					white(back);
				}
				if ((functions == "left" || functions == "tab") && position == 2) {
					white(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					move(16, centerN(5));
					moveL(6);
					red(back);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					position = 1;
					white(back);
				}
				if (functions == "enter" && position == 1) {
					loginpage_ui();
					loginpage();
				}
				if (functions == "enter" && position == 2) {
					position = 1;
					system_admin_pages(current_user);
				}
			} while (true);



		}
	} while (true);
}


void change_sys_status(employee& current_user) {
	main_ui("Setting", 4);
	string functions;
	int position = 0;
	
	move(9, 7);
	hoverd_button;
	Dframe(1, 31);
	move(10, centerLN(8, 39, ((string)"Active")));
	fcolor(hoverd_font_color);
	cout << "Active";
	move(13, 7);
	non_hoverd_button;
	Dframe(1, 31);
	move(14, centerLN(8, 39, ((string)"Inactive")));
	fcolor(main_font_color);
	cout << "Inactive";
	position = 1;
	functions = "";
	do {
		buttons(functions = "super_admin");
		if (functions == "esc") { super_setting_ui(current_user); }
		if (((functions == "tab" || functions == "down") && position == 1)) {
			non_hoverd_button;
			move(9, 7);
			Dframe(1, 31);
			move(10, centerLN(8, 39, ((string)"Active")));
			fcolor(main_font_color);
			cout << "Active";
			move(13, 7);
			hoverd_button;
			Dframe(1, 31);
			move(14, centerLN(8, 39, ((string)"Inactive")));
			fcolor(hoverd_font_color);
			cout << "Inactive";
			position = 2;
			functions = "";
		}
		else if ((functions == "tab" || functions == "up") && position == 2) {
			hoverd_button;
			move(9, 7);
			Dframe(1, 31);
			move(10, centerLN(8, 39, ((string)"Active")));
			fcolor(hoverd_font_color);
			cout << "Active";
			move(13, 7);
			non_hoverd_button;
			Dframe(1, 31);
			move(14, centerLN(8, 39, ((string)"Inactive")));
			fcolor(main_font_color);
			cout << "Inactive";
			position = 1;
			functions = "";
		}
		else if (functions == "enter" && position == 1) {
			sys.set_system_online(true);
			string error = "System is now active";
			move(19, 2);
			bcolor(main_back_color);
			string s = string(43, ' ');
			cout << s;
			move(19, centerS(error));
			green(font);
			cout << error;
			Sleep(2000);
			loginpage();


		}
		else if (functions == "enter" && position == 2) {
			sys.set_system_online(false);
			string error = "System is now inactive";
			move(19, 2);
			bcolor(main_back_color);
			string s = string(43, ' ');
			cout << s;
			move(19, centerS(error));
			green(font);
			cout << error;
			Sleep(2000);
			loginpage();
		}
	} while (true);
}


void change_pass_page(employee& current_user) {
	main_ui("Setting", 4);
	string functions, _pass,new_pass;
	move(10, 7);
	fcolor(main_boxborder_color);
	bcolor(main_boxback_color);
	Dframe(1, 31);
	move(15, 7);
	Dframe(1, 31);
	bcolor(main_back_color);
	fcolor(main_font_color);
	move(9, centerLN(8, 39, ((string)"Enter new password")));
	fcolor(main_font_color);
	cout << "Enter new password";
	move(14, centerLN(8, 39, ((string)"Confirm new password")));
	cout << "Confirm new password";
	move(11, 9);
	bcolor(main_boxback_color);
	write_frame(28, pass, _pass, functions);
	move(16, 9);
	write_frame(28, pass, new_pass, functions);
	if (functions == "esc") { super_setting_ui(current_user); }
	if (functions == "enter") {
		if ((_pass.length() >= 8 && any_of(_pass.begin(), _pass.end(), ::isupper) && any_of(_pass.begin(), _pass.end(), ::islower) && any_of(_pass.begin(), _pass.end(), ::isdigit) && any_of(_pass.begin(), _pass.end(), [](char c) { return ispunct(c); })) ) {
			if (_pass == new_pass) {
				pass = _pass;
				string error = "Password changed successfully";
				move(19, 2);
				bcolor(main_back_color);
				string s = string(43, ' ');
				cout << s;
				move(19, centerS(error));
				green(font);
				cout << error;
				Sleep(2000);
				current_user.set_pass(_pass);
				super_setting_ui(current_user);
			}else {
				string error = "Passwords do not match";
				move(19, 2);
				bcolor(main_back_color);
				string s = string(43, ' ');
				cout << s;
				move(19, centerS(error));
				red(font);
				cout << error;
				Sleep(2000);
				change_pass_page(current_user);
			}
		}
		else {
			string error = "Passwords not valid";
			move(19, 2);
			bcolor(main_back_color);
			string s = string(43, ' ');
			cout << s;
			move(19, centerS(error));
			red(font);
			cout << error;
			Sleep(2000);
			change_pass_page(current_user);
		}
	}
	
	
}