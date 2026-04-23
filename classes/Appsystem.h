#pragma once
#include "../Main_H.h"
#include "company.h"


class  Appsystem {

	bool system_online=true;
	vector<company> companylist;
	

public:
	int get_emps_count();
	int current_user_id(string email);
	bool get_system_online();
	void set_system_online(bool online);
	void add_comp(string company_name);
	int get_comp_count();
	int get_company_id(string company_name);
	string get_company_name(int id);
	int search_company_id(int id);
	int search_company_name(string name);
	void delete_comp(string company_name);
	employee& get_employee_by_email(string email);
	company& get_company_by_id(int id);
	
};

