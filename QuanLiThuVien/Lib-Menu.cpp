#include"Lib-Menu.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )

//Menu đầu tiên lúc mới mở chương trình
//Đọc file user.bin và mảng container (mảng chứa n phần tử User)
//Nếu như n==0, nghĩa là file rỗng --> Creat tài khoản admin --> Hiển thị lại Menu()

/*-------------------Hien thi man hinh luc chua dang nhap-----------------*/

void Menu()
{
	while (true)
	{
		backToMenu = false;
		bool back;
		do
		{
			back = false;
			system("cls");

			//Khởi tạo giao diện đầu tiên của chương trình

			for (int i = 0; i < 30; i++)
				cout << "-";
			cout << "DO AN QUAN LI THU VIEN - DAI HOC KHOA HOC TU NHIEN";
			for (int i = 0; i < 30; i++)
				cout << "-";
			cout << endl << endl;

			//Đọc file user.bin 
			ReadFileUser(UserFile);

			//Nếu file rỗng thì container.numUser=0 do ban đầu ta đã gán nó = 0

			//Chưa có dữ liệu của User
			//Yêu cầu người dùng tạo admin của chương trình
			if (container.numUser == 0)
			{
				cout << setw(75);
				cout << "Chuong trinh chua cho thong tin cua User";

				cout << endl << endl;

				char selection;
				cout << setw(70);
				cout << "Nhan phim bat ki de tao Admin: ";
				selection = _getch();
				cout << endl;
				//cin.ignore();
				system("cls");
				CreateAdmin();
				back = true;
			}

			//Ngược lại, tạo biến user --> Hàm SignIn
			//Sau khi đăng nhập chuyển đến Menu0 
			//(Menu chính chứa các bảng chọn các menu khác, mỗi menu là 1 chức năng)
			else
			{
				cout << endl;
				cout << "Moi ban dang nhap tai khoan" << endl;
				SignIn();

				//Nếu tài khoản là ACTIVATED thì chào mừng rồi vào Menu0;

				if (user.status == ACTIVATED)
				{

					system("cls");
					cout << "WELCOME" << user.name << endl;
					Menu0();
				}
				//Ngược lại, tài khoản bị BLOCKED thì thông báo tài khoản bị khóa và trở về Menu() ban đầu
				else
				{
					system("cls");
					cout << "Tai khoan ban da bi khoa" << endl;
					char selection;
					back = true;
					cout << "Nhap phim bat ki de quay lai: ";
					selection = getch();

				}

			}
		} while (back);
	}
}

/*-------------------Tao admin neu chua co-----------------*/

void SetSpace(int n, char c)
{
	for (int i = 0; i < n; i++) 
	{
		cout << c;
	}
}
void CreateAdmin()
{
	//Tạo 1 biến usertemp để lưu user tạm ta đang nhập
	User userTemp;

	SetSpace(center, '-');
	cout << "Moi ban tao tai khoan admin cho thu vien";
	SetSpace(center, '-');
	cout << endl << endl;

	//Thông báo cho người dùng quy tắc nhập;

	cout << "Luu y: " << endl;
	cout << "So ki tu username phai nho hon " << MAX_CHAR_USERNAME << endl;
	cout << "So ki tu password phai nho hon " << MAX_CHAR_PASSWORD << endl;
	cout << "So ki tu ten nguoi dung phai nho hon " << MAX_CHAR_NAME_USER << endl;
	cout << "So ki tu cmnd phai nho hon " << MAX_CHAR_CMND << endl;
	cout << "So ki tu dia chi phai nho hon " << MAX_CHAR_ADDRESS << endl << endl;

	
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


	cout << "Chon gioi tinh: " << endl;
	cout << "--- 1 - Nam ---- " << endl;
	cout << "--- 0 - Nu ---- " << endl;
	cout << "--> Chon: ";
	cin >> userTemp.sex;
	cin.ignore();

	userTemp.status = ACTIVATED;
	userTemp.permission = 1;
	
	//Sau khi nhập tất cả thông tin của user (admin)
	//Hàm WriteUser sẽ ghi tiếp vào cuối file user.bin thông tin của user (admin) này
	//trong trường hợp hàm này thì file rỗng nên hàm ghi thông tin user vào file

	WriteFileUser(UserFile, userTemp);

}

