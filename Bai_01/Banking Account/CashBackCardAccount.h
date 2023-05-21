#include "RewardCardAccount.h"

class CashbackCardAccount :public CreditCardAccount
{
protected:
	double cashbackRate;
	int currentCashBack;
public:
	CashbackCardAccount();
	int getCurrentCashBack();
	bool charge(double amount);
	void  redeemCashBack();
	void input();
	void output();
};
