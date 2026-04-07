#include "main.h"


int main() {
	company new_comp;
	new_comp.set_company_name("ecu");
	new_comp.add_emp("abdo", "abdo@", "1234", 1);
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	
	
	body();
	footer();
	loginpage();
	
	
	//move(16, centerN(emailbarL) + 1);
	//clearL(emailbarL - domain.length() - 2);
}