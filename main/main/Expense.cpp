#include "Expense.h"

Expense::Expense(string category, string paymentMethod, float price, int day, int month, int year) : m_category{ category }, m_paymentMethod{ paymentMethod }, m_price{ price }
{
	m_date = { day,month,year };
}

Expense::Expense(string category, string paymentMethod, float price) : m_category{ category }, m_paymentMethod{ paymentMethod }, m_price{ price } { m_date = {}; }

Expense::Expense() :Expense("None", "None", 0)
{
	m_date = {};
}

Expense::Expense(const Expense& expense) :m_category{ expense.m_category }, m_paymentMethod{ expense.m_paymentMethod }, m_price{ expense.m_price }
{
	m_date = expense.m_date;
}

Expense& Expense::setCategory(string category)
{
	m_category = category;
	return *this;
}

Expense& Expense::setPrice(float price)
{
	m_price = price;
	return *this;
}

string Expense::getCategory()
{
	return m_category;
}

string Expense::getPaymentMethod()
{
	return m_paymentMethod;
}

float Expense::getPrice()
{
	return m_price;
}

Date Expense::getDate()
{
	return m_date;
}

istream& operator>>(istream& input, Expense& expense)
{
	cout << "Введитe номер платежного средства: ";
	input >> expense.m_paymentMethod;
	cout << "Введите категорию: ";
	input >> expense.m_category;
	cout << "Введите цену: ";
	input >> expense.m_price;
	cout << "Введите дату(день месяц год (через пробел)): ";
	input >> expense.m_date;
	return input;
}

ostream& operator<<(ostream& output, Expense& expense)
{
	output << "Номер платежного средства: " << expense.m_paymentMethod << endl
		<< "Категория: " << expense.m_category << endl
		<< "Цена: " << expense.m_price << endl
		<< "Время совершения покупки: " << expense.m_date << endl;
	return output;
}

ofstream& operator<<(ofstream& fout, Expense& expense)
{
	fout << expense.m_paymentMethod << " " << expense.m_category << " " << expense.m_price << " " << expense.m_date.getDay()<<" "<<expense.m_date.getMonth()<<" "<<expense.m_date.getYear();
	return fout;
}

ifstream& operator>>(ifstream& fin, Expense& expense)
{
	fin >> expense.m_paymentMethod >> expense.m_category >> expense.m_price >> expense.m_date;
	return fin;
}
