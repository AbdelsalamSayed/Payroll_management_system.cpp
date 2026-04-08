#include "employee.h"

employee::employee(string emp_name, string emp_email, string emp_pass, float emp_salary, int _company_id) {
	last_emp_id++;
	company_id = _company_id;
	employee_name = emp_name;
	employee_email = emp_email;
	employee_password = emp_pass;
	employee_id = last_emp_id;
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

string employee::get_name() { return employee_name; }
string employee::get_email() { return employee_email; }
string employee::get_pass() { return employee_password; }
string employee::get_rank() { return employee_rank; }
int employee::get_id() { return employee_id; }
string employee::get_num() { return employee_num; }

bool employee::get_statu() { return statu_in; }
void employee::set_statu(const bool& statu) { statu_in = statu; }

void employee::set_name(const string& new_name) { employee_name = new_name; }
void employee::set_pass(const string& new_pass) { employee_password = new_pass; }
void employee::set_rank(const string& new_rank) { employee_rank = new_rank; }
void employee::set_num(const string& new_num) { employee_num = new_num; }

float employee::get_leavenum() { return employee_leave; }
float employee::get_attendance() { return employee_attendance; }
float employee::get_borrowing() { return employee_borrowing; }
float employee::get_salary() { return employee_salary; }
float employee::get_bouns() { return employee_bouns; }
float employee::get_overtime() { return employee_overtime; }
float employee::get_absence() { return employee_absence; }
float employee::get_deduction() { return employee_deduction; }

void employee::set_leavenum(float new_leave) { employee_leave = new_leave; }
void employee::set_attendance(float new_att) { employee_attendance = new_att; }
void employee::set_borrowing(float new_borr) { employee_borrowing = new_borr; }
void employee::set_salary(float new_salary) { employee_salary = new_salary; }
void employee::set_bouns(float new_bouns) { employee_bouns = new_bouns; }
void employee::set_overtime(float new_overtime) { employee_overtime = new_overtime; }
void employee::set_absence(float new_abs) { employee_absence = new_abs; }
void employee::set_deduction(float new_deduction) { employee_deduction = new_deduction; }
