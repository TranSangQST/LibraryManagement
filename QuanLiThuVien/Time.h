#pragma once
#include"Header.h"
#include"Lib-Menu.h"
#include<time.h>
//Đếm số ngày của tháng
int CountDaysOfMonth(Time date);
//Kiểm tra ngày hợp lệ
bool CheckDate(Time date);
//Nhập ngày tháng năm
void InputDateCenter(Time& date);
void InputDate(Time& date);
//Xuất ngày
void OutputDay(Time date);
void OutputDateToString(Time date, char s[15]);

int countDays(Time date1, Time date2);
Time FindDateAfter(Time date, int n);
Time GetRealTime();
