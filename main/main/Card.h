
#include <iostream>
#include <fstream>

using namespace std;

enum CardType
{
	debit,
	credit,
};

struct date
{
	int month;
	int year;
};

class Card
{
private:
	string m_cardNumber;
	string m_CVC;
	date m_validityPeriod;
	float m_balance;
	CardType m_type;

	friend istream& operator>>(istream& input, Card& card);
	friend ostream& operator<<(ostream& output, Card& card);
	friend ofstream& operator<<(ofstream& fout, Card& card);
	friend ifstream& operator>>(ifstream& fin, Card& card);

public:
	Card(string cardNumber, string CVC, int m, int y, float balance, CardType type);
	Card();
	Card(const Card& card);

	Card& setCardNumber(string cardNumber);
	Card& setCVC(string CVC);
	Card& setDate(int month, int year);
	Card& setBalance(float balance);

	string getCardNumber();
	float getBalance();

	Card& operator=(const Card& card);
};

