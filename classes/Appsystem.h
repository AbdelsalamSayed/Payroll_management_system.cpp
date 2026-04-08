#pragma once
#include "../draw.h"
#include "company.h"
#include "employee.h"

class  Appsystem {

	vector<company> companylist;
	vector<employee> employeeslist;

public:
	void add_emp(string emp_name, string emp_email, string emp_pass, float emp_salary,string company_name);
	int get_emp_count();
	int search_emp_ID(int id);
	int search_emp_email(string email);
	void delete_emp(int id);
	employee& get_employee_by_email(string email);
	void add_comp(string company_name, string company_domain);
	int get_comp_count();
	int get_company_id(string company_name);
	void delete_comp(string company_name);
};