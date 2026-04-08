#include "company.h"
#include "../draw.h"

company::company(string _company_name, string _company_domain) {
	last_comp_id++;
	company_name = _company_name;
	company_domain = _company_domain;
	company_id = last_comp_id;
}


string company::get_company_name() { return company_name; }
int company::get_company_id() { return company_id; }



