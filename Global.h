#pragma once

#include"clsUser.h"

clsUser CurrentUser = clsUser::Find("", "");

string UserName = CurrentUser.UserName;