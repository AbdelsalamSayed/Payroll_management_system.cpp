#include "../pages.H/system_admin.h"

void admins_page(employee& current_user) {
	admin_ui("Home", 1,roles[1]);
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
	string total_salary = "Total Salaries    --->  " + to_string(current_comp.get_total_salary());
	move(16, 2);
	cout << total_employees;
	move(20, 2);
	cout << total_salary;
	draw_logo(5);
	do {
		buttons(functions = "main");
		if (functions == "esc") {
			logout_msg();
			admins_page(current_user);
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
			admin_ui("Home",1,roles[1]);
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
			string total_salary = "Total Salaries    --->  " + to_string(current_comp.get_total_salary());
			move(16, 2);
			cout << total_employees;
			move(20, 2);
			cout << total_salary;
			draw_logo(5);
			
		}
		else if (functions == "enter" && (position == 4 || position == 2)) {
			
			Admin_edit_com_page(current_user);
		}
		else if (functions == "enter" && position == 3) {
			admin_ui("Setting", 3, roles[1]);
			string line1 = "Name     :  " + current_user.get_name();
			string line2 = "Email    :  " + current_user.get_email();
			string line4 = "Password :  " + current_user.get_pass();
			string line5 = "Company  :  " + current_user.get_comp_name();
			string line6 = "Role     :  " + current_user.get_role();
			string line7 = "Number   :  " + current_user.get_num();
			string line3 = "id	   :  " + to_string(current_user.get_id());
			fcolor(main_font_color);
			move(5, 2);
			cout << line1;
			move(7, 2);
			cout << line2;
			move(9, 2);
			cout << line3;
			move(11, 2);
			cout << line4;
			move(13, 2);
			cout << line5;
			move(15, 2);
			cout << line6;
			move(17, 2);
			printf ("Net Salary   :  %.2f",current_user.get_net_salary());
			move(19, 2);
			cout << line7;
			move(22, 7);
			hoverd_button;
			Dframe(1, 31);
			fcolor(main_font_color);
			move(23, centerLN(8, 39, ((string)"Log out")));
			fcolor(hoverd_font_color);
			cout << "Log out";
		
			do {
				buttons(functions = "main");
				if (functions == "esc") { admins_page(current_user); }
				if (functions == "enter") {
					reset;
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
						buttons(functions = "main");
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
							clear_token();
							loginpage();
							
						}
						if (functions == "enter" && position == 2) {
							position = 1;
							admins_page(current_user);
						}
					} while (true);



				}
			} while (true);

			
		}
		

	} while (true);
}