#include "../pages.H/system_admin.h"

void add_emp_page(string company_name,employee& _current_user) {
	position = 0;
	employee& current_user = _current_user;
	employee emp = sys.get_employee_by_email(current_user.get_email());
	string functions = "start", emp_name, emp_email, emp_pass;
	double emp_salary;
	if (current_user.get_role() == roles[0]) {
		system_admin_ui("Add Employee", 3, roles[0]);
	}else {
		admin_ui("Add Employee", 2, roles[1]);
	}
	bcolor(main_back_color);
	fcolor(main_boxborder_color);
	move(6, 1);
	cout << "Full employee name: ";
	
	move(9, 1);
	cout << "Employee email: ";
	move(12, 1);
	cout << "Employee password: ";
	move(15, 1);
	cout << "Employee salary: ";
	move(18, 1);
	red(font);
	cout << "Note: Employee name must only contain letters\n";
	moveR(1);
	cout << "and spaces. Employee email will be generated\n";
	moveR(1);
	cout << "automatically based on the employee name and\n";
	moveR(1);
	cout << "the company domain. Employee password must be\n";
	moveR(1);
	cout << "at least 8 characters long and contain at\n";
	moveR(1);
	cout << "least one uppercase letter, one lowercase\n";
	moveR(1);
    cout << ",letter one digit, and one special character.";
	fcolor(main_font_color);
	do {
		emp_pass = "";
		emp_name = "";
		fcolor(main_font_color);
		move(6, ((string)"Full employee name: ").length()+1);
		write_frame(25, normal, emp_name, functions);
		if (functions == "esc" && current_user.get_role() == roles[0]) { edit_com_page(current_user); }
		else if (functions == "esc" && current_user.get_role() == roles[1]) { Admin_edit_com_page(current_user); }
		if (functions == "enter" && emp_name.empty()) { functions = "start"; continue; }
		if (functions == "enter" && !emp_name.empty()) {
			if (!all_of(emp_name.begin(), emp_name.end(), [](char c) { return isalpha(c) || c == ' '; })) {
				functions = "start";
				move(6, ((string)"Full employee name: ").length() + 1);
				cout << string(25, ' ');
				continue;
			}
			move(9, ((string)"Employee email: ").length()+1);
			string id = to_string(sys.get_company_by_id(sys.get_company_id(company_name)).comp_emp_num()+1);
			stringstream ss(emp_name);
			string first_name;
			ss >> first_name;
			transform(first_name.begin(), first_name.end(), first_name.begin(), tolower);
			emp_email = first_name + id + sys.get_company_by_id(sys.get_company_id(company_name)).get_company_domain();
			write_frame(29, notinput, emp_email, functions);
			move(12, ((string)"Employee password: ").length() + 1);
			write_frame(26, _pass, emp_pass, functions);
			if (functions == "esc" && current_user.get_role() == roles[0]) { edit_com_page(current_user); }
			else if (functions == "esc" && current_user.get_role() == roles[1]) { Admin_edit_com_page(current_user); }
			if (functions == "enter" && emp_pass.empty()) { functions = "start"; continue; }
			if (emp_pass.length() < 8 || !any_of(emp_pass.begin(), emp_pass.end(), ::isupper) || !any_of(emp_pass.begin(), emp_pass.end(), ::islower) || !any_of(emp_pass.begin(), emp_pass.end(), ::isdigit) || !any_of(emp_pass.begin(), emp_pass.end(), [](char c) { return ispunct(c); })) {
				functions = "start";
				move(12, ((string)"Employee password: ").length() + 1);
				cout << string(26, ' ');
				move(6, ((string)"Full employee name: ").length() + 1);
				cout << string(25, ' ');
				move(9, ((string)"Employee email: ").length() + 1);
				cout << string(29, ' ');
				
				continue;
				


			}
			move(15, ((string)"Employee salary: ").length() + 1);
			id_write(28, emp_salary, functions);
			if (functions == "esc") { edit_com_page(current_user); }
			if (emp_salary <= 0) {
				functions = "start";
				move(15, ((string)"Employee salary: ").length() + 1);
				cout << string(28, ' ');
				move(6, ((string)"Full employee name: ").length() + 1);
				cout << string(25, ' ');
				move(9, ((string)"Employee email: ").length() + 1);
				cout << string(29, ' ');
				move(12, ((string)"Employee password: ").length() + 1);
				cout << string(26, ' ');
				continue;
				
			}
			break;


		}

	} while (true);
	
	if (current_user.get_role() == roles[0]) {
		sys.get_company_by_id(sys.get_company_id(company_name)).add_emp(emp_name, emp_email, emp_pass, emp_salary, company_name);
		sys.get_employee_by_email(emp_email).set_role(roles[1]);
	}
	else {
		sys.get_company_by_id(sys.get_company_id(company_name)).add_emp(emp_name, emp_email, emp_pass, emp_salary, company_name);
	}
	move(18, 1);
	cout << string(45, ' ');
	move(19, 1);
	cout << string(45, ' ');
	move(20, 1);
	cout << string(45, ' ');
	move(21, 1);
	cout << string(45, ' ');
	move(22, 1);
	cout << string(45, ' ');
	move(23, 1);
	cout << string(45, ' ');
	move(24, 1);
	cout << string(45, ' ');
	
	move(19, centerS(((string)"Employee added successfully.")));
	green(font);
	cout << "Employee added successfully.";
	save_data();
	Sleep(2000);
	
	if (emp.get_role() == roles[0]) {
		system_admin_pages(emp);
	}
	else if (emp.get_role() == roles[1]) {
		Admin_edit_com_page(emp);
	}
}