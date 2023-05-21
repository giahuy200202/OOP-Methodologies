#ifndef _PAYMENTHISTORY_H_
#define _PAYMENTHISTORY_H_
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct dateFormat { int day, month, year; };

class PaymentHistory
{
protected:
	string accountNumber;
	double transferAmount;
	string transferContent;
	dateFormat tradeDate;
public:
	PaymentHistory(string, double, string, dateFormat);
	friend ostream& operator<<(ostream&, const PaymentHistory&);
};
#endif