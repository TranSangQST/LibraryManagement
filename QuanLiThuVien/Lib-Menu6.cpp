#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
#include <iomanip>
using namespace std;
#include"Lib-Menu6.h"

void Menu6()
{
	bool back;
	do
	{
		back = false;
		system("cls");
		switch (user.permission)
		{
		case 1:
			Menu6_Admin();
			break;
		case 2:
			Menu6_Manager();
			break;
		case 3:
			Menu6_Staff();
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
		//Menu6();
	} while (back);
	

}
void Menu6_Admin()
{
	cout << "Chuc nang                                  Chon" << endl;
	cout << "Thong ke so luong sach trong thu vien       1" << endl;
	cout << "Thong ke so luong sach theo the loai        2" << endl;
	cout << "Thong ke so luong doc gia                   3" << endl;
	cout << "Thong ke so luong doc gia  theo gioi tinh   4" << endl;
	cout << "Thong ke so luong sach dang duoc muon       5" << endl;
	cout << "Thong ke danh sach doc gia bi tre hen       6" << endl;
	cout << "Nhap 0 de quay lai                          0" << endl;
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
			StatisticsBooks();
			break;
		}
		case 2:
		{
			StatisticsBooksByType();
			break;
		}
		case 3:
		{
			StatisticsReader();
			break;
		}
		case 4:
		{
			StatisticsReaderBySex();
			break;
		}
		case 5:
		{
			StatisticsBorrowBook();
			break;
		}
		case 6:
		{
			StatisticsOverdueReader();
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
	} while (selection < 0 && selection>6);
}
void Menu6_Manager()
{
	cout << "Chuc nang                                  Chon" << endl;
	cout << "Thong ke so luong sach trong thu vien       1" << endl;
	cout << "Thong ke so luong sach theo the loai        2" << endl;
	cout << "Thong ke so luong doc gia                   3" << endl;
	cout << "Thong ke so luong doc gia  theo gioi tinh   4" << endl;
	cout << "Thong ke so luong sach dang duoc muon       5" << endl;
	cout << "Thong ke danh sach doc gia bi tre hen       6" << endl;
	cout << "Nhap 0 de quay lai                          0" << endl;
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
			StatisticsBooks();
			break;
		}
		case 2:
		{
			StatisticsBooksByType();
			break;
		}
		case 3:
		{
			StatisticsReader();
			break;
		}
		case 4:
		{
			StatisticsReaderBySex();
			break;
		}
		case 5:
		{
			StatisticsBorrowBook();
			break;
		}
		case 6:
		{
			StatisticsOverdueReader();
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
	} while (selection < 0 && selection>6);
}
void Menu6_Staff()
{
	cout << "Chuc nang                                  Chon" << endl;
	cout << "Thong ke so luong sach dang duoc muon       5" << endl;
	cout << "Thong ke danh sach doc gia bi tre hen       6" << endl;
	cout << "Nhap 0 de quay lai                          0" << endl;
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
			StatisticsBorrowBook();
			break;
		}
		case 6:
		{
			StatisticsOverdueReader();
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
	} while (selection != 5 && selection != 6 && selection != 0);
}

void StatisticsBooks()
{
	int count = 0;;
	for (int i = 0; i < listBook.numBook; i++)
	{
		count = count + listBook.book[i].count;
	}
	cout << "So luong sach trong thu vien la: " << count << endl;
}

int CheckTypeInList(char listType[MAX_BOOKS][MAX_CHAR_TYPE], int numType, char type[MAX_CHAR_TYPE])
{
	for (int i = 0; i < numType; i++)
	{
		if (strcmp(listType[i], type) == 0)
			return i;
	}
	return -1;
}

void StatisticsBooksByType()
{
	char listType[MAX_BOOKS][MAX_CHAR_TYPE];
	int numType=0;
	int countType[MAX_BOOKS] = { 0 };
	
	for (int i = 0; i < listBook.numBook; i++)
	{
		int pos = CheckTypeInList(listType, numType, listBook.book[i].type);
		if (pos >= 0)
			countType[pos]++;
		else
		{
			strcpy(listType[numType], listBook.book[i].type);
			countType[numType]++;
			numType++;			
		}
	}
	cout << setw(20) << std::left << "The loai";
	cout << "So luong" << endl;
	for (int j = 0; j < numType; j++)
	{
		cout << setw(20) << std::left << listType[j];
		cout << countType[j] << endl;
	}

}

void StatisticsReader()
{
	cout << "So luong doc gia la: " << listReader.numReader << endl;
}

void StatisticsReaderBySex()
{
	//bool listSex[MAX_READERS];
	int countMale = 0;
	int countFeMale = 0;

	for (int i = 0; i < listReader.numReader; i++)
	{
		if (listReader.reader[i].sex)
			countMale++;
		else
			countFeMale++;
	}

	cout << "So luong doc gia nam : " << countMale << endl;
	cout << "So luong doc gia nu  : " << countFeMale << endl;
}

void StatisticsBorrowBook()
{
	int count=0;
	for (int i = 0; i < listBorrowReceipt.numReceipt; i++)
	{
		count = count + listBorrowReceipt.borrowReceipt[i].listISBN.numISBN;
	}
	cout << "So luong sach dang duoc muon: " << count << endl;

}


void OverdueReader(int overdueDay[], int pos[], int &count, Time &now)
{
	count = 0;
	now = GetRealTime();
	for (int i = 0; i < listBorrowReceipt.numReceipt; i++)
	{
		int temp = countDays(listBorrowReceipt.borrowReceipt[i].borrowDate, now);
		if (temp > 7)
		{
			overdueDay[count] = temp-7;
			pos[count]=i;
			count++;
		}
	}

}


void PrintAOverdueReader(BorrowReceipt borrowReceipt, int countOverdueDay )
{
	cout << setw(MAX_CHAR_ID + 3) << std::left << borrowReceipt.id;
	int overdueDay = borrowReceipt.countBorrowDays - 7;
	cout << setw(20) << std::left << countOverdueDay;
	cout << endl;
	int n = MAX_CHAR_ID + 3 + 20;
	SetSpace(n, '-');
	cout << endl;
}

void PrintOverdueReader(int overdueDay[],int pos[], int count)
{
	cout << setw(MAX_CHAR_ID + 3) << std::left << "ID";
	cout << setw(20) << std::left << "So ngay qua han";
	cout << endl;
	int n = MAX_CHAR_ID + 3 +20;
	SetSpace(n, '-');
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		int j = pos[i];
		int countOverdueDay = overdueDay[i];
		PrintAOverdueReader(listBorrowReceipt.borrowReceipt[j],countOverdueDay);
		cout << endl;
	}
	
}

void Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}


int partition(int* a, int *b,int begin, int end)
{
	int pivot = a[end];
	int L = begin;
	int R = end - 1;
	while (1)
	{
		while (L <= R && a[L] > pivot)
		{
			L++;
		}
		while (L <= R && a[R] < pivot)
		{
			R--;
		}
		if (L >= R) break;
		Swap(a[L], a[R]);
		Swap(b[L], b[R]);
		L++;
		R--;
	}
	Swap(a[L], a[end]);
	Swap(b[L], b[end]);
	return L;
}

void QuickSort(int* a, int *b, int begin, int end)
{
	if (begin >= end)
		return;
	int position = partition(a, b,begin, end);
	QuickSort(a, b,begin, position - 1);
	QuickSort(a, b,position + 1, end);
}

void StatisticsOverdueReader()
{
	Time now;
	int count = 0;
	int pos[MAX_READERS];
	int overdueDay[100];
	OverdueReader(overdueDay,pos,count,now);
	QuickSort(overdueDay, pos,0, count - 1);
	cout << "Thong ke so luong doc gia qua han";
	cout << "(tu nhieu nhat den it nhat)" << endl;
	PrintOverdueReader(overdueDay,pos,count);
	cout << "So luong doc gia qua han la: " << count << endl << endl;
	cout << "Tinh den thoi diem hom nay: ";
	OutputDay(now);
	cout << endl;

}


