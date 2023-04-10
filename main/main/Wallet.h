
#include <iostream>
#include <fstream>

using namespace std;

class Wallet
{
private:
	float m_balance;
	string m_name;
	string m_walletNumber;

	friend istream& operator>>(istream& input, Wallet& wallet);
	friend ostream& operator<<(ostream& output, Wallet& wallet);
	friend ofstream& operator<<(ofstream& fout, Wallet& wallet);
	friend ifstream& operator>>(ifstream& fin, Wallet& wallet);
public:
	Wallet(float balance, string name, string walletNumber);
	Wallet();
	Wallet(const Wallet& wallet);

	Wallet& operator=(const Wallet& wallet);

	Wallet& setBalance(float balance);

	string getWalletNumber();

	float getBalance();
};

