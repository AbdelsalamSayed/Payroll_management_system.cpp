#include "../pages.H/system_admin.h"

void system_admin_pages() {
	system_admin_home_ui();
	position = 1;
	string functions = "start";
	do {
		hideC;
		buttons(functions = "super_admin");
		if (functions == "esc") {
			position = 1;
			move(11, centerN(21));
			white(back);
			red(font);
			Dframe(8, 21);
			string error = "Do you want to Logout";
			move(13,centerLN(13, 33, error));
			black(font);
			cout << "\a" << error;
			move(16, centerN(5));
			moveR(6);
			Dframe(1, 5);
			move(17, centerN(5));
			moveR(8);
			cout << "No";
			move(16, centerN(5));
			moveL(6);
			red(back);
			Dframe(1, 5);
			move(17, centerN(5));
			moveL(4);
			cout << "Yes";
			white(back);
			do {
				buttons(functions = "super_admin");
				if ((functions == "right" || functions == "tab") && position == 1) {
					white(back);
					move(16, centerN(5));
					moveL(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					red(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					position = 2;
					white(back);
				}
				if ((functions == "left" || functions == "tab") && position == 2) {
					white(back);
					move(16, centerN(5));
					moveR(6);
					Dframe(1, 5);
					move(17, centerN(5));
					moveR(8);
					cout << "No";
					move(16, centerN(5));
					moveL(6);
					red(back);
					Dframe(1, 5);
					move(17, centerN(5));
					moveL(4);
					cout << "Yes";
					position = 1;
					white(back);
				}
				if (functions == "enter" && position == 1) {
					loginpage_ui();
					loginpage();
				}
				if (functions == "enter" && position == 2) {
					position = 1;
					system_admin_pages();
				}
			} while (true);
			
			

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
				system_admin_home_ui();
				break;
			}
			else if (position == 2 || position == 6) {
				add_comp_page();
				break;

			}
			else if (position == 3 || position == 5) {
				edit_com_page();
				break;

			}
			else if (position == 4) {
				super_setting_page();
				break;

			}
		}
	} while (true);

	
}


void add_comp_page() {
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
		if (functions == "esc") { system_admin_pages(); }
		if (comp_name.empty()) { functions = "start"; continue; }
		transform(comp_name.begin(), comp_name.end(), comp_name.begin(), toupper);
		if (sys.get_company_id(comp_name) == -1) {

			if (comp_name.length() >= 4 && all_of(comp_name.begin(), comp_name.end(), isalnum) && !isdigit(comp_name[0])) {
				
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
				buttons(functions = "super_admin");
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
				if ((functions == "tab" || functions == "left") && position == 2) {
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
					system_admin_pages();
				}
				if (functions == "enter" && position == 1) {
					sys.add_comp(comp_name,comp_domain);
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
					Sleep(2000);
					system_admin_pages();
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
			system_admin_pages();

		}





		

	} while (true);



}

void edit_com_page() {
	edit_comp_ui();
	string functions,Cname;
	int Cid=0;
	int position = 0;
	do {
		if (position == 0) {
			hoverd_button;
			move(10, 15);
			Dframe(1, 14);
			fcolor(hoverd_font_color);
			move(11, centerLN(17, 30, ((string)"Company  Name")));
			cout << "Company Name";
			non_hoverd_button;
			move(14, 15);
			Dframe(1, 14);
			fcolor(button_font_color);
			move(15, centerLN(16, 30, ((string)"Company ID")));
			cout << "Company ID";
			bcolor(main_back_color);
			fcolor(main_font_color);
			move(8, centerS(((string)"How to search by")));
			cout << "How to search by ?";
			
			position = 1;
		}
		buttons(functions = "super_admin");

		if (functions == "esc") { system_admin_pages(); }
		if ((functions == "down" || functions == "tab") && position == 1) {
			hoverd_button;
			move(14, 15);
			Dframe(1, 14);
			fcolor(hoverd_font_color);
			move(15, centerLN(16, 30, ((string)"Company ID")));
			cout << "Company ID";
			non_hoverd_button;
			move(10, 15);
			Dframe(1, 14);
			fcolor(button_font_color);
			move(11, centerLN(17, 30, ((string)"Company  Name")));
			cout << "Company Name";
			bcolor(main_back_color);
			fcolor(main_font_color);
			position = 2;
		}
		else if ((functions == "up"|| functions == "tab") && position == 2) {
			hoverd_button;
			move(10, 15);
			Dframe(1, 14);
			fcolor(hoverd_font_color);
			move(11, centerLN(17, 30, ((string)"Company  Name")));
			cout << "Company Name";
			non_hoverd_button;
			move(14, 15);
			Dframe(1, 14);
			fcolor(button_font_color);
			move(15, centerLN(16, 30, ((string)"Company ID")));
			cout << "Company ID";
			bcolor(main_back_color);
			fcolor(main_font_color);
			position = 1;
		}
		if (functions == "enter" && position == 1) {
			edit_comp_ui();
			do {
				Cname = "";
				string space = string(28, ' ');
				move(8, centerS(((string)"Enter company name")));
				cout << "Enter company name";
				fcolor(main_boxborder_color);
				bcolor(main_boxback_color);
				move(10, centerN(30));
				Dframe(1, 30);
				move(11, 10);
				fcolor(main_font_color);
				cout << space;
				moveL(28);
				write_frame(28, normal, Cname, functions);
				transform(Cname.begin(), Cname.end(), Cname.begin(), toupper);
				if (functions == "esc") { edit_com_page(); }
				if (functions == "enter") {
					if (sys.search_company_name(Cname) != -1) {
						edit_comp_ui();
						move(5, centerS(((string)"What do you want to edit ?")));
						cout << "What do you want to edit ?";
						move(7, 26);
						hoverd_button;
						Dframe(1, 17);
						fcolor(hoverd_font_color);
						move(8, centerLN(27, 44, ((string)"Company  name")));
						cout << "Company  name";
						bcolor(main_boxback_color);
						fcolor(main_font_color);
						move(8, 2);
						write_frame(22, notinput, Cname,functions);
						non_hoverd_button;
						move(12, 26);
						Dframe(1, 17);
						fcolor(hoverd_font_color);
						move(13, centerLN(27, 44, ((string)"Company  name")));
						cout << "Company  name";
						non_hoverd_button;

						
						
						move(9, 2);
						cout << "Add employee";
						cout << "     ->  ";
						
						move(11, 2);
						cout << "Delete employee";
						cout << "  ->  ";
						break;
					}
					else {
						move(14, centerS(((string)"Company Name not found.")));
						red(Bfont);
						bcolor(main_back_color);
						cout << "Company Name not foun.";
						fcolor(main_font_color);
					}
				}
			} while (true);
		}
		if (functions == "enter" && position == 2) {
			edit_comp_ui();
			do {
				string space = string(28, ' ');
				move(8, centerS(((string)"Enter company ID")));
				cout << "Enter company ID";
				move(10, centerN(30));
				fcolor(main_boxborder_color);
				bcolor(main_boxback_color);
				Dframe(1, 30);
				move(11, 10);
				fcolor(main_font_color);
				cout << space;
				moveL(28);
				id_write(28, Cid, functions);
				if (functions == "esc") { edit_com_page(); }
				if (functions == "enter") {
					if (sys.search_company_id(Cid) != -1) {
						edit_comp_ui();
					}
					else {
						move(14, centerS(((string)"Company ID not found.")));
						red(font);
						bcolor(main_back_color);
						cout << "Company ID not foun.";
						fcolor(main_font_color);
					}
				}
			} while (true);
		}
		
	} while (true);
}
void super_setting_page() {
	super_setting_ui();
}
