#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include <iostream>
#include "Lib-Menu.h"
#include <conio.h>
#include <Windows.h>
using namespace std;
void SignIn();
void WriteUserName(User& userTemp);
void WritePassword(User& userTemp);
bool CheckUser(User& userTemp);