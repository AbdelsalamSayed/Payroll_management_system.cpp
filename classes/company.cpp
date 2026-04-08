#include "company.h"
#include "../draw.h"
int company::employee::last_id = 1000;

company::company() {
	company_name = "";
}
company::company(string comp_name) {
	company_name = comp_name;
}

string company::get_company_name() { return company_name; }
void company::set_company_name(string comp_name) { company_name = comp_name; }




company::employee::employee() {
	last_id++;
	employee_id = last_id;
	employee_leave = 0.0;
	employee_attendance = 0.0;
	employee_borrowing = 0.0;
	employee_salary = 0.0;
	employee_bouns = 0.0;
	employee_overtime = 0.0;
	employee_late = 0.0;
	employee_absence = 0.0;
	employee_deduction = 0.0;
	statu_in = false;
}
company::employee::employee(string emp_name, string emp_email, string emp_pass, float emp_salary) {
	last_id++;
	employee_name = emp_name;
	employee_email = emp_email;
	employee_password = emp_pass;
	employee_id = last_id;
	employee_rank = "Staff";
	employee_leave = 0.0;
	employee_attendance = 0.0;
	employee_borrowing = 0.0;
	employee_salary = emp_salary;
	employee_bouns = 0.0;
	employee_overtime = 0.0;
	employee_late = 0.0;
	employee_absence = 0.0;
	employee_deduction = 0.0;
	statu_in = false;
}
string company::employee::get_name() { return employee_name; }
string company::employee::get_email() { return employee_email; }
string company::employee::get_pass() { return employee_password; }
string company::employee::get_rank() { return employee_rank; }
int company::employee::get_id() { return employee_id; }
string company::employee::get_num() { return employee_num; }

bool company::employee::get_statu() { return statu_in; }
void company::employee::set_statu(const bool& statu) { statu_in = statu; }

void company::employee::set_name(const string& new_name) { employee_name = new_name; }
void company::employee::set_pass(const string& new_pass) { employee_password = new_pass; }
void company::employee::set_rank(const string& new_rank) { employee_rank = new_rank; }
void company::employee::set_num(const string& new_num) { employee_num = new_num; }

float company::employee::get_leavenum() { return employee_leave; }
float company::employee::get_attendance() { return employee_attendance; }
float company::employee::get_borrowing() { return employee_borrowing; }
float company::employee::get_salary() { return employee_salary; }
float company::employee::get_bouns() { return employee_bouns; }
float company::employee::get_overtime() { return employee_overtime; }
float company::employee::get_absence() { return employee_absence; }
float company::employee::get_deduction() { return employee_deduction; }

void company::employee::set_leavenum(float new_leave) { employee_leave = new_leave; }
void company::employee::set_attendance(float new_att) { employee_attendance = new_att; }
void company::employee::set_borrowing(float new_borr) { employee_borrowing = new_borr; }
void company::employee::set_salary(float new_salary) { employee_salary = new_salary; }
void company::employee::set_bouns(float new_bouns) { employee_bouns = new_bouns; }
void company::employee::set_overtime(float new_overtime) { employee_overtime = new_overtime; }
void company::employee::set_absence(float new_abs) { employee_absence = new_abs; }
void company::employee::set_deduction(float new_deduction) { employee_deduction = new_deduction; }



void company::add_emp(string emp_name, string emp_email, string emp_pass, float emp_salary) {
employee new_emp(emp_name, emp_email, emp_pass, emp_salary);
employeeslist.push_back(new_emp);
}

int company::get_emp_count() { return (int)company::employeeslist.size(); }

int company::searchID(int id) {
	for (int i = 0;i < (int)company::employeeslist.size();i++) {
		if (company::employeeslist[i].get_id() == id) {
			return i;
		}
	}
	return -1;
}
int company::searchemail(string email) {

	for (int i = 0;i < (int)company::employeeslist.size();i++) {
		if (company::employeeslist[i].get_email() == email) {
			return i;
		}
	}
	return -1;
}

void company::delete_emp(int id) {
	int index = searchID(id);
	if (index != -1) {
		company::employeeslist.erase(company::employeeslist.begin() + index);
	}
}
