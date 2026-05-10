#include "employee.h"
#include "Appsystem.h"
#include "company.h"


employee::employee(const string& emp_name, const string& emp_email, const string& emp_pass, double emp_salary, const string& _comp_name) {

	comp_name = _comp_name;
	name = emp_name;
	email = emp_email;
	password = emp_pass;
	if (sys.get_company_by_id(sys.get_company_id(comp_name)).get_emp_count() > 0) {
		employee_id = 100 + sys.get_company_by_id(sys.get_company_id(comp_name)).get_emp_count()+1;
	}else {
		employee_id = 101;
	}
	hours = 8;
	role = roles[2];
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
	taxes = (emp_salary*(1/100));
	employee_net_salary = emp_salary;
}
string employee::get_comp_name() const { return comp_name; }
string employee::get_name() const { return name; }
string employee::get_email() const { return email; }
string employee::get_pass() const { return password; }
string employee::get_role() const { return role; }
int employee::get_id() const { return employee_id; }
string employee::get_num() const { return num; }

float employee::get_taxes() const { return employee_salary*0.01; }
void employee::set_taxes(float _taxes) { taxes = _taxes; }

bool employee::get_statu() const { return statu_in; }
void employee::set_statu(bool statu) { statu_in = statu; }

bool employee::get_locked() const { return locked; }
void employee::set_locked(bool _locked) { locked = _locked; }

void employee::set_name(const string& new_name) { this->name = new_name; }
void employee::set_pass(const string& new_pass) { this->password = new_pass; }
void employee::set_role(const string& new_role) { this->role = new_role; }
void employee::set_num(const string& new_num) { this->num = new_num; }

float employee::get_leavenum() const { return employee_leave; }
float employee::get_attendance() const { return employee_attendance; }
double employee::get_borrowing() const { return employee_borrowing; }
double employee::get_salary() const { return employee_salary; }
double employee::get_bouns() const { return employee_bouns; }
double employee::get_overtime() const { return  employee_overtime; }
float employee::get_absence() const { return employee_absence; }
double employee::get_deduction() const { return employee_deduction; }
double employee::get_net_salary() const {
	return employee_attendance*(employee_salary / 30) / 8 + employee_bouns + (((employee_overtime/60)*1.5)* ((employee_salary/30)/hours)) - employee::get_taxes() - employee_deduction - (employee_absence*(employee_salary/30)) - (employee_late*(employee_salary/30/hours)) - employee_borrowing-(employee_leave*(employee_salary/30));
}
float employee::get_late() const { return employee_late; }

void employee::set_leavenum(float new_leave) { employee_leave += new_leave; }
void employee::set_attendance(float new_att) { employee_attendance += new_att; }
void employee::set_borrowing(float new_borr) { employee_borrowing += new_borr; }
void employee::set_salary(double new_salary) { employee_salary = new_salary; }
void employee::set_bouns(double new_bouns) { employee_bouns += new_bouns; }
void employee::set_overtime(double new_overtime) { employee_overtime += new_overtime; }
void employee::set_absence(float new_abs) { employee_absence = new_abs; }
void employee::set_deduction(double new_deduction) { employee_deduction += new_deduction; }
void employee::set_late(float new_late) { employee_late = new_late; }
void employee::set_comp_name(const string& new_comp_name) { 
	comp_name = new_comp_name;
	stringstream ss(name);
	string first_name;
	ss >> first_name;
	transform(first_name.begin(), first_name.end(), first_name.begin(), tolower);
	email = first_name + to_string(employee_id-100) + sys.get_company_by_id(sys.get_company_id(comp_name)).get_company_domain();
}
void employee::check_in(long long time) { time_in = time; }
long long employee::check_out(){
	long long time_out = time_in;
	time_in = 0;
	return time_out;
}
long long employee::get_time_in() const {
	return time_in;
}
void employee::set_time_in(long long time) {
	time_in = time;
}


