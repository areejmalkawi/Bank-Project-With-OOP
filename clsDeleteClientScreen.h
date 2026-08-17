#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
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

	static void ShowDeleteClientScreen() {

		string AccountNumber;

		_DrawScreenHeader("Delete Client Screen");

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Does Not Exist Please Enter Another : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';

		cout << "\nAre You Sure You Want to Delete This Client ? (y/n) : ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			if (Client1.Delete()) {

				cout << "\nAccount Deleted Successfully :-) \n";
				_PrintClient(Client1);
			}
			else {

				cout << "\nError Client Was Not Deleted \n";
			}
		}

	}
};

