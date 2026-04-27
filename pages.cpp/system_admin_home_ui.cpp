#include "../pages.H/system_admin.h"

void main_ui(string page,int i,string role) {
	string space = string(Width, double2);
	body();
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	string date = to_string(ltm.tm_mday) + "  /  " + to_string(1 + ltm.tm_mon) + "  /  " + to_string(1900 + ltm.tm_year);
	string dashboard = "SYSTEM ADMINISTRATION CONSOLE ("+page+")";
	move(0, 1);
	red(back);
	black(Bfont);
	cout << "X";
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	cout << "ESC";
	white(Bfont);
	bold;
	move(2, centerS(dashboard));
	cout << dashboard;
	move(0, centerS(date));
	cout << date;
	fcolor(main_bordr_color);
	move(1, 0);cout << double9 << space << double10;
	move(3, 0);cout << double9 << space << double10;
	if (role == roles[0]) {
		footer(roles[0], i);
	}	else if (role == roles[1]) {
		footer(roles[1], i);
	}
	else if (role == roles[2]) {
		footer(roles[2], i);
	}
	fcolor("100;210;255");
}
void main__ui(string page,int i,string role) {
	string space = string(Width, double2);
	body();
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	string date = to_string(ltm.tm_mday) + "  /  " + to_string(1 + ltm.tm_mon) + "  /  " + to_string(1900 + ltm.tm_year);
	string dashboard = "ADMINS CONSOLE ("+page+")";
	move(0, 1);
	red(back);
	black(Bfont);
	cout << "X";
	fcolor(main_bordr_color);
	bcolor(main_back_color);
	cout << "ESC";
	white(Bfont);
	bold;
	move(2, centerS(dashboard));
	cout << dashboard;
	move(0, centerS(date));
	cout << date;
	fcolor(main_bordr_color);
	move(1, 0);cout << double9 << space << double10;
	move(3, 0);cout << double9 << space << double10;
	if (role == roles[0]) {
		footer(roles[0], i);
	}	else if (role == roles[1]) {
		footer(roles[1], i);
	}
	else if (role == roles[2]) {
		footer(roles[2], i);
	}
	fcolor("100;210;255");
}



void system_admin_home_ui() {
	main_ui("home", 1,roles[0]);
	string system_status;
	string space = string(Width, double2);
	fcolor(main_bordr_color);
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
	string total_employees = "Total Employees   --->  " + to_string(sys.get_emps_count());
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
	draw_logo(5);
}