
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

	friend istream& operator>>(istream& input, Date & date);
	friend ostream& operator<<(ostream& output, const Date& date);
	friend ofstream& operator<<(ofstream& fout, Date& date);
	friend ifstream& operator>>(ifstream& fin, Date& date);
public:
	Date(int day, int month, int year);
	Date();
	Date(const Date& date);

	int getDay();
	int getMonth();
	int getYear();

	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);

	bool operator==(const Date& date);
	int operator-(const Date& date);
	Date& operator()(int value);
};

