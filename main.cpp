#include <iostream>
#include "encryption.h"
#include "auth.h"  // Include authentication header
using namespace std;

int main() {
    string loggedInUser, role;
    char mode;  // for encrypted mode or decrypted mode
    int choice;

    cout << "Welcome to Secure File System!\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();  // Calls register function
            cout << "Please restart and login to continue.\n";
            return 0;
        case 2:
            // User must log in before proceeding
            if (!loginUser(loggedInUser, role)) {
                cerr << "Login failed. Exiting program.\n";
                return 1;  // Exit if login fails
            }
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cerr << "Invalid choice! Please restart and select a valid option.\n";
            return 1;
    }

    string filename;  // for storing file name
    cout << "Enter the filename : ";
    // Using getline to read the entire line, including spaces, from input
    getline(cin >> ws, filename);

    cout << "Encrypt (e) or Decrypt (d)? : ";
    cin >> mode;

    // Role-based access control (RBAC) implemented
    if (mode == 'e' || mode == 'E') {
        if (role == "admin") {  // Only admins can encrypt
            if (encryptFile(filename, true)) {
                cout << "Encryption Completed Successfully!" << endl;
            } else {
                cerr << "Error: Unable to perform Encryption" << endl;
            }
        } else {
            cerr << "Error: Only admins can encrypt files!" << endl;
        }
    } 
    else if (mode == 'd' || mode == 'D') {
        if (encryptFile(filename, false)) {
            cout << "Decryption Completed Successfully!" << endl;
        } else {
            cerr << "Error: Unable to perform Decryption" << endl;
        }
    } 
    else {
        cerr << "Error : Invalid mode selected. Use 'e' for encryption & 'd' for decryption." << endl; 
    }

    return 0;
}
