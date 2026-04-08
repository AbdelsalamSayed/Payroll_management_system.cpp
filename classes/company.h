#pragma once
#include "../draw.h"




class company
{
	inline static int last_comp_id = 1;
	string company_name;
	int company_id;
	string company_domain;



public:

	company(string _company_name, string _company_domaine);

	string get_company_name();
	int get_company_id();


};