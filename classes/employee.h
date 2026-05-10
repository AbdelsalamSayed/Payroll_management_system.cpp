#pragma once
#include "../Main_H.h"

class employee {
private:
	int employee_id;
	string employee_name;
	string employee_email;
	string employee_password;
	string employee_role;
	string employee_num;
	string comp_name;

	float hours;
	double employee_salary;
	float employee_leave;
	float employee_attendance;
	double employee_borrowing;
	double employee_bouns;
	double employee_overtime;
	float taxes;
	float employee_late;
	float employee_absence;
	double employee_deduction;
	double employee_net_salary;

	bool statu_in;
	bool locked;

	long long time_in;

public:
	employee(const string& emp_name, const string& emp_email, const string& emp_pass, double emp_salary, const string& _comp_name);

	// Getters
	string get_name() const;
	string get_email() const;
	string get_pass() const;
	string get_role() const;
	string get_num() const;
	string get_comp_name() const;
	int get_id() const;

	float get_taxes() const;
	bool get_statu() const;
	bool get_locked() const;

	float get_leavenum() const;
	float get_attendance() const;
	double get_borrowing() const;
	double get_salary() const;
	double get_bouns() const;
	double get_overtime() const;
	float get_absence() const;
	double get_deduction() const;
	double get_net_salary() const;
	float get_late() const;

	// Setters
	void set_taxes(float _taxes);
	void set_statu(bool statu);
	void set_locked(bool _locked);

	void set_name(const string& new_name);
	void set_pass(const string& new_pass);
	void set_role(const string& new_role);
	void set_num(const string& new_num);

	void set_leavenum(float new_leave);
	void set_attendance(float new_att);
	void set_borrowing(float new_borr);
	void set_salary(double new_salary);
	void set_bouns(double new_bouns);
	void set_overtime(double new_overtime);
	void set_absence(float new_abs);
	void set_deduction(double new_deduction);
	void set_late(float new_late);
	void set_comp_name(const string& new_comp_name);

	long long get_time_in() const;
	void set_time_in(long long time);
	void check_in(long long time);
	long long check_out();
};