#include "CreditCardAccount.h"

class RewardCardAccount : public CreditCardAccount
{
protected:
	double rewardRate;
	int currentPoints;
public:
	RewardCardAccount();
	int getCurrentPoints();
	bool charge(double amount);
	void payWithPoints(int pAmount);
	void input();
	void output();
};
