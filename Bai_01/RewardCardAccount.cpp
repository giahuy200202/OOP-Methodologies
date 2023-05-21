#include "RewardCardAccount.h"

RewardCardAccount::RewardCardAccount() {}


int RewardCardAccount::getCurrentPoints() {
	return currentPoints;
}

bool RewardCardAccount::charge(double amount) {
	if (amount + balance <= creditLimit) {
		balance += amount;
		tradeHistory.push_back(PaymentHistory(accountNumber, amount, "Receive", releaseDate));
		currentPoints += (int)(amount * rewardRate);
		return true;
	}
	else return false;
}
void RewardCardAccount::payWithPoints(int pAmount) {
	if (currentPoints >= pAmount) currentPoints -= pAmount;
}
void RewardCardAccount::input() {
	cout << "Input credit account number: ";
	getline(cin, accountNumber);
	creditLimit = 30000000;
	cout << "Input interest rate: "; cin >> interestRate;
	minPayment += balance * 0.05;
	latePenalty = 2000000;
	cout << "Input reward rate: "; cin >> rewardRate;
	cout << "Input day: "; cin >> releaseDate.day;
	cout << "Input month: "; cin >> releaseDate.month;
	cout << "Input year: "; cin >> releaseDate.year; cin.ignore(1);
}
void RewardCardAccount::output() {
	cout << "Account number: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
	cout << "Credit limit: " << fixed << setprecision(0) << creditLimit << endl;
	cout << "Interest rate: " << interestRate << endl;
	cout << "Min payment: " << minPayment << endl;
	cout << "Late penalty " << latePenalty << endl;
	cout << "Reward rate: " << rewardRate << endl;
	cout << "Current points: " << currentPoints << endl;
	cout << "Release date: " << releaseDate.day << "/" << releaseDate.month << "/" << releaseDate.year << endl;
}