#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Header.h"
#include<Windows.h>
#include"Time.h"
#include"Lib-SignIn.h"
#include"Lib-Menu.h"
using namespace std;
void Menu1();
void Menu1_Admin();
void Menu1_Manager();
void Menu1_Staff();

void CreateUser();
void LogOut();
void ChangePassword();
void ChangeProfile();

void ChangePermissionAndStatus();
void ChangePermission();
void ChangeStatus();
void PrintUser(User userTemp);
