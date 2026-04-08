#pragma once
#include "../draw.h"
#include "../pages/login_page.h"

void login_head();

void body();
void footer();
void write_frame(int num, string statu, string& lastinput, string &functions);
string write(int num, string wrap);
void bottons(string& functions);
