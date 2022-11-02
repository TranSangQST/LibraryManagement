#include"Lib-Menu3.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
void Menu3()
{
	bool back;
	do
	{
		back = false;
		system("cls");
		switch (user.permission)
		{
		case 1:
			Menu3_Admin();
			break;
		case 2:
			Menu3_Manager();
			break;
		case 3:
			Menu3_Staff();
			break;
		default:
			break;
		}
		if (backToMenu0 == true)
			return;
		char selection;
		back = true;
		cout << "Nhap phim bat ki de quay lai: ";
		selection = _getch();
		//cin.ignore();
		//Menu3();
	} while (back);
}
void Menu3_Admin()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Xem danh sach sach trong thu vien      1" << endl;
	cout << "Them sach                              2" << endl;
	cout << "Chinh sua thong tin mot quyen sach     3" << endl;
	cout << "Xoa thong tin sach                     4" << endl;
	cout << "Tim kiem sach theo ISBN                5" << endl;
	cout << "Tim kiem sach theo ten sach            6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	cout << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		system("cls");
		switch (selection)
		{
		case 1:
		{
			cout << "Sap xep                             Chon" << endl;
			cout << "Sap xep theo nam xuat ban              1" << endl;
			cout << "Sap xep theo gia tien                  2" << endl;
			int selection2;
			cout << "Chon kieu sap xep: ";
			cin >> selection2;
			if (selection2 == 1)
			{
				ListBook listBookTemp = listBook;
				QuickSortPublishingYear(listBookTemp.book, 0, listBookTemp.numBook - 1);
				PrintListBook(listBook);
			}
			else if (selection2 == 2)
			{
				ListBook listBookTemp = listBook;
				QuickSortPrice(listBookTemp.book, 0, listBookTemp.numBook - 1);
				PrintListBook(listBook);
			}
			break;
		}
		case 2:
		{
			AddBookToList();
			//ghi đè file vào file Bool.csv
			//vì đã cập nhập listBook nên ta ko cần gọi lại hàm ReadFileBook
			OverwriteFileBook(BookFile);
			break;
		}
		case 3:
		{
			ChangeInforBook();
			OverwriteFileBook(BookFile);
			break;
		}
		case 4:
		{
			DeleteBookFromList();
			OverwriteFileBook(BookFile);
			break;
		}
		case 5:
		{
			PrintFindBookISBN();
			break;
		}
		case 6:
		{
			PrintFindBookName();
			break;
		}
		case 0:
			backToMenu0 = true;
			return;
			//Menu0();
			//break;
		default:
		{
			cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
			break;
		}
		}
	} while (selection<0 || selection>6);
	
}
void Menu3_Manager()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Xem danh sach sach trong thu vien      1" << endl;
	cout << "Them sach                              2" << endl;
	cout << "Chinh sua thong tin mot quyen sach     3" << endl;
	cout << "Xoa thong tin sach                     4" << endl;
	cout << "Tim kiem sach theo ISBN                5" << endl;
	cout << "Tim kiem sach theo ten sach            6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	cout << endl;

	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		system("cls");
		switch (selection)
		{
		case 1:
		{
			ListBook listBookTemp = listBook;
			QuickSortPublishingYear(listBookTemp.book, 0, listBookTemp.numBook - 1);
			PrintListBook(listBookTemp);
			break;
		}
		case 2:
		{
			AddBookToList();
			//ghi đè file vào file Bool.csv
			//vì đã cập nhập listBook nên ta ko cần gọi lại hàm ReadFileBook
			OverwriteFileBook(BookFile);
			break;
		}
		case 3:
		{
			ChangeInforBook();
			OverwriteFileBook(BookFile);
			//PrintListBook();

			break;
		}
		case 4:
		{
			DeleteBookFromList();
			OverwriteFileBook(BookFile);
			//PrintListBook();
			break;
		}
		case 5:
		{
			PrintFindBookISBN();
			break;
		}
		case 6:
		{
			PrintFindBookName();
			break;
		}
		case 0:
			backToMenu0 = true;
			return;
			//Menu0();
			//break;
		default:
		{
			cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
			break;
		}
		}

	}while (selection < 0 || selection>6);
}
void Menu3_Staff()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Tim kiem sach theo ISBN                5" << endl;
	cout << "Tim kiem sach theo ten sach            6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	cout << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		system("cls");
		switch (selection)
		{
		case 5:
		{
			PrintFindBookISBN();
			break;
		}
		case 6:
		{
			PrintFindBookName();
			break;
		}
		case 0:
			backToMenu0 = true;
			return;
			//Menu0();
			//break;
		default:
		{
			cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
			break;
		}
		}
	} while (selection != 5 && selection != 6 && selection!=0);
}

/**********************Sort***********************/
void SwapBook(Book &book1 , Book &book2)
{
	Book temp;
	temp = book1;
	book1 = book2;
	book2 = temp;

}
/*
void InterchangeSort(ListBook &listBookTemp)
{
	for (int i = 0; i < listBookTemp.numBook - 1; i++)
	{
		for (int j = i + 1; j < listBookTemp.numBook; j++)
		{
			if (listBookTemp.book[i].publishingYear < listBookTemp.book[j].publishingYear)
				SwapBook(listBookTemp.book[i], listBookTemp.book[j]);
		}
	}
}
*/
//*
int partitionPublishingYear(Book* lsBook, int begin, int end)
{
	int pivot = lsBook[end].publishingYear;
	int L = begin;
	int R = end - 1;
	while (1)
	{
		while (L <= R && lsBook[L].publishingYear > pivot)
		{
			L++;
		}
		while (L <= R && lsBook[R].publishingYear < pivot)
		{
			R--;
		}
		if (L >= R) break;
		SwapBook(lsBook[L], lsBook[R]);
		L++;
		R--;
	}
	SwapBook(lsBook[L], lsBook[end]);
	return L;
}

void QuickSortPublishingYear(Book* lsBook, int begin, int end)
{
	if (begin >= end)
		return;
	int position = partitionPublishingYear(lsBook, begin, end);
	QuickSortPublishingYear(lsBook, begin, position - 1);
	QuickSortPublishingYear(lsBook, position + 1, end);
}
int partitionPrice(Book* lsBook, int begin, int end)
{
	int pivot = lsBook[end].price;
	int L = begin;
	int R = end - 1;
	while (1)
	{
		while (L <= R && lsBook[L].price > pivot)
		{
			L++;
		}
		while (L <= R && lsBook[R].price < pivot)
		{
			R--;
		}
		if (L >= R) break;
		SwapBook(lsBook[L], lsBook[R]);
		L++;
		R--;
	}
	SwapBook(lsBook[L], lsBook[end]);
	return L;
}

void QuickSortPrice(Book* lsBook, int begin, int end)
{
	if (begin >= end)
		return;
	int position = partitionPrice(lsBook, begin, end);
	QuickSortPrice(lsBook, begin, position - 1);
	QuickSortPrice(lsBook, position + 1, end);
}
//*/

/*------------------------Chuc nang 3.1 Xem danh sách sách trong TV-------------*/
void PrintABook(Book book)
{
	cout << "ISBN: " << book.ISBN << endl;
	cout << "Ten sach: " << book.name << endl;
	cout << "Ten tac gia: " << book.author << endl;
	cout << "Ten nha xuat ban: " << book.publishingCompany << endl;
	cout << "Nam xuat ban: " << book.publishingYear << endl;
	cout << "The loai: " << book.type << endl;
	cout << "Gia sach: " << book.price << endl;
	cout << "So luong sach: " << book.count << endl;
}
void PrintBook(Book book)
{
	cout << setw(MAX_CHAR_ISBN+3) << std::left <<book.ISBN;
	cout << setw(MAX_CHAR_NAME_BOOK+3) << std::left << book.name;
	cout << setw(MAX_CHAR_AUTHOR+3) << std::left << book.author;
	cout << setw(MAX_CHAR_COMPANY+3) << std::left << book.publishingCompany;
	cout << setw(MAX_CHAR_YEAR +3) << std::left << book.publishingYear;
	cout << setw(MAX_CHAR_TYPE+3) << std::left << book.type;
	cout << setw(MAX_CHAR_PRICE+3) << std::left << book.price;
	cout << setw(MAX_CHAR_COUNT + 3) << std::left << book.count;
	
	cout << endl;
	int n = MAX_CHAR_ISBN + MAX_CHAR_NAME_BOOK + MAX_CHAR_AUTHOR + MAX_CHAR_COMPANY
		+ MAX_CHAR_YEAR + MAX_CHAR_TYPE + MAX_CHAR_PRICE + MAX_CHAR_COUNT + 3 * 8;
	SetSpace(n, '-');
	cout << endl;
}
void PrintListBook(ListBook listBookTemp)
{
	cout << setw(MAX_CHAR_ISBN + 3) << std::left << "ISBN";
	cout << setw(MAX_CHAR_NAME_BOOK + 3) << std::left << "Ten sach";
	cout << setw(MAX_CHAR_AUTHOR + 3) << std::left << "Tac gia";
	cout << setw(MAX_CHAR_COMPANY + 3) << std::left << "Nha xuat ban";
	cout << setw(MAX_CHAR_YEAR + 3) << std::left << "Nam";
	cout << setw(MAX_CHAR_TYPE + 3) << std::left << "The loai";
	cout << setw(MAX_CHAR_PRICE + 3) << std::left << "Gia";
	cout << setw(MAX_CHAR_COUNT + 3) << std::left << "So luong";
	cout << endl;
	int n = MAX_CHAR_ISBN + MAX_CHAR_NAME_BOOK + MAX_CHAR_AUTHOR + MAX_CHAR_COMPANY
		+ MAX_CHAR_YEAR + MAX_CHAR_TYPE + MAX_CHAR_PRICE + MAX_CHAR_COUNT + 3 * 8;
	SetSpace(n, '-');
	cout << endl;
	for (int i = 0; i < listBookTemp.numBook; i++)
	{
		PrintBook(listBookTemp.book[i]);
		cout << endl;
	}
}

/*-----------------------Chuc nang 3.2 Them sach-------------------------------*/


void AddBook(Book book)
{
	int n = listBook.numBook;
	ListBook listBookTemp;

	listBookTemp.numBook = n + 1;
	listBookTemp.book = new Book[listBookTemp.numBook];

	//copy listBook cũ vào listBookTemp
	for (int i = 0; i < n; i++)
	{
		listBookTemp.book[i] = listBook.book[i];
	}

	//Xóa listBook cũ
	delete[] listBook.book;

	//copy listBookTemp vào listBook (để tăng thêm vùng nhớ cho listBook.book
	listBook = listBookTemp;

	//thêm book vào cuối listBook.book
	//n <=> listBook.numBook (đã đc tăng thêm 1) 
	listBook.book[n] = book;

}
//*/
void InputInforBook(Book &book)
{
	cout << "nhap ten: ";
	cin.getline(book.name, MAX_CHAR_NAME_BOOK);
	cout << "Nhap tac gia: ";
	cin.getline(book.author, MAX_CHAR_AUTHOR);
	cout << "Nhap nha xuat ban: ";
	cin.getline(book.publishingCompany, MAX_CHAR_COMPANY);
	cout << "Nhap nam xuat ban: ";
	cin >> book.publishingYear;
	cin.ignore();
	cout << "Nhap the loai: ";
	cin.getline(book.type, MAX_CHAR_TYPE);
	cout << "Nhap gia sach: ";
	cin >> book.price;
	cout << "Nhap so luong: ";
	cin >> book.count;
	cin.ignore();
}

void AddBookToList()
{
	Book book;
	cout << "Nhap ISBN: ";
	cin.getline(book.ISBN, MAX_CHAR_ISBN);
	InputInforBook(book);
	cout << "Da nhap xong" << endl;

	if (listBook.numBook == 0)
	{
		listBook.book = new Book[1];
		listBook.numBook = 1;
		listBook.book[0] = book;
		PrintBook(book);
		cout << endl;
		PrintListBook(listBook);
	}
	else
	{
		AddBook(book);
	}

}

/*-----------------------Chuc nang 3.3 Chinh sua thong tin sach-------------------------------*/
void ChangeInforBook()
{
	Book book;
	int pos = -1;
	char ISBN[MAX_CHAR_ISBN];
	cout << "Nhap ISBN sach sua thong tin: ";
	cin.getline(ISBN, MAX_CHAR_ISBN);
	
	if (FindBookISBN(ISBN, book, pos))
	{
		//InputInforBook(book);
		int selection;
		do
		{
			system("cls");

			cout << "Chuc nang                   Chon" << endl;
			cout << "Thay doi ten sach            1" << endl;
			cout << "Thay doi ten gia             2" << endl;
			cout << "Thay doi ten nha xuat ban    3" << endl;
			cout << "Thay doi nam xuat ban        4" << endl;
			cout << "Thay doi the loai            5" << endl;
			cout << "Thay doi gia sach            6" << endl;
			cout << "Thay doi so luong            7" << endl;
			cout << "Ket thuc thay doi            0" << endl;

			cout << endl;
			PrintABook(book);
			cout << endl;
			cout << "Nhap thong tin muon thay doi: ";
			cin >> selection;
			cin.ignore();
			switch (selection)
			{
			case 1:
			{
				cout << "Nhap ten: ";
				cin.getline(book.name, MAX_CHAR_NAME_BOOK);
				break;
			}
			case 2:
			{
				cout << "Nhap tac gia: ";
				cin.getline(book.author, MAX_CHAR_AUTHOR);
				break;
			}
			case 3:
			{
				cout << "Nhap nha xuat ban: ";
				cin.getline(book.publishingCompany, MAX_CHAR_COMPANY);
				break;
			}
			case 4:
			{
				cout << "Nhap nam xuat ban: ";
				cin >> book.publishingYear;
				cin.ignore();
				break;
			}
			case 5:
				cout << "Nhap the loai: ";
				cin.getline(book.type, MAX_CHAR_TYPE);
				break;
			case 6:
				cout << "Nhap gia sach: ";
				cin >> book.price;
				cin.ignore();
				break;
			case 7:
				cout << "Nhap so luong: ";
				cin >> book.count;
				cin.ignore();
				break;
			case 0:
				break;
			default:
			{
				cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
				break;
			}
			}
		} while (selection != 0);
		listBook.book[pos] = book;
		cout << "Da thay doi thong tin sach" << endl;
	}
	else
	{
		cout << "Khong ton tai sach nay" << endl;
	}
}

/*-----------------------Chuc nang 3.4 xoa thong tin sach-------------------------------*/
void DeleteBook(int pos)
{
	int n = listBook.numBook;
	ListBook listBookTemp;

	listBookTemp.numBook = n - 1;
	listBookTemp.book = new Book[listBookTemp.numBook];

	//copy listBook cũ vào listBookTemp
	for (int i = 0; i < pos; i++)
	{
		listBookTemp.book[i] = listBook.book[i];
	}
	for (int i =pos; i < listBookTemp.numBook; i++)
	{
		listBookTemp.book[i] = listBook.book[i+1];
	}

	//Xóa listBook cũ
	delete[] listBook.book;

	//copy listBookTemp vào listBook (để tăng thêm vùng nhớ cho listBook.book
	listBook = listBookTemp;

}
void DeleteBookFromList()
{
	Book book;
	int pos = -1;
	char ISBN[MAX_CHAR_ISBN];
	cout << "Nhap ISBN sach can xoa thong tin: ";
	cin.getline(ISBN, MAX_CHAR_ISBN);
	if (FindBookISBN(ISBN, book, pos))
	{
		DeleteBook(pos);
		cout << "Da xoa sach " << endl;
	}
	else
	{
		cout << "Khong ton tai sach nay" << endl;
	}
}
/*------------------------Chức năng 3.5: ----Tim sach theo ISBN----------- */
//Kiểm tra và tìm kiếm sách, vị trí sách theo ISBN
bool FindBookISBN(char ISBN[MAX_CHAR_ISBN], Book &book, int &pos)
{
	for (int i = 0; i < listBook.numBook; i++)
		if (strcmp(listBook.book[i].ISBN, ISBN)==0)
		{
			book = listBook.book[i];
			pos = i;
			return true;
		}
	return false;
}
//Kiểm tra có tồn tại ISBN sách hay không?
bool FindBookISBN(char ISBN[MAX_CHAR_ISBN])
{
	for (int i = 0; i < listBook.numBook; i++)
		if (strcmp(listBook.book[i].ISBN, ISBN) == 0)
		{
			return true;
		}
	return false;
}
void PrintFindBookISBN()
{
	Book book;
	int pos = -1;
	char ISBN[MAX_CHAR_ISBN];
	cout << "Nhap ISBN sach muon tim: ";
	cin.getline(ISBN, MAX_CHAR_ISBN);
	if (FindBookISBN(ISBN, book, pos))
	{
		PrintABook(book);
	}
	else
	{
		cout << "Khong ton tai sach nay" << endl;
	}

}

/*------------------------Chức năng 3.5: ----Tim sach theo ten sach----------- */
bool FindBookName(char bookName[MAX_CHAR_NAME_BOOK], Book& book)
{
	for (int i = 0; i < listBook.numBook; i++)
		if (strcmp(listBook.book[i].name, bookName) == 0)
		{
			book = listBook.book[i];
			return true;
		}
	return false;
}
void PrintFindBookName()
{
	Book book;
	char bookName[MAX_CHAR_NAME_BOOK];
	cout << "Nhap ten sach muon tim: ";
	cin.getline(bookName, MAX_CHAR_NAME_BOOK);
	if (FindBookName(bookName, book))
	{
		PrintABook(book);
		cout << endl;
	}
	else
	{
		cout << "Khong ton tai sach nay" << endl;
	}

}
