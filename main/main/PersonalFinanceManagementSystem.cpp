#include "PersonalFinanceManagementSystem.h"

PersonalFinanceManagementSystem::PersonalFinanceManagementSystem(int walletsSize, int cardsSize, int expensesSize) : m_walletsSize{ walletsSize }, m_cardsSize{ cardsSize }, m_expensesSize{ expensesSize }, m_wallets{ new Wallet[walletsSize] }, m_cards{ new Card[cardsSize] }, m_expenses{ new Expense[expensesSize] } {}

PersonalFinanceManagementSystem::PersonalFinanceManagementSystem() : m_walletsSize{ 0 }, m_cardsSize{ 0 }, m_expensesSize{ 0 }, m_wallets{ new Wallet[0] }, m_cards{ new Card[0] }, m_expenses{ new Expense[0] } {}

PersonalFinanceManagementSystem::~PersonalFinanceManagementSystem()
{
	if (m_wallets != nullptr)
	{
		delete[] m_wallets;
	}
	if (m_cards != nullptr)
	{
		delete[] m_cards;
	}
	if (m_expenses != nullptr)
	{
		delete[] m_expenses;
	}
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setExpenses(Expense* expenses, int expensesSize)
{
	m_expensesSize = expensesSize;
	delete[] m_expenses;
	m_expenses = new Expense[m_expensesSize];
	for (int i = 0; i < expensesSize; i++)
	{
		m_expenses[i] = expenses[i];
	}
	return *this;
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setCards(Card* cards, int cardsSize)
{
	m_cardsSize = cardsSize;
	delete[] m_cards;
	m_cards = new Card[m_cardsSize];
	for (int i = 0; i < cardsSize; i++)
	{
		m_cards[i] = cards[i];
	}
	return *this;
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setWallets(Wallet* wallets, int walletsSize)
{
	m_walletsSize = walletsSize;
	delete[] m_wallets;
	m_wallets = new Wallet[m_walletsSize];
	for (int i = 0; i < walletsSize; i++)
	{
		m_wallets[i] = wallets[i];
	}
	return *this;
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setExpensesSize(int size)
{
	delete[] m_expenses;
	m_expensesSize = size;
	m_expenses = new Expense[m_expensesSize];
	return *this;
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setWalletsSize(int size)
{
	delete[] m_wallets;
	m_walletsSize = size;
	m_wallets = new Wallet[m_walletsSize];
	return *this;
}

PersonalFinanceManagementSystem& PersonalFinanceManagementSystem::setCardsSize(int size)
{
	delete[] m_cards;
	m_cardsSize = size;
	m_cards = new Card[m_cardsSize];
	return *this;
}

int PersonalFinanceManagementSystem::getExpensesSize()
{
	return m_expensesSize;
}

void PersonalFinanceManagementSystem::showPaymentMethods()
{
	for (int i = 0; i < m_walletsSize; i++)
	{
		if(i==0)
		{
			cout << "\n��������: " <<endl<< endl;
		}
		cout << "[" << i + 1 << "] " << "����� ��������: " << m_wallets[i].getWalletNumber() << "\t������: " << m_wallets[i].getBalance() << endl;
	}

	
	for (int i = 0; i < m_cardsSize; i++)
	{
		if(i==0)
		{
			cout << "\n�����: \n" << endl;
		}
		cout << "[" << i + 1 << "] " << "����� �����: " << m_cards[i].getCardNumber() << "\t������: " << m_cards[i].getBalance() << endl;
	}
	cout << endl;
}

bool PersonalFinanceManagementSystem::ReplenishmentOfPaymentMethods(string number, int balance)
{
	int cnt = 0;
	for (int i = 0; i < m_walletsSize; i++)
	{
		if (m_wallets[i].getWalletNumber() == number)
		{
			m_wallets[i].setBalance(m_wallets[i].getBalance() + balance);
			cnt++;
			break;
		}
	}
	if (cnt > 0)
	{
		return true;
	}
	for (int i = 0; i < m_cardsSize; i++)
	{
		if (m_cards[i].getCardNumber() == number)
		{
			m_cards[i].setBalance(m_cards[i].getBalance() + balance);
			cnt++;
			return true;
		}
	}

	return false;
}

void PersonalFinanceManagementSystem::printWallets()
{
	for (int i = 0; i < m_walletsSize; i++)
	{
		cout << m_wallets[i] << endl;
	}
}

void PersonalFinanceManagementSystem::printCards()
{
	for (int i = 0; i < m_cardsSize; i++)
	{
		cout << m_cards[i] << endl;
	}
}

bool PersonalFinanceManagementSystem::DeleteWallet(string number)
{
	int cnt = 0;
	int index = 0;
	int k = 0;

	for (int i = 0; i < m_walletsSize; i++)
	{
		if (m_wallets[i].getWalletNumber() == number)
		{
			cnt++;
			index = i;
			break;
		}
	}

	if (cnt == 0)
	{
		return false;
	}

	m_walletsSize--;

	Wallet* tmp = new Wallet[m_walletsSize];

	for (int i = 0; i < m_walletsSize + 1; i++)
	{
		if (index != i)
		{
			tmp[k] = m_wallets[i];
			k++;
		}
	}

	delete[] m_wallets;

	m_wallets = new Wallet[m_walletsSize];

	for (int i = 0; i < m_walletsSize; i++)
	{
		m_wallets[i] = tmp[i];
	}

	delete[] tmp;
}

bool PersonalFinanceManagementSystem::DeleteCard(string number)
{
	int cnt = 0;
	int index = 0;
	int k = 0;

	for (int i = 0; i < m_cardsSize; i++)
	{
		if (m_cards[i].getCardNumber() == number)
		{
			cnt++;
			index = i;
			break;
		}
	}

	if (cnt == 0)
	{
		return false;
	}

	m_cardsSize--;

	Card* tmp = new Card[m_cardsSize];

	for (int i = 0; i < m_cardsSize + 1; i++)
	{
		if (index != i)
		{
			tmp[k] = m_cards[i];
			k++;
		}
	}

	delete[] m_cards;

	m_cards = new Card[m_cardsSize];

	for (int i = 0; i < m_cardsSize; i++)
	{
		m_cards[i] = tmp[i];
	}

	delete[] tmp;
}

void PersonalFinanceManagementSystem::addWallet(Wallet& wallet)
{
	m_walletsSize++;
	Wallet* tmp = new Wallet[m_walletsSize];

	for (int i = 0; i < m_walletsSize - 1; i++)
	{
		tmp[i] = m_wallets[i];
	}
	tmp[m_walletsSize - 1] = wallet;

	delete[] m_wallets;

	m_wallets = new Wallet[m_walletsSize];

	for (int i = 0; i < m_walletsSize; i++)
	{
		m_wallets[i] = tmp[i];
	}

	delete[] tmp;
}

void PersonalFinanceManagementSystem::addCard(Card& card)
{
	m_cardsSize++;
	Card* tmp = new Card[m_cardsSize];

	for (int i = 0; i < m_cardsSize - 1; i++)
	{
		tmp[i] = m_cards[i];
	}
	tmp[m_cardsSize - 1] = card;

	delete[] m_cards;

	m_cards = new Card[m_cardsSize];

	for (int i = 0; i < m_cardsSize; i++)
	{
		m_cards[i] = tmp[i];
	}

	delete[] tmp;
}

void PersonalFinanceManagementSystem::addExpense(Expense& expense)
{
	int cnt = 0;
	for (int i = 0; i < m_walletsSize; i++)
	{
		if (m_wallets[i].getWalletNumber() == expense.getPaymentMethod())
		{
			if (m_wallets[i].getBalance() >= expense.getPrice())
			{
				m_wallets[i].setBalance(m_wallets[i].getBalance() - expense.getPrice());
				cnt++;
				break;
			}
		}
	}
	for (int i = 0; i < m_cardsSize; i++)
	{
		if (cnt > 0)
		{
			break;
		}
		if (m_cards[i].getCardNumber() == expense.getPaymentMethod())
		{
			if (m_cards[i].getBalance() >= expense.getPrice())
			{
				m_cards[i].setBalance(m_cards[i].getBalance() - expense.getPrice());
				cnt++;
				break;
			}
		}
	}

	if (cnt == 1)
	{

		m_expensesSize++;
		Expense* tmp = new Expense[m_expensesSize];

		for (int i = 0; i < m_expensesSize - 1; i++)
		{
			tmp[i] = m_expenses[i];
		}
		tmp[m_expensesSize - 1] = expense;

		delete[] m_expenses;

		m_expenses = new Expense[m_expensesSize];

		for (int i = 0; i < m_expensesSize; i++)
		{
			m_expenses[i] = tmp[i];
		}

		delete[] tmp;
	}
	else
	{
		system("cls");
		cout << "�������� ����� ������ ������ ��� �� ����� �� ������� �������!!" << endl << endl;
	}
}

int PersonalFinanceManagementSystem::expenseReportAllTime(Expense*& expenses)
{
	expenses = new Expense[m_expensesSize];
	int k = 0;
	for (int i = 0; i < m_expensesSize; i++)
	{
		int cnt = 0;
		for (int j = 0; j < k; j++)
		{
			if (m_expenses[i].getCategory() == expenses[j].getCategory())
			{
				cnt++;
				break;
			}
		}
		if (cnt == 0)
		{
			expenses[k].setCategory(m_expenses[i].getCategory());
			k++;
		}
	}

	Expense* tmp = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;
	expenses = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		expenses[i] = tmp[i];
	}
	delete[] tmp;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m_expensesSize; j++)
		{
			if (expenses[i].getCategory() == m_expenses[j].getCategory())
			{
				expenses[i].setPrice(expenses[i].getPrice() + m_expenses[j].getPrice());
			}
		}
	}

	return k;
}

int PersonalFinanceManagementSystem::expenseReportDay(Expense*& expenses, Date date)
{
	expenses = new Expense[m_expensesSize];
	int k = 0;
	for (int i = 0; i < m_expensesSize; i++)
	{
		int cnt = 0;
		for (int j = 0; j < k; j++)
		{
			if (m_expenses[i].getCategory() == expenses[j].getCategory())
			{
				cnt++;
				break;
			}
		}
		if (date == m_expenses[i].getDate())
		{
			if (cnt == 0)
			{
				expenses[k].setCategory(m_expenses[i].getCategory());
				k++;
			}
		}
	}

	Expense* tmp = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;
	expenses = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		expenses[i] = tmp[i];
	}
	delete[] tmp;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m_expensesSize; j++)
		{
			if (date == m_expenses[j].getDate())
			{
				if (expenses[i].getCategory() == m_expenses[j].getCategory())
				{
					expenses[i].setPrice(expenses[i].getPrice() + m_expenses[j].getPrice());
				}
			}
		}
	}

	return k;
}

int PersonalFinanceManagementSystem::expenseReportMonth(Expense*& expenses, int month, int year)
{
	expenses = new Expense[m_expensesSize];
	int k = 0;
	for (int i = 0; i < m_expensesSize; i++)
	{
		int cnt = 0;
		for (int j = 0; j < k; j++)
		{
			if (m_expenses[i].getCategory() == expenses[j].getCategory())
			{
				cnt++;
				break;
			}
		}
		if (m_expenses[i].getDate().getYear() == year)
		{
			if (m_expenses[i].getDate().getMonth() == month)
			{
				if (cnt == 0)
				{
					expenses[k].setCategory(m_expenses[i].getCategory());
					k++;
				}
			}
		}
	}

	Expense* tmp = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;
	expenses = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		expenses[i] = tmp[i];
	}
	delete[] tmp;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m_expensesSize; j++)
		{
			if (m_expenses[j].getDate().getYear() == year)
			{
				if (m_expenses[j].getDate().getMonth() == month)
				{
					if (expenses[i].getCategory() == m_expenses[j].getCategory())
					{
						expenses[i].setPrice(expenses[i].getPrice() + m_expenses[j].getPrice());
					}
				}
			}
		}
	}

	return k;
}

int PersonalFinanceManagementSystem::expenseReportWeek(Expense*& expenses, Date date)
{
	expenses = new Expense[m_expensesSize];
	int k = 0;
	for (int i = 0; i < m_expensesSize; i++)
	{
		int cnt = 0;
		for (int j = 0; j < k; j++)
		{
			if (m_expenses[i].getCategory() == expenses[j].getCategory())
			{
				cnt++;
				break;
			}
		}
		if (m_expenses[i].getDate() - date <= 6 and m_expenses[i].getDate() - date >= 0)
		{
			if (cnt == 0)
			{
				expenses[k].setCategory(m_expenses[i].getCategory());
				k++;
			}
		}
	}

	Expense* tmp = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;
	expenses = new Expense[k];

	for (int i = 0; i < k; i++)
	{
		expenses[i] = tmp[i];
	}
	delete[] tmp;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m_expensesSize; j++)
		{
			if (m_expenses[j].getDate() - date <= 6 && m_expenses[j].getDate() - date >= 0)
			{
				if (expenses[i].getCategory() == m_expenses[j].getCategory())
				{
					expenses[i].setPrice(expenses[i].getPrice() + m_expenses[j].getPrice());
				}
			}
		}
	}

	return k;
}

void PersonalFinanceManagementSystem::expenseSortPrice()
{
	Expense tmp = {};
	for (int i = 0; i < m_expensesSize; i++)
	{
		for (int j = 0; j < m_expensesSize - i; j++)
		{
			if (m_expenses[j].getPrice() < m_expenses[j + 1].getPrice())
			{
				tmp = m_expenses[j];
				m_expenses[j] = m_expenses[j + 1];
				m_expenses[j + 1] = tmp;
			}
		}
	}
}

int PersonalFinanceManagementSystem::ratingPrice(Expense expenses[3])
{
	expenseSortPrice();
	for (int i = 0; i < 3; i++)
	{
		expenses[i] = m_expenses[i];
	}
	if (m_expensesSize < 3)
	{
		return m_expensesSize;
	}
	else
	{
		return 3;
	}
}

int PersonalFinanceManagementSystem::ratingPriceWeek(Expense*& expenses, Date date)
{
	int k = 0;
	expenseSortPrice();
	for (int i = 0; i < m_expensesSize; i++)
	{
		if (k == 3)
		{
			break;
		}
		if (m_expenses[i].getDate() - date <= 6 && m_expenses[i].getDate() - date >= 0)
		{
			expenses[k] = m_expenses[i];
			k += 1;
		}
	}

	return k;
}

int PersonalFinanceManagementSystem::ratingPriceMonth(Expense*& expenses, int month, int year)
{
	int k = 0;

	expenseSortPrice();

	for (int i = 0; i < m_expensesSize; i++)
	{
		if (k == 3)
		{
			break;
		}
		if (m_expenses[i].getDate().getYear() == year)
		{
			if (m_expenses[i].getDate().getMonth() == month)
			{
				expenses[k] = m_expenses[i];
				k += 1;
			}
		}
	}

	return k;
}

int PersonalFinanceManagementSystem::ratingCategory(Expense*& expensesTop)
{
	Expense* expenses = new Expense[m_expensesSize];
	Expense tmp = {};
	int size = expenseReportAllTime(expenses);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (expenses[j].getPrice() < expenses[j + 1].getPrice())
			{
				tmp = expenses[j];
				expenses[j] = expenses[j + 1];
				expenses[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		expensesTop[i] = expenses[i];
	}

	if (m_expensesSize < 3)
	{
		return m_expensesSize;
	}
	else
	{
		return 3;
	}
}

int PersonalFinanceManagementSystem::ratingCategoryWeek(Expense*& expensesTop, Date date)
{
	Expense* expenses = new Expense[m_expensesSize];
	Expense tmp = {};
	int size = expenseReportWeek(expenses, date);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (expenses[j].getPrice() < expenses[j + 1].getPrice())
			{
				tmp = expenses[j];
				expenses[j] = expenses[j + 1];
				expenses[j + 1] = tmp;
			}
		}
	}

	if (size < 3)
	{
		for (int i = 0; i < size; i++)
		{
			expensesTop[i] = expenses[i];
		}
		delete[] expenses;
		return size;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			expensesTop[i] = expenses[i];
		}
		delete[] expenses;
		return 3;
	}
}

int PersonalFinanceManagementSystem::ratingCategoryMonth(Expense*& expensesTop, int month, int year)
{
	Expense* expenses = new Expense[m_expensesSize];
	Expense tmp = {};
	int size = expenseReportMonth(expenses, month, year);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (expenses[j].getPrice() < expenses[j + 1].getPrice())
			{
				tmp = expenses[j];
				expenses[j] = expenses[j + 1];
				expenses[j + 1] = tmp;
			}
		}
	}

	if (size < 3)
	{
		for (int i = 0; i < size; i++)
		{
			expensesTop[i] = expenses[i];
		}
		delete[] expenses;
		return size;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			expensesTop[i] = expenses[i];
		}
		delete[] expenses;
		return 3;
	}
}

void PersonalFinanceManagementSystem::ToFile2(Expense*& expenses, string path, string str, int cnt)
{
	ofstream fout;

	fout.open(path);

	fout << str << ": " << endl << "��������� / ����������� ������ �� ������ ���� ��������� " << endl;
	for (int i = 0; i < cnt; i++)
	{
		fout << "[" << i + 1 << "]" << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
	}
	fout.close();

	cout << "\n������ ���������!" << endl;
}

void PersonalFinanceManagementSystem::ToFile4(Expense*& expenses, string path, string str, int cnt)
{
	ofstream fout;

	fout.open(path);

	fout << str << ": " << endl << "����� ���������� �������� / ��������� / ���� / ����" << endl;
	for (int i = 0; i < cnt; i++)
	{
		fout << expenses[i] << endl;
	}
	fout.close();

	cout << "\n������ ���������!" << endl;
}

int PersonalFinanceManagementSystem::allReportDay(Expense*& expenses, Date date)
{
	expenses = new Expense[m_expensesSize];
	int cnt = 0;

	for (int i = 0; i < m_expensesSize; i++)
	{
		if (m_expenses[i].getDate() == date)
		{
			expenses[cnt] = m_expenses[i];
			cnt++;
		}
	}

	Expense* tmp = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;

	expenses = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		expenses[i] = tmp[i];
	}

	delete[] tmp;

	return cnt;
}

int PersonalFinanceManagementSystem::allReportWeek(Expense*& expenses, Date date)
{
	expenses = new Expense[m_expensesSize];
	int cnt = 0;

	for (int i = 0; i < m_expensesSize; i++)
	{
		if (m_expenses[i].getDate() - date <= 6 && m_expenses[i].getDate() - date >= 0)
		{
			expenses[cnt] = m_expenses[i];
			cnt++;
		}
	}

	Expense* tmp = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;

	expenses = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		expenses[i] = tmp[i];
	}

	delete[] tmp;

	return cnt;
}

int PersonalFinanceManagementSystem::allReportMonth(Expense*& expenses, int month, int year)
{
	expenses = new Expense[m_expensesSize];
	int cnt = 0;

	for (int i = 0; i < m_expensesSize; i++)
	{
		if (m_expenses[i].getDate().getYear() == year)
		{
			if (m_expenses[i].getDate().getMonth() == month)
			{
				expenses[cnt] = m_expenses[i];
				cnt++;
			}
		}
	}

	Expense* tmp = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;

	expenses = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		expenses[i] = tmp[i];
	}

	delete[] tmp;

	return cnt;
}

int PersonalFinanceManagementSystem::allReport(Expense*& expenses)
{
	expenses = new Expense[m_expensesSize];
	int cnt = 0;

	for (int i = 0; i < m_expensesSize; i++)
	{
		expenses[cnt] = m_expenses[i];
		cnt++;
	}
	Expense* tmp = new Expense[cnt];

	for (int i = 0; i < cnt; i++)
	{
		tmp[i] = expenses[i];
	}

	delete[] expenses;

	expenses = new Expense[cnt];
	for (int i = 0; i < cnt; i++)
	{
		expenses[i] = tmp[i];
	}

	delete[] tmp;

	return cnt;
}

istream& operator>>(istream& input, PersonalFinanceManagementSystem& PFMS)
{
	for (int i = 0; i < PFMS.m_walletsSize; i++)
	{
		if (i == 0)
		{
			cout << "��������: " << endl;
		}
		input >> PFMS.m_wallets[i];
	}

	for (int i = 0; i < PFMS.m_cardsSize; i++)
	{
		if (i == 0)
		{
			cout << "\n�����: " << endl;
		}
		input >> PFMS.m_cards[i];
	}

	for (int i = 0; i < PFMS.m_expensesSize; i++)
	{
		if (i == 0)
		{
			cout << "\n�����: " << endl;
		}
		input >> PFMS.m_expenses[i];
	}
	return input;
}

ostream& operator<<(ostream& output, const PersonalFinanceManagementSystem& PFMS)
{
	for (int i = 0; i < PFMS.m_walletsSize; i++)
	{
		if (i == 0)
		{
			cout << "��������: " << endl<<endl;
		}
		output << PFMS.m_wallets[i] << endl;
	}

	for (int i = 0; i < PFMS.m_cardsSize; i++)
	{
		if (i == 0)
		{
			cout << "\n�����: " << endl << endl;
		}
		output << PFMS.m_cards[i] << endl;
	}

	for (int i = 0; i < PFMS.m_expensesSize; i++)
	{
		if (i == 0)
		{
			cout << "\n�����: " << endl << endl;
		}
		output << PFMS.m_expenses[i] << endl;
	}
	return output;
}

ofstream& operator<<(ofstream& fout, PersonalFinanceManagementSystem& PFMS)
{
	fout << PFMS.m_walletsSize << " " << PFMS.m_cardsSize << " " << PFMS.m_expensesSize << endl;

	for (int i = 0; i < PFMS.m_walletsSize; i++)
	{
		fout << PFMS.m_wallets[i] << endl;
	}
	for (int i = 0; i < PFMS.m_cardsSize; i++)
	{
		fout << PFMS.m_cards[i] << endl;
	}
	for (int i = 0; i < PFMS.m_expensesSize; i++)
	{
		fout << PFMS.m_expenses[i] << endl;
	}

	return fout;
}

void OutOfFile(PersonalFinanceManagementSystem& PFMS)
{
	string path = "Saved data.txt";
	ifstream fin;
	int k = 0;
	int iW = 0;
	int iC = 0;
	int iE = 0;
	int wSize = 0, cSize = 0, eSize = 0;

	fin.open(path);

	while (!fin.eof())
	{
		if (k != 0)
		{
			break;
		}
		fin >> wSize >> cSize >> eSize;
		k++;
	}
	PFMS.setCardsSize(cSize).setWalletsSize(wSize).setExpensesSize(eSize);

	while (!fin.eof())
	{
		if (iW == wSize)
		{
			break;
		}
		fin >> PFMS.m_wallets[iW];
		iW++;
	}

	while (!fin.eof())
	{
		if (iC == cSize)
		{
			break;
		}
		fin >> PFMS.m_cards[iC];
		iC++;
	}

	while (!fin.eof())
	{
		if (iE == eSize)
		{
			break;
		}
		fin >> PFMS.m_expenses[iE];
		iE++;
	}

	fin.close();
}



