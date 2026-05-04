#include "company.h"

company::company(string _company_name, string _company_domain) {
	last_comp_id++;
	company_name = _company_name;
	company_domain = _company_domain;
	company_id = last_comp_id;
}


string company::get_company_name() { return company_name; }
string company::get_company_domain() { return company_domain; }
int company::get_company_id() { return company_id; }

employee& company::get_emp(int index) { return employeeslist[index]; }



void company::set_company_name(string name) { 
	company_name = name;
	string domain = "@" + company_name + ".com";
	company_domain = domain;
}
void company::set_company_id(int id) { company_id = id; }



int company::comp_emp_num() {
	return employeeslist.size();
}

void company::add_emp(string emp_name, string emp_email, string emp_pass, double emp_salary,string _comp_name) {
	transform(emp_name.begin(), emp_name.end(), emp_name.begin(), ::toupper);
	transform(emp_email.begin(), emp_email.end(), emp_email.begin(), ::tolower);
	transform(_comp_name.begin(), _comp_name.end(), _comp_name.begin(), ::toupper);
	employee new_emp = employee(emp_name, emp_email, emp_pass, emp_salary, _comp_name);
	employeeslist.push_back(new_emp);
}

int company::get_emp_count() { return (int)employeeslist.size(); }

int company::search_emp_ID(int id) {
	for (int i = 0;i < get_emp_count();i++) {
		if (employeeslist[i].get_id() == id) {
			return i;
		}
	}
	return -1;
}
employee& company::get_employee_by_email(string email) {
	int index = search_emp_email(email);
	return employeeslist[index];
}
int company::search_emp_email(string email) {

	for (int i = 0;i < (int)employeeslist.size();i++) {
		if (employeeslist[i].get_email() == email) {
			return i;
		}
	}
	return -1;
}

void company::delete_emp(int id) {
	int index = search_emp_ID(id);
	if (index != -1) {
		employeeslist.erase(employeeslist.begin() + index);
	}
}


