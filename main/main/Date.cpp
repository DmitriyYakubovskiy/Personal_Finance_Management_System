
#include <ctime>
#include <chrono>
#include <cassert>
#include <map>
#include "Date.h"

time_t now = time(0);
tm* ltm = localtime(&now);

map <int, int> MonthNumber = { {1, 31},
{2, 28},
{3, 31},
{4, 30},
{5, 31},
{6, 30},
{7, 31},
{8, 31},
{9, 30},
{10, 31},
{11, 30},
{12, 31},
};

Date::Date(int day, int month, int year) :m_day{ day }, m_month{ month }, m_year{ year }
{
	if(month==2 and year%4==0)
	{
		assert(day > 0 and day < 29 and "Eror date!");
	}
	else
	{
		assert(day>0 and day<MonthNumber[month] and "Eror date!");
	}
}

Date::Date() :Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year) {}

Date::Date(const Date& date) :m_day{ date.m_day }, m_month{ date.m_month }, m_year{ date.m_year } {}

int Date::getDay()
{
	return m_day;
}

int Date::getMonth()
{
	return m_month;
}

int Date::getYear()
{
	return m_year;
}

Date& Date::setDay(int day)
{
	m_day = day;
	return *this;
}

Date& Date::setMonth(int month)
{
	m_month = month;
	return *this;
}

Date& Date::setYear(int year)
{
	m_year = year;
	return *this;
}

bool Date::operator==(const Date& date)
{
	if(this==&date)
	{
		return true;
	}

	if(m_year==date.m_year)
	{
		if(m_month==date.m_month)
		{
			if(m_day==date.m_day)
			{
				return true;
			}
		}
	}
	return false;
}

int Date::operator-(const Date& date)
{
	if (this == &date)
	{
		return 0;
	}

	int S1 = 0;
	int S2 = 0;

	for (int i = 1; i < m_month + 1; i++)
	{
		S1 += MonthNumber[i];
	}

	for (int i = 1; i < date.m_month + 1; i++)
	{
		S2 += MonthNumber[i];
	}

	return ( ( (m_year%4==0?m_year*366:m_year*365) + S1 + m_day) - ( (date.m_year % 4 == 0 ? date.m_year * 366 : date.m_year * 365) + S2 + date.m_day) );
}

Date& Date::operator()(int value)
{
	if (value == 0)
	{
		return *this;
	}
	int S = (m_year * 365 + m_month * 30 + m_day) + value;
	m_year = S / 365;
	m_month = S % 365 / 30;
	m_day = S % 365 % 30;
	return *this;
}

istream& operator>>(istream& input, Date& date)
{
	int day, month, year;
	input >> day >> month >> year;
	date = { day,month,year };
	return input;
}

ostream& operator<<(ostream& output, const Date& date)
{
	output << ((date.m_day < 10) ? "0" : "") << date.m_day << "." << ((date.m_month < 10 ? "0":"")) <<date.m_month<< "." << date.m_year;
	return output;
}

ofstream& operator<<(ofstream& fout, Date& date)
{
	fout << date.m_day<<" " << date.m_month<<" " << date.m_year;
	return fout;
}

ifstream& operator>>(ifstream& fin, Date& date)
{
	fin >> date.m_day >> date.m_month >> date.m_year;
	return fin;
}
