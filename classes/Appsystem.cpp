#include "Appsystem.h"

void Appsystem::add_comp(string company_name, string company_domain) {
	company new_company = company(company_name, company_domain);
	companylist.push_back(new_company);
}

int Appsystem::get_comp_count() { return (int)Appsystem::companylist.size(); }

void Appsystem::delete_comp(string company_name) {
	int index = get_company_id(company_name);
	if (index != -1) {
		Appsystem::companylist.erase(Appsystem::companylist.begin() + index);
	}
}
int Appsystem::get_company_id(string company_name) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_name() == company_name) {
			return companylist[i].get_company_id();
		}
	}
}
void Appsystem::add_emp(string emp_name, string emp_email, string emp_pass, float emp_salary, string company_name) {
	int id = get_company_id(company_name);
	employee new_emp = employee(emp_name, emp_email, emp_pass, emp_salary, id);
	employeeslist.push_back(new_emp);
}

int Appsystem::get_emp_count() { return (int)employeeslist.size(); }

int Appsystem::search_emp_ID(int id) {
	for (int i = 0;i < get_emp_count();i++) {
		if (employeeslist[i].get_id() == id) {
			return i;
		}
	}
	return -1;
}
employee& Appsystem::get_employee_by_email(string email) {
	int index = search_emp_email(email);
	return employeeslist[index];
}
int Appsystem::search_emp_email(string email) {

	for (int i = 0;i < (int)employeeslist.size();i++) {
		if (employeeslist[i].get_email() == email) {
			return i;
		}
	}
	return -1;
}

void Appsystem::delete_emp(int id) {
	int index = search_emp_ID(id);
	if (index != -1) {
		employeeslist.erase(employeeslist.begin() + index);
	}
}