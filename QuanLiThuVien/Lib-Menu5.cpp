#include"Lib-Menu5.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
void Menu5()
{
	bool back;
	do
	{
		back = false;
		system("cls");
		cout << "Chuc nang               Chon         " << endl;
		cout << "Lap phieu tra sach        1           " << endl;
		cout << "Nhap phim 0 de quay lai   0           " << endl;
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
				BorrowReceipt borrowReceipt;
				InputReturnReceipt(borrowReceipt);
				PrintReturnReceipt(borrowReceipt);
				OverwriteFileBorrow(BorrowFile);
				OverwriteFileBook(BookFile);
				break;
			}
			case 0:
				backToMenu0 = true;
				return;
				//Menu0();
				//break;
			default:
				break;
			}
		} while (selection < 0 || selection>1);

		char nextSelection;
		back = true;
		cout << "Nhap phim bat ki de quay lai: ";
		nextSelection = _getch();
		//cin.ignore();
		//Menu5();
	} while (back);

}

bool FindBorrowReceiptByID(char* ID, BorrowReceipt& borrowReceipt, int &pos)
{
	for (int i = 0; i < listBorrowReceipt.numReceipt; i++)
		if (strcmp(listBorrowReceipt.borrowReceipt[i].id, ID) == 0)
		{
			pos = i;
			borrowReceipt = listBorrowReceipt.borrowReceipt[i];
			return true;
		}
	return false;
}

void DeleteBorrowReceipt(int posBorrowReceipt)
{
	for (int i = posBorrowReceipt; i < listBorrowReceipt.numReceipt - 1; i++)
	{
		listBorrowReceipt.borrowReceipt[i] = listBorrowReceipt.borrowReceipt[i + 1];
	}
	listBorrowReceipt.numReceipt--;
}
void InputReturnReceipt(BorrowReceipt& borrowReceipt)
{
	int posBorrowReceipt = -1;
	char ID[MAX_CHAR_ID];
	bool T = false;
	do
	{
		cout << "Nhap ID doc gia tra sach: ";
		cin.getline(ID, MAX_CHAR_ID);
		T = FindBorrowReceiptByID(ID, borrowReceipt, posBorrowReceipt);
		if (T)
		{
			int posReader = -1;
			Reader reader;
			if (FindReaderByID(ID, reader, posReader))
				cout << "Ten doc gia: " << reader.name << endl;
		}
		else
		{
			cout << "Khong ton tai doc gia nay" << endl;
		}
	} while (!T);
	PrintBorrowReceipt(borrowReceipt);
	borrowReceipt.returnDate = GetRealTime();

	borrowReceipt.countBorrowDays
		= countDays(borrowReceipt.borrowDate, borrowReceipt.returnDate);

	int numLostBook = 0;
	int totalMoney = 0;

	int n = 0;
	cout << "Nhap so luong sach tra: ";
	cin >> n;
	cin.ignore();

	do
	{
		if (n == borrowReceipt.listISBN.numISBN)
			cout << "Sach duoc tra day du. " << endl;
		else if (n < borrowReceipt.listISBN.numISBN)
		{
			numLostBook = borrowReceipt.listISBN.numISBN - n;
			cout << "Nhap ISBN sach bi mat: " << endl;

			for (int i = 0; i < numLostBook; i++)
			{
				Book book;
				int posBook = -1;
				char ISBN[MAX_CHAR_ISBN];
				cout << "Nhap ISBN sach thu: " << i + 1 << " :";
				cin.getline(ISBN, MAX_CHAR_ISBN);
				do
				{
					T = FindBookISBN(ISBN, book, posBook);
					if (T)
					{
						//giảm số lượng của sách bị mất 
						listBook.book[posBook].count--;
						totalMoney = totalMoney + book.price;
					}
					else
					{
						cout << "Khong ton tai sach nay" << endl;
					}
				} while (!T);
			}
		}
		else
		{
			cout << "So luong sach phai nho hon " << borrowReceipt.listISBN.numISBN << endl;
		}
	} while (n > borrowReceipt.listISBN.numISBN);

	int fine1, fine2;

	fine2 = totalMoney = totalMoney * 2;

	if (borrowReceipt.countBorrowDays > 7)
		fine1 = (borrowReceipt.countBorrowDays - 7) * 5000;
	else
		fine1 = 0;
	borrowReceipt.fine = fine1 + fine2;

	DeleteBorrowReceipt(posBorrowReceipt);
	

}

void PrintReturnReceipt(BorrowReceipt borrowReceipt)
{
	cout << "ID nguoi muon     : " << borrowReceipt.id << endl;
	cout << "Ngay muon         : "; OutputDay(borrowReceipt.borrowDate);
	cout << endl;
	cout << "Ngay tra du kien  : "; OutputDay(borrowReceipt.estimatedDate);
	cout << endl;
	cout << "Ngay tra thuc te  : "; OutputDay(borrowReceipt.returnDate);
	cout << endl;
	cout << "So ngay muon sach : " << borrowReceipt.countBorrowDays << endl;
	if (borrowReceipt.countBorrowDays > 7)
	{
		cout << "So ngay qua han : " << borrowReceipt.countBorrowDays - 7 << endl;
	}
	cout << "So tien phai boi thuong: " << borrowReceipt.fine << endl;


}
