#pragma once
#include "../Main_H.h"
#include "company.h"
#include "../program.h"



class Appsystem {
private:
	bool system_online = true;
	vector<company> companylist;

public:
	int get_emps_count() const;
	int current_user_id(const string& email) const;
	bool get_system_online() const;
	int get_comp_count() const;
	int get_company_id(const string& company_name) const;
	string get_company_name(int id) const;
	int search_company_id(int id) const;
	int search_company_name(const string& name) const;

	void set_system_online(bool online);
	void add_comp(string company_name);
	void delete_comp(const string& company_name);

	employee& get_employee_by_email(const string& email);
	company& get_company_by_id(int id);
};

inline Appsystem sys;


void save_token(employee& emp);
void clear_token();
void save_data();
void get_data();
void export_report(employee& current_user);