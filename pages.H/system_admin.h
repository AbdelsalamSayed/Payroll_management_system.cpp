#pragma once

#include "../Main_H.h"
#include "../UI/Head.h"

void system_admin_home_ui();
void system_admin_addcompany_ui();
void system_admin_pages(employee& current_user);

void delete_emp_page(string company_name, employee& current_user);
void system_admin_ui(string page, int i, string role);
void admin_ui(string page, int i, string role);
void staff_ui(string page, int i,employee& current_user);
void add_comp_page(employee& current_user);
void edit_com_page(employee& current_user);
void Admin_edit_com_page(employee& current_user);
void super_setting_ui(employee& current_user);
void add_emp_page(string company_name, employee& _current_user);
void delete_emp_page(string company_name, employee& current_user);
void change_sys_status(employee& current_user);
void change_pass_page(employee& current_user);
void admins_page(employee& current_user);
void staff_page(employee& current_user);