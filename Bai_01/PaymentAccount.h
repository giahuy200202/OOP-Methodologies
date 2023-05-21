#include "PaymentHistory.h"

class PaymentAccount
{
private:
	string accountNumber;
	double balance;
	dateFormat releaseDate;
	vector <PaymentHistory> tradeHistory;
public:
	PaymentAccount();
	string getAccountNumber();
	double getBalance();
	bool transferTo(double amount);
	void showHistory();
	friend istream& operator>>(istream&, PaymentAccount&);
	friend ostream& operator<<(ostream&, const PaymentAccount&);
};
