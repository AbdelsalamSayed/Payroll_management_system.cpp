#include "../pages.H/system_admin.h"


void edit_com_page(employee& current_user) {

	string found;
	main_ui("Edit Company", 3,roles[0]);
	string functions, Cname;
	string space = string(28, ' ');
	double Cid = 0;
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

		if (functions == "esc") { system_admin_pages(current_user); }
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
		else if ((functions == "up" || functions == "tab") && position == 2) {
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
		if (functions == "enter") {
			main_ui("Edit Company", 3,roles[0]);
			move(11, 10);
			fcolor(main_font_color);
			cout << space;
			do {
				if (position == 1) {
					Cname = "";
					bcolor(main_back_color);
					fcolor(main_font_color);
					move(8, centerS(((string)"Enter company name")));
					cout << "Enter company name";
					fcolor(main_boxborder_color);
					bcolor(main_boxback_color);
					move(10, centerN(30));
					Dframe(1, 30);
					move(11, 10);
					fcolor(main_font_color);
					write_frame(28, normal, Cname, functions);
					transform(Cname.begin(), Cname.end(), Cname.begin(), toupper);
					if (functions == "esc") { edit_com_page(current_user); }
					if (functions == "enter") {
						if (sys.search_company_name(Cname) != -1) {
							found = "name";
							Cid = sys.get_company_id(Cname);
						}
					}
				}
				if (position == 2) {
					Cid = 0;
					bcolor(main_back_color);
					fcolor(main_font_color);
					move(8, centerS(((string)"Enter company ID")));
					cout << "Enter company ID";
					fcolor(main_boxborder_color);
					bcolor(main_boxback_color);
					move(10, centerN(30));
					Dframe(1, 30);
					move(11, 10);
					fcolor(main_font_color);
					id_write(28, Cid, functions);
					if (functions == "esc") { edit_com_page(current_user); }
					if (functions == "enter") {
						if (sys.search_company_id(Cid) != -1) {
							found = "id";
							Cname = sys.get_company_name(sys.get_company_id(sys.get_company_name(Cid)));
						}
					}
					else {
						move(11, 10);
						fcolor(main_font_color);
						cout << space;
						moveL(28);
						write_frame(28, notinput, Cname, functions);
						continue;
					}
				}
				if (found == "id" || found == "name") {
					main_ui("Edit Company", 3,roles[0]);
					position = 0;
					do {
						if (functions == "esc") { edit_com_page(current_user); }
						if (position == 0 || ((functions == "up" || functions == "tab") && (position == 2 || position == 4))) {

							bcolor(main_back_color);
							green(font);

							if (found == "name") {
								domain = "Company domain ---> " + sys.get_company_by_id(sys.get_company_id(Cname)).get_company_domain();
								move(7, centerS(domain));
								cout << domain;
								move(5, centerS((Cname + " Company")));
								cout << Cname + " Company";
							}
							else {
								domain = "Company domain ---> " + sys.get_company_by_id(Cid).get_company_domain();
								move(7, centerS(domain));
								cout << domain;
								Cname = sys.get_company_name(Cid);
								move(5, centerS((Cname + " Company")));
								cout << Cname + " Company";
							}
							move(22, centerS(((string)"Total Employees: " + to_string(sys.get_company_by_id(sys.get_company_id(Cname)).comp_emp_num()) + " Employee(s)")));
							cout << "Total Employees: " << sys.get_company_by_id(sys.get_company_id(Cname)).comp_emp_num() << " Employee(s)";
							move(9, 8);
							hoverd_button;
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(10, centerLN(9, 39, ((string)"Company name")));
							cout << "Company name";
							non_hoverd_button;
							move(13, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(14, centerLN(9, 39, ((string)"Add employee")));
							cout << "Add employee";
							non_hoverd_button;
							move(17, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(18, centerLN(9, 39, ((string)"Delete employee")));
							cout << "Delete employee";
							non_hoverd_button;
							position = 1;
							functions = "super_admin";

						}
						buttons(functions = "super_admin");
						if (((functions == "down" || functions == "tab") && position == 1) || ((functions == "up" || functions == "tab") && position == 3)) {
							move(9, 8);
							non_hoverd_button;
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(10, centerLN(9, 39, ((string)"Company name")));
							cout << "Company name";
							hoverd_button;
							move(13, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(14, centerLN(9, 39, ((string)"Add employee")));
							cout << "Add employee";
							non_hoverd_button;
							move(17, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(18, centerLN(9, 39, ((string)"Delete employee")));
							cout << "Delete employee";
							non_hoverd_button;
							if (position == 1) {
								position = 2;
							}
							else {
								position = 4;
							}
							functions = "super_admin";
						}
						else if (((functions == "down" || functions == "tab") && position == 2) || (functions == "down" && position == 4)) {
							move(9, 8);
							non_hoverd_button;
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(10, centerLN(9, 39, ((string)"Company name")));
							cout << "Company name";
							non_hoverd_button;
							move(13, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(14, centerLN(9, 39, ((string)"Add employee")));
							cout << "Add employee";
							hoverd_button;
							move(17, 8);
							Dframe(1, 30);
							fcolor(hoverd_font_color);
							move(18, centerLN(9, 39, ((string)"Delete employee")));
							cout << "Delete employee";
							non_hoverd_button;
							position = 3;
							functions = "super_admin";
						}

						if (functions == "enter" && position == 1) {
							main_ui("Edit Company", 3,roles[0]);
							string new_name;
							move(6, centerS(((string)"Current company name is " + Cname)));
							cout << "Current company name is " + Cname;
							draw_logo(8);
							bcolor(main_back_color);
							fcolor(main_font_color);
							move(15, centerS(((string)"Enter new company name")));
							cout << "Enter new company name";
							move(16, centerN(30));
							fcolor(main_boxborder_color);
							bcolor(main_boxback_color);
							Dframe(1, 30);
							fcolor(main_font_color);
							move(17, 10);
							write_frame(28, normal, new_name, functions);
							if (functions == "esc") { edit_com_page(current_user); }
							if (functions == "enter") {
								transform(new_name.begin(), new_name.end(), new_name.begin(), toupper);
								if (sys.search_company_name(new_name) == -1 && new_name.length() >= 4 && new_name.length() <= 16 && sys.get_company_by_id(sys.get_company_id(Cname)).get_company_name() != new_name && all_of(new_name.begin(), new_name.end(), isalnum) && !isdigit(new_name[0])) {
									sys.get_company_by_id(sys.get_company_id(Cname)).set_company_name(new_name);
									string error = "Company name updated successfully";
									move(20, 2);
									bcolor(main_back_color);
									string s = string(43, ' ');
									cout << s;
									move(20, centerS(error));
									green(font);
									cout << error;
									bcolor(main_boxback_color);
									fcolor(main_font_color);
									Sleep(2000);
									edit_com_page(current_user);
								}

								else {
									do {
										new_name = "";
										move(20, centerS(((string)"Company Name already exists.")));
										red(Bfont);
										bcolor(main_back_color);
										cout << "Company Name already exists.";
										fcolor(main_font_color);
										move(17, 10);
										bcolor(main_boxback_color);
										fcolor(main_font_color);
										cout << space;
										moveL(28);
										write_frame(28, normal, new_name, functions);
										if (functions == "esc") { edit_com_page(current_user); }
										transform(new_name.begin(), new_name.end(), new_name.begin(), toupper);
										if (sys.search_company_name(new_name) == -1 && new_name.length() >= 4 && all_of(new_name.begin(), new_name.end(), isalnum) && !isdigit(new_name[0])) {
											sys.get_company_by_id(sys.get_company_id(Cname)).set_company_name(new_name);
											string error = "Company name updated successfully";
											move(20, 2);
											bcolor(main_back_color);
											string s = string(43, ' ');
											cout << s;
											move(20, centerS(error));
											green(font);
											cout << error;
											bcolor(main_boxback_color);
											fcolor(main_font_color);
											Sleep(2000);
											edit_com_page(current_user);
											break;
										}

									} while (true);

								}
							}

						}
						else if (functions == "enter" && (position == 2 || position == 4)) {
							add_emp_page(Cname, current_user);


						}
						else if (functions == "enter" && position == 3) {
							delete_emp_page(Cname, current_user);


						}
					}while (true);
				}
				else {
					move(14, centerS(((string)"Company Name not found.")));
					red(Bfont);
					bcolor(main_back_color);
					cout << "Company Name not found.";
					fcolor(main_font_color);
					}

			} while (true);
		}
	}while (true);
}
void Admin_edit_com_page(employee& current_user) {

	string found;
	main_ui("Edit Company", 2, roles[1]);
	string functions, Cname = current_user.get_comp_name();
	string space = string(28, ' ');
	double Cid = 0;
	int position = 0;
	company& current_comp = sys.get_company_by_id(sys.get_company_id(current_user.get_comp_name()));
	do {
		if (functions == "esc") { admins_page(current_user); }
		if (position == 0 || ((functions == "up" || functions == "tab") && (position == 2 || position == 4))) {

			bcolor(main_back_color);
			green(font);


			domain = "Company domain ---> " + current_comp.get_company_domain();
			move(7, centerS(domain));
			cout << domain;
			move(5, centerS((Cname + " Company")));
			cout << Cname + " Company";

			move(22, centerS(((string)"Total Employees: " + to_string(current_comp.comp_emp_num()) + " Employee(s)")));
			cout << "Total Employees: " << current_comp.comp_emp_num() << " Employee(s)";
			move(9, 8);
			hoverd_button;
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(10, centerLN(9, 39, ((string)"Edit Employee")));
			cout << "Edit Employee";
			non_hoverd_button;
			move(13, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(14, centerLN(9, 39, ((string)"Add employee")));
			cout << "Add employee";
			non_hoverd_button;
			move(17, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(18, centerLN(9, 39, ((string)"Delete employee")));
			cout << "Delete employee";
			non_hoverd_button;
			position = 1;
			functions = "super_admin";

		}
		buttons(functions = "super_admin");
		if (((functions == "down" || functions == "tab") && position == 1) || ((functions == "up" || functions == "tab") && position == 3)) {
			move(9, 8);
			non_hoverd_button;
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(10, centerLN(9, 39, ((string)"Edit Employee")));
			cout << "Edit Employee";
			hoverd_button;
			move(13, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(14, centerLN(9, 39, ((string)"Add employee")));
			cout << "Add employee";
			non_hoverd_button;
			move(17, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(18, centerLN(9, 39, ((string)"Delete employee")));
			cout << "Delete employee";
			non_hoverd_button;
			if (position == 1) {
				position = 2;
			}
			else {
				position = 4;
			}
			functions = "super_admin";
		}
		else if (((functions == "down" || functions == "tab") && position == 2) || (functions == "down" && position == 4)) {
			move(9, 8);
			non_hoverd_button;
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(10, centerLN(9, 39, ((string)"Edit Employee")));
			cout << "Edit Employee";
			non_hoverd_button;
			move(13, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(14, centerLN(9, 39, ((string)"Add employee")));
			cout << "Add employee";
			hoverd_button;
			move(17, 8);
			Dframe(1, 30);
			fcolor(hoverd_font_color);
			move(18, centerLN(9, 39, ((string)"Delete employee")));
			cout << "Delete employee";
			non_hoverd_button;
			position = 3;
			functions = "super_admin";
		}

		if (functions == "enter" && position == 1) {
			main_ui("Edit Company", 3, roles[0]);
			

		}
		else if (functions == "enter" && (position == 2 || position == 4)) {
			add_emp_page(Cname, current_user);


		}
		else if (functions == "enter" && position == 3) {
			delete_emp_page(Cname, current_user);


		}
	} while (true);

}
