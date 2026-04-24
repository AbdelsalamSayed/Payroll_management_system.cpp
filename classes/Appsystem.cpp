#include "Appsystem.h"
bool Appsystem::get_system_online() { return system_online; }
void Appsystem::set_system_online(bool online) { 
	if (online == true) {
		for (int i = 0;i < Appsystem::get_comp_count();i++) {
			for (int j = 0;j < Appsystem::companylist[i].get_emp_count();j++) {
				Appsystem::companylist[i].get_emp(j).set_locked(false);
			}
		}
		system_online = online;
	}
	else {
		for (int i = 0;i < Appsystem::get_comp_count();i++) {
			for (int j = 0;j < Appsystem::companylist[i].get_emp_count();j++) {
				if (Appsystem::companylist[i].get_emp(j).get_role()!=roles[0])
				Appsystem::companylist[i].get_emp(j).set_locked(true);
			}
		}
		system_online = online;
	}
	
}

void Appsystem::add_comp(string company_name) {
	transform(company_name.begin(), company_name.end(), company_name.begin(), tolower);
	string company_domain = "@"+company_name + ".com";
	transform(company_name.begin(), company_name.end(), company_name.begin(), toupper);
	company new_company = company(company_name, company_domain);
	companylist.push_back(new_company);
}

int Appsystem::current_user_id(string email) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		for (int j = 0;j < Appsystem::companylist[i].get_emp_count();j++) {
			if (Appsystem::companylist[i].get_emp(j).get_email() == email) {
				return Appsystem::companylist[i].get_emp(j).get_id();
			}
		}
	}
	return -1;
}

int Appsystem::get_comp_count() { return (int)Appsystem::companylist.size(); }

void Appsystem::delete_comp(string company_name) {
	int index = get_company_id(company_name);
	if (index != -1) {
		Appsystem::companylist.erase(Appsystem::companylist.begin() + index);
	}
}
string Appsystem::get_company_name(int company_id) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_id() == company_id) {
			return companylist[i].get_company_name();
		}
	}
	return "!!";
}

company& Appsystem::get_company_by_id(int id) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_id() == id) {
			return companylist[i];
		}
	}
	throw runtime_error("Company with ID " + to_string(id) + " not found.");
}

employee& Appsystem::get_employee_by_email(string email) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		for (int j = 0;j < Appsystem::companylist[i].get_emp_count();j++) {
			if (Appsystem::companylist[i].get_emp(j).get_email() == email) {
				return Appsystem::companylist[i].get_emp(j);
			}
		}
	}
	throw runtime_error("Employee with email " + email + " not found.");
}

int Appsystem::get_emps_count() {
	int count = 0;
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		count += Appsystem::companylist[i].get_emp_count();
	}
	return count;
}


int Appsystem::search_company_id(int id){
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_id() == id) {
			return i;
		}
	}
	return -1;
}



int Appsystem::search_company_name(string name){
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_name() == name) {
			return i;
		}
	}
	return -1;
}


int Appsystem::get_company_id(string company_name) {
	for (int i = 0;i < Appsystem::get_comp_count();i++) {
		if (Appsystem::companylist[i].get_company_name() == company_name) {
			return companylist[i].get_company_id();
		}
	}
	return -1;
}



