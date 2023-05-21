#include "Card.h"

class CreditCardAccount
{
protected:
	double creditLimit;
	double interestRate;
	double minPayment;
	double latePenalty;
	double balance;

	string accountNumber;
	dateFormat releaseDate;

	vector <PaymentHistory> tradeHistory;
	vector <Card> listCard;
public:
	CreditCardAccount();
	double getBalance();
	void payment(double amount);
	void showHistory();
	virtual bool charge(double amount);
	virtual void input();
	virtual void output();
	virtual int getCurrentPoints();
	virtual void payWithPoints(int pAmount);
	virtual int  getCurrentCashBack();
	virtual void redeemCashBack();
	void pusblishCreditCard();
	vector <Card> getlistCard();
};
