#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen() {

		_DrawScreenHeader("Deposit Screen");

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
		cout << "\nPlease Enter Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\n\nAre you Sure You Want to Perform This Transaction ?  ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			Client1.Deposit(Amount);
			cout << "Amount Deposited Successfully !";
			cout << "New Balance is : " << Client1.AccountBalance << endl;
		}
		else {

			cout << "Operation Was Cancelled. \n";
		}
	}
};

