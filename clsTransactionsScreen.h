#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenuOptions {

		eDeposit = 1, eWithdraw = 2,
		eTotalBalances = 3, eMainMenu = 4
	};

	static short _ReadTransactionsMenuOption() {
		cout << setw(37) << left << "" << "Choose What Do You Want to Do? [1 to 4]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);

		return Choice;
	}

	static void _GoBackToTransactionsMenu() {

		cout << "\nPress Any Key To Go Back To Transactions Menu ... ";
		system("pause>0");
		system("cls");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen() {

		//cout << "\nDeposit Screen Will Be Here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		//cout << "\nWithdraw Screen Will Be Here... \n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {

		//cout << "\nTotal Balances Screen Will Be Here... \n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionOption) {

		switch (TransactionOption) {

		case(enTransactionsMenuOptions::eDeposit):
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;

		case(enTransactionsMenuOptions::eWithdraw):
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;

		case(enTransactionsMenuOptions::eTotalBalances):
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;

		case(enTransactionsMenuOptions::eMainMenu):{}
			
		}
	}

public:

	static void ShowTransactionsMenu() {


		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {

			return;
		}

		_DrawScreenHeader("Transactions Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\tTransactions Menu Screen\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

