#include"Lib-menu0.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
/*-----------------------Hiển thị Menu sau khi đăng nhập thành côn ----------------------------------*/
//Đây là Menu chính của chương trình
//Hiển thị các lựa chọn các Menu chức năng (từ 1 --> 6)

void Menu0()
{
	while (true)
	{
		backToMenu0 = false;
		system("cls");
		cout << "Welcome " << user.name << endl << endl;
		cout << "Quyen nguoi dung: ";
		if (user.permission == 1)
			cout << "ADMIN" << endl;
		else if (user.permission == 2)
			cout << "MANAGER" << endl;
		else if (user.permission == 3)
			cout << "STAFF" << endl;

		cout << endl;

		cout << "Chuc nang                   Chon         " << endl;
		cout << "Quan li nguoi dung           1           " << endl;
		cout << "Quan li doc gia              2           " << endl;
		cout << "Quan li sach                 3           " << endl;
		cout << "Lap phieu muon sach          4           " << endl;
		cout << "Lap phieu tra sach           5           " << endl;
		cout << "Thong ke                     6           " << endl;
		cout << "Dang xuat                    0           " << endl;

		cout << endl;

		int selection;
		do
		{
			cout << "Nhap chuc nang: ";
			cin >> selection;
			//sau mỗi câu lệnh nhập 1 số cuối 1 hàm, nên viết cin.ignore(); 
			//để xóa bộ nhớ đệm, ko ảnh hưởng tới các hàm cin.getline() viêt sau nó
			cin.ignore();
			switch (selection)
			{
			case 1:
				Menu1();
				break;
			case 2:
				Menu2();
				break;
			case 3:
				Menu3();
				break;
			case 4:
				Menu4();
				break;
			case 5:
				Menu5();
				break;
			case 6:
				Menu6();
				break;
			case 0:
				//sau khi chọn logout và agree==1
				//sẽ ra khỏi LogOut và vì backToMenu=true;
				//nên nó sẽ quay lại Menu
				//Ngược lại  agree==0 thì 
				//Thoát khỏi LogOut và tiếp tục lạp lại Menu0
				LogOut();
				//return;
				break;
			default:
			{
				cout << "Nhap khong dung lenh, moi nhap lai: " << endl;
				break;
			}
			}
		} while (selection < 0 || selection>6);

		if (backToMenu == true)
			return;

	}
	
}
