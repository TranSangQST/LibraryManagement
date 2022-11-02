#include"Lib-Menu2.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
void Menu2()
{
	bool back;
	do
	{
		back = false;
		system("cls");
		switch (user.permission)
		{
		case 1:
			Menu2_Admin();
			break;
		case 2:
			Menu2_Manager();
			break;
		case 3:
			Menu2_Staff();
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
	} while (back);

}
void Menu2_Admin()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Xem danh sach doc gia                  1" << endl;
	cout << "Them doc gia                           2" << endl;
	cout << "Chinh sua thong tin mot doc gia        3" << endl;
	cout << "Xoa thong tin mot doc gia              4" << endl;
	cout << "Tim kiem thong tin doc gia theo cmnd   5"<< endl;
	cout << "Tim kiem doc gia theo ten              6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 1:
		{
			PrintListReader();
			break;
		}
		case 2:
		{
			AddReaderToList();
			//ghi đè file vào file Bool.csv
			//vì đã cập nhập listBook nên ta ko cần gọi lại hàm ReadFileBook
			OverwriteFileReader(ReaderFile);
			break;
		}
		case 3:
		{
			ChangeInforReader();
			OverwriteFileReader(ReaderFile);
			PrintListReader();

			break;
		}
		case 4:
		{
			DeleteReaderFromList();
			OverwriteFileReader(ReaderFile);
			PrintListReader();
			break;
		}
		case 5:
		{
			PrintReaderByCMND();
			break;
		}
		case 6:
		{
			FindByName();
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
	} while (selection < 0 || selection>6);
}
void Menu2_Manager()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Xem danh sach doc gia                  1" << endl;
	cout << "Them doc gia                           2" << endl;
	cout << "Chinh sua thong tin mot doc gia        3" << endl;
	cout << "Xoa thong tin mot doc gia              4" << endl;
	cout << "Tim kiem thong tin doc gia theo cmnd   5" << endl;
	cout << "Tim kiem doc gia theo ten              6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 1:
		{
			PrintListReader();
			break;
		}
		case 2:
		{
			AddReaderToList();
			//ghi đè file vào file Bool.csv
			//vì đã cập nhập listBook nên ta ko cần gọi lại hàm ReadFileBook
			OverwriteFileReader(ReaderFile);
			break;
		}
		case 3:
		{
			ChangeInforReader();
			OverwriteFileReader(ReaderFile);
			PrintListReader();

			break;
		}
		case 4:
		{
			DeleteReaderFromList();
			OverwriteFileReader(ReaderFile);
			PrintListReader();
			break;
		}
		case 5:
		{
			PrintReaderByCMND();
			break;
		}
		case 6:
		{
			FindByName();
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
	} while (selection < 0 || selection>6);
}
void Menu2_Staff()
{
	cout << "Chuc nang                             Chon" << endl;
	cout << "Xem danh sach doc gia                  1" << endl;
	cout << "Them doc gia                           2" << endl;
	cout << "Chinh sua thong tin mot doc gia        3" << endl;
	cout << "Tim kiem thong tin doc gia theo cmnd   5" << endl;
	cout << "Tim kiem doc gia theo ten              6" << endl;
	cout << "Nhap 0 de quay lai                     0" << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 1:
		{
			PrintListReader();
			break;
		}
		case 2:
		{
			AddReaderToList();
			//ghi đè file vào file Bool.csv
			//vì đã cập nhập listBook nên ta ko cần gọi lại hàm ReadFileBook
			OverwriteFileReader(ReaderFile);
			break;
		}
		case 3:
		{
			ChangeInforReader();
			OverwriteFileReader(ReaderFile);
			PrintListReader();

			break;
		}
		case 5:
		{
			PrintReaderByCMND();
			break;
		}
		case 6:
		{
			FindByName();
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
	} while (selection < 0 || selection>6 || selection==4);
}

/*------------------------Chuc nang 2.1 Xem danh sách độc giả-------------*/
void PrintAReader(Reader reader) {
	cout << "ID: " << reader.id << endl;
	cout << "Ten nguoi doc: " << reader.name << endl;
	cout << "CMND nguoi doc: " << reader.cmnd << endl;
	cout << "Ngay sinh: ";
	OutputDay(reader.birthday);
	cout << endl;
	cout << "Gioi tinh: ";
	if (reader.sex)
		cout << "Nam" << endl;
	else
		cout << "Nu" << endl;
	cout << "Email: " << reader.email << endl;
	cout << "Dia chi: " << reader.address << endl;
	cout << "Ngay lap the: ";
	OutputDay(reader.newCard);
	cout << endl;
	cout << "Ngay het han: ";
	OutputDay(reader.expiredCard);
	cout << endl;
}

void PrintReader(Reader reader) 
{
	char s[15];
	cout << setw(MAX_CHAR_ID + 1) << std::left << reader.id;
	cout << setw(MAX_CHAR_NAME_READER + 1) << std::left << reader.name;
	cout << setw(MAX_CHAR_CMND + 1) << std::left << reader.cmnd;
	OutputDateToString(reader.birthday, s);
	cout << setw(MAX_CHAR_DATE + 1) << std::left << s;
	if (reader.sex)
		cout << setw(MAX_CHAR_SEX + 5) << std::left << "Nam";
	else
		cout << setw(MAX_CHAR_SEX + 5) << std::left << "Nu";
	cout << setw(MAX_CHAR_EMAIL + 1) << std::left << reader.email;
	cout << setw(MAX_CHAR_ADDRESS + 1) << std::left << reader.address;
	OutputDateToString(reader.newCard, s);
	cout << setw(MAX_CHAR_DATE + 1) << std::left << s;
	OutputDateToString(reader.expiredCard, s);
	cout << setw(MAX_CHAR_DATE + 1) << std::left << s;
	cout << endl;
	int n = MAX_CHAR_ID + MAX_CHAR_NAME_READER + MAX_CHAR_CMND + MAX_CHAR_DATE + MAX_CHAR_SEX
		+ MAX_CHAR_EMAIL + MAX_CHAR_ADDRESS + MAX_CHAR_DATE + MAX_CHAR_DATE + 1 * 8 + 5;
	SetSpace(n, '-');
	cout << endl;
}

void PrintListReader()
{
	int n = MAX_CHAR_ID + MAX_CHAR_NAME_READER + MAX_CHAR_CMND + MAX_CHAR_DATE + MAX_CHAR_SEX
		+ MAX_CHAR_EMAIL + MAX_CHAR_ADDRESS + MAX_CHAR_DATE + MAX_CHAR_DATE + 1 * 8 + 5;
	SetSpace(n, '-');
	cout << endl;
	cout << setw(MAX_CHAR_ID + 1) << std::left << "ID";
	cout << setw(MAX_CHAR_NAME_READER + 1) << std::left << "Ho ten";
	cout << setw(MAX_CHAR_CMND + 1) << std::left << "CMND";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay sinh";
	cout << setw(MAX_CHAR_SEX + 5) << std::left << "Gioi tinh";
	cout << setw(MAX_CHAR_EMAIL + 1) << std::left << "Email";
	cout << setw(MAX_CHAR_ADDRESS + 1) << std::left << "Dia chi";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay tao";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay het han";
	cout << endl;

	SetSpace(n, '-');
	cout << endl;
	for (int i = 0; i < listReader.numReader; i++)
	{
		PrintReader(listReader.reader[i]);
		cout << endl;
	}
}

/*-----------------------Chuc nang 2.2 Them reader-------------------------------*/
void AddReader(Reader reader) {
	int n = listReader.numReader;
	ListReader listReaderTemp;
	listReaderTemp.numReader = n + 1;
	listReaderTemp.reader = new Reader[listReaderTemp.numReader];
	for (int i = 0; i < n; i++)
	{
		listReaderTemp.reader[i] = listReader.reader[i];
	}
	delete[] listReader.reader;
	listReader = listReaderTemp;
	listReader.reader[n] = reader;
}

void InputInforReader(Reader& reader) {
	cout << "Nhap ho ten: ";
	cin.getline(reader.name, MAX_CHAR_NAME_READER);
	cout << "Nhap CMND: ";
	cin.getline(reader.cmnd, MAX_CHAR_CMND);
	cout << "Nhap ngay sinh: " << endl;
	InputDate(reader.birthday);
	cout << "nhap gioi tinh: " << endl;
	cout << "chon gioi tinh: " << endl;
	cout << "--- 1: Nam ---- " << endl;
	cout << "--- 0: Nu ---- " << endl;
	cout << "--> Chon: ";
	cin >> reader.sex;
	cin.ignore();
	cout << "Nhap email: ";
	cin.getline(reader.email, MAX_CHAR_EMAIL);
	cout << "Nhap dia chi: ";
	cin.getline(reader.address, MAX_CHAR_ADDRESS);
	//cout << "Nhap ngay tao the (het han sau 48 thang(4 nam) ke tu ngay tao the): ";
	reader.newCard = GetRealTime();
	reader.expiredCard = reader.newCard;
	reader.expiredCard.year = reader.newCard.year + 4;
}

void AddReaderToList() {
	Reader reader;
	cout << "nhap ID: ";
	cin.getline(reader.id, MAX_CHAR_ID);
	InputInforReader(reader);
	cout << "DONE" << endl;
	if (listReader.numReader == 0)
	{
		listReader.reader = new Reader[1];
		listReader.numReader = 1;
		listReader.reader[0] = reader;
		PrintReader(reader);
		cout << endl;
		PrintListReader();
	}
	else
	{
		AddReader(reader);
	}
}

/*-----------------------Chuc nang 2.3 Chinh sua thong tin mot doc gia-------------------------------*/
void ChangeInforReader() {
	Reader reader;
	int pos = -1;
	char ID[MAX_CHAR_ID];
	cout << "Nhap ID doc gia can chinh sua thong tin: ";
	cin.getline(ID, MAX_CHAR_ID);
	if (FindReaderByID(ID, reader, pos))
	{
		int selection;
		do
		{
			system("cls");

			cout << "Chuc nang                   Chon" << endl;
			cout << "Thay doi ho ten doc gia      1" << endl;
			cout << "Thay doi so cmnd             2" << endl;
			cout << "Thay doi ngay sinh           3" << endl;
			cout << "Thay doi gioi tinh           4" << endl;
			cout << "Thay doi email               5" << endl;
			cout << "Thay doi dia chi             6" << endl;
			cout << "Ket thuc thay doi            0" << endl;

			cout << endl;
			PrintAReader(reader);
			cout << endl;
			cout << "Nhap thong tin doc gia muon thay doi: ";
			cin >> selection;
			cin.ignore();
			switch (selection)
			{
			case 1:
			{
				cout << "Nhap ho ten: ";
				cin.getline(reader.name, MAX_CHAR_NAME_READER);
				break;
			}
			case 2:
			{
				cout << "Nhap CMND: ";
				cin.getline(reader.cmnd, MAX_CHAR_CMND);
				break;
			}
			case 3:
			{
				cout << "Nhap ngay sinh: ";
				InputDate(reader.birthday);
				break;
			}
			case 4:
			{
				cout << "Nhap gioi tinh: " << endl;
				cout << "Chon gioi tinh: " << endl;
				cout << "--- 1: Nam ---- " << endl;
				cout << "--- 0: Nu ---- " << endl;
				cout << "--> Chon: ";
				cin >> reader.sex;
				cin.ignore();
				break;
			}
			case 5:
				cout << "Nhap email: ";
				cin.getline(reader.email, MAX_CHAR_EMAIL);
				break;
			case 6:
				cout << "Nhap dia chi: ";
				cin.getline(reader.address, MAX_CHAR_ADDRESS);
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
		listReader.reader[pos] = reader;
		cout << "Da thay doi thong tin nguoi doc" << endl;
	}
	else
	{
		cout << "Khong ton tai doc gia nay" << endl;
	}
}
//Kiểm tra và tìm reader, vị trí của reader theo ID
bool FindReaderByID(char ID[MAX_CHAR_ID], Reader& reader, int& pos) 
{
	for (int i = 0; i < listReader.numReader; i++)
	{
		if (strcmp(listReader.reader[i].id, ID) == 0)
		{
			reader = listReader.reader[i];
			pos = i;
			return true;
		}
	}
	return false;
}
//kiểm tra có tồn tại ID của Reader
bool FindReaderByID(char ID[MAX_CHAR_ID])
{
	for (int i = 0; i < listReader.numReader; i++)
	{
		if (strcmp(listReader.reader[i].id, ID) == 0)
		{
			return true;
		}
	}
	return false;
}


/*-----------------------Chuc nang 2.4 Xoa thong tin mot doc gia-------------------------------*/
void DeleteReader(int pos) {
	int n = listReader.numReader;
	ListReader listReaderTemp;
	listReaderTemp.numReader = n - 1;
	listReaderTemp.reader = new Reader[listReaderTemp.numReader];
	for (int i = 0; i < pos; i++)
	{
		listReaderTemp.reader[i] = listReader.reader[i];
	}
	for (int i = pos; i < listReaderTemp.numReader; i++)
	{
		listReaderTemp.reader[i] = listReader.reader[i + 1];
	}
	delete[] listReader.reader;
	listReader = listReaderTemp;
}

void DeleteReaderFromList() {
	Reader reader;
	int pos = -1;
	char ID[MAX_CHAR_ID];
	cout << "Nhap ID doc gia can xoa: ";
	cin.getline(ID, MAX_CHAR_ID);
	if (FindReaderByID(ID, reader, pos))
	{
		DeleteReader(pos);
		cout << "Da xoa thong tin doc gia" << endl;
	}
	else
	{
		cout << "Khong ton tai doc gia nay" << endl;
	}
}

/*-----------------------Chuc nang 2.5 Tim kiem doc gia theo CMND-------------------------------*/
bool FindByCMND(char CMND[MAX_CHAR_CMND], Reader& reader, int& pos) {
	for (int i = 0; i < listReader.numReader; i++)
	{
		if (strcmp(listReader.reader[i].cmnd, CMND) == 0)
		{
			reader = listReader.reader[i];
			pos = i;
			return true;
		}
	}
	return false;
}

void PrintReaderByCMND() {
	{
		Reader reader;
		int pos = -1;
		char CMND[MAX_CHAR_CMND];
		cout << "Nhap CMND cua doc gia muon tim: ";
		cin.getline(CMND, MAX_CHAR_CMND);

		if (FindByCMND(CMND, reader, pos))
		{
			PrintAReader(reader);
		}
		else
		{
			cout << "Khong ton tai doc gia nay" << endl;
		}
	}
}

/*-----------------------Chuc nang 2.6 Tim kiem doc gia theo ten-------------------------------*/
void FindByName()
{
	int count = 0;
	char NAME[MAX_CHAR_NAME_READER];
	cout << "Nhap ho ten cua doc gia muon tim: ";
	cin.getline(NAME, MAX_CHAR_NAME_READER);
	int n = MAX_CHAR_ID + MAX_CHAR_NAME_READER + MAX_CHAR_CMND + MAX_CHAR_DATE + MAX_CHAR_SEX
		+ MAX_CHAR_EMAIL + MAX_CHAR_ADDRESS + MAX_CHAR_DATE + MAX_CHAR_DATE + 1 * 8 + 5;
	SetSpace(n, '-');
	cout << endl;
	cout << setw(MAX_CHAR_ID + 1) << std::left << "ID";
	cout << setw(MAX_CHAR_NAME_READER + 1) << std::left << "Ho ten";
	cout << setw(MAX_CHAR_CMND + 1) << std::left << "CMND";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay sinh";
	cout << setw(MAX_CHAR_SEX + 5) << std::left << "Gioi tinh";
	cout << setw(MAX_CHAR_EMAIL + 1) << std::left << "Email";
	cout << setw(MAX_CHAR_ADDRESS + 1) << std::left << "Dia chi";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay tao";
	cout << setw(MAX_CHAR_DATE + 1) << "Ngay het han";
	cout << endl;
	SetSpace(n, '-');
	cout << endl;
	for (int i = 0; i < listReader.numReader; i++)
	{
		if (strcmp(listReader.reader[i].name, NAME) == 0)
		{
			PrintReader(listReader.reader[i]);
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Khong co doc gia can tim" << endl;
	}
}