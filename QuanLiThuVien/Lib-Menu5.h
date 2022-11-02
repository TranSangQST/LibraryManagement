#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include"Lib-Menu0.h"
#include"Lib-Menu3.h"
#include"Lib-Menu4.h"
void Menu5();

bool FindBorrowReceiptByID(char* ID, BorrowReceipt& borrowReceipt, int &pos);
void InputReturnReceipt(BorrowReceipt& borrowReceipt);
void PrintReturnReceipt(BorrowReceipt borrowReceipt);
void DeleteBorrowReceipt(int posBorrowReceipt);
//*/