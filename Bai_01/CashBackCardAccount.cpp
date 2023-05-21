#include "CashBackCardAccount.h"

CashbackCardAccount::CashbackCardAccount() {}

int CashbackCardAccount::getCurrentCashBack() {
	return currentCashBack;
}
bool CashbackCardAccount::charge(double amount) {
	if (amount + balance <= creditLimit) {
		balance += amount;
		tradeHistory.push_back(PaymentHistory(accountNumber, amount, "Receive", releaseDate));
		currentCashBack += (int)(amount * cashbackRate);
		return true;
	}
	else return false;
}
void CashbackCardAccount::redeemCashBack() {
	balance -= currentCashBack;
	currentCashBack = 0;
}
void CashbackCardAccount::input() {
	cout << "Input credit account number: ";
	getline(cin, accountNumber);
	creditLimit=30000000;
	cout << "Input interest rate: "; cin >> interestRate;
	minPayment += balance * 0.05;
	latePenalty = 2000000;
	cout << "Input cash back rate: "; cin >> cashbackRate;
	cout << "Input day: "; cin >> releaseDate.day;
	cout << "Input month: "; cin >> releaseDate.month;
	cout << "Input year: "; cin >> releaseDate.year; cin.ignore(1);
}
void CashbackCardAccount::output() {
	cout << "Account number: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
	cout << "Credit limit: " << fixed << setprecision(0) << creditLimit << endl;
	cout << "Interest rate: " << interestRate << endl;
	cout << "Min payment: " << minPayment << endl;
	cout << "Late penalty " << latePenalty << endl;
	cout << "Cash back rate: " << cashbackRate << endl;
	cout << "Current cash back: " << currentCashBack << endl;
	cout << "Release date: " << releaseDate.day << "/" << releaseDate.month << "/" << releaseDate.year << endl;
}