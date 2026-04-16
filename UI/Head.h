#pragma once
#include "../Main_H.h"
#include "../pages.h/login_page.h"

void login_head();

void body();
void footer(string role, int button_num);
void write_frame(int num, string statu, string& lastinput, string& functions);
void buttons(string& functions);
