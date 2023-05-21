#include "CashBackCardAccount.h"

int main()
{
	cout << "------------PAYMENT ACCOUNT-------------\n";
	PaymentAccount pay;
	cin >> pay;
	CreditCardAccount* a[] = { new CreditCardAccount(), new RewardCardAccount(), new CashbackCardAccount() };
	int n = sizeof(a) / sizeof(a[0]);
	while (true)
	{
		system("cls");
		cout << "------------PAYMENT ACCOUNT-------------\n";
		cout << pay;
		cout << "\n-----------------MENU-------------------\n";
		cout << "1. Credit Card Account" << endl;
		cout << "2. Reward Card Account" << endl;
		cout << "3. Cash back Card Account" << endl;
		cout << "4. Exit" << endl;
		int choose;
		cout << "Input choose: "; cin >> choose; cin.ignore(1);
		if (choose == 1) 
		{
			cout << "\n------------CREDIT CARD ACCOUNT-------------\n";
			a[0]->input(); a[0]->output();
			cout << "\n------------PUBLISH CREDIT CARD-------------\n";
			a[0]->pusblishCreditCard();
			cout << "\n------------USE CREDIT CARD-------------\n";
			string name; cout << "Input credit card to use: "; getline(cin, name);
			vector<Card> temp = a[0]->getlistCard();
			int level = 1;
			while (level <=5)
			{
				a[0]->charge(1000000*(double)level);
				level += 2;
			}
			cout << "\n------------HISTORY OF CREDIT CARD-------------\n";
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i].getCreditNumber() == name) temp[i].output();
			} cout << endl;
			a[0]->showHistory();
			cout << "\n------------PAY CREDIT CARD BY PAYMENT ACCOUNT-------------\n";
			cout << "-----PAYMENT ACCOUNT------\n";
			if (pay.transferTo(a[0]->getBalance())) {
				a[0]->payment(a[0]->getBalance()); a[0]->output();
				cout << pay;
				cout << "\n-----HISTORY OF PAYMENT ACCOUNT------\n";
				pay.showHistory();
			}
			else cout << "Dont have enough money to pay" << endl;
			system("pause");
		}
		else if (choose == 2)
		{
			cout << "\n------------REWARD CARD ACCOUNT-------------\n";
			a[1]->input(); a[1]->output();
			cout << "\n------------PUBLISH REWARD CARD-------------\n";
			a[1]->pusblishCreditCard();
			cout << "\n------------USE REWARD CARD-------------\n";
			string name; cout << "Input reward card to use: "; getline(cin, name);
			vector<Card> temp = a[1]->getlistCard();
			int level = 1;
			while (level <= 5)
			{
				a[1]->charge(1000000 * (double)level);
				level += 2;
			}
			cout << "\n------------PAY WITH 100 POINTS-------------\n";
			
			a[1]->payWithPoints(100);
			a[1]->output();
			cout << "\n------------HISTORY OF REWARD CARD-------------\n";
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i].getCreditNumber() == name) temp[i].output();
			} cout << endl;
			a[1]->showHistory();
			cout << "\n------------PAY REWARD CARD BY PAYMENT ACCOUNT-------------\n";
			cout << "-----PAYMENT ACCOUNT------\n";
			if (pay.transferTo(a[1]->getBalance())) {
				a[1]->payment(a[1]->getBalance()); a[1]->output();
				cout << pay;
				cout << "\n-----HISTORY OF PAYMENT ACCOUNT------\n";
				pay.showHistory();
			}
			else cout << "Dont have enough money to pay" << endl;
			system("pause");

		}
		else if (choose == 3)
		{
			cout << "\n------------CASH BACK CARD ACCOUNT-------------\n";
			a[2]->input(); a[2]->output();
			cout << "\n------------PUBLISH CASH BACK CARD-------------\n";
			a[2]->pusblishCreditCard();
			cout << "\n------------USE CASH BACK CARD-------------\n";
			string name; cout << "Input cash back card to use: "; getline(cin, name);
			vector<Card> temp = a[2]->getlistCard();
			int level = 1;
			while (level <= 5)
			{
				a[2]->charge(1000000 * (double)level);
				level += 2;
			}
			cout << "\n------------CASH BACK-------------\n";
			cout << "Cash back is available: " << a[2]->getCurrentCashBack() << endl;
			cout << "Redeem cash back" << endl;
			a[2]->redeemCashBack();
			a[2]->output();
			cout << "\n------------HISTORY OF CASH BACK CARD-------------\n";
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i].getCreditNumber() == name) temp[i].output();
			} cout << endl;
			a[2]->showHistory();
			cout << "\n------------PAY CASH BACK CARD BY PAYMENT ACCOUNT-------------\n";
			cout << "-----PAYMENT ACCOUNT------\n";
			if (pay.transferTo(a[2]->getBalance())) {
				a[2]->payment(a[2]->getBalance()); a[2]->output();
				cout << pay;
				cout << "\n-----HISTORY OF PAYMENT ACCOUNT------\n";
				pay.showHistory();
			}
			else cout << "Dont have enough money to pay" << endl;
			system("pause");
		}
		else {
			for (int i = 0; i < n; i++) {
				delete a[i];
				a[i] = nullptr;
			}
			return 0;
		}
	}
	return 0;
}