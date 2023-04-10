#include "Wallet.h"

Wallet::Wallet(float balance, string name, string walletNumber) :m_balance{ balance }, m_name{ name }, m_walletNumber{ walletNumber }{}
Wallet::Wallet() :Wallet(0, "None", "None") {}
Wallet::Wallet(const Wallet& wallet) :m_balance{ wallet.m_balance }, m_name{ wallet.m_name }, m_walletNumber{ wallet.m_walletNumber } {}

Wallet& Wallet:: operator=(const Wallet& wallet)
{
	m_balance = wallet.m_balance;
	m_name = wallet.m_name;
	m_walletNumber = wallet.m_walletNumber;

	return *this;
}

Wallet& Wallet::setBalance(float balance)
{
	m_balance = balance;
	return *this;
}

string Wallet::getWalletNumber()
{
	return m_walletNumber;
}

float Wallet::getBalance()
{
	return m_balance;
}

istream& operator>>(istream& input, Wallet& wallet)
{
	cout << "Введите баланс кошелька: ";
	input >> wallet.m_balance;
	cout << "Введите название кошелька: ";
	input >> wallet.m_name;
	cout << "Введите номер кошелька: ";
	input >> wallet.m_walletNumber;
	return input;
}

ostream& operator<<(ostream& output, Wallet& wallet)
{
	output << "Баланс: " << wallet.m_balance << endl
		<< "Имя кошелька: " << wallet.m_name << endl
		<< "Номер кошелька: " << wallet.m_walletNumber << endl;
	return output;
}

ofstream& operator<<(ofstream& fout, Wallet& wallet)
{
	fout << wallet.m_balance << " " << wallet.m_name << " " << wallet.m_walletNumber;
	return fout;
}

ifstream& operator>>(ifstream& fin, Wallet& wallet)
{
	fin >> wallet.m_balance >> wallet.m_name >> wallet.m_walletNumber;
	return fin;
}
