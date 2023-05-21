#include "PaymentAccount.h"

PaymentAccount::PaymentAccount() {}
string PaymentAccount::getAccountNumber() {
	return accountNumber;
}
double PaymentAccount::getBalance() {
	return balance;
}
bool PaymentAccount::transferTo(double amount) {
	if (balance < amount) return false;
	else {
		balance -= amount;
		tradeHistory.push_back(PaymentHistory(accountNumber, amount, "Payment", releaseDate));
		return true;
	}
}
void PaymentAccount::showHistory() {
	for (int i = 0; i < tradeHistory.size(); i++) {
		cout << "------TRANSACTION " << i + 1 << "--------" << endl;
		cout << tradeHistory[i] << endl;
	}
}
istream& operator>>(istream& in, PaymentAccount& a) {
	cout << "Input account number: ";
	getline(in, a.accountNumber);
	cout << "Input balance: ";
	in >> a.balance; 
	cout << "Input day: "; in >> a.releaseDate.day;
	cout << "Input month: "; in >> a.releaseDate.month;
	cout << "Input year: "; in >> a.releaseDate.year; in.ignore(1);
	return in;
}
ostream& operator<<(ostream& out, const PaymentAccount& a) {
	out << "Account number: " << a.accountNumber << endl;
	out << "Balance: " << fixed << setprecision(0) << a.balance << endl;
	out << "Release date: " << a.releaseDate.day << "/" << a.releaseDate.month << "/" << a.releaseDate.year << endl;
	return out;
}