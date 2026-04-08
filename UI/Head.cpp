#include "Head.h"


void body() {
	string STR = "Ecu Payroll Managment System.";
	move(-1, 0);
	Sframe(Bhight, Width);
	move(-1, centerS(STR));
	bold;
	fcolor("100;210;255");
	cout<<STR;
	bcolor(main_back_color);
	

}

void footer() {
	
}

void login_head() {

}

void bottons(string& functions) {
	do
	{
	char input = _getch();
	if (input == 13) { functions = "enter"; position = 1; } //Enter
	else if (input == 27) { functions = "esc"; }
	else if (input == -32) {
		input = _getch();
		if (input == 72) { functions = "up"; } //Arrow Up
		else if (input == 80) { functions = "down"; } //Arrow Down
		else if (input == 77) { functions = "right"; } //Arrow Right
		else if (input == 75) { functions = "left"; } //Arrow Left
	}else{}
	} while (functions!= "enter" && functions!= "up");
}

void write_frame(int num, string statu, string& lastinput, string& functions) {
	char input;

	do {
		showC;
		input = _getch();
		hideC;
		if (input == 13) { functions = "enter"; break; } //Enter
		else if (input == 9) {  }//TAP
		else if (input == 127) {  }//CTRL+BACKSPACE
		else if (input == 27) { functions = "esc"; break; }//ESC
		else if (input == -32) {
			input = _getch();
			if (input == 72) { functions = "up"; break; } //Arrow Up
			else if (input == 80) { functions = "down"; break; } //Arrow Down
			else if (input == 77) { functions = "right"; break; } //Arrow Right
			else if (input == 75) { functions = "left"; break; } //Arrow Left
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
			else if (statu == email && lastinput.length() != 0) {
				if (lastinput.length() == 1) {
					lastinput.pop_back();
					cout << "\b \b";
					fcolor("80;80;80");
					cout << domain;
					moveL(domain.length());
					fcolor(main_font_color);
				}
				else if (lastinput.length() > num && lastinput.length() != num + 1) {
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


			// defult letters or digits
		}
		else if (statu == wrap) {
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
		else if ( statu == email ){
			std::string W(num , ' ');
			if (lastinput.length() == 0) {
				cout << W;
				moveL(num );
				cout << input;
				lastinput += input;
			}else if (lastinput.length() < num) {
					cout << input;
					lastinput += input;
			}else {
					cout << "\b\b..";
					lastinput += input;

			 
			}
		}
	} while (true);
}