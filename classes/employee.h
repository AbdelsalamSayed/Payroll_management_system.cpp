#pragma once
#include "../Main_H.h"

class employee {
	inline static int last_emp_id = 1000;
	int employee_id,company_id;
	string employee_name, employee_email, employee_password, employee_role, employee_num;
	float employee_leave, employee_attendance, employee_borrowing, employee_salary, employee_bouns, employee_overtime,
		taxes,employee_late, employee_absence, employee_deduction;
	bool statu_in,locked;
public:

	employee(string emp_name, string emp_email, string emp_pass, float emp_salary,int company_id);
	string get_name();
	string get_email();
	string get_pass();
	string get_role();
	int get_id();
	string get_num();

	float get_taxes();
	void set_taxes(float _taxes);

	bool get_statu();
	void set_statu(const bool& statu);

	bool get_locked();
	void set_locked(const bool& _locked);

	void set_name(const string& new_name);
	void set_pass(const string& new_pass);
	void set_role(const string& new_role);
	void set_num(const string& new_num);

	float get_leavenum();
	float get_attendance();
	float get_borrowing();
	float get_salary();
	float get_bouns();
	float get_overtime();
	float get_absence();
	float get_deduction();

	void set_leavenum(float new_leave);
	void set_attendance(float new_att);
	void set_borrowing(float new_borr);
	void set_salary(float new_salary);
	void set_bouns(float new_bouns);
	void set_overtime(float new_overtime);
	void set_absence(float new_abs);
	void set_deduction(float new_deduction);

};