#include "../pages.H/system_admin.h"

void staff_page(employee& current_user) {
	string functions;
	int position = 1;
	staff_ui("home", 1,current_user);
	move(5, centerS(((string)"Your Status: " + (current_user.get_statu() ? "\033[32mIN" : "\033[31mOUT"))));
	cout << "   Your Status: " << (current_user.get_statu() ? "\033[32mIN" : "\033[31mOUT");
	string status = (current_user.get_statu() ? "Check Out" : "Check In");
	hoverd_button;
	move(7, 7);
	Dframe(1, 31);
	non_hoverd_button;
	move(11, 7);
	Dframe(1, 31);
	move(15, 7);
	Dframe(1, 31);
	move(19, 7);
	Dframe(1, 31);
	move(23, 7);
	Dframe(1, 31);
	hoverd_button;
	fcolor(hoverd_font_color);
	move(8, centerS(status));
	cout << status;
	non_hoverd_button;
	fcolor(main_font_color);
	move(12, centerS(((string)"Request Leave")));
	cout << "Request Leave";
	move(16, centerS(((string)"Request Borrowing")));
	cout << "Request Borrowing";
	move(20, centerS(((string)"Salary Information")));
	cout << "Salary Information";
	move(24, centerS(((string)"Log out")));
	cout << "Log out";
	do {
		buttons(functions = "main");
		if (functions == "esc") {
			logout_msg();
			staff_page(current_user);
		}
		else if (functions == "up" && (position == 2 || position == 8)) {
			hoverd_button;
			move(7, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(8, centerS(status));
			cout << status;
			non_hoverd_button;
			move(11, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(12, centerS(((string)"Request Leave")));
			cout << "Request Leave";
			position = 1;

		}
		else if ((functions == "down" && position == 1) || (functions == "up" && position == 7)) {
			hoverd_button;
			move(11, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(12, centerS(((string)"Request Leave")));
			cout << "Request Leave";
			non_hoverd_button;
			move(7, 7);
			Dframe(1, 31);
			move(15, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(8, centerS(status));
			cout << status;
			move(16, centerS(((string)"Request Borrowing")));
			cout << "Request Borrowing";
			if (position == 1) {
				position = 2;
			}
			else {
				position = 8;
			}

		}
		else if ((functions == "down" && (position == 8 || position == 2)) || (functions == "up" && position == 6)) {
			hoverd_button;
			move(15, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(16, centerS(((string)"Request Borrowing")));
			cout << "Request Borrowing";
			non_hoverd_button;
			move(11, 7);
			Dframe(1, 31);
			move(19, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(12, centerS(((string)"Request Leave")));
			cout << "Request Leave";
			move(20, centerS(((string)"Salary Information")));
			cout << "Salary Information";
			if (position == 1) {
				position = 3;
			}
			else {
				position = 7;
			}
			
		}
		else if ((functions == "down" && (position == 3 || position == 7)) || (functions == "up" && position == 5)) {
			hoverd_button;
			move(19, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(20, centerS(((string)"Salary Information")));
			cout << "Salary Information";
			non_hoverd_button;
			move(15, 7);
			Dframe(1, 31);
			move(23, 7);
			Dframe(1, 31);
			non_hoverd_button;
			fcolor(main_font_color);
			move(16, centerS(((string)"Request Borrowing")));
			cout << "Request Borrowing";
			move(24, centerS(((string)"Log out")));
			cout << "Log out";
			if (position == 1) {
				position = 4;
			}
			else {
				position = 6;
			}
			
		}
		else if ((functions == "down" && (position == 4 || position == 6))) {
			hoverd_button;
			move(23, 7);
			Dframe(1, 31);
			fcolor(hoverd_font_color);
			move(24, centerS(((string)"Log out")));
			cout << "Log out";
			non_hoverd_button;
			move(19, 7);
			Dframe(1, 31);
			fcolor(main_font_color);
			move(20, centerS(((string)"Salary Information")));
			cout << "Salary Information";
			position = 5;
			
		}
		else if (functions == "enter") { break; }
	} while (true);
	
	if (position == 1) {
		if (current_user.get_statu()) {
			current_user.set_statu(false);
			current_user.set_attendance((time(0)-current_user.check_out())/3600.0);
			save_data();
		}
		else {
			current_user.set_statu(true);
			current_user.check_in(time(0));
			save_data();
		}
		staff_page(current_user);
	}
	else if (position == 2 || position == 8) {
		staff_ui("Leave", 1, current_user);
		double leave;
		move(11, centerS(((string)"Enter How Many Days To Leave")));
		cout << "Enter How Many Days To Leave";
		move(13, 7);
		bcolor(main_boxback_color);
		fcolor(main_boxborder_color);
		Dframe(1, 31);
		fcolor(main_font_color);
		move(14, 8);
		do {
			id_write(29, leave, functions);
		} while (functions != "enter" && functions != "esc");
		if (functions == "esc") { staff_page(current_user); }
		else {
			current_user.set_leavenum(leave);
			move(17, centerS(((string)"Leave updated successfully")));
			green(font);
			bcolor(main_back_color);
			cout << "Leave updated successfully";
			save_data();
			Sleep(2000);
			staff_page(current_user);
		}

	}
	else if (position == 3 || position == 7) {
		staff_ui("Borrowing", 1, current_user);
		double borrowing;
		move(11, centerS(((string)"Enter Amount to Borrow")));
		cout << "Enter Amount to Borrow";
		move(13, 7);
		bcolor(main_boxback_color);
		fcolor(main_boxborder_color);
		Dframe(1, 31);
		fcolor(main_font_color);
		move(14, 8);
		do {
			id_write(29, borrowing, functions);
		} while (functions != "enter" && functions != "esc");
		if (functions == "esc") { staff_page(current_user); }
		else {
			current_user.set_borrowing(borrowing);
			move(17, centerS(((string)"Borrowing updated successfully")));
			green(font);
			bcolor(main_back_color);
			cout << "Borrowing updated successfully";
			save_data();
			Sleep(2000);
			staff_page(current_user);
		}
	}
	else if (position == 4 || position == 6) {
		staff_ui("salary_info", 1, current_user);
		fcolor(main_font_color);
		move(4, 1);
		cout << " Your Salary       | " << current_user.get_salary();
		move(6, 1);
		printf(" Your Attendance   | %0.2f --> %0.2f", current_user.get_attendance(), current_user.get_attendance()*(current_user.get_salary()/30)/8);
		move(8, 1);
		cout << " Your Leave        | " << current_user.get_leavenum() << " --> " << current_user.get_leavenum() * (current_user.get_salary() / 30);
		move(10, 1);
		cout << " Your Bouns        | " << current_user.get_bouns();
		move(12, 1);
		cout << " Your Overtime     | " << current_user.get_overtime() << " --> " << (((current_user.get_overtime() / 60) * 1.5) * ((current_user.get_salary() / 30) / 8));
		move(14, 1);
		cout << " Your Deduction    | " << current_user.get_deduction();
		move(16, 1);
		cout << " Your Taxes        | " << current_user.get_taxes();
		move(18, 1);
		cout << " Your Borrowing    | " << current_user.get_borrowing();
		move(20, 1);
		cout << " Your Net Salary   | " << current_user.get_net_salary();
		do {
			buttons(functions = "main");
		} while (functions != "esc");
		staff_page(current_user);
	}
	else if (position == 5) {
		logout_msg();
		staff_page(current_user);
	}
	
}