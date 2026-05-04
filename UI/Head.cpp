#include "Head.h"


void body() {
	bcolor(main_back_color);
	fcolor(main_bordr_color);
	string STR = "Ecu Payroll Management System.";
	move(-1, 0);
	Dframe(Bhight, Width);
	move(-1, centerS(STR));
	bold;
	fcolor("100;210;255");
	cout<<STR;
	bcolor(main_back_color);
	fcolor(main_bordr_color);

	

}

void footer(string role,int button_num) {
	string home = "Home",add = "Add  Comp", edit = "Edit Comp", setting = "Settings";

	bcolor(main_back_color);
	fcolor(main_bordr_color);
	move(Bhight - 4, 0);
	if (role == roles[0]) {
		if (button_num == 1) {
			f3frame(1, 10, 11, 11, 10, button_num);
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(1, 11, home));
			cout << home;
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(12, 23, add));
			cout << add;
			move(Bhight - 3, centerLN(24, 35, edit));
			cout << edit;
			move(Bhight - 3, centerLN(37, 45, setting));
			cout << setting;
		}
		else if (button_num == 2) {
			f3frame(1, 10, 11, 11, 10, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 11, home));
			cout << home;
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(12, 23, add));
			cout << add;
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(24, 35, edit));
			cout << edit;
			move(Bhight - 3, centerLN(37, 45, setting));
			cout << setting;
		}
		else if (button_num == 3) {
			f3frame(1, 10, 11, 11, 10, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 11, home));
			cout << home;
			move(Bhight - 3, centerLN(12, 23, add));
			cout << add;
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(24, 35, edit));
			cout << edit;
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(37, 45, setting));
			cout << setting;
		}
		else if (button_num == 4) {
			f3frame(1, 10, 11, 11, 10, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 11, home));
			cout << home;
			move(Bhight - 3, centerLN(12, 23, add));
			cout << add;
			move(Bhight - 3, centerLN(24, 35, edit));
			cout << edit;
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(37, 45, setting));
			cout << setting;
			bcolor(main_back_color);
			fcolor(main_font_color);
		}
	}
	else if (role == roles[1]) {
		if (button_num == 0) {
			f3frame(1, 14, 15, 14, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 15, home));
			cout << home;
			move(Bhight - 3, centerLN(18, 29, edit));
			cout << edit;
			move(Bhight - 3, centerLN(33, 45, setting));
			cout << setting;
		}
		if (button_num == 1) {
			f3frame(1, 14, 15, 14, button_num);
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(1, 15, home));
			cout << home;
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(18, 29, edit));
			cout << edit;
			move(Bhight - 3, centerLN(33, 45, setting));
			cout << setting;
		}
		else if (button_num == 2) {
			f3frame(1, 14, 15, 14, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 15, home));
			cout << home;
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(18, 29, edit));
			cout << edit;
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(33, 45, setting));
			cout << setting;
		}
		else if (button_num == 3) {
			f3frame(1, 14, 15, 14, button_num);
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(Bhight - 3, centerLN(1, 15, home));
			cout << home;
			move(Bhight - 3, centerLN(18, 29, edit));
			cout << edit;
			fcolor(hoverd_font_color);
			bcolor(hoverd_button_color);
			move(Bhight - 3, centerLN(33, 45, setting));
			cout << setting;
			bcolor(main_back_color);
			fcolor(main_font_color);
		}
	}

}

void buttons(string& functions) {
	if (functions == "login" || functions == "pass") {
		do
		{

			char input = _getch();
			if (input == 13) { functions = "enter"; position = 1; } //Enter
			else if (input == 27) { functions = "esc"; }
			else if (input == 9) { functions = "tab"; break; }//tap
			else if (input == -32) {
				input = _getch();
				if (input == 72) { functions = "up"; } //Arrow Up
				else if (input == 80) { functions = "down"; } //Arrow Down
				else if (input == 77) { functions = "right"; } //Arrow Right
				else if (input == 75) { functions = "left"; } //Arrow Left
			}

		} while (functions != "enter" && functions != "up");
	}else if (functions == "super_admin") {
		do
		{
			char input = _getch();
			if (input == 13) { functions = "enter";break; } //Enter
			else if (input == 27) { functions = "esc";break; }
			else if (input == 9) { functions = "tab"; break; }//tap
			else if (input == -32) {
				input = _getch();
				if (input == 72) { functions = "up"; break; } //Arrow Up
				else if (input == 80) { functions = "down";break; } //Arrow Down
				else if (input == 77) { functions = "right";break; } //Arrow Right
				else if (input == 75) { functions = "left"; break; } //Arrow Left
			}

		} while (true);
	}
}

void write_frame(int num, string statu, string& lastinput, string& functions) {
	char input;
	
	do {
		if (statu != notinput) {
			showC;
			input = _getch();
			hideC;

			if (input == 13) { functions = "enter"; break; }//Enter
			else if (input == 27) { functions = "esc"; break; }//ESC
			else if (input == 9) { functions = "tab"; break; }//tap
			else if (input == -32) {
				input = _getch();
				if (input == 72) { functions = "up"; break; } //Arrow Up
				else if (input == 80) { functions = "down"; break; } //Arrow Down
				else if (input == 77 && statu != _email && statu != pass) { functions = "right"; break; } //Arrow Right
				else if (input == 75 && statu != _email && statu != pass) { functions = "left"; break; } //Arrow Left
			}
			//Back Space
			else if (input == 8) {
				if (statu == wrap && lastinput.length() != 0) {
					if (lastinput.length() % num != 0) {
						cout << "\b \b";
						lastinput.pop_back();
					}
					else if (lastinput.length() % num == 0) {
						lastinput.pop_back();
						moveU(1);
						moveR(num);
						cout << "\b \b";
					}
				}
				else if (statu == normal && lastinput.length() != 0) {
					if (lastinput.length() > num && lastinput.length() != num + 1) {
						lastinput.pop_back();
					}
					else if (lastinput.length() <= num) {
						lastinput.pop_back();
						cout << "\b \b";
					}
					else if (lastinput.length() == num + 1) {
						lastinput.pop_back();
						cout << "\b\b" << lastinput[num - 2] << lastinput[num - 1];

					}
				}
				else if ((statu == _email || statu == pass|| statu == _pass) && lastinput.length() != 0) {
					if (lastinput.length() == 1) {
						if (statu == _email) {
							lastinput.pop_back();
							cout << "\b \b";
						}
						else if (statu == pass) {
							lastinput.pop_back();
							cout << "\b \b";
							fcolor("80;80;80");
							cout << "Password";
							moveL(8);
							fcolor(main_font_color);
						}
						else if (statu == _pass) {
							lastinput.pop_back();
							cout << "\b \b";
						}
						
					}
					else if (lastinput.length() > num && lastinput.length() != num + 1) {
						lastinput.pop_back();
					}
					else if (lastinput.length() <= num) {
						lastinput.pop_back();
						cout << "\b \b";
					}
					else if (lastinput.length() == num + 1) {
						if (statu == _email) {
							lastinput.pop_back();
							cout << "\b\b" << lastinput[num - 2] << lastinput[num - 1];
						}
						else if (statu == pass||statu == _pass) {
							lastinput.pop_back();
							cout << "\b\b" << "**";
						}

					}
				}


				// defult letters or digits
			}
			else if (input >= 32 && input <= 126) {
				if (statu == wrap) {
					if (lastinput.length() != 0 && lastinput.length() % num == 0) {
						moveD(1);
						moveL(num);
						cout << input;
						lastinput += input;
					}
					else {
						cout << input;
						lastinput += input;
					}
				}
				else if (statu == normal) {
					if (lastinput.length() < num) {
						cout << input;
						lastinput += input;
					}
					else {
						cout << "\b\b..";
						lastinput += input;
					}
				}
				else if (statu == _email) {
					std::string W(num, ' ');
					if (lastinput.length() == 0) {
						cout << W;
						moveL(num);
						cout << input;
						lastinput += input;
					}
					else if (lastinput.length() < num) {
						cout << input;
						lastinput += input;
					}
					else {
						cout << "\b\b..";
						lastinput += input;


					}
				}
				else if (statu == pass||statu==_pass) {
					std::string W(num, ' ');
					if (lastinput.length() == 0) {
						cout << W;
						moveL(num);
						cout << "*";
						lastinput += input;
					}
					else if (lastinput.length() < num) {
						cout << "*";
						lastinput += input;
					}
					else {
						cout << "\b\b..";
						lastinput += input;


					}
				}
			}
		}
		else if (statu == notinput) {
			std::string W(num, ' ');
			cout << W;
			moveL(num);
			if (lastinput.length() <= num) {
				cout << lastinput;
			}
			else {
				for (int i = 0; i < num - 2;i++) {
					cout << lastinput[i];
				}
				cout << "..";
			}
			break;
		}
	} while (true);
	hideC;
}

void id_write(int num, double &id,string &functions) {
	string str_id;
	
	
	do {
		char input;
		showC;
		input = _getch();
		hideC;
		if (input == 13 && !str_id.empty()) { functions = "enter"; id = stod(str_id); break; }//Enter
		else if (input == 27) { functions = "esc"; break; }//ESC
		else if (input == 9) { functions = "tab"; break; }//tap
		else if (input == -32) {
			input = _getch();
			if (input == 72) { functions = "up"; break; } //Arrow Up
			else if (input == 80) { functions = "down"; break; } //Arrow Down
			else if (input == 77) { functions = "right"; break; } //Arrow Right
			else if (input == 75) { functions = "left"; break; } //Arrow Left
		}
		//Back Space
		else if (input == 8) {
			if (str_id.length() > 0 && str_id.length() <= num) {
				cout << "\b \b";
				str_id.pop_back();
			}
			else if (str_id.length() > num && str_id.length() != num + 1) {
				str_id.pop_back();
			}
			else if (str_id.length() == num + 1) {
				cout << "\b\b" << str_id[num - 2] << str_id[num - 1];
				str_id.pop_back();
			}
		}
		else if (input >= '0' && input <= '9'||input=='.') {
			
			if (str_id.length() < num) {
				str_id += input;
				cout << input;
			}else if (str_id.length() == num) {
				str_id += input;
				cout << "\b\b..";
			}else if (str_id.length() > num) {
				str_id += input;
				
			}
		}
	} while (true);
	
}
void domain_write(int num, string input) {
	if (input.length() > num) {
		if (input[input.length()-4] == '.') {
			for (int i = 0;i < num - 6;i++) {
				cout << input[i];
			}
			cout << "...com";
		}else {
			for (int i = 0;i < num - 2;i++) {
				cout << input[i];
			}
			cout << "..";
		}
	}
	else { cout << input; }
}

