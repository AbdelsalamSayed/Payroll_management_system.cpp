#pragma once

#include "../draw.h"
#include "../UI/Head.h"

inline string help = "For help contact HR";
inline int emailbarL = 41;

inline int edomain = (centerN(emailbarL) + 2);
inline string loginSTR = "Welcome back!";
inline string loginSTR2 = "Please use your employee Email";
inline string loginSTR3 = "to securely access your payroll dashboard";

inline int position;
inline string domain;
string loginpage();
void loginpage_ui();

