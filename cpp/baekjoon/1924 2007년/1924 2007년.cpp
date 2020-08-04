#include <iostream>
using namespace std;

int main()
{
	int DayofMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string StringofDay[7] { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	//1월1일이 월요일
	int Month, Day, Day_sum=0;
	cin >> Month;
	cin >> Day;
	for (int i = 0; i < Month; i++)
	{
		Day_sum += DayofMonth[i];
	}
	Day_sum += (Day-1);
	cout << StringofDay[Day_sum % 7];
	return 0;
}