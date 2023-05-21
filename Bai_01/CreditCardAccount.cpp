#include "CreditCardAccount.h"

CreditCardAccount::CreditCardAccount() {}
double CreditCardAccount::getBalance() {
	return balance;
}
bool CreditCardAccount::charge(double amount) {
	if (amount + balance <= creditLimit) {
		balance += amount;
		tradeHistory.push_back(PaymentHistory(accountNumber, amount, "Receive", releaseDate));
		return true;
	}
	else return false;
}
void CreditCardAccount::payment(double amount) {
	balance -= amount;
}
void CreditCardAccount::showHistory() {
	for (int i = 0; i < tradeHistory.size(); i++) {
		cout << "------TRANSACTION " << i + 1 << "--------" << endl;
		cout << tradeHistory[i] << endl;
	}
}
void CreditCardAccount::input() {
	cout << "Input credit account number: ";
	getline(cin, accountNumber);
	creditLimit = 30000000;
	cout << "Input interest rate: "; cin >> interestRate;
	minPayment += balance * 0.05;
	latePenalty = 2000000;
	cout << "Input day: "; cin >> releaseDate.day;
	cout << "Input month: "; cin >> releaseDate.month;
	cout << "Input year: "; cin >> releaseDate.year; cin.ignore(1);
}
void CreditCardAccount::output() {
	cout << "Account number: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
	cout << "Credit limit: " << fixed << setprecision(0) << creditLimit << endl;
	cout << "Interest rate: " << interestRate << endl;
	cout << "Min payment: " << minPayment << endl;
	cout << "Late penalty " << latePenalty << endl;
	cout << "Release date: " << releaseDate.day << "/" << releaseDate.month << "/" << releaseDate.year << endl;
}
void CreditCardAccount::pusblishCreditCard() {
	int n;
	cout << "-----INPUT-----\n";
	while (true){
		cout << "Input the number of cards to publish ( max 6 ): ";
		cin >> n; cin.ignore(1);
		if (n <= 6) break;
	}
	for (int i = 0; i < n; i++) {
		cout << "Card " << i + 1 << endl;
		listCard.push_back(Card(releaseDate, accountNumber));
		listCard[i].input();
	}
	cout << "\n-----OUTPUT-----\n";
	for (int i = 0; i < n; i++) {
		cout << "Card " << i + 1 << endl;
		listCard[i].output();
	}
}
vector <Card>  CreditCardAccount::getlistCard() {
	return listCard;
}

int  CreditCardAccount::getCurrentPoints() { return 0; }
void  CreditCardAccount::payWithPoints(int pAmount){}
int   CreditCardAccount::getCurrentCashBack() { return 0; }
void  CreditCardAccount::redeemCashBack() {}