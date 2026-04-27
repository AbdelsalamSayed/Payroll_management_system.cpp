#include "../pages.H/system_admin.h"

void admins_page(employee& current_user) {
	main__ui("home", 0,roles[1]);
	string system_status;
	string comp_name = current_user.get_comp_name();
	transform(comp_name.begin(), comp_name.end(), comp_name.begin(), ::toupper);
	company& current_comp = sys.get_company_by_id(sys.get_company_id(comp_name));
	string space = string(Width, double2);
	fcolor(main_bordr_color);
	move(14, 0);
	cout << double9 << space << double10;
	move(18, 0);
	cout << double9 << space << double10;
	move(22, 0);
	cout << double9 << space << double10;
	fcolor(main_font_color);
	string total_companys = "Total Companies   --->  " + to_string(current_comp.get_emp_count());
	move(16, 2);
	cout << total_companys;
	string total_employees = "Total Employees   --->  " + to_string(current_comp.get_emp_count());
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