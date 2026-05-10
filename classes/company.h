#pragma once
#include "../Main_H.h"
#include "employee.h"

class company {
private:
	inline static int last_comp_id = 0;
	int company_id;
	string company_name;
	string company_domain;

	vector<employee> employeeslist;

public:
	company(const string& _company_name, const string& _company_domain);

	// Getters
	string get_company_name() const;
	string get_company_domain() const;
	int get_company_id() const;
	int get_emp_count() const;
	int comp_emp_num() const;

	employee& get_emp(int index);
	employee& get_employee_by_email(const string& email);
	int search_emp_ID(int id) const;
	int search_emp_email(const string& email) const;
	int get_total_salary() const;
	int get_total_net_salary() const;

	// Setters
	void set_company_name(const string& name);
	void set_company_id(int id);
	void add_emp(string emp_name, string emp_email, string emp_pass, double emp_salary, string _comp_name);
	void delete_emp(int id);
};