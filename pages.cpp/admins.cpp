#include "../pages.H/system_admin.h"

void admins_page(employee& current_user) {
	main__ui("Home", 1,roles[1]);
	int position = 1;
	string functions;
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
	fcolor(main_font_color);
	string total_employees = "Total Employees   --->  " + to_string(current_comp.get_emp_count());
	move(16, 2);
	cout << total_employees;
	draw_logo(5);
	do {
		buttons(functions = "super_admin");
		if (functions == "esc") {
			position = 1;
			move(11, centerN(21));
			white(back);
			red(font);
			Dframe(8, 21);
			string error = "Do you want to Logout";
			move(13, centerLN(13, 33, error));
			black(font);
			cout << "\a" << error;
			move(16, centerN(5));
			moveR(6);
			Dframe(1, 5);
			move(17, centerN(5));
			moveR(8);
			cout << "No";
			move(16, centerN(5));
			moveL(6);
			red(back);
			Dframe(1, 5);
			move(17, centerN(5));
			moveL(4);
			cout << "Yes";
			white(back);
			do {
				buttons(functions = "super_admin");
				if ((functions == "right" || functions == "tab") && position == 1) {
					white(back);
					move(16, centerN(5));
					moveL(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					red(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					position = 2;
					white(back);
				}
				if ((functions == "left" || functions == "tab") && position == 2) {
					white(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					move(16, centerN(5));
					moveL(6);
					red(back);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					position = 1;
					white(back);
				}
				if (functions == "enter" && position == 1) {
					loginpage_ui();
					loginpage();
				}
				if (functions == "enter" && position == 2) {
					position = 1;
					admins_page(current_user);
				}
			} while (true);



		}
		else if ((functions=="right"|| functions == "tab" ) && position==1) {
			footer(roles[1],2);
			position = 2;
		}
		else if ((functions == "right" || functions == "tab") && position == 2) {
			footer(roles[1], 3);
			position = 3;
		}
		else if ((functions == "left" || functions == "tab") && position == 2) {
			footer(roles[1], 1);
			position = 1;
		}
		else if ((functions == "left" || functions == "tab") && position == 3) {
			footer(roles[1], 2);
			position = 4;
		}
		else if ((functions == "left" || functions == "tab") && position == 4) {
			footer(roles[1], 1);
			position = 1;
		}
		else if (functions == "right" && position == 4) {
			footer(roles[1], 3);
			position = 3;
		}
		else if (functions == "enter" && position == 1) {
			main_ui("Home",1,roles[1]);
			int position = 1;
			string functions;
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
			fcolor(main_font_color);
			string total_employees = "Total Employees   --->  " + to_string(current_comp.get_emp_count());
			move(16, 2);
			cout << total_employees;
			draw_logo(5);
			
		}
		else if (functions == "enter" && (position == 4 || position == 2)) {
			
			Admin_edit_com_page(current_user);
		}
		else if (functions == "enter" && position == 3) {
			main_ui("Setting", 3, roles[1]);
			
		}
		

	} while (true);
}