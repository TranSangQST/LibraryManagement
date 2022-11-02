#include"Lib-SignIn.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
void SignIn()
{
	bool check;
	do
	{
	
		WriteUserName(user);
		WritePassword(user);
		check = CheckUser(user);
		if (!check)
		{
			system("cls");
			cout << "Sai ten dang nhap hoac mat khau" << endl;
			cout << "Moi nhap lai: " << endl;
		}
	} while (!check);
	cout << "Chuc mung ban da dang nhap thanh cong: " << endl;
}

//2 hàm WriteUserName(User &userTemp) và WritePassword(User& userTemp), ta truyền vào
//tham số là userTemp để ko ảnh hưởng đến biến toàn cục user,
//nếu muốn WriteUserName hay WritePassword cho biến toàn cục user thì truyền biến đó vào

void WriteUserName(User &userTemp)
{

	cout << "Nhap ten dang nhap: ";
	cin.getline(userTemp.username, MAX_CHAR_USERNAME);
}

void WritePassword(User& userTemp)
{
	while (true)
	{
		char temp;
		int size = 0;

	
		cout << "Nhap mat khau: ";
		while (1)
		{
			temp = _getch();
			if (temp == 13) 
				break;
			if (temp == 8)
			{
				if (size > 0)
				{
					cout << "\b \b";
					size--;

				}
				continue;
			}
			userTemp.password[size] = temp;
			size++;
			cout << temp;
			Sleep(100);
			cout << "\b*";
		}
		if (size >= MAX_CHAR_PASSWORD)
		{
			cout << "Do dai password phai nho hon " << MAX_CHAR_PASSWORD << endl;
		}
		else
		{
			userTemp.password[size] = 0;
			cout << endl;
			break;
		}
	}
	
}

bool CheckUser(User &userTemp)

{	
	for (int i = 0; i < container.numUser; i++)
	{
		if (strcmp(userTemp.username, container.user[i].username) == 0)
			if (strcmp(userTemp.password, container.user[i].password) == 0)
			{
				userTemp = container.user[i];
				return true;
			}
	}
	return false;
}
