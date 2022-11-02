#include"Lib-Menu1.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
/*------------------------Menu chức năng 1 - Quản lí người dùng----------------------------------------*/
//Hàm Menu1(), sẽ dựa vào permisson của user để nhận biết là admin, magager hay staff để hiển thị menu chức năng 1 phù hợp
//với quyền của mỗi loại người dùng
void Menu1()
{
	bool back;
	do
	{
		back = false;

		system("cls");
		cout << "Chuc nang 1 - Quan li nguoi dung" << endl << endl;
	
		switch (user.permission)
		{
		case 1:
			Menu1_Admin();
			break;
		case 2:
			Menu1_Manager();
			break;
		case 3:
			Menu1_Staff();
			break;
		default:
			break;
		}

		//nếu như backToMenu0=true thì ta đưa lại menu0, ko cần lặp lại menu1
		if (backToMenu0 == true)
			return;

		char selection;
		cout << "Nhap phim bat ki de quay lai: ";
		back = true;
		selection = _getch();
		//cin.ignore();

	} while (back);
}

/*-----------------------Menu chức năng 1 của admin------------------------*/
//bao gồm các chức năng từ 2 - đến 6 (do chức năng 1 - đăng nhập ta đã thực hiện ở đầu chương trình-------------------------
void Menu1_Admin()
{
	cout << "Chuc nang                   Chon         " << endl;
	cout << "Dang xuat                    2           " << endl;
	cout << "Doi mau khau                 3           " << endl;
	cout << "Cap nhap thong tin           4           " << endl;
	cout << "Tao nguoi dung               5           " << endl;
	cout << "Phan quyen nguoi dung        6           " << endl;
	cout << "Xem thong tin ca nhan        7           " << endl;
	cout << "Nhap 0 de quay lai           0           " << endl;
	cout << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 2:
		{
			//sau khi chọn logout và agree==1
			//sẽ ra khỏi LogOut và vì backToMenu0=true;
			//nên nó sẽ quay lại Menu0
			//vì backToMenu = true; nên sau đó nó quay lại Menu
			//Ngược lại  agree==0 thì 
			//Thoát khỏi LogOut và tiếp tục lạp lại Menu1
			LogOut();
			return;
			//break;
		}
		case 3:
		{
			system("cls");
			ChangePassword();
			OverwriteFile(UserFile); //ghi đè lại file user.bin
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile(); 
			break;
		}
		case 4:
		{
			system("cls");
			ChangeProfile(); //ghi đè lại file user.bin
			OverwriteFile(UserFile);
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile();
			break;
		}
		case 5:
			system("cls");
			CreateUser();
			//sau ghi tạo user mới và ghi thêm vào file user.bin, ta đọc lại vào container để cập nhập
			//Vì phải đổi cấp phát động của container.user nên ta đọc lại file cho gọn
			ReadFileUser(UserFile);
			return;
			//Menu1();
			//break;
		case 6:
			system("cls");
			ChangePermissionAndStatus();
			//ghi đè lại file
			OverwriteFile(UserFile);
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//	ReadFile();

			//Menu1();
			return;
		case 7:
			system("cls");
			PrintUser(user);
			break;
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
	} while (selection < 1 || selection>7);

	/*
	cout << "nhan 0 de quay lai: ";
	do
	{
		
		cout << "nhap lenh: ";
		cin >> selection;
		cin.ignore();
		if (selection)
			cout << "nhap sai lenh, moi nhap lai: ";
	} while (selection);
	Menu1();
	*/



}

void Menu1_Manager()
{
	cout << "Chuc nang                   Chon         " << endl;
	cout << "Dang xuat                    2           " << endl;
	cout << "Doi mau khau                 3           " << endl;
	cout << "Cap nhap thong tin           4           " << endl;
	cout << "Xem thong tin ca nhan        7           " << endl;
	cout << "Nhap 0 de quay lai           0           " << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 2:
		{
			LogOut();
			return;
			//break;
		}
		case 3:
		{
			system("cls");
			ChangePassword();
			OverwriteFile(UserFile); //ghi đè lại file user.bin
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile(); 
			break;
		}
		case 4:
		{
			system("cls");
			ChangeProfile(); //ghi đè lại file user.bin
			OverwriteFile(UserFile);
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile();
			break;
		}
		case 7:
			system("cls");
			PrintUser(user);
			break;
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
	} while (selection < 1 || selection>7 || selection==5 || selection == 6);

}
void Menu1_Staff()
{
	cout << "Chuc nang                   Chon         " << endl;
	cout << "Dang xuat                    2           " << endl;
	cout << "Doi mau khau                 3           " << endl;
	cout << "Cap nhap thong tin           4           " << endl;
	cout << "Xem thong tin ca nhan        7           " << endl;
	cout << "Nhap 0 de quay lai           0           " << endl;
	int selection;
	do
	{
		cout << "Nhap chuc nang: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 2:
		{
			
			LogOut();
			return;
			//break;
		}
		case 3:
		{
			system("cls");
			ChangePassword();
			OverwriteFile(UserFile); //ghi đè lại file user.bin
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile(); 
			break;
		}
		case 4:
		{
			system("cls");
			ChangeProfile(); //ghi đè lại file user.bin
			OverwriteFile(UserFile);
			//vì đã chỉnh sửa container.user trong ChangePassword() nên ko cần đọc file lần nữa
			//ReadFile();
			break;
		}
		case 7:
			system("cls");
			PrintUser(user);
			break;
		case 0:
			backToMenu0 = true;
			return;
			//Menu0();
			//break;
		default:
			break;
		}
	} while (selection < 1 || selection>7 || selection == 5 || selection == 6);
}


/*------------------------------------Chức năng 1.2 - đăng xuất ---------------------*/
void LogOut()
{
	system("cls");
	cout << "Ban co chac muon dang xuat ? " << endl;

	int agree;
	cout << "1 - Co" << endl;
	cout << "0 - Khong" << endl;
	cin >> agree;
	cin.ignore();

	// nếu chọn 1 thì quay về Menu đầu tiên (đăng nhập)
	do
	{
		if (agree == 1)
		{
			//đưa dấu hiệu để sau khi return vê menu1 nó sẽ back đến menu
			backToMenu = true;
			backToMenu0 = true;
			return;
			//Menu();
		}
		else if (agree == 0)
			//Ngược lại nếu chọn 0 thì quay về Menu1 (chức năng 1)
		{
			//quay lai menu1
			return;
		}
	} while (agree != 1 && agree != 0);

}

/*------------------------------------Chức năng 1.3 - đổi password ---------------------*/
void ChangePassword()
{
	char old_password[MAX_CHAR_PASSWORD];
	cout << "Nhap mau khau cu: ";
	char temp;
	int size = 0;
	while (1)
	{
		temp = _getch();
		if (temp == 13)
			break;
		old_password[size] = temp;
		size++;
		cout << temp;
		Sleep(100);
		cout << "\b*";
	}
	old_password[size] = 0;
	cout << endl;

	//kiểm tra mật khẩu vừa nhập có trùng mật khẩu user hay ko
	//giống mỗi lần đổi pass fb
	if (strcmp(user.password, old_password) == 0)
	{
		cout << "Nhap mau khau moi: " << endl;
		//đổi mật khẩu của user 
		//ta truyền trực tiếp biến cục bộ user vào hàm để thay đổi user.password
		WritePassword(user);

		//sau khi đổi pass của user (các thông tin khác của user ko đổi)
		//ta sửa đổi thông tin của container.user 
		for (int i = 0; i < container.numUser; i++)
		{
			if (strcmp(user.username, container.user[i].username) == 0)
			{
				//sửa lại thông tin container.user[i] theo user
				container.user[i] = user;
			}
		}

		//ra ngoài chương trình và ghi lại file user.bin	
		cout << "Thay doi mat khau thanh cong" << endl;
	}
	else
	{
		system("cls");
		cout << "Nhap sai mat khau cu, moi nhap lai: " << endl;
		//nếu nhập sai thì quay lại ô nhập pass
		ChangePassword();
	}
}

/*------------------------------------Chức năng 1.4 - đổi thông tin cá nhân ---------------------*/
//Hàm này tương tự thay đổi pass nhưng ko cần phải kiểm tra mật khẩu 
void ChangeProfile()
{
	//cập nhập các thông tin của user
	//thay đổi trực tiếp thông của user, ko cần thông qua biến tạm
	//Thông báo cho người dùng quy tắc nhập 

	int selection;
	do
	{

		system("cls");

		cout << "Chuc nang                   Chon         " << endl;
		cout << "Thay doi ho ten              1           " << endl;
		cout << "Thay doi ngay sinh           2           " << endl;
		cout << "Thay doi so cmnd             3           " << endl;
		cout << "Thay doi dia chi             4           " << endl;
		cout << "Thay doi gioi tinh           5           " << endl;
		cout << "Ket thuc thay doi            0           " << endl;

		cout << "Nhap thong tin muon thay doi: ";
		cin >> selection;
		cin.ignore();
		switch (selection)
		{
		case 1:
		{
			cout << "Nhap ho ten nguoi dung: ";
			cin.getline(user.name, MAX_CHAR_NAME_USER);
			break;
		}
		case 2:
		{
			cout << "Nhap ngay thang nam sinh: " << endl;
			InputDate(user.birthday);
			break;
		}
		case 3:
		{
			cout << "Nhap CMND: ";
			cin.getline(user.cmnd, MAX_CHAR_CMND);
			break;
		}
		case 4:
		{
			cout << "Nhap dia chi: ";
			cin.getline(user.address, MAX_CHAR_ADDRESS);
			break;
		}
		case 5:
			cout << "Nhap gioi tinh: " << endl;
			cout << "--- 1 - Nam ---- " << endl;
			cout << "--- 0 - Nu ---- " << endl;
			cout << "--> Chon: ";
			cin >> user.sex;
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
	} while (selection!=0);
	



	// tìm và thay đổi thông tin của container.user[thứ i] (==user đang dùng)
	for (int i = 0; i < container.numUser; i++)
	{
		if (strcmp(user.username, container.user[i].username) == 0)
		{
			container.user[i] = user;
			break;
		}
	}

	cout << "Thay doi thong tin ca nhan thanh cong" << endl;
}



/*------------------------------------Chức năng 1.5 - tạo user mới ---------------------*/
//Hàm này tương tự hàm CreadAdmin, chỉ khác là mình phải nhập thêm tình trạng ACTIVATED/BLOCK
//và loại người dùng: quản lí hoặc chuyên viên
void CreateUser()
{
	//tạo 1 biến userTemp để nhập thông tin user mới vào biến này
	User userTemp;
	cout << "--------Create User--------" << endl;

	WriteUserName(userTemp);
	WritePassword(userTemp);

	cout << "Nhap ho ten nguoi dung: ";
	cin.getline(userTemp.name, MAX_CHAR_NAME_USER);
	cout << "Nhap ngay thang nam sinh: " << endl;
	InputDate(userTemp.birthday);
	cout << "Nhap CMND: ";
	cin.getline(userTemp.cmnd, MAX_CHAR_CMND);
	cout << "Nhap dia chi: ";
	cin.getline(userTemp.address, MAX_CHAR_ADDRESS);
	cout << "Nhap gioi tinh: ";
	cout << "Chon gioi tinh: " << endl;
	cout << "--- 1 - Nam ---- " << endl;
	cout << "--- 0 - Nu ---- " << endl;
	cout << "--> Chon: ";
	cin >> userTemp.sex;
	cin.ignore();

	cout << "Chon loai nguoi dung: " << endl;
	int permisson;
	do
	{
		cout << "---Nhap 2 de neu la quan li: " << endl;
		cout << "---Nhap 3 de neu la chuyen vien: " << endl;
		cin >> permisson;
		cin.ignore();
		if (permisson != 2 && permisson != 3)
			cout << "Nhap sai quyen, moi nhap lai: " << endl;
	} while (permisson != 2 && permisson != 3);
	userTemp.permission = permisson;
	userTemp.status=ACTIVATED;

	//sau khi tạo xong userTemp, ghi vào cuối file user.bin thông tin userTemp
	WriteFileUser(UserFile,userTemp);
}

/*------------------------------------Chức năng 1.6 - phân quyền người dùng ---------------------*/
void ChangePermissionAndStatus()
{
	cout << "Chuc nang                      Chon         " << endl;
	cout << "Phan quyen cho nguoi dung       1           " << endl;
	cout << "Kich hoat hoac khoa tai khoan   2           " << endl;
	cout << "Nhap 0 de quay lai              0           " << endl;
	cout << endl;
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
			ChangePermission();
			break;
		}
		case 2:
		{
			ChangeStatus();
			break;
		}
		case 0:
			//Menu0();
			//break;
			return;
		default:
		{
			cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
			break;
		}
		}
	} while (selection !=1 && selection!=2 && selection != 0);

	
}
void ChangePermission()
{
	User userTemp;
	bool T;

	do
	{
		system("cls");
		T = false;
		cout << "Nhap username cua nguoi dung muon phan quyen: ";
		cin.getline(userTemp.username, 50);
		for (int i = 0; i < container.numUser; i++)
		{
			T = (strcmp(userTemp.username, container.user[i].username) == 0);
			if (T)
			{
				cout << "Chon loai nguoi dung: " << endl;
				int permisson;
				cout << "---Nhap 2 de neu la quan li: " << endl;
				cout << "---Nhap 3 de neu la chuyen vien: " << endl;
				cin >> permisson;
				cin.ignore();
				userTemp.permission = permisson;
				//tìm người dùng trong container, nếu trùng với user vừa nhập thì đổi permisson
				container.user[i].permission = userTemp.permission;

				break;
			}
		}
		if (!T)
		{
			cout << "Khong ton tai ten dang nhap nay " << endl;
			cout << "Nhan phim bat ki de quay lai: ";
			char selection;
			selection = _getch();
			cout << endl;
		}
	} while (!T);
	cout << "Da doi quyen nguoi dung" << endl;
}void ChangeStatus()
{
	User userTemp;
	bool T;

	do
	{
		system("cls");
		T = false;
		cout << "Nhap username cua nguoi dung muon phan quyen: ";
		cin.getline(userTemp.username, 50);
		for (int i = 0; i < container.numUser; i++)
		{
			T = (strcmp(userTemp.username, container.user[i].username) == 0);
			if (T)
			{
				cout << "Chon loai nguoi dung: " << endl;
				cout << "---Nhap 1 de Activated: " << endl;
				cout << "---Nhap 0 de Block: " << endl;
				cin >> userTemp.status;
				cin.ignore();
				if (userTemp.status)
				{
					cout << "Ban da kich hoat tai khoan " << userTemp.username << endl;
				}
				else
				{
					cout << "Ban da khoa tai khoan " << userTemp.username << endl;
				}
				container.user[i].status = userTemp.status;
				break;
			}
		}
		if (!T)
		{
			cout << "Khong ton tai ten dang nhap nay! " << endl;
			cout << "Nhan phim bat ki de quay lai ";
			char selection;
			selection = _getch();
			cout << endl;
		}
	} while (!T);
	cout << "Da doi trang thai nguoi dung" << endl;
}
void PrintUser(User userTemp)
{
	cout << "Ten dang nhap: " << userTemp.username << endl;
	cout << "Ho va ten: " << userTemp.name << endl;
	cout << "Ngay sinh: ";
	OutputDay(userTemp.birthday);
	cout << endl;
	cout << "CMND: " << userTemp.cmnd << endl;
	cout << "Dia chi: " << userTemp.address << endl;
	cout << "Gioi tinh: " << userTemp.sex << endl;
	cout << "Loai nguoi dung: ";
	if (userTemp.permission == 1)
		cout << "--ADMIN--" << endl;
	else if (userTemp.permission == 2)
		cout << "--MANAGER--" << endl;
	else if (userTemp.permission == 3)
		cout << "--STAFF--" << endl;

}