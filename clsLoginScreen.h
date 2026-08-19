#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short LoginFaildCount = 0;

        string Username, Password;

        do
        {
            
            if (LoginFaild)
            {
                LoginFaildCount++;
                cout << "\n\nInvlaid Username/Password!\n\n";
                cout << "You Have " << 3 - LoginFaildCount << " Trial(s) To Login\n\n";
            }

            if (LoginFaildCount == 3) {

                cout << "\nYou are Looked After 3 Failed Trials\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            
            
            

        } while (LoginFaild);

       
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("Login Screen");
        return _Login();

    }

};

