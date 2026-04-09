#include "company.h"
#include "../Main_H.h"

company::company(string _company_name, string _company_domain) {
	last_comp_id++;
	company_name = _company_name;
	company_domain = _company_domain;
	company_id = last_comp_id;
}


string company::get_company_name() { return company_name; }
string company::get_company_domain() { return company_domain; }
int company::get_company_id() { return company_id; }


void company::set_company_name(string name) { company_name = name; }
void company::set_company_id(int id) { company_id = id; }
void company::set_company_domain(string domain) { company_domain = domain; }
