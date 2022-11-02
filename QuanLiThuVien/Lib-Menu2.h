#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<Windows.h>
#include"File-Processing.h"
void Menu2();
void Menu2_Admin();
void Menu2_Manager();
void Menu2_Staff();
/*------------------------Chuc nang 2.1 Xem danh sách độc giả-------------*/
void PrintReader(Reader reader);
void PrintListReader();

/*-----------------------Chuc nang 2.2 Them reader-------------------------------*/
void AddReader(Reader reader);

void InputInforReader(Reader& reader);

void AddReaderToList();
/*-----------------------Chuc nang 2.3 Chinh sua thong tin mot doc gia-------------------------------*/
void ChangeInforReader();

bool FindReaderByID(char ID[MAX_CHAR_ID], Reader& reader, int& pos);
bool FindReaderByID(char ID[MAX_CHAR_ID]);

/*-----------------------Chuc nang 2.4 Xoa thong tin mot doc gia-------------------------------*/
void DeleteReader(int pos);

void DeleteReaderFromList();
/*-----------------------Chuc nang 2.5 Tim kiem doc gia theo CMND-------------------------------*/
bool FindByCMND(char CMND[MAX_CHAR_CMND], Reader& reader, int& pos);
void PrintReaderByCMND();
/*-----------------------Chuc nang 2.6 Tim kiem doc gia theo ten-------------------------------*/
void FindByName();