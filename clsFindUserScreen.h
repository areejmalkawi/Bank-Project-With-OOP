#pragma once
#include"clsScreen.h"


class clsFindUserScreen : protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen() {

        _DrawScreenHeader("Find User Screen");

        string UserName;

        cout << "\nEnter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {

            cout << "\nUser Name is Not Found, Enter Another : ";
            getline(cin >> ws, UserName);
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
            cout << "\nUser Found :-)\n";
        else
            cout << "\nUser Not Found :-(\n";

        _PrintUser(User1);
    }
};

