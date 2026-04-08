#include "main.h"
// abdelsalamsayued684@ecu.com

int main() {
	hideC;
	domain = "username@example.ecu";
	position = 1;
	Appsystem sys;
	sys.add_comp("ecu", "@ecu.com");
	sys.add_emp("abdo", "abdelsalamsayued684@ecu.com", "123", 5000, "ecu");

	string email;
	int index;
	loginpage_ui();
	do {
		email = loginpage();
		index = sys.search_emp_email(email);
		if (index == -1) {
			string error0 = "Email not registered in the system.\a";
			string error1 = "Please contact HR";
			red(font);
			bcolor(main_back_color);
			move(18, centerS(error0));
			cout << error0;
			move(19, centerS(error1));
			cout << error1;
			fcolor(main_font_color);

		}
		else {
			break;
		}


	} while (true);
	employee& current_user = sys.get_employee_by_email(email);
	passpage_ui(email);
	do {
		string pass = pass_page();
		if (current_user.get_pass() != pass) {
			string error = "Incorrect password\a";
			red(font);
			bcolor(main_back_color);
			move(18, centerS(error));
			cout << error;
			fcolor(main_font_color);
		}
		else { break; }
	} while (true);
}