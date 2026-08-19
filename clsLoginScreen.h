#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:

    static  void _Login()
    {
        bool LoginFaild = false;

        string Username, Password;

        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        clsMainScreen::ShowMainMenu();

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("Login Screen");
        _Login();

    }

};

