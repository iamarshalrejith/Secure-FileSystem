#include <iostream>
#include "auth.h"  // Includes function declaration
#include "fstream"  // File handling -> reading and writing
#include <sstream>  // String stream for splitting data
#include <functional>  // Used to generate hash values for strings

#define USER_FILE "user.txt"

using namespace std;

string hashPassword(const string& password) {
    hash<string> hasher;  // Hash for strings
    return to_string(hasher(password));  // Convert hashed value to string
}

void registerUser() {
    string username, password, role;
    
    cout << "Enter username: ";
    cin.ignore();  // Clears newline character from previous input
    getline(cin, username);  // Reads full username including spaces

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter the role (admin/user): ";
    cin >> role;

    // Open the file in append mode (ios::app) -> New users are added without overwriting existing data
    ofstream file(USER_FILE, ios::app);
    if (!file) {
        cerr << "Error: Unable to open user file for writing!\n";
        return;
    }

    // Use a comma (`,`) as a delimiter to avoid space-related issues
    file << username << "," << hashPassword(password) << "," << role << endl;
    cout << "User registered successfully!\n";
}

bool loginUser(string& loggedInUser, string& role) {
    string username, password;

    cout << "Enter username: ";
    cin.ignore();  // Clears newline character from previous input
    getline(cin, username);  // Reads full username including spaces

    cout << "Enter password: ";
    cin >> password;

    ifstream file(USER_FILE);  // Open file for reading
    if (!file) {
        cerr << "Error: Unable to open user file for reading!\n";
        return false;
    }

    string line, storedUser, storedHash, storedRole;
    while (getline(file, line)) {
        stringstream ss(line);  // Create a string stream to split the line
        getline(ss, storedUser, ',');  // Read username
        getline(ss, storedHash, ',');  // Read hashed password
        getline(ss, storedRole, ',');  // Read role

        if (storedUser == username && storedHash == hashPassword(password)) {
            loggedInUser = storedUser;
            role = storedRole;
            cout << "Login successful! Role: " << role << endl;
            return true;
        }
    }

    cout << "Invalid username or password.\n";
    return false;
}
