#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void PrintClientRecordBalanceLine(clsBankClient Client) {

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:

	static void ShowTotalBalances() {

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "Balances List Screen";
		string SubTitle = "(" + to_string(vClients.size()) + ") Client(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0) {

			cout << "\t\t\t\tNo Clients Not Available In The System!";
		}

		else {
			for (clsBankClient& Client : vClients) {

				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << "\n\t\t\t\tTotalBalances : " << TotalBalances;
		cout << "\n\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";


	}
};

