//#include "Head.h"
//
//
//void body() {
//	string STR = "Ecu Payroll Mangment System.";
//	Sframe(0,0, Bhight, Width);
//	move(-1, center(STR));
//	printf("%s", STR.c_str());
//	
//
//}
//
//void footer() {
//	
//}
//
//void login_head() {
//
//}
//
//
//string write_frame(int num,string statu) {
//	char input;
//	string lastinput="";
//	do {
//		input = _getch();
//		if (input == 13) { return lastinput; break; } //Enter
//		else if (input == 27) { return "esc"; break; }
//		else if (input == 72) { return "up"; } //Arrow Up
//		else if (input == 80) { return "down"; } //Arrow Down
//		else if (input == 77) { return "right"; } //Arrow Right
//		else if (input == 75) { return "left"; } //Arrow Left
//
//		//Back Space
//		else if (input == 8) {
//			if (lastinput.length() != 0 && lastinput.length() % num != 0) {
//				cout << "\b \b";
//				lastinput.pop_back();
//			}
//			else if (lastinput.length() != 0 && lastinput.length() % num == 0 && statu == wrap) {
//				lastinput.pop_back();
//				moveU(1);
//				moveR(num);
//				cout << "\b \b";
//			}
//		} 
//		// defult letters or digits
//		else if (lastinput.length() != 0 &&lastinput.length() % num == 0 && statu == wrap) {
//			moveD(1);
//			moveL(num);
//			cout << input;
//			lastinput += input;
//		}
//		else if (lastinput.length() != 0 && statu == normal) {
//			if (lastinput.length() < num) {
//				cout << input;
//				
//			}
//			lastinput += input;
//		}
//		
//		else { cout << input; lastinput += input; }
//	} while (true);
//}