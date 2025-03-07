#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

void registerUser();
bool loginUser(string& loggedInUser,string& role);

#endif