#include "../pages.H/system_admin.h"

void system_admin_addcompany_ui() {
	
	main_ui("Add Company", 2,roles[0]);
	move(5,centerS(((string)"Company Name")));
	cout << "Company Name";
	move(10,centerS(((string)"Company Domain")));
	cout << "Company Domain";
	move(6, 3);
	move(15,centerS(((string)"Company ID")));
	cout << "Company ID";
	move(6, 3);
	bcolor(main_boxback_color);
	Dframe(1, 39);
	move(11, 3);
	Dframe(1, 39);
	move(16, 3);
	Dframe(1, 39);
	fcolor(button_border_color);
	bcolor(button_color);
	move(22, 3);
	Dframe(1, 15);
	move(22, 27);
	Dframe(1, 15);
	fcolor(button_font_color);
	move(23, centerLN(4, 19, ((string)"Add")));
	cout << "Add";
	move(23, centerLN(28, 42, ((string)"Cancel")));
	cout << "Cancel";
}