#include "system_admin.h"

void system_admin_pages() {
	system_admin_home_ui();
	position = 1;
	string functions = "start";
	do {
		hideC;
		buttons(functions = "super_admin");
		if (functions != "enter") {
			if (position == 1)
			{
				if (functions == "right" || functions == "tab") {
					position = 2;
					footer(roles[0], position);
				}
			}
			else if (position == 2)
			{
				if (functions == "right" || functions == "tab") {
					position = 3;
					footer(roles[0], position);
				}
				else if (functions == "left") {
					position = 1;
					footer(roles[0], position);
				}
			}
			else if (position == 3)
			{
				if (functions == "right" || functions == "tab") {
					position = 4;
					footer(roles[0], position);
				}
				else if (functions == "left") {
					position = 2;
					footer(roles[0], position);
				}
			}
			else if (position == 4)
			{
				if (functions == "left" || functions == "tab") {
					position = 5;
					footer(roles[0], 3);
				}
			}
			else if (position == 5)
			{
				if (functions == "left" || functions == "tab") {
					position = 6;
					footer(roles[0], 2);
				}
				else if (functions == "right") {
					position = 4;
					footer(roles[0], position);
				}
			}
			else if (position == 6)
			{
				if (functions == "left" || functions == "tab") {
					position = 1;
					footer(roles[0], position);
				}
				else if (functions == "right") {
					position = 3;
					footer(roles[0], position);
				}
			}
		}
		else {
			if (position == 1) {
				system_admin_home_ui();
			}
			else if (position == 2 || position == 6) {
				add_comp_page();break;

			}
		}
	} while (true);

	
}


void add_comp_page() {
	string comp_name, comp_domain,functions;
	system_admin_addcompany_ui();
	bcolor(main_boxback_color);
	
	move(17, centerLN(4, 43, (to_string(sys.get_comp_count()))));
	cout << sys.get_comp_count() + 1;
	do {
		move(7, 5);
		bcolor(main_boxback_color);
		fcolor(main_font_color);
		write_frame(37, normal, comp_name, functions);
		if (functions == "tab") { break; }
		else if (functions == "enter") { 
			
			if (sys.get_company_id(comp_name) == -1) {
				comp_domain = "@" + comp_name + ".com";
				move(12, 5);
				fcolor(main_boxborder_color);
				cout << comp_domain;
				sys.add_comp(comp_name, comp_domain);
		}
		}
	} while (true);
	



}
void edit_com_page() {

}
void super_setting_page() {

}
