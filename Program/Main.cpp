#include <iostream>
#include"Header.h"
#include"Lib-Menu.h"
#include"File-Processing.h"
#include"Lib-Menu3.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
using namespace std;

int main()
{
	//khởi tạo số lượng user lúc đầu là 0
	container.numUser = 0;

	ReadFileBook(BookFile);
	ReadFileReader(ReaderFile);
	ReadFileBorrow(BorrowFile);	
	Menu();

	return 0;
}
