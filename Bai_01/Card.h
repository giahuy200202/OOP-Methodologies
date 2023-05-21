#include "PaymentAccount.h"

class Card
{
protected:
	string creditNumber;
	dateFormat releaseDate;
	string linkAccount;
public:
	Card(dateFormat, string);
	string getCreditNumber();
	void input();
	void output();
};