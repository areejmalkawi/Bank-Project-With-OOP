#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsers : protected clsScreen
{
private:

	enum enManageUsersMenuOptions {
		eListUsers = 1, eAddNewUser = 2,
		eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenu = 6
	};

	static short ReadManageUsersOption() {

		cout << setw(37) << left << "" << "Choose What Do You Want to Do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);

		return Choice;
	}

	static void _GoBackToManageUsersMenu() {

		cout << "\nPress Any Key To Go Back To Manage Users Menu ... ";
		system("pause>0");
		system("cls");
		ShowManageUsersScreen();
	}

	static void _ShowListUsersScreen() {

		//cout << "\n\nList Users Screen Will Be Here...\n";
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen() {
		//cout << "\n\nAdd New User Screen Will Be Here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen() {

		//cout << "\n\nDelete Users Screen Will Be Here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {

		//cout << "\n\nUpdate Users Screen Will Be Here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() {

		//cout << "\n\nFind Users Screen Will Be Here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption) {

		switch (ManageUsersMenuOption) {

		
		case(enManageUsersMenuOptions::eListUsers):
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;

		case(enManageUsersMenuOptions::eAddNewUser):
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenu();
			break;

		case(enManageUsersMenuOptions::eDeleteUser):
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case(enManageUsersMenuOptions::eUpdateUser):
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case(enManageUsersMenuOptions::eFindUser):
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case(enManageUsersMenuOptions::eMainMenu): {}
			
		}
		
	}

public:

	static void ShowManageUsersScreen() {

		system("cls");

		_DrawScreenHeader("Manage Users Screen");

		cout << setw(37) << left << ""<< "============================================\n";
		cout << setw(37) << left << ""<< "\tManage Users Menu Screen\n";
		cout << setw(37) << left << ""<< "============================================\n";
		cout << setw(37) << left << ""<< "\t[1]List Users.\n";
		cout << setw(37) << left << ""<< "\t[2]Add New User.\n";
		cout << setw(37) << left << ""<< "\t[3]Delete User.\n";
		cout << setw(37) << left << ""<< "\t[4]Update User.\n";
		cout << setw(37) << left << ""<< "\t[5]Find User.\n";
		cout << setw(37) << left << ""<< "\t[6]MainMenu.\n";
		cout << setw(37) << left << ""<< "============================================\n";

		_PerformManageUsersMenuOption((enManageUsersMenuOptions)ReadManageUsersOption());
	}
};

