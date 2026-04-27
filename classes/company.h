#pragma once
#include "../Main_H.h"
#include "employee.h"



class company
{
	inline static int last_comp_id = 0;
	string company_name;
	int company_id;
	string company_domain;

	vector<class employee> employeeslist;



public:

	
	employee& get_emp(int index);
	company(string _company_name, string _company_domaine);
	int comp_emp_num();
	void add_emp(string emp_name, string emp_email, string emp_pass, double emp_salary,string _comp_name);
	int get_emp_count();
	int search_emp_ID(int id);
	int search_emp_email(string email);
	void delete_emp(int id);
	employee& get_employee_by_email(string email);

	string get_company_name();
	string get_company_domain();
	int get_company_id();

	void set_company_name(string name);
	void set_company_id(int id);
	

};