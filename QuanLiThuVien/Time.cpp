#include"Time.h"
#pragma warning( disable : 4996 )
#pragma warning( disable : 4717 )
int CountDaysOfMonth(Time date)
{
	int count;
	switch (date.month)
	{
	case 4: case 6: case 9: case 11: count = 30; break;
	case 2:
	{
		if (date.year % 400 == 0 or (date.year % 4 == 0 && date.year % 100 != 0))
			count = 29;
		else count = 28;
		break;
	}

	default: count = 31; break;
	}
	return count;
}

bool CheckDate(Time date)
{
	if (1 <= date.month && date.month <= 12 &&
		1 <= date.day && date.day <= 31 && date.day <= CountDaysOfMonth(date)
		&& date.year > 0)
	{
		return true;
	}
	else
		return false;
}

void InputDateCenter(Time& date)
{
	do
	{
		
		(center, ' ');
		cout << "Nhap ngay: ";
		cin >> date.day;
		SetSpace(center, ' ');
		cout << "Nhap thang: ";
		cin >> date.month;
		SetSpace(center, ' ');
		cout << "Nhap nam: ";
		cin >> date.year;
		if (!CheckDate(date))
		{
			//SetSpace(center, ' ');
			cout << "Nhap khong hop le, nhap lai: \n";
		}
		cin.ignore();

	} while (!CheckDate(date));
}

void InputDate(Time& date)
{
	do
	{
		cout << "Nhap ngay: ";
		cin >> date.day;
		cout << "Nhap thang: ";
		cin >> date.month;
		cout << "Nhap nam: ";
		cin >> date.year;
		if (!CheckDate(date))
		{
			cout << "Nhap khong hop le, nhap lai: \n";
		}
		cin.ignore();

	} while (!CheckDate(date));
}
void OutputDay(Time date)
{
	cout << date.day << "/" << date.month << "/" << date.year;
}

void OutputDateToString(Time date, char s[15])
{
	char day[100];
	char month[100];
	char year[100];

	itoa(date.day, day, 10);
	strcat(day, "/");
	itoa(date.month, month, 10);
	strcat(month, "/");
	itoa(date.year, year, 10);
	strcat(day, month);
	strcat(day, year);
	strcpy(s, day);
}
//điều kiền date1<date2
int countDays(Time date1, Time date2)
{
	int count = 0;
	Time temp;
	temp = date1;
	while (!(temp.day == date2.day && temp.month == date2.month && temp.year == date2.year))
	{
		int n = CountDaysOfMonth(temp);
		if (temp.day < n)
		{
			temp.day++;
		}
		else if (temp.month < 12)
		{
			temp.month++;
			temp.day = 1;
		}
		else
		{
			temp.year++;
			temp.month = 1;
			temp.day = 1;

		}
		count++;
	}
	return count;
}

Time FindDateAfter(Time date, int n)
{
	int count = 0;
	Time temp;
	temp = date;
	while (n != count)
	{
		int n = CountDaysOfMonth(temp);
		if (temp.day < n)
		{
			temp.day++;
		}
		else if (temp.month < 12)
		{
			temp.month++;
			temp.day = 1;
		}
		else
		{
			temp.year++;
			temp.month = 1;
			temp.day = 1;

		}
		count++;
	}
	return temp;
}

Time GetRealTime()
{
	//Sat Jul 25 23:33 : 21 2020
	Time temp;
	time_t now;

	time(&now);

	char* s = ctime(&now);

	char* token;
	token = strtok(s, " ");
	token = strtok(NULL, " ");

	if (strcmp(token, "Jan") == 0)
		temp.month = 1;
	if (strcmp(token, "Feb") == 0)
		temp.month = 2;
	if (strcmp(token, "Mar") == 0)
		temp.month = 3;
	if (strcmp(token, "Apr") == 0)
		temp.month = 4;
	if (strcmp(token, "May") == 0)
		temp.month = 5;
	if (strcmp(token, "Jun") == 0)
		temp.month = 6;
	if (strcmp(token, "Jul") == 0)
		temp.month = 7;
	if (strcmp(token, "Aug") == 0)
		temp.month = 8;
	if (strcmp(token, "Sep") == 0)
		temp.month = 9;
	if (strcmp(token, "Oct") == 0)
		temp.month = 10;
	if (strcmp(token, "Nov") == 0)
		temp.month = 11;
	if (strcmp(token, "Dec") == 0)
		temp.month = 12;
	//Sat Jul 25 23:33 : 21 2020
	token = strtok(NULL, " ");
	temp.day = atoi(token);
	token = strtok(NULL, " ");
	token = strtok(NULL, " ");
	temp.year = atoi(token);
	
	return temp;
}