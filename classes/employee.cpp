#include "employee.h"

employee::employee(string emp_name, string emp_email, string emp_pass, double emp_salary) {
	last_emp_id++;
	employee_name = emp_name;
	employee_email = emp_email;
	employee_password = emp_pass;
	employee_id = last_emp_id;
	employee_role = "Staff";
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
	locked = false;
	taxes = 0;
}

string employee::get_name() { return employee_name; }
string employee::get_email() { return employee_email; }
string employee::get_pass() { return employee_password; }
string employee::get_role() { return employee_role; }
int employee::get_id() { return employee_id; }
string employee::get_num() { return employee_num; }

float employee::get_taxes() { return taxes; }
void employee::set_taxes(float _taxes) { taxes = _taxes; }

bool employee::get_statu() { return statu_in; }
void employee::set_statu(const bool& statu) { statu_in = statu; }

bool employee::get_locked() { return locked; }
void employee::set_locked(const bool& _locked) { locked = _locked; }

void employee::set_name(const string& new_name) { employee_name = new_name; }
void employee::set_pass(const string& new_pass) { employee_password = new_pass; }
void employee::set_role(const string& new_role) { employee_role = new_role; }
void employee::set_num(const string& new_num) { employee_num = new_num; }

float employee::get_leavenum() { return employee_leave; }
float employee::get_attendance() { return employee_attendance; }
float employee::get_borrowing() { return employee_borrowing; }
double employee::get_salary() { return employee_salary; }
float employee::get_bouns() { return employee_bouns; }
float employee::get_overtime() { return employee_overtime; }
float employee::get_absence() { return employee_absence; }
float employee::get_deduction() { return employee_deduction; }

void employee::set_leavenum(float new_leave) { employee_leave = new_leave; }
void employee::set_attendance(float new_att) { employee_attendance = new_att; }
void employee::set_borrowing(float new_borr) { employee_borrowing = new_borr; }
void employee::set_salary(double new_salary) { employee_salary = new_salary; }
void employee::set_bouns(float new_bouns) { employee_bouns = new_bouns; }
void employee::set_overtime(float new_overtime) { employee_overtime = new_overtime; }
void employee::set_absence(float new_abs) { employee_absence = new_abs; }
void employee::set_deduction(float new_deduction) { employee_deduction = new_deduction; }
