
#include "Wallet.h"
#include "Card.h"
#include "Expense.h"

class PersonalFinanceManagementSystem
{
private:
	Wallet* m_wallets;
	Card* m_cards;
	Expense* m_expenses;
	int m_walletsSize;
	int m_cardsSize;
	int m_expensesSize;

	friend istream& operator>>(istream& input, PersonalFinanceManagementSystem& PFMS);
	friend ostream& operator<<(ostream& output, const PersonalFinanceManagementSystem& PFMS);
	friend ofstream& operator<<(ofstream& fout, PersonalFinanceManagementSystem& PFMS);

	friend void OutOfFile(PersonalFinanceManagementSystem& PFMS);
public:
	PersonalFinanceManagementSystem(int walletsSize, int cardsSize, int expensesSize);
	PersonalFinanceManagementSystem();
	~PersonalFinanceManagementSystem();

	PersonalFinanceManagementSystem& setExpenses(Expense* expenses, int expensesSize);
	PersonalFinanceManagementSystem& setCards(Card* cards, int cardsSize);
	PersonalFinanceManagementSystem& setWallets(Wallet* wallets, int walletsSize);
	PersonalFinanceManagementSystem& setExpensesSize(int size);
	PersonalFinanceManagementSystem& setWalletsSize(int size);
	PersonalFinanceManagementSystem& setCardsSize(int size);
	
	int getExpensesSize();

	void showPaymentMethods();

	bool ReplenishmentOfPaymentMethods(string number, int balance);

	void printWallets();
	void printCards();

	bool DeleteWallet(string number);
	bool DeleteCard(string number);

	void addWallet(Wallet& wallet);
	void addCard(Card& card);
	void addExpense(Expense& expense);

	int expenseReportAllTime(Expense*& expenses);
	int expenseReportDay(Expense*& expenses, Date date);
	int expenseReportMonth(Expense*& expenses, int month, int year);
	int expenseReportWeek(Expense*& expenses, Date date);

	void expenseSortPrice();

	int ratingPrice(Expense expenses[3]);
	int ratingPriceWeek(Expense*& expenses, Date date);
	int ratingPriceMonth(Expense*& expenses, int month, int year);

	int ratingCategory(Expense*& expensesTop);
	int ratingCategoryWeek(Expense*& expensesTop, Date date);
	int ratingCategoryMonth(Expense*& expensesTop, int month, int year);

	void ToFile2(Expense*& expenses, string path, string str, int cnt);
	void ToFile4(Expense*& expenses, string path, string str, int cnt);

	int allReportDay(Expense*& expenses, Date date);
	int allReportWeek(Expense*& expenses, Date date);
	int allReportMonth(Expense*& expenses, int month, int year);
	int allReport(Expense*& expenses);
};

