#include "main.h"


int main() {
	hideC;
	domain = "username@example.ecu";
	position = 1;
	company comp;
	comp.set_company_name("ecu");
	comp.add_emp("abdo", "abdo@", "1234", 1);
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	body();
	footer();
	do {
		string input = loginpage();
		int index = comp.searchemail(input);
		if (index == -1) {
			string error0 = "Email not registered in the system.";
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
			string error0 = "Email not registered in the system.";
			string error1 = "Please contact HR";
			green(font);
			bcolor(main_back_color);
			move(18, centerS(error0));
			cout << error0;
			move(19, centerS(error1));
			cout << error1;
			fcolor(main_font_color);
		}


	} while (true);
	
}