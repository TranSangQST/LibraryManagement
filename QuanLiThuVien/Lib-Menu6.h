#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include"Lib-Menu0.h"
#include"Lib-Menu6.h"
#include"Time.h"

void Menu6();

void Menu6_Admin();
void Menu6_Manager();
void Menu6_Staff();

void StatisticsBooks();
void StatisticsBooksByType();
void StatisticsReader();
void StatisticsReaderBySex();
void StatisticsBorrowBook();

void StatisticsOverdueReader();
void OverdueReader(int overdueDay[], int pos[], int& count, Time& now);
void PrintAOverdueReader(BorrowReceipt borrowReceipt, int countOverdueDay);
void PrintOverdueReader(int overdueDay[], int pos[], int count);
void StatisticsOverdueReader();
