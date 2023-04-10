
#include "Card.h"
#include <cassert>

Card::Card(string cardNumber, string CVC, int month, int year, float balance, CardType type) : m_balance{ balance }, m_type{ type }
{
	setDate(month, year);
	setCardNumber(cardNumber).setCVC(CVC);
}

Card::Card() :Card("0000000000000000", "000", 1, 2024, 0, debit) {}

Card::Card(const Card& card) : m_balance{ card.m_balance }, m_type{ card.m_type }
{
	m_validityPeriod = card.m_validityPeriod;
	setCardNumber(card.m_cardNumber).setCVC(card.m_CVC);
}

Card& Card::setCardNumber(string cardNumber)
{
	assert(cardNumber.size() == 16 and "����� ����� ��� 16 ����!");
	m_cardNumber=cardNumber;
	return *this;
}

Card& Card::setCVC(string CVC)
{
	assert(CVC.size() == 3 and "��� CVC ��� ��� �����!");
	m_CVC=CVC;
	return *this;
}

Card& Card::setDate(int month, int year)
{
	assert(month > 0 and month < 13 and year>2022 and "Error Date!!");
	m_validityPeriod.month = month;
	m_validityPeriod.year = year;
	return *this;
}

Card& Card::setBalance(float balance)
{
	m_balance = balance;
	return *this;
}

string Card::getCardNumber()
{
	return m_cardNumber;
}

float Card::getBalance()
{
	return m_balance;
}

Card& Card::operator=(const Card& card)
{
	m_balance = card.m_balance;
	m_type = card.m_type;
	m_validityPeriod = card.m_validityPeriod;
	setCardNumber(card.m_cardNumber).setCVC(card.m_CVC);
	return *this;
}

istream& operator>>(istream& input, Card& card)
{
	string cardNumber, CVC;
	int year, month;
	cout << "������� ����� �����: ";
	input >>cardNumber;
	card.setCardNumber(cardNumber);
	cout << "������� CVC �����: ";
	input >> CVC;
	card.setCVC(CVC);
	cout << "������� ���� ��������(����� ��� (����� ������)): ";
	input >> month >> year;
	card.setDate(month, year);
	cout << "������� ������ �����: ";
	input >> card.m_balance;
	cout << "������� ��� �����(��������� ��� ���������): ";
	string type;
	input >> type;
	type == "���������" ? card.m_type = credit : card.m_type = debit;
	return input;
}

ostream& operator<<(ostream& output, Card& card)
{
	output << "������: " << card.m_balance << endl
		<< "����� �����: " << card.m_cardNumber << endl
		<< "CVC ���: " << card.m_CVC << endl
		<< "���� ��������:" << card.m_validityPeriod.month << "/" << card.m_validityPeriod.year << endl
		<< "��� �����: " << ((card.m_type) == debit ? "���������" : "���������") << endl;
	return output;
}

ofstream& operator<<(ofstream& fout, Card& card)
{
	fout << card.m_cardNumber << " " << card.m_CVC << " " << card.m_validityPeriod.month<<" " << card.m_validityPeriod.year << " " << card.m_balance << " " << card.m_type;
	return fout;
}

ifstream& operator>>(ifstream& fin, Card& card)
{
	int type;
	fin >> card.m_cardNumber >> card.m_CVC >> card.m_validityPeriod.month >> card.m_validityPeriod.year >> card.m_balance >> type;
	type == 0 ? card.m_type = debit : card.m_type = credit;
	return fin;
}