#include "../pages.H/system_admin.h"

void system_admin_pages(employee& current_user) {
	system_admin_home_ui();
	position = 1;
	string functions = "start";
	do {
		hideC;
		buttons(functions = "main");
		if (functions == "esc") {
			logout_msg();
			position = 1;
			system_admin_pages(current_user);
		}
		else if (functions != "enter") {
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
				system_admin_pages(current_user);
				break;
			}
			else if (position == 2 || position == 6) {
				add_comp_page(current_user);
				break;

			}
			else if (position == 3 || position == 5) {
				edit_com_page(current_user);
				break;

			}
			else if (position == 4) {
				super_setting_ui(current_user);
				
				break;

			}
		}
	} while (true);

	
}


void add_comp_page(employee& current_user) {
	position = 0;
	string functions = "start",comp_name, comp_domain;
	system_admin_addcompany_ui();
	bcolor(main_boxback_color);

	move(17, centerLN(4, 43, (to_string(sys.get_comp_count()))));
	cout << sys.get_comp_count() + 1;
	int x = 0;
	string tab = "tab";
	string enter = "enter";
	
	do {
		bcolor(main_boxback_color);
		fcolor(main_font_color);
		
		if (functions == "start") {
			comp_name = ""; comp_domain = "";
			move(7, 5);
			do {
				write_frame(37, normal, comp_name, functions);
			} while (functions != "tab" && functions != "enter" && functions != "down" && functions != "esc");
		}
		if (functions == "esc") { system_admin_pages(current_user); }
		if (comp_name.empty()) { functions = "start"; continue; }
		transform(comp_name.begin(), comp_name.end(), comp_name.begin(), tolower);
		if (sys.get_company_id(comp_name) == -1) {

			if (comp_name.length() >= 4 && all_of(comp_name.begin(), comp_name.end(), [](char c) {return isalnum(c) || c == '_';}) && !isdigit(comp_name[0])) {
				
				if (x==0) {
					comp_domain = "@" + comp_name + ".com";
					move(12, 5);
					fcolor(main_boxborder_color);
					domain_write(37, comp_domain);
					move(7, 5);
					fcolor(main_font_color);
					domain_write(37, comp_name);
					hoverd_button;
					move(22, 3);
					Dframe(1, 15);
					fcolor(hoverd_font_color);
					move(23, centerLN(4, 19, ((string)"Add")));
					cout << "Add";
					non_hoverd_button;
					move(22, 27);
					Dframe(1, 15);
					fcolor(button_font_color);
					move(23, centerLN(28, 42, ((string)"Cancel")));
					cout << "Cancel";
					position = 1;
					x = 1;
					
				}
				buttons(functions = "main");
				if ((functions == "tab"||functions == "right") && position == 1) {
					fcolor(main_font_color);
					bcolor(main_boxback_color);
					move(7, 5);
					domain_write(37, comp_name);
					non_hoverd_button;
					move(22, 3);
					Dframe(1, 15);
					fcolor(button_font_color);
					move(23, centerLN(4, 19, ((string)"Add")));
					cout << "Add";
					hoverd_button;
					move(22, 27);
					Dframe(1, 15);
					fcolor(hoverd_font_color);
					move(23, centerLN(28, 42, ((string)"Cancel")));
					cout << "Cancel";
					position = 2;
					
				}
				else if ((functions == "tab" || functions == "left") && position == 2) {
					hoverd_button;
					move(22, 3);
					Dframe(1, 15);
					fcolor(hoverd_font_color);
					move(23, centerLN(4, 19, ((string)"Add")));
					cout << "Add";
					non_hoverd_button;
					move(22, 27);
					Dframe(1, 15);
					fcolor(button_font_color);
					move(23, centerLN(28, 42, ((string)"Cancel")));
					cout << "Cancel";
					position = 1;
					
				}
				if (functions == "enter" && position == 2) {
					save_data();
					system_admin_pages(current_user);
				}
				if (functions == "enter" && position == 1) {
					sys.add_comp(comp_name);
					string error = "Company added successfully";
					move(19, 2);
					bcolor(main_back_color);
					string s = string(43, ' ');
					cout << s;
					move(19, centerS(error));
					green(font);
					cout << error;
					bcolor(main_boxback_color);
					fcolor(main_font_color);
					save_data();
					Sleep(2000);
					system_admin_pages(current_user);
				}
				
			}
			else {
				string error = "Please enter  valid company name.";
				move(7, 5);
				string spaces = string(37, ' ');
				cout << spaces;
				moveL(37);
				move(19, centerS(error));
				red(Bfont);
				bcolor(main_back_color);
				cout << error;
				bcolor(main_boxback_color);
				fcolor(main_font_color);
				functions = "start";
			}
		
		}
		else {
			string error = "This name company already exists.";
			move(7, 5);
			string spaces = string(37, ' ');
			cout << spaces;
			moveL(37);
			move(19, centerS(error));
			red(Bfont);
			bcolor(main_back_color);
			cout << error;
			bcolor(main_boxback_color);
			fcolor(main_font_color);
			functions = "start";
		}

		

	} while (true);



}

