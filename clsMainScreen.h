#pragma once
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h";
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"

using namespace std;


class clsMainScreen : protected clsScreen
{

	enum enMainMenuOptions {
		eListClients = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLogOut = 8
	};

	static short _ReadMainMenuOption() {

		cout << setw(37) << left << "" << "Choose What Do You Want to Do? [1 to 8]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 8);

		return Choice;
	}

	static void _GoBackToMainMenu() {

		cout << "\nPress Any Key To Go Back To Main Menu ... ";
		system("pause>0");
		system("cls");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen() {

		//cout << "\nClients List Screen Will Be Here... \n";

		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen() {

		//cout << "\nAdd New Client Screen Will Be Here... \n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {

		//cout << "\nDelete Client Screen Will Be Here... \n";
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdateClientScreen() {

		//cout << "\nUpdate Client Screen Will Be Here... \n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {

		//cout << "\nFind Client Screen Will Be Here... \n";
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionsMenu() {

		//cout << "\nTransactions Screen Will Be Here... \n";
		clsTransactionsScreen::ShowTransactionsMenu();

	}

	static void _ShowManageUsersMenu() {

		clsManageUsers::ShowManageUsersScreen();

	}


	static void _Logout() {

		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption) {

		switch (MainMenuOption) {

		case(enMainMenuOptions::eListClients):
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;


		case(enMainMenuOptions::eAddNewClient):

			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eDeleteClient):

			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eUpdateClient):

			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eFindClient):

			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eTransactions):
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eManageUsers):
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case(enMainMenuOptions::eLogOut):
			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void ShowMainMenu() {

		system("cls");

		clsScreen::_DrawScreenHeader("Main Screen");
		

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());


	}
};

