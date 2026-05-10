#include "Appsystem.h"



bool Appsystem::get_system_online() const { return system_online; }

void Appsystem::set_system_online(bool online) { 
	if (online) {
		for (int i = 0; i < get_comp_count(); i++) {
			for (int j = 0; j < companylist[i].get_emp_count(); j++) {
				companylist[i].get_emp(j).set_locked(false);
			}
		}
	} else {
		for (int i = 0; i < get_comp_count(); i++) {
			for (int j = 0; j < companylist[i].get_emp_count(); j++) {
				if (companylist[i].get_emp(j).get_role() != roles[0]) {
					companylist[i].get_emp(j).set_locked(true);
				}
			}
		}
	}
	system_online = online;
}

void Appsystem::add_comp(string company_name) {
	transform(company_name.begin(), company_name.end(), company_name.begin(), tolower);
	string company_domain = "@" + company_name + ".com";
	transform(company_name.begin(), company_name.end(), company_name.begin(), toupper);
	company new_company(company_name, company_domain);
	companylist.push_back(new_company);
}

int Appsystem::current_user_id(const string& email) const {
	for (int i = 0; i < get_comp_count(); i++) {
		for (int j = 0; j < companylist[i].get_emp_count(); j++) {
			company& comp = const_cast<company&>(companylist[i]);
			if (comp.get_emp(j).get_email() == email) {
				return comp.get_emp(j).get_id();
			}
		}
	}
	return -1;
}

int Appsystem::get_comp_count() const { return (int)companylist.size(); }

void Appsystem::delete_comp(const string& company_name) {
	int index = get_company_id(company_name);
	if (index != -1) {
		companylist.erase(companylist.begin() + index);
	}
}

string Appsystem::get_company_name(int company_id) const {
	for (int i = 0; i < get_comp_count(); i++) {
		company& comp = const_cast<company&>(companylist[i]);
		if (comp.get_company_id() == company_id) {
			return comp.get_company_name();
		}
	}
	return "!!";
}

company& Appsystem::get_company_by_id(int id) {
	for (int i = 0; i < get_comp_count(); i++) {
		if (companylist[i].get_company_id() == id) {
			return companylist[i];
		}
	}
	throw runtime_error("Company with ID " + to_string(id) + " not found.");
}

employee& Appsystem::get_employee_by_email(const string& email) {
	for (int i = 0; i < get_comp_count(); i++) {
		for (int j = 0; j < companylist[i].get_emp_count(); j++) {
			if (companylist[i].get_emp(j).get_email() == email) {
				return companylist[i].get_emp(j);
			}
		}
	}
	throw runtime_error("Employee with email " + email + " not found.");
}

int Appsystem::get_emps_count() const {
	int count = 0;
	company& comp = const_cast<company&>(companylist[0]);
	for (int i = 0; i < get_comp_count(); i++) {
		company& iterComp = const_cast<company&>(companylist[i]);
		count += iterComp.get_emp_count();
	}
	return count;
}

int Appsystem::search_company_id(int id) const {
	for (int i = 0; i < get_comp_count(); i++) {
		company& comp = const_cast<company&>(companylist[i]);
		if (comp.get_company_id() == id) {
			return i;
		}
	}
	return -1;
}

int Appsystem::search_company_name(const string& name) const {
	for (int i = 0; i < get_comp_count(); i++) {
		company& comp = const_cast<company&>(companylist[i]);
		if (comp.get_company_name() == name) {
			return i;
		}
	}
	return -1;
}

int Appsystem::get_company_id(const string& company_name) const {
	for (int i = 0; i < get_comp_count(); i++) {
		company& comp = const_cast<company&>(companylist[i]);
		if (comp.get_company_name() == company_name) {
			return comp.get_company_id();
		}
	}
	return -1;
}





void save_token(employee& emp) {
	ofstream token_file("Ztoken.txt", ios::out);
	if (token_file.is_open()) {
		token_file << emp.get_email() << endl;
		token_file << emp.get_pass() << endl;
		token_file.close();
	}
	else {
		cerr << "Unable to open token file for writing." << endl;
	}
}

void clear_token() {
	ofstream token_file("Ztoken.txt", ios::out | ios::trunc);
	if (token_file.is_open()) {
		token_file.close();
	}
	else {
		cerr << "Unable to open token file for clearing." << endl;
	}
}


void save_data() {
	ofstream file("Zdata.txt", ios::out);
	if (file.is_open()) {
		for (int i = 0;i < sys.get_comp_count();i++) {
			company comp = sys.get_company_by_id(i+1);
			file << "New_Company" << endl;
			file << comp.get_company_name() << endl;
			for (int j = 0;j < comp.comp_emp_num();j++) {
				employee  emp = comp.get_emp(j);
				file << emp.get_comp_name() << ",";
				file << emp.get_name() << ",";
				file << emp.get_email() << ",";
				file << emp.get_id() << ",";
				file << emp.get_num() << ",";
				file << emp.get_pass() << ",";
				file << emp.get_role() << ",";
				file << emp.get_salary() << ",";
				file << emp.get_overtime() << ",";
				file << emp.get_statu() << ",";
				file << emp.get_taxes() << ",";
				file << emp.get_absence() << ",";
				file << emp.get_attendance() << ",";
				file << emp.get_borrowing() << ",";
				file << emp.get_bouns() << ",";
				file << emp.get_deduction() << ",";
				file << emp.get_late() << ",";
				file << emp.get_leavenum() << ",";
				file << emp.get_locked() << ",";
				file << emp.get_time_in() << ",";
				file << emp.get_net_salary() << endl;

			}
			
		}
	}
	else {
		cerr << "Unable to open data file for writing." << endl;
	}
}

void get_data() {
	ifstream file("Zdata.txt");
	string line,current_company="";
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.empty() || line == "New_Company") {
				current_company = "";
				continue;
				
			}
			if (current_company == "") {
				current_company= line;
				sys.add_comp(current_company);
				

			}
			else {
				stringstream ss(line);
				string comp_name, emp_name, emp_email, emp_id_str, emp_num, emp_pass, emp_role, emp_salary_str, emp_overtime_str, emp_statu_str, emp_taxes_str, emp_absence_str, emp_attendance_str, emp_borrowing_str, emp_bouns_str, emp_deduction_str, emp_late_str, emp_leavenum_str, emp_locked_str, emp_time_in_str, emp_net_salary_str;
				getline(ss, comp_name, ',');
				getline(ss, emp_name, ',');
				getline(ss, emp_email, ',');
				getline(ss, emp_id_str, ',');
				getline(ss, emp_num, ',');
				getline(ss, emp_pass, ',');
				getline(ss, emp_role, ',');
				getline(ss, emp_salary_str, ',');
				getline(ss, emp_overtime_str, ',');
				getline(ss, emp_statu_str, ',');
				getline(ss, emp_taxes_str, ',');
				getline(ss, emp_absence_str, ',');
				getline(ss, emp_attendance_str, ',');
				getline(ss, emp_borrowing_str, ',');
				getline(ss, emp_bouns_str, ',');
				getline(ss, emp_deduction_str, ',');
				getline(ss, emp_late_str, ',');
				getline(ss, emp_leavenum_str, ',');
				getline(ss, emp_locked_str, ',');
				getline(ss, emp_time_in_str, ',');
				getline(ss, emp_net_salary_str);
				double salary = stod(emp_salary_str);
				double overtime = stod(emp_overtime_str);
				bool statu = (emp_statu_str == "1");
				float taxes = stof(emp_taxes_str);
				float absence = stof(emp_absence_str);
				float attendance = stof(emp_attendance_str);
				double borrowing = stod(emp_borrowing_str);
				double bouns = stod(emp_bouns_str);
				double deduction = stod(emp_deduction_str);
				float late = stof(emp_late_str);
				float leavenum = stof(emp_leavenum_str);
				bool locked = (emp_locked_str == "1");
				long long time_in = stoll(emp_time_in_str);

				sys.get_company_by_id(sys.get_company_id(comp_name)).add_emp(emp_name, emp_email, emp_pass, salary, comp_name);
				employee& emp = sys.get_company_by_id(sys.get_company_id(comp_name)).get_employee_by_email(emp_email);
				emp.set_overtime(overtime);
				emp.set_statu(statu);
				emp.set_taxes(taxes);
				emp.set_absence(absence);
				emp.set_attendance(attendance);
				emp.set_borrowing(borrowing);
				emp.set_bouns(bouns);
				emp.set_deduction(deduction);
				emp.set_late(late);
				emp.set_leavenum(leavenum);
				emp.set_locked(locked);
				emp.set_num(emp_num);
				emp.set_role(emp_role);
				emp.set_time_in(time_in);
				
				
			}

		}
	}
	else {
		cerr << "Unable to open data file for writing." << endl;
	}
}


void export_report(employee& current_user) {
	ofstream file("zreport.txt", ios::out);
	if (file.is_open()) {
		if (current_user.get_role() == roles[2]) {
			string space = string(50, '=');
			file << "Employee Report" << endl;
			file << "company: " << current_user.get_comp_name() << endl;
			file << space << endl;
			file << current_user.get_name() << " | " << current_user.get_email() << " | " << current_user.get_id() << " | " << current_user.get_num() << " | " << endl;
			file << space << endl;
			file << "Company: " << current_user.get_comp_name() << endl;
			file << "Salary: " << current_user.get_salary() << endl;
			file << "Attendance: " << current_user.get_attendance() << "  -->  "<< current_user.get_attendance() * ((current_user.get_salary() / 30.0) / 8.0) << endl;
			file << "Overtime: " << current_user.get_overtime() <<"  -->  "<< current_user.get_overtime()/60.0*( current_user.get_salary()/160.0) << endl;
			file << "Taxes: " << current_user.get_taxes() << endl;
			file << "Bounes: " << current_user.get_bouns() << endl;
			file << "Deduction: " << current_user.get_deduction() << endl;
			file << "Leave: " << current_user.get_leavenum() << "  -->  " << current_user.get_leavenum() * (current_user.get_salary() / 30.0) << endl;
			file << "Borrowing: " << current_user.get_borrowing() << endl;
			file << "Net Salary: " << current_user.get_net_salary() << endl;
			file << space << endl;
		}
		else {
			string space = string(50, '=');
			file << "Company Report" << endl;
			file << "company: " << current_user.get_comp_name() << endl;
			file << space << endl;
			for (int i = 0; i < sys.get_company_by_id(sys.get_company_id(current_user.get_comp_name())).comp_emp_num(); i++) {
				employee& emp = sys.get_company_by_id(sys.get_company_id(current_user.get_comp_name())).get_emp(i);
				file << emp.get_name() << " | " << emp.get_email() << " | " << emp.get_id() << " | " << emp.get_num() << " | " << emp.get_role() << endl;
				file << space << endl;
				file << "Salary: " << emp.get_salary() << endl;
				file << "Attendance: " << emp.get_attendance() << "  -->  " << emp.get_attendance() * ((emp.get_salary() / 30) / 8) << endl;
				file << "Overtime: " << emp.get_overtime() <<"  -->  "<< emp.get_overtime()/60.0*( emp.get_salary() / 160.0)<< endl;
				file << "Taxes: " << emp.get_taxes() << endl;
				file << "Bounes: " << emp.get_bouns() << endl;
				file << "Deduction: " << emp.get_deduction() << endl;
				file << "Leave: " << emp.get_leavenum() << "  -->  " << emp.get_leavenum() * (emp.get_salary() / 30.0) << endl;
				file << "Borrowing: " << emp.get_borrowing() << endl;
				file << "Net Salary: " << emp.get_net_salary() << endl;
				file << space << endl;
			}
			company& current_comp = sys.get_company_by_id(sys.get_company_id(current_user.get_comp_name()));
			file<< "Total Company Gross Salaries    --->  " << current_comp.get_total_salary() << endl;
			file<< "Total Company Net Salaries    --->  " << current_comp.get_total_net_salary() << endl;

		}
	}
	else {
		cerr << "Unable to open report file for writing." << endl;
	}

}

