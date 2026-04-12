#pragma once
#include "../Main_H.h"




class company
{
	inline static int last_comp_id = 0;
	string company_name;
	int company_id;
	string company_domain;



public:

	company(string _company_name, string _company_domaine);

	string get_company_name();
	string get_company_domain();
	int get_company_id();

	void set_company_name(string name);
	void set_company_id(int id);
	void set_company_domain(string domain);

};