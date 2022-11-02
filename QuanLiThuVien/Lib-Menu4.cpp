#include"Lib-Menu4.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
void Menu4()
{
	bool back;
	do
	{
		back = false;
		system("cls");
		cout << "Chuc nang					   Chon         " << endl;
		cout << "Lap phieu muon moi             1           " << endl;
		cout << "Xem danh sach phieu muon       2           " << endl;
		cout << "Nhan 0 de quay lai             0           " << endl;

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
				int pos = 1;

				BorrowReceipt borrowReceipt;
				AddBorrowReceiptToList(borrowReceipt);
				OverwriteFileBorrow(BorrowFile);
		
				break;
			}
			case 2:
			{
				PrintListBorrowReceipt();
				break;
			}
			case 0:
				backToMenu0 = true;
				return;

			default:
				break;
			}
		} while (selection < 0 || selection>3);

		char nextSelection;
		back = true;
		cout << "Nhap phim bat ki de quay lai: ";
		nextSelection = _getch();
		//cin.ignore();
		//Menu4();
	} while (back);

}
void InputBorrowReceipt(BorrowReceipt& borrowReceipt)
{

	char ID[MAX_CHAR_ID];
	bool T = false;
	do
	{
		cout << "Nhap ID doc gia muon sach: ";
		cin.getline(ID, MAX_CHAR_ID);
		T = FindReaderByID(ID);
		if (T)
		{
			strcpy(borrowReceipt.id, ID);
		}
		else
		{
			cout << "Khong ton tai doc gia nay" << endl;
		}
	} while (!T);

	int& numISBN = borrowReceipt.listISBN.numISBN;
	numISBN = 0;

	cout << "Nhap so luong sach muon muon: ";
	cin >> numISBN;
	cin.ignore();

	char ISBN[MAX_CHAR_ISBN];
	borrowReceipt.listISBN.numISBN = numISBN;
	borrowReceipt.listISBN.ISBN = new char* [numISBN];
	for (int i = 0; i < numISBN; i++)
	{
		borrowReceipt.listISBN.ISBN[i] = new char[MAX_CHAR_ISBN];
		do
		{
			cout << "Nhap ISBN sach thu " << i + 1 << ": ";
			cin.getline(ISBN, MAX_CHAR_ISBN);
			T = FindBookISBN(ISBN);
			if (T)
				strcpy(borrowReceipt.listISBN.ISBN[i], ISBN);
			else
				cout << "Khong ton tai sach nay, moi nhap lai: " << endl;

		} while (!T);
	}

	borrowReceipt.borrowDate = GetRealTime();
	borrowReceipt.estimatedDate = FindDateAfter(borrowReceipt.borrowDate, 7);

	//listBorrowReceipt.numBook++;

}

void PrintBorrowReceipt(BorrowReceipt borrowReceipt)
{
	cout << "ID nguoi muon    : " << borrowReceipt.id << endl;
	cout << "Ngay muon        : "; OutputDay(borrowReceipt.borrowDate);
	cout << endl;
	cout << "Ngay tra du kien : "; OutputDay(borrowReceipt.estimatedDate);
	cout << endl;
	cout << "Danh sach sach muon: " << endl;
	for (int i = 0; i < borrowReceipt.listISBN.numISBN; i++)
	{
		cout << " - " << borrowReceipt.listISBN.ISBN[i] << endl;
	}
	cout << endl;
}

void PrintListBorrowReceipt()
{
	for (int i = 0; i < listBorrowReceipt.numReceipt; i++)
	{
		PrintBorrowReceipt(listBorrowReceipt.borrowReceipt[i]);
	}
	cout << endl;
}

void AddBorrowReceipt(BorrowReceipt borrowReceipt)
{
	int n = listBorrowReceipt.numReceipt;
	ListBorrowReceipt listBorrowReceiptTemp;

	listBorrowReceiptTemp.numReceipt = n + 1;
	listBorrowReceiptTemp.borrowReceipt = new BorrowReceipt[n + 1];

	//copy listBook cũ vào listBookTemp
	for (int i = 0; i < n; i++)
	{
		listBorrowReceiptTemp.borrowReceipt[i] = listBorrowReceipt.borrowReceipt[i];
	}

	//Xóa listBook cũ
	delete[] listBorrowReceipt.borrowReceipt;

	//copy listBookTemp vào listBook (để tăng thêm vùng nhớ cho listBook.book
	listBorrowReceipt = listBorrowReceiptTemp;

	//thêm book vào cuối listBook.book
	//n <=> listBook.numBook (đã đc tăng thêm 1) 
	listBorrowReceipt.borrowReceipt[n] = borrowReceipt;
}

void AddBorrowReceiptToList(BorrowReceipt& borrowReceipt)
{

	InputBorrowReceipt(borrowReceipt);

	if (listBorrowReceipt.numReceipt == 0)
	{
		listBorrowReceipt.borrowReceipt = new BorrowReceipt[1];
		listBorrowReceipt.numReceipt = 1;
		listBorrowReceipt.borrowReceipt[0] = borrowReceipt;
		PrintBorrowReceipt(borrowReceipt);
		cout << endl;
	}
	else
	{
		AddBorrowReceipt(borrowReceipt);
	}

}