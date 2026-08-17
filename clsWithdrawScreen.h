#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsWithdrawScreen : clsScreen
{
private:

	static void _PrintClient(clsBankClient Client) {

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowWithdrawScreen() {

		_DrawScreenHeader("Withdraw Screen");

		string AccountNumber;

		cout << "\n\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();


		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "The Account Number Does Not Exist, Enter Another : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Withdraw Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\n\nAre you Sure You Want to Perform This Transaction ?  ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			if (Client1.Withdraw(Amount)) {

				cout << "\nAmount Withdrawed Successfully !";
				cout << "New Balance is : " << Client1.AccountBalance << endl;
			}
			else {

				cout << "\nCannot Withdraw, Insufficient Balance!\n";
				cout << "\nAmount to Withdraw is : " << Amount;
				cout << "\nYour Balance Is : " << Client1.AccountBalance;
			}
		}
		else {

			cout << "Operation Was Cancelled. \n";
		}
	}
};

