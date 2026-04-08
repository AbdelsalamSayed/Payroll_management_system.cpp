#pragma once
#include "../draw.h"

class company
{
	string company_name;
	
public:
	company();
	company(string comp_name);

	string get_company_name();
	void set_company_name(string comp_name);
	class employee {
		static int last_id;
		int employee_id;
		string employee_name, employee_email, employee_password, employee_rank, employee_num;
		float employee_leave, employee_attendance, employee_borrowing, employee_salary, employee_bouns, employee_overtime, employee_late, employee_absence, employee_deduction;
		bool statu_in;
	public:
		employee();
		employee(string emp_name,string emp_email,string emp_pass,float emp_salary);
		string get_name();
		string get_email();
		string get_pass();
		string get_rank();
		int get_id();
		string get_num();

		bool get_statu();
		void set_statu(const bool& statu);

		void set_name(const string& new_name);
		void set_pass(const string& new_pass);
		void set_rank(const string& new_rank);
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
private:
	vector<employee> employeeslist;
public:
	void add_emp(string emp_name, string emp_email, string emp_pass, float emp_salary);
	int get_emp_count();
	int searchID(int id);
	int searchemail(string email);
	void delete_emp(int id);



};

