#include "../pages.H/system_admin.h"


void edit_com_page(employee& current_user) {

	string found;
	system_admin_ui("Edit Company", 3,roles[0]);
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
		buttons(functions = "main");

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
			system_admin_ui("Edit Company", 3,roles[0]);
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
						if (sys.search_company_id(static_cast<int>(Cid)) != -1) {
							found = "id";
							Cname = sys.get_company_name(sys.get_company_id(sys.get_company_name(static_cast<int>(Cid))));
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
					system_admin_ui("Edit Company", 3,roles[0]);
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
								domain = "Company domain ---> " + sys.get_company_by_id(static_cast<int>(Cid)).get_company_domain();
								move(7, centerS(domain));
								cout << domain;
								Cname = sys.get_company_name(static_cast<int>(Cid));
								move(5, centerS((Cname + " Company")));
								cout << Cname + " Company";
							}
							if (Cname.empty()) {
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
							else {
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
								move(14, centerLN(9, 39, ((string)"Add Employee")));
								cout << "Add Employee";
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

						}
						buttons(functions = "main");
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
							move(14, centerLN(9, 39, ((string)"Add Employee")));
							cout << "Add Employee";
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
							move(14, centerLN(9, 39, ((string)"Add Employee")));
							cout << "Add Employee";
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
							system_admin_ui("Edit Company", 3,roles[0]);
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
							do {
								write_frame(28, normal, new_name, functions);
							} while (functions != "enter" && functions != "esc");
							if (functions == "esc") { edit_com_page(current_user); }
							if (functions == "enter") {
								transform(new_name.begin(), new_name.end(), new_name.begin(), toupper);
								if (sys.search_company_name(new_name) == -1 && new_name.length() >= 4 && new_name.length() <= 16 && sys.get_company_by_id(sys.get_company_id(Cname)).get_company_name() != new_name && all_of(new_name.begin(), new_name.end(), isalnum) && !isdigit(new_name[0])) {
									sys.get_company_by_id(sys.get_company_id(Cname)).set_company_name(new_name);
									for (int i = 0; i < sys.get_company_by_id(sys.get_company_id(new_name)).comp_emp_num(); i++) {
										sys.get_company_by_id(sys.get_company_id(new_name)).get_emp(i).set_comp_name(new_name);

									}
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
									save_data();
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
											save_data();
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
	admin_ui("Edit Company", 2, roles[1]);
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
		buttons(functions = "main");
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
			admin_ui("Edit Company", 2, roles[1]);
			move(7, centerS(((string)"Enter employee ID to Edit")));
			cout << "Enter employee ID to Edit";
			move(9, centerN(32));
			double emp_id;
			fcolor(main_boxborder_color);
			bcolor(main_boxback_color);
			Dframe(1, 30);
			string functions = "start";
			do {
				string space = string(28, ' ');
				move(10, 9);
				bcolor(main_boxback_color);
				cout << space;
				move(10, 9);
				fcolor(main_font_color);
				id_write(28, emp_id, functions);
				if (functions == "esc" && current_user.get_role() == roles[0]) { edit_com_page(current_user); }
				else if (functions == "esc" && current_user.get_role() == roles[1]) { Admin_edit_com_page(current_user); }
				if (functions == "enter") {
					move(13, 1);
					string spaces = string(45, ' ');
					bcolor(main_back_color);
					
					cout << spaces;
					int emp_index = current_comp.search_emp_ID(static_cast<int>(emp_id));
					if (emp_index != -1) {
						position = 0;
						admin_ui("Edit Company", 2, roles[1]);
						fcolor(main_font_color);
						move(5, 1);
						cout << "Edit salary  <--";
						move(7, 1);
						cout << "Edit bouns";
						move(9, 1);
						cout << "Edit overtime";
						move(11, 1);
						cout << "Edit deduction";
						move(13, 1);
						cout << "Edit position";
						move(15, 1);
						cout << "Edit password";
						move(17, 1);
						cout << "Edit status";
						move(19, 1);
						cout << "Edit Number";
						move(20, centerS(((string)"Employee ID: " + to_string(current_comp.get_emp(emp_index).get_id()))));
						cout << "Employee ID: " << current_comp.get_emp(emp_index).get_id();
						move(22, centerS(((string)"Employee Name: " + current_comp.get_emp(emp_index).get_name())));
						cout << "Employee Name: " << current_comp.get_emp(emp_index).get_name();
						move(24, centerS(((string)"Employee Status: " + (current_comp.get_emp(emp_index).get_locked() ? "\033[31mLocked" : "\033[32mActive"))));
						cout << "   Employee Status: " << (current_comp.get_emp(emp_index).get_locked() ? "\033[31mLocked" : "\033[32mActive");
						fcolor(main_font_color);
						move(4, centerS(((string)"Employee : " + (current_comp.get_emp(emp_index).get_statu() ? "\033[32mIN" : "\033[31mOUT"))));
						cout << "   Employee : " << (current_comp.get_emp(emp_index).get_statu() ? "\033[32mIN" : "\033[31mOUT");
						fcolor(main_font_color);
						position = 1;
						do {
							
							buttons(functions = "main");
							if (functions == "esc") { Admin_edit_com_page(current_user); }
							if ((functions == "up" && (position == 14||position==2))) {
								
								move(5, 1);
								cout << "Edit salary  <--";
								move(7, 1);
								cout << space;
								move(7, 1);
								cout << "Edit bouns";
								position = 1;
							}
							else if ((functions =="down" && position == 1) || (functions == "up" && (position == 13||position ==3))) {
								
								move(5, 1);
								cout << space;
								move(5, 1);
								cout << "Edit salary";
								move(7, 1);
								cout << "Edit bouns  <--";
								move(9, 1);
								cout << space;
								move(9, 1);
								cout << "Edit overtime";
								if (position == 1) {
									position = 2;
								}
								else {
									position = 14;
								}
							}
							else if ((functions == "down"  && (position == 2||position == 14))||(functions == "up" && (position == 12||position ==4))) {
								
								move(7, 1);
								cout << space;
								move(7, 1);
								cout << "Edit bouns";
								move(9, 1);
								cout << "Edit overtime  <--";
								move(11, 1);
								cout << space;
								move(11, 1);
								cout << "Edit deduction";
								if (position == 2) {
									position = 3;
								}else {
									position = 13;
								}
							}
							else if (functions == "down"  && (position == 3|| position == 13)||(functions == "up" && (position == 11|| position == 5))) {
								
								move(9, 1);
								cout << space;
								move(9, 1);
								cout << "Edit overtime";
								move(11, 1);
								cout << "Edit deduction  <--";
								move(13, 1);
								cout << space;
								move(13, 1);
								cout << "Edit position";
								if (position == 3) {
									position = 4;
								}
								else {
									position = 12;
								}
								
							}
							else if ((functions == "down"  && (position == 4|| position == 12))||(functions == "up" && (position == 10||position ==6))) {
								
								move(11, 1);
								cout << space;
								move(11, 1);
								cout << "Edit deduction";
								move(13, 1);
								cout << "Edit position  <--";
								move(15, 1);
								cout << space;
								move(15, 1);
								cout << "Edit password";
								if (position == 4) {
									position = 5;
								}
								else {
									position = 11;
								}
							}
							else if ((functions == "down"  && (position == 5|| position == 11))||(functions == "up" && (position == 7||position == 9))) {
								
								move(13, 1);
								cout << space;
								move(13, 1);
								cout << "Edit position";
								move(15, 1);
								cout << "Edit password  <--";
								move(17, 1);
								cout << space;
								move(17, 1);
								cout << "Edit status";
								if (position == 5) {
									position = 6;
								}
								else {
									position = 10;
								}
							}
							else if ((functions == "down"  && (position == 6|| position == 10))||(functions == "up" && position == 8)) {
								
								
								move(15, 1);
								cout << space;
								move(15, 1);
								cout << "Edit password";
								move(17, 1);
								cout << "Edit status  <--";
								move(19, 1);
								cout << space;
								move(19, 1);
								cout << "Edit Number";
								if (position == 6) {
									position = 7;
								}
								else {
									position = 9;
								}
							}
							else if (functions == "down" && (position == 7||position == 9)) {
								move(17, 1);
								cout << space;
								move(17, 1);
								cout << "Edit status";
								move(19, 1);
								cout << "Edit Number  <--";
								position = 8;
							}

						
								if (functions == "enter") {
									admin_ui("Edit Company", 2, roles[1]);
									fcolor(main_font_color);
									move(20, centerS(((string)"Employee ID: " + to_string(current_comp.get_emp(emp_index).get_id()))));
									cout << "Employee ID: " << current_comp.get_emp(emp_index).get_id();
									move(22, centerS(((string)"Employee Name: " + current_comp.get_emp(emp_index).get_name())));
									cout << "Employee Name: " << current_comp.get_emp(emp_index).get_name();
									move(24, centerS(((string)"ID Status: " + (current_comp.get_emp(emp_index).get_locked() ? "\033[31mLocked" : "\033[32mActive"))));
									cout << "   ID Status: " << (current_comp.get_emp(emp_index).get_locked() ? "\033[31mLocked" : "\033[32mActive");
									fcolor(main_font_color);
									if (position == 1) {
										double salary;
										move(11, centerS(((string)"Enter New Salary")));
										cout << "Enter New Salary";
										move(13, 7);
										bcolor(main_boxback_color);
										fcolor(main_boxborder_color);
										Dframe(1, 31);
										fcolor(main_font_color);
										move(14, 8);
										do {
											id_write(29, salary, functions);
										} while (functions != "enter" && functions != "esc");
										if (functions == "esc") { Admin_edit_com_page(current_user); }
										else {
											current_comp.get_emp(emp_index).set_salary(salary);
											move(17, centerS(((string)"Salary updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Salary updated successfully";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
									else if (position == 2 || position == 14) {
										double bouns;
										move(11, centerS(((string)"Enter Bounes Amount")));
										cout << "Enter Bounes Amount";
										move(13, 7);
										bcolor(main_boxback_color);
										fcolor(main_boxborder_color);
										Dframe(1, 31);
										fcolor(main_font_color);
										move(14, 8);
										do {
											id_write(29, bouns, functions);
										} while (functions != "enter" && functions != "esc");
										if (functions == "esc") { Admin_edit_com_page(current_user); }
										else {
											current_comp.get_emp(emp_index).set_bouns(bouns);
											move(17, centerS(((string)"Bounes updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Bounes updated successfully";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
									else if (position == 3 || position == 13) {
										double overtime;
										move(11, centerS(((string)"Enter Overtime in min")));
										cout << "Enter Overtime in min";
										move(13, 7);
										bcolor(main_boxback_color);
										fcolor(main_boxborder_color);
										Dframe(1, 31);
										fcolor(main_font_color);
										move(14, 8);
										do {
											id_write(29, overtime, functions);
										} while (functions != "enter" && functions != "esc");
										if (functions == "esc") { Admin_edit_com_page(current_user); }
										else {
											current_comp.get_emp(emp_index).set_overtime(overtime);
											move(17, centerS(((string)"Overtime updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Overtime updated successfully";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
									else if (position == 4 || position == 12) {
										double deduction;
										move(11, centerS(((string)"Enter Deduction Amount")));
										cout << "Enter Deduction Amount";
										move(13, 7);
										bcolor(main_boxback_color);
										fcolor(main_boxborder_color);
										Dframe(1, 31);
										fcolor(main_font_color);
										move(14, 8);
										do {
											id_write(29, deduction, functions);
										} while (functions != "enter" && functions != "esc");
										if (functions == "esc") { Admin_edit_com_page(current_user); }
										else {
											current_comp.get_emp(emp_index).set_deduction(deduction);
											move(17, centerS(((string)"Deduction updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Deduction updated successfully";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
									else if (position == 5 || position == 11) {
										string role;
										move(9, centerS(((string)"Choose New Role")));
										cout << "Choose New Role";
										move(10, 7);
										hoverd_button;
										Dframe(1, 31);
										fcolor(hoverd_font_color);
										move(11, centerS(((string)"Admin")));
										cout << "Admin";
										move(14, 7);
										non_hoverd_button;
										Dframe(1, 31);
										fcolor(main_font_color);
										move(15, centerS(((string)"Staff")));
										cout << "Staff";
										position = 1;
										do {
											buttons(role="super_admin");
											if (role == "down" && position == 1) {
												move(10, 7);
												non_hoverd_button;
												Dframe(1, 31);
												fcolor(main_font_color);
												move(11, centerS(((string)"Admin")));
												cout << "Admin";
												move(14, 7);
												hoverd_button;
												Dframe(1, 31);
												fcolor(hoverd_font_color);
												move(15, centerS(((string)"Staff")));
												cout << "Staff";
												position = 2;
											}
											else if (role == "up" && position == 2) {
												move(10, 7);
												hoverd_button;
												Dframe(1, 31);
												fcolor(hoverd_font_color);
												move(11, centerS(((string)"Admin")));
												cout << "Admin";
												move(14, 7);
												non_hoverd_button;
												Dframe(1, 31);
												fcolor(main_font_color);
												move(15, centerS(((string)"Staff")));
												cout << "Staff";
												position = 1;
											}
										} while (role != "enter" && role != "esc");
										if (role == "esc") { Admin_edit_com_page(current_user); }
										else {
											if (position == 1) {
												role = roles[1];
											}
											else {
												role = roles[2];
											}
											current_comp.get_emp(emp_index).set_role(role);
											move(17, centerS(((string)"Role updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Role updated successfully.";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
									else if (position == 6 || position == 10) {
										change_pass_page(current_comp.get_emp(emp_index));
										Admin_edit_com_page(current_user);
									}
									else if (position == 7 || position == 9) {
										string status = (current_comp.get_emp(emp_index).get_statu() ? "Check Out" : "Check In");
										admin_ui("Setting", 2, roles[1]);
										string functions;
										int position = 0;

										move(7, 7);
										hoverd_button;
										Dframe(1, 31);
										move(8, centerLN(8, 39, ((string)"Active")));
										fcolor(hoverd_font_color);
										cout << "Active";
										non_hoverd_button;
										move(11, 7);
										Dframe(1, 31);
										move(15, 7);
										Dframe(1, 31);
										move(12, centerLN(8, 39, ((string)"Inactive")));
										fcolor(main_font_color);
										cout << "Inactive";
										move(16, centerLN(8, 39, status));
										cout << status;
										position = 1;
										functions = "";
										do {
											buttons(functions = "main");
											if (functions == "esc") {break;}
											if (((functions == "tab" || functions == "down") && position == 1)|| ((functions == "tab" || functions == "up") && position == 3)) {
												non_hoverd_button;
												move(7, 7);
												Dframe(1, 31);
												move(15, 7);
												Dframe(1, 31);
												move(8, centerLN(8, 39, ((string)"Active")));
												fcolor(main_font_color);
												cout << "Active";
												move(16, centerLN(8, 39, status));
												cout << status;
												move(11, 7);
												hoverd_button;
												Dframe(1, 31);
												move(12, centerLN(8, 39, ((string)"Inactive")));
												fcolor(hoverd_font_color);
												cout << "Inactive";
												position = 2;
												functions = "";
											}
											else if ((functions == "tab" || functions == "up") && position == 2) {
												move(7, 7);
												hoverd_button;
												Dframe(1, 31);
												move(8, centerLN(8, 39, ((string)"Active")));
												fcolor(hoverd_font_color);
												cout << "Active";
												non_hoverd_button;
												move(11, 7);
												Dframe(1, 31);
												move(15, 7);
												Dframe(1, 31);
												move(12, centerLN(8, 39, ((string)"Inactive")));
												fcolor(main_font_color);
												cout << "Inactive";
												move(16, centerLN(8, 39, status));
												cout << status;
												position = 1;
												functions = "";
											}else if(functions=="down"&& position == 2) {
												non_hoverd_button;
												move(7, 7);
												Dframe(1, 31);
												move(11, 7);
												Dframe(1, 31);
												move(8, centerLN(8, 39, ((string)"Active")));
												fcolor(main_font_color);
												cout << "Active";
												move(12, centerLN(8, 39, ((string)"Inactive")));
												cout << "Inactive";
												hoverd_button;
												move(15, 7);
												Dframe(1, 31);
												fcolor(hoverd_font_color);
												move(16, centerLN(8, 39, status));
												cout << status;
												position = 3;
												functions = "";
											}
											else if (functions == "enter" && position == 1) {
												current_comp.get_emp(emp_index).set_locked(false);
												string error = "Employee Id is now active";
												move(19, 2);
												bcolor(main_back_color);
												string s = string(43, ' ');
												cout << s;
												move(19, centerS(error));
												green(font);
												cout << error;
												save_data();
												Sleep(2000);
												break;


											}
											else if (functions == "enter" && position == 2) {
												current_comp.get_emp(emp_index).set_locked(true);
												string error = "Employee Id is now inactive";
												move(19, 2);
												bcolor(main_back_color);
												string s = string(43, ' ');
												cout << s;
												move(19, centerS(error));
												green(font);
												cout << error;
												save_data();
												Sleep(2000);
												break;
											}
											else if (functions == "enter" && position == 3) {
												string error;
												if (current_comp.get_emp(emp_index).get_statu()) {
													current_comp.get_emp(emp_index).set_statu(false);
													current_comp.get_emp(emp_index).set_attendance((time(0) - current_comp.get_emp(emp_index).check_out()) / 3600.0);
													save_data();
													error = "Employee Check Out Successfully";
												}
												else {
													current_comp.get_emp(emp_index).set_statu(true);
													current_comp.get_emp(emp_index).check_in(time(0));
													save_data();
													error = "Employee Check IN Successfully";
												}
												move(19, 2);
												bcolor(main_back_color);
												string s = string(43, ' ');
												cout << s;
												move(19, centerS(error));
												green(font);
												cout << error;
												save_data();
												Sleep(2000);
												break;
												
											}
										} while (true);
										
										Admin_edit_com_page(current_user);
										
									}
									else if (position == 8) {
										string num_str;
										move(11, centerS(((string)"Enter New Number")));
										cout << "Enter New Number";
										move(13, 7);
										bcolor(main_boxback_color);
										fcolor(main_boxborder_color);
										Dframe(1, 31);
										fcolor(main_font_color);
										move(14, 8);
										do {
											string space = string(27, ' ');
											move(14, 8);
											cout << space;
											moveL(27);
											move(14, 8);
											double number;
											id_write(29,number, functions);
											num_str = to_string(static_cast<long long>(number));
											if (functions == "enter") {
												if (num_str.length() >= 10 && num_str.length() <= 10 && all_of(num_str.begin(), num_str.end(), ::isdigit)) {
													break;
												}
												else { continue; }
											}
											else if (functions == "esc") {
												break;
											}
										} while (true);
										if (functions == "esc") { Admin_edit_com_page(current_user); }
										else {
											current_comp.get_emp(emp_index).set_num(num_str);
											move(17, centerS(((string)"Number updated successfully")));
											green(font);
											bcolor(main_back_color);
											cout << "Number updated successfully";
											save_data();
											Sleep(2000);
											Admin_edit_com_page(current_user);
										}
									}
								}
						} while (true);
					}
					else {

						string error = "Employee ID not found.";
						bcolor(main_back_color);
						move(13, 1);
						string spaces = string(30, ' ');
						cout << spaces;
						red(Bfont);
						move(13, centerS(((string)"Employee ID not found.")));
						cout << "Employee ID not found.";
						fcolor(main_font_color);
						continue;

					}
				}
			} while (true);

		}
		else if (functions == "enter" && (position == 2 || position == 4)) {
			add_emp_page(Cname, current_user);


		}
		else if (functions == "enter" && position == 3) {
			delete_emp_page(Cname, current_user);


		}
	} while (true);

}
