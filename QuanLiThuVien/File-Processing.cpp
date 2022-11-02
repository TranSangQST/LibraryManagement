#include"File-Processing.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )

void EncodeUser(char *s)
{
	for (int i = 0; i < sizeof(User); i++)
	{
		s[i] = s[i] + 1;
	}
}
void DecryptionUser(char *s)
{
	for (int i = 0; i < sizeof(User); i++)
	{
		s[i] = s[i] - 1;
	}
}
//*/


/*------------------------------------------Đọc File user.bin vào mảng container.user-------------------------------- */
//Hàm đọc file, đọc từng user vào mảng container đến khi hết file
void ReadFileUser(const char *filename)
{
	delete[]container.user;
	FILE* fi;
	fi = fopen(filename, "rb");
	if (!fi)
	{
		return;
	}

	// Tạo ra 1 containerTemp tạm, cấp phát động 1 lượng = số lượng User tối đa
	int n = 0;
	ListUser containerTemp;
	containerTemp.numUser = MAX_USERS;
	containerTemp.user = new User[MAX_USERS];

	//Đọc vào containerTemp.user thông tin các users từ file
	char s[sizeof(User) + 1] = { 0 };
	while (fread(s, sizeof(User), 1, fi))
	{
		DecryptionUser(s);
		memcpy(&containerTemp.user[n], s, sizeof(User));
		n++;
	}
	//containerTemp.user[n]v

	//n chính là số lượng user trong file
	//ta cấp phát động cho container.user 1 lượng = n 
	container.numUser = n;
	container.user = new User[n];

	//Ta copy từng user trong mảng containerTemp.user sang mảng container.user

	for (int i = 0; i < n; i++)
	{
		container.user[i] = containerTemp.user[i];
	}

	//Xóa vùng nhớ của containerTemp.user
	delete[]containerTemp.user;

	//Chú ý: Ta ko được viết container=containerTemp vì nó sẽ copy luôn lượng bộ nhớ mà ta
	//cấp phát cho containerTemp (=Max_USERS), trong khi thực tế ta chỉ cần n vùng nhớ
	fclose(fi);
}


/*------------------------------------------Ghi thêm vào 1 userTemp vào cuối File user.bin -------------------------------- */
//Ghi thông tin của user được truyền vào cuối file user.bin
//Tham số truyền vào hàm là userTemp, để ta có thể thêm 1 user bất kì mà ko ảnh hưởng
//đến biến toàn cục user 

void WriteFileUser(const char* filename, User userTemp)
{
	//thêm userTemp vào cuối file
	FILE* fo;
	fo = fopen(filename, "ab");
	if (!fo)
	{
		cout << "Khong co output" << endl;
		return;
	}
	//fwrite(&userTemp, sizeof(User), 1, fo);
	char s[sizeof(User) + 1] = { 0 };
	memcpy(s, &userTemp, sizeof(User));
	EncodeUser(s);
	fwrite(s, sizeof(User), 1, fo);
	fclose(fo);
}

/*------------------------------Xóa toàn bộ file user.bin và ghi lại (cập nhập) file mới từ container.user ---------------------------- */

//Ghi đè thông tin (tức là xóa hết nội file user.bin) rồi ghi lại từng container.user[i]
//vào bên trong user.bin
//hàm này áp dụng mỗi khi ta thay đổi thông tin như đổi mật khẩu,....
//-->Nên sửa lại bằng fseek chứ ko nên viết hàm này
//nhưng code ghi đè trước cho dễ, nếu còn thời gian sẽ sửa code
void OverwriteFile(const char* filename)
{
	FILE* fo;
	fo = fopen(filename, "wb");
	if (!fo)
	{
		cout << "Khong co output" << endl;
		return;
	}
	for (int i = 0; i < container.numUser; i++)
	{
		//fwrite(&container.user[i], sizeof(User), 1, fo);
		char s[sizeof(User) + 1] = { 0 };
		memcpy(s, &container.user[i], sizeof(User));
		EncodeUser(s);
		fwrite(s, sizeof(User), 1, fo);
	}
	fclose(fo);
}


/*------------------------------Xu li file Book---------------------------*/
Book ConvertLineToListBook(char* line)
{
	Book book;
	strcpy(book.ISBN, strtok(line, ","));
	strcpy(book.name, strtok(NULL, ","));
	strcpy(book.author, strtok(NULL, ","));
	strcpy(book.publishingCompany, strtok(NULL, ","));
	book.publishingYear= atoi(strtok(NULL, ","));
	strcpy(book.type, strtok(NULL, ","));
	book.price = atoi(strtok(NULL, ","));
	book.count = atoi(strtok(NULL, ","));
	return book;
}
void ReadFileBook(const char* filename)
{
	ifstream fi(filename);

	if (fi.fail())
	{
		cerr << "Khong tim thay file nguon";
		return;
	}

	fi >> listBook.numBook;
	//sau mỗi lần đọc số phải thêm ignore để xóa bộ nhớ đệm
	fi.ignore();


	listBook.book = new Book[listBook.numBook];
	char line[MAX_BOOKS];

	for (int i = 0; i < listBook.numBook; i++)
	{
		fi.getline(line, MAX_BOOKS);
		listBook.book[i] = ConvertLineToListBook(line);
	}
	fi.close();
}


//hàm này sẽ xóa toàn bộ file cũ và ghi đè file mới vào
//điều kiên: listBook đã được cập nhập
void OverwriteFileBook(const char* filename)
{
	ofstream fo;
	fo.open(filename);

	if (fo.fail())
	{
		cout << "Khong co file " << filename << endl;
		return;
	}

	//ghi số lượng sách 
	fo << listBook.numBook << endl;

	for (int i = 0; i < listBook.numBook; ++i)
	{
		//truyền tham chiều biến book vào listBook.book[i]
		Book& book = listBook.book[i];

		fo << book.ISBN << "," << book.name << "," << book.author << "," << book.publishingCompany
			<< ","<<book.publishingYear <<"," <<book.type << "," << book.price << "," << book.count << endl;
	}

	fo.close();
}

/*------------------------------Xu li file Reader---------------------------*/
//*
Reader ConvertLineToListReader(char* line)
{
	Reader reader;
	strcpy(reader.id, strtok(line, ","));
	strcpy(reader.name, strtok(NULL, ","));
	strcpy(reader.cmnd, strtok(NULL, ","));

	reader.birthday.day = atoi(strtok(NULL, "/"));
	reader.birthday.month = atoi(strtok(NULL, "/"));
	reader.birthday.year = atoi(strtok(NULL, ","));
	//gioi tinh
	char sex[5];
	strcpy(sex, strtok(NULL, ","));
	if (strcmp(sex, "Nam") == 0)
		reader.sex = true;
	else if(strcmp(sex, "Nu") == 0)
		reader.sex = false;
	strcpy(reader.email, strtok(NULL, ","));
	strcpy(reader.address, strtok(NULL, ","));
	//the muon the tra
	reader.newCard.day = atoi(strtok(NULL, "/"));
	reader.newCard.month = atoi(strtok(NULL, "/"));
	reader.newCard.year = atoi(strtok(NULL, ","));

	reader.expiredCard.day = atoi(strtok(NULL, "/"));
	reader.expiredCard.month = atoi(strtok(NULL, "/"));
	reader.expiredCard.year = atoi(strtok(NULL, ","));

	return reader;
}
void ReadFileReader(const char* filename)
{
	ifstream fi(filename);

	if (fi.fail())
	{
		cerr << "Khong tim thay file nguon";
		return;
	}

	fi >> listReader.numReader;
	//sau mỗi lần đọc số phait thêm ignore để xóa bộ nhớ đệm
	fi.ignore();


	listReader.reader = new Reader[listReader.numReader];
	char line[1000];

	for (int i = 0; i < listReader.numReader; i++)
	{
		fi.getline(line, 1000);
		listReader.reader[i] = ConvertLineToListReader(line);
	}
	fi.close();
}


//hàm này sẽ xóa toàn bộ file cũ và ghi đè file mới vào
//điều kiên: listBook đã được cập nhập
void OverwriteFileReader(const char* filename)
{
	ofstream fo;
	fo.open(filename);

	if (fo.fail())
	{
		cout << "Khong co file " << filename << endl;
		return;
	}

	//ghi số lượng sách 
	fo << listReader.numReader << endl;

	//*
	for (int i = 0; i < listReader.numReader; ++i)
	{
		//truyền tham chiều biến book vào listBook.book[i]
		Reader& reader = listReader.reader[i];
		fo << reader.id << "," << reader.name << "," << reader.cmnd << ",";
		fo << reader.birthday.day << "/" << reader.birthday.month << "/" << reader.birthday.year << ",";
		if (reader.sex)
			fo << "Nam" << ",";
		else
			fo << "Nu" << ",";
		fo << reader.email << "," << reader.address << ",";
		fo << reader.newCard.day << "/" << reader.newCard.month << "/" << reader.newCard.year << ",";
		fo << reader.expiredCard.day << "/" << reader.expiredCard.month << "/" << reader.expiredCard.year << "," << endl;
	}
	//*/
	fo.close();
}
//*/

/*----------------------Tao file phieu muon ----------------*/
BorrowReceipt ConvertLineToListBorrow(char* line)
{
	BorrowReceipt borrowReceipt;
	strcpy(borrowReceipt.id, strtok(line, ","));

	borrowReceipt.borrowDate.day = atoi(strtok(NULL, "/"));
	borrowReceipt.borrowDate.month = atoi(strtok(NULL, "/"));
	borrowReceipt.borrowDate.year = atoi(strtok(NULL, ","));

	borrowReceipt.estimatedDate.day = atoi(strtok(NULL, "/"));
	borrowReceipt.estimatedDate.month = atoi(strtok(NULL, "/"));
	borrowReceipt.estimatedDate.year = atoi(strtok(NULL, ","));

	borrowReceipt.listISBN.numISBN = atoi(strtok(NULL, ","));

	int numISBN = borrowReceipt.listISBN.numISBN;

	borrowReceipt.listISBN.ISBN = new char* [numISBN];
	for (int i = 0; i < numISBN; i++)
	{
		borrowReceipt.listISBN.ISBN[i] = new char[MAX_CHAR_ISBN];
		strcpy(borrowReceipt.listISBN.ISBN[i], strtok(NULL, ","));
	}
	return borrowReceipt;
}
void ReadFileBorrow(const char* filename)
{
	ifstream fi(filename);

	if (fi.fail())
	{
		cerr << "Khong tim thay file nguon";
		return;
	}

	fi >> listBorrowReceipt.numReceipt;
	//sau mỗi lần đọc số phait thêm ignore để xóa bộ nhớ đệm
	fi.ignore();

	int n = listBorrowReceipt.numReceipt;
	listBorrowReceipt.borrowReceipt = new BorrowReceipt[n];
	char line[1000];

	for (int i = 0; i < n; i++)
	{
		fi.getline(line, 1000);
		listBorrowReceipt.borrowReceipt[i] = ConvertLineToListBorrow(line);
	}
	fi.close();
}
void OverwriteFileBorrow(const char* filename)
{
	ofstream fo;
	fo.open(filename);

	if (fo.fail())
	{
		cout << "Khong co file" << filename << endl;
		return;
	}

	//ghi số lượng sách 
	fo << listBorrowReceipt.numReceipt << endl;

	//*
	for (int i = 0; i < listBorrowReceipt.numReceipt; ++i)
	{
		//truyền tham chiều biến book vào listBook.book[i]
		BorrowReceipt& borrowReceipt = listBorrowReceipt.borrowReceipt[i];
		fo << borrowReceipt.id << ",";
		fo << borrowReceipt.borrowDate.day << "/"
			<< borrowReceipt.borrowDate.month << "/"
			<< borrowReceipt.borrowDate.year << ",";
		fo << borrowReceipt.estimatedDate.day << "/"
			<< borrowReceipt.estimatedDate.month << "/"
			<< borrowReceipt.estimatedDate.year << ",";
		fo << borrowReceipt.listISBN.numISBN << ",";
		for (int j = 0; j < borrowReceipt.listISBN.numISBN; j++)
			fo << borrowReceipt.listISBN.ISBN[j] << ",";
		fo << endl;
	}
	fo.close();
}

/*
void ReadFileBorrow(const char* filename)
{
	ifstream fi(filename);
	cout << filename << endl;
	if (fi.fail())
	{
		cerr << "Ko tim thay file nguon";
		return;
	}

	fi >> listBorrowReceipt.numReceipt;
	//sau mỗi lần đọc số phait thêm ignore để xóa bộ nhớ đệm
	fi.ignore();

	int n = listBorrowReceipt.numReceipt;
	listBorrowReceipt.borrowReceipt = new BorrowReceipt[n];
	char line[1000];

	for (int i = 0; i < n; i++)
	{
		fi.getline(line, 1000);
		listBorrowReceipt.borrowReceipt[i] = ConvertLineToListBorrow(line);
	}
	fi.close();
}
/**/
//chưa viết xong
/*
void PrintFileBorrow(BorrowReceipt borrowReceipt, Reader reader)
{
	ofstream fo;

	char txt[5] = "txt";
	char filename[MAX_CHAR_ID+20];
	strcpy(filename, borrowReceipt.id);
	strcat(txt,filename);
	fo.open(filename,ios::out);

	fo << "Ho ten nguoi muon: " << reader.name << endl;
	fo << "ID nguoi muon    : " << borrowReceipt.id << endl;
	fo << "Ngay muon        : ";
	fo << borrowReceipt.borrowDate.day << "/"
		<< borrowReceipt.borrowDate.month << "/"
		<< borrowReceipt.borrowDate.year << endl;

	fo << "Ngay tra du kien : "; 
	fo << borrowReceipt.estimatedDate.day << "/"
		<< borrowReceipt.estimatedDate.month << "/"
		<< borrowReceipt.estimatedDate.year << endl;
	fo << "danh sach sach muon: " << endl;
	for (int i = 0; i < borrowReceipt.listISBN.numISBN; i++)
	{
		cout << " - " << borrowReceipt.listISBN.ISBN[i] << endl;
	}



	fo.close();
}
*/
/*
void ReadFileBorrow(const char* filename)
{
	ifstream fi(filename);
	cout << filename << endl;
	if (fi.fail())
	{
		cerr << "Ko tim thay file nguon";
		return;
	}

	fi >> listBorrowReceipt.numReceipt;
	//sau mỗi lần đọc số phait thêm ignore để xóa bộ nhớ đệm
	fi.ignore();
	
	int num = listBorrowReceipt.numReceipt;
	listBorrowReceipt.borrowReceipt = new BorrowReceipt[num];

	for (int i = 0; i < num; i++)
	{
		BorrowReceipt borrowReceipt = listBorrowReceipt.borrowReceipt[i];
		fi.getline(borrowReceipt.id, MAX_CHAR_ID);
		fi >> borrowReceipt.borrowDate.day;
		fi.seekg(1, 1);
		fi >> borrowReceipt.borrowDate.month;
		fi.seekg(1, 1);
		fi >> borrowReceipt.borrowDate.year;

		fi >> borrowReceipt.estimatedDate.day;
		fi.seekg(1, 1);
		fi >> borrowReceipt.estimatedDate.month;
		fi.seekg(1, 1);
		fi >> borrowReceipt.estimatedDate.year;

		for (int j = 0; j < borrowReceipt.listISBN.numISBN; j++)
		{
			fi.getline(borrowReceipt.listISBN.ISBN[j], MAX_CHAR_ISBN);
		}
	}
	fi.close();
}
*/