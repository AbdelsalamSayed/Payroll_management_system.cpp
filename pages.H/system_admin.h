#pragma once

#include "../Main_H.h"
#include "../UI/Head.h"

void system_admin_home_ui();
void system_admin_addcompany_ui();
void system_admin_pages(employee& current_user);
void super_setting_ui(employee& current_user);
void delete_emp_page(string company_name, employee& current_user);
void main_ui(string page, int i);
void add_comp_page(employee& current_user);
void edit_com_page(employee& current_user);
void super_setting_page(employee& current_user);
void add_emp_page(string company_name, employee& current_user);
void delete_emp_page(string company_name, employee& current_user);
void change_sys_status(employee& current_user);
void change_pass_page(employee& current_user);