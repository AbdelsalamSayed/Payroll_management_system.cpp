#include "../pages.H/system_admin.h"

void super_setting_ui() {
	main_ui("Setting", 4);

	hoverd_button;
	move(5, 7);
	Dframe(1, 31);
	move(6, centerLN(9, 38, ((string)"Change  system status")));
	cout << "Change  system status";
	move(9, 7);
	Dframe(1, 31);
	move(10, centerLN(8, 39, ((string)"Change password")));
	cout << "Change password";
	move(13, 7);
	Dframe(1, 31);
	move(14, centerLN(8, 39, ((string)"Log out")));
	cout << "Log out";
}