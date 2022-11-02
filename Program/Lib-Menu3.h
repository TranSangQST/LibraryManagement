#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<Windows.h>
#include"File-Processing.h"
/**********************Sort***********************/
void SwapBook(Book &book1, Book &book2);

int partitionPublishingYear(Book* lsBook, int begin, int end);

void QuickSortPublishingYear(Book* lsBook, int begin, int end);

int partitionPrice(Book* lsBook, int begin, int end);

void QuickSortPrice(Book* lsBook, int begin, int end);

//-----------------------------Menu---------------------------
void Menu3();
void Menu3_Admin();
void Menu3_Manager();
void Menu3_Staff();

/*------------------------Chuc nang 3.1 Xem danh sách sách trong TV-------------*/
void PrintABook(Book book);
void PrintBook(Book book);
void PrintListBook(ListBook listBookTemp);

/*-----------------------Chuc nang 3.2 Them sach-------------------------------*/
void AddBook(Book book);
void InputInforBook(Book& book);
void AddBookToList();

/*-----------------------Chuc nang 3.3 Chinh sua thong tin sach-------------------------------*/

void ChangeInforBook();

/*-----------------------Chuc nang 3.4 xoa thong tin sach-------------------------------*/

void DeleteBook(int pos);
void DeleteBookFromList();

/*------------------------Chức năng 3.5: ----Tim sach theo ISBN----------- */

bool FindBookISBN(char ISBN[MAX_CHAR_ISBN], Book& book, int& pos);
bool FindBookISBN(char ISBN[MAX_CHAR_ISBN]);
void PrintFindBookISBN();

/*------------------------Chức năng 3.5: ----Tim sach theo ten sach----------- */
bool FindBookName(char bookName[MAX_CHAR_NAME_BOOK], Book& book);
void PrintFindBookName();