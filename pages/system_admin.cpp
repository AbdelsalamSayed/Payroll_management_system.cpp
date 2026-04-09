#include "system_admin.h"

void system_admin_ui() {
	string system_status;
	string space = string(Width, double2);
	body();
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	string date = to_string(ltm.tm_mday) + "  /  " + to_string(1 + ltm.tm_mon) + "  /  " + to_string(1900 + ltm.tm_year);
	string dashboard = "SYSTEM ADMINISTRATION CONSOLE";
	white(Bfont);
	bold;
	move(2, centerS(dashboard));
	cout << dashboard;
	move(0, centerS(date));
	cout << date;
	fcolor(main_bordr_color);
	move(1, 0);cout << double9 << space << double10;
	move(3, 0);cout << double9 << space << double10;
	move(14, 0);
	cout << double9 << space << double10;
	move(18, 0);
	cout << double9 << space << double10;
	move(22, 0);
	cout << double9 << space << double10;
	fcolor(main_font_color);
	string total_companys = "Total Companies   --->  " + to_string(sys.get_comp_count());
	move(16, 2);
	cout << total_companys;
	string total_employees = "Total Employees   --->  " + to_string(sys.get_emp_count());
	move(20, 2);
	cout << total_employees;
	if (sys.get_system_online()) {
		system_status = "System Status     --->  \033[32mOnline";
		fcolor(main_font_color);
	}
	else {
		system_status = "System Status     --->  \033[31mOffline";
		fcolor(main_font_color);
	}
	move(24, 2);
	cout << system_status;
	footer(roles[0], 1);
}
void system_admin_pages() {
	system_admin_ui();
	draw_logo(5);
	position = 1;
	string functions = "start";
	do {
		buttons(functions= "super_admin");
		if ((functions == "right"|| functions == "tab")&& position == 1)
		{
			position = 2;
			footer(roles[0], position);
		}else if ((functions == "right" || functions == "tab") && position == 2)
		{
			position = 3;
			footer(roles[0], position);
		}else if ((functions == "left" || functions == "tab") && position == 3)
		{
			position = 4;
			footer(roles[0], 2);
		}else if ((functions == "left" || functions == "tab") && position == 4)
		{
			position = 1;
			footer(roles[0], position);
		}
		else if (functions == "enter") {
			break;
		}
	} while (true);

	if (position == 1) {
		add_comp_page();
	}
	if (position == 2||position==4) {
		edit_com_page();
	}
	if (position == 3) {
		super_setting_page();
	}
}


void add_comp_page() {

}
void edit_com_page() {

}
void super_setting_page() {

}
