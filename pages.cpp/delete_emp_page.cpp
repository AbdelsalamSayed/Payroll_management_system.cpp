#include "../pages.H/system_admin.h"

void delete_emp_page(string company_name, employee& current_user) {
	company& comp = sys.get_company_by_id(sys.get_company_id(company_name));
	position = 0;
	if (current_user.get_role() == roles[0]) {
		system_admin_ui("Setting", 3, roles[0]);
	}else {
		admin_ui("Delete Employee", 2, roles[1]);
	}
	move(5, centerS(((string)"Delete employee from " + company_name + " company")));
	cout << "Delete employee from " + company_name + " company";
	move(7, centerS(((string)"Enter employee ID to delete")));
	cout << "Enter employee ID to delete";
	move(9, centerN(32));
	double emp_id;
	fcolor(main_boxborder_color);
	bcolor(main_boxback_color);
	Dframe(1, 30);
	string functions = "start";
	do {
		string space = string(28, ' ');
		move(10,9);
		bcolor(main_boxback_color);
		cout << space;
		move(10, 9);
		fcolor(main_font_color);
		id_write(28, emp_id, functions);
		if (functions == "esc" && current_user.get_role() == roles[0]) { edit_com_page(current_user); }
		else if (functions == "esc" && current_user.get_role() == roles[1]) { Admin_edit_com_page(current_user); }
		if (functions == "enter") {
			move(13, 1);
			string spaces = string(45, ' ');
			bcolor(main_back_color);
			cout << spaces;
			int emp_index = comp.search_emp_ID(static_cast<int>(emp_id));
			if (emp_index != -1) {
				bcolor(main_back_color);
				move(12, 1);
				cout << "employee name: " << comp.get_emp(emp_index).get_name();
				move(14, 1);
				cout << "employee email: " << comp.get_emp(emp_index).get_email();
				move(16, 1);
				cout << "employee salary: " << comp.get_emp(emp_index).get_salary();
				move(18, 1);
				cout << "employee role: " << comp.get_emp(emp_index).get_role();
				move(20, 1);
				cout << "employee status: " << (comp.get_emp(emp_index).get_locked() ? "\033[31minactive" : "\033[32mactive");
				bcolor(main_back_color);
				move(22, centerS(((string)"Are you sure you want to delete this employee")));
				red(font);
				cout << "Are you sure you want to delete this employee";
				fcolor(main_font_color);
				move(23, centerS(((string)"Yes")));
				hoverd_button;;
				fcolor(main_font_color);
				cout << "Yes";
				bcolor(main_back_color);
				do {
					buttons(functions = "main");
					if (functions == "enter") {
						sys.get_company_by_id(sys.get_company_id(company_name)).delete_emp(static_cast<int>(emp_id));
						string error = "Employee deleted successfully";
						move(24, 2);
						bcolor(main_back_color);
						string s = string(43, ' ');
						cout << s;
						move(24, centerS(error));
						green(font);
						cout << error;
						bcolor(main_boxback_color);
						fcolor(main_font_color);
						save_data();
						Sleep(2000);
						if (current_user.get_role() == roles[0]) {
							edit_com_page(current_user);
						}
						else if (current_user.get_role() == roles[1]) {
							Admin_edit_com_page(current_user);
						}

					}
					if (functions == "esc"){
						if (current_user.get_role() == roles[0]) {
							edit_com_page(current_user);
						}
						else if (current_user.get_role() == roles[1]) {
							Admin_edit_com_page(current_user);
						}
					}
				} while (true);
			}else {
				
				string error = "Employee ID not found.";
				bcolor(main_back_color);
				move(13, 1);
				string spaces = string(30, ' ');
				cout << spaces;
				red(Bfont);
				move(13, centerS(((string)"Employee ID not found.")));
				cout << "Employee ID not found.";
				fcolor(main_font_color);
				continue;
				
			}
		} 
	} while (true);
}