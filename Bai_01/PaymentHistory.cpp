#include "PaymentHistory.h"

PaymentHistory::PaymentHistory(string a, double b, string c, dateFormat d) {
	accountNumber = a;
	transferAmount = b;
	transferContent = c;
	tradeDate = d;
}

ostream& operator<<(ostream& out, const PaymentHistory& a) {
	out << "Account number: " << a.accountNumber << endl;
	if(a.transferContent=="Receive") out << "Transfer amount: +" << a.transferAmount << endl;
	else out << "Transfer amount: -" << a.transferAmount << endl;
	out << "Transfer content: " << a.transferContent << endl;
	out << "Trade date: " << a.tradeDate.day << "/" << a.tradeDate.month << "/" << a.tradeDate.year << endl;
	return out;
}