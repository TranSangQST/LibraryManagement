#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<fstream>
#include"Lib-Menu1.h"
void ReadFileUser(const char* filename);
void WriteFileUser(const char* filename,User userTemp);
void OverwriteFile(const char* filename);

Book ConvertLineToListBook(char* line);
void ReadFileBook(const char* filename);
void OverwriteFileBook(const char* filename);

Reader ConvertLineToListReader(char* line);
void ReadFileReader(const char* filename);
void OverwriteFileReader(const char* filename);

BorrowReceipt ConvertLineToListBorrow(char* line);
void ReadFileBorrow(const char* filename);
void OverwriteFileBorrow(const char* filename);

