#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
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

	static void ReadClientInfo(clsBankClient& Client) {

		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance :";
		Client.AccountBalance = stof(clsInputValidate::ReadString());
	}

public:

	static void ShowUpdateClientScreen() {

		_DrawScreenHeader("Update Client Screen");

		string AccountNumber;

		cout << "Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number is Not Found, Enter Another : ";
			getline(cin >> ws, AccountNumber);
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';
		cout << "\nAre You Sure You Want to Update This Client ? (y/n)? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			ReadClientInfo(Client1);


			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client1.Save();

			switch (SaveResult) {

			case(clsBankClient::enSaveResults::svSucceeded):

				cout << "\nAccount Updated Succesfully :-) \n";
				_PrintClient(Client1);
				break;

			case(clsBankClient::enSaveResults::svFaildEmptyObject):

				cout << "\nError Account was Not Saved Because It's Empty \n";
				break;
			}
		}
	}
};

