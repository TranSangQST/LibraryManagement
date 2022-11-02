#pragma once
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#define ACTIVATED true
#define BLOCK false
#define center 35
#define col 40

#define UserFile "User.bin"
#define ReaderFile "Reader.csv"
#define BookFile "Book.csv"
#define BorrowFile "Borrow.csv"

#define MAX_USERS 20
#define MAX_CHAR_USERNAME 25
#define MAX_CHAR_PASSWORD 21
#define MAX_CHAR_NAME_USER 25
#define MAX_CHAR_CMND 16
#define MAX_CHAR_ADDRESS 30
#define MAX_CHAR_SEX 8
#define MALE "nam"
#define FEMALE "nu"


#define MAX_BOOKS 100
#define MAX_CHAR_ISBN 7
#define MAX_CHAR_NAME_BOOK 35
#define MAX_CHAR_AUTHOR 25
#define MAX_CHAR_COMPANY 25
#define MAX_CHAR_PRICE 10
#define MAX_CHAR_YEAR 10
#define MAX_CHAR_COUNT 10
#define MAX_CHAR_TYPE 20

#define MAX_READERS 100
#define MAX_CHAR_ID 7
#define MAX_CHAR_NAME_READER 25
#define MAX_CHAR_EMAIL 35

#define MAX_CHAR_DATE 12

struct Time
{
	int day;
	int month;
	int year;
};
struct User
{
	char username[MAX_CHAR_USERNAME];
	char password[MAX_CHAR_PASSWORD];
	char name[MAX_CHAR_NAME_USER];
	Time birthday;
	char cmnd[MAX_CHAR_CMND];
	char address[MAX_CHAR_ADDRESS];
	bool sex;
	bool status;
	int permission;
};
struct ListUser
{
	User* user;
	int numUser;
};
struct Reader
{
	char id[MAX_CHAR_ID];
	char name[MAX_CHAR_NAME_READER];
	char cmnd[MAX_CHAR_CMND];
	Time birthday;
	bool sex;
	char email[MAX_CHAR_EMAIL];
	char address[MAX_CHAR_ADDRESS];
	Time newCard;
	Time expiredCard;

};
struct ListReader
{
	Reader* reader;
	int numReader;
};
struct Book
{
	char ISBN[MAX_CHAR_ISBN]; //isbn có tối đa 6 kí tự
	char name[MAX_CHAR_NAME_BOOK];
	char author[MAX_CHAR_AUTHOR];
	int publishingYear;
	char publishingCompany[MAX_CHAR_COMPANY];
	char type[MAX_CHAR_TYPE];
	int price;
	int count;
};
struct ListBook
{
	Book *book;
	int numBook;
};

struct ListISBN
{
	char** ISBN;
	int numISBN;
};
struct BorrowReceipt
{
	char id[MAX_CHAR_ID];
	Time borrowDate;
	Time estimatedDate;
	Time returnDate;
	ListISBN listISBN;
	int countBorrowDays;
	int fine;

};
struct ListBorrowReceipt
{
	BorrowReceipt* borrowReceipt;
	int numReceipt;
};
extern ListUser container;
extern User user;
extern ListBook listBook;
extern ListReader listReader;
extern ListBorrowReceipt listBorrowReceipt; 
extern bool backToMenu0;
extern bool backToMenu;



