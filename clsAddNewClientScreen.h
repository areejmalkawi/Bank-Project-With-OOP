#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient& Client) {

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

	static void ShowAddNewClientScreen() {

		string AccountNumber;

		clsScreen::_DrawScreenHeader("Add New Client Screen");

		cout << "\nPlease Enetr Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is Already Exists Please Enter Another : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult) {

		case(clsBankClient::enSaveResults::svSucceeded):

			cout << "\nAccount Added Succesfully :-) \n";
			_PrintClient(NewClient);
			break;

		case(clsBankClient::enSaveResults::svFaildEmptyObject):

			cout << "\nError Account was Not Saved Because It's Empty \n";
			break;

		case(clsBankClient::enSaveResults::svFaildAccountNumberExist):
			cout << "\nAccount Number Does Not Exist \n";
			break;
		}


	}

};

