#include "Head.h"


void body() {
	string STR = "Ecu Payroll Mangment System.";
	move(-1, 0);

	Sframe(Bhight, Width);
	move(-1, centerS(STR));
	bold;
	fcolor(100,200,255);
	printf("%s", STR.c_str());
	white(Bfont);
	bcolor(10, 25, 47);
	

}

void footer() {
	
}

void login_head() {

}


string write_frame(int num,string statu) {
	char input;
	string lastinput="";
	do {
		input = _getch();
		if (input == 13) { return lastinput; } //Enter
		else if (input == 27) { return "esc"; }
		else if (input == 72) { return "up"; } //Arrow Up
		else if (input == 80) { return "down"; } //Arrow Down
		else if (input == 77) { return "right"; } //Arrow Right
		else if (input == 75) { return "left"; } //Arrow Left

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
				if (lastinput.length() > num && lastinput.length() != num+1) {
					lastinput.pop_back();
				}
				else if (lastinput.length() <= num) {
					lastinput.pop_back();
					cout << "\b \b";
				}
				else if (lastinput.length() == num+1) {
					lastinput.pop_back();
					cout << "\b\b"<<lastinput[num-2] << lastinput[num - 1];

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

	} while (true);
}