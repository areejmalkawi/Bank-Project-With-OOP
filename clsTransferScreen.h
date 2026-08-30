#pragma once
#include"clsBankClient.h"

class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client) {

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber() {

		string AccountNumber;

		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "The Account Number Does Not Exist, Enter Another : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		
		return AccountNumber;
	}

	static double ReadAmount(clsBankClient SourceClient) {

		double Amount;

		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance) {

			cout << "Amount Exceeds the Available Balance!Enter Another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}

public:

	static void ShowTransferScreen() {

		_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		double Amount = ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\n\nAre you Sure You Want to Perform This Transaction ?  ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {
			
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}
		
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

