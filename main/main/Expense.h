
#include "Date.h"
#include <fstream>
#include <iostream>

using namespace std;

class Expense
{
private:
	string m_category;
	string m_paymentMethod;
	float m_price;
	Date m_date;

	friend istream& operator>>(istream& input, Expense& expense);
	friend ostream& operator<<(ostream& output, Expense& expense);
	friend ofstream& operator<<(ofstream& fout, Expense& expense);
	friend ifstream& operator>>(ifstream& fin, Expense& expense);
public:
	Expense(string category, string paymentMethod, float price, int day, int month, int year);
	Expense(string category, string paymentMethod, float price);
	Expense();
	Expense(const Expense& expense);

	Expense& setCategory(string category);
	Expense& setPrice(float price);

	string getCategory();
	string getPaymentMethod();
	float getPrice();
	Date getDate();
};

