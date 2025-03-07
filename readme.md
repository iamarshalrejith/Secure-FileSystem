Secure File System

Overview

This project is a C++ Secure File System that allows users to encrypt and decrypt files with user authentication and role-based access control (RBAC). It ensures that only authorized users can access sensitive information.

Features

✅ File Encryption & Decryption

Uses a Caesar Cipher (shift-based encryption) to protect files.

Converts files into an unreadable format (encryption).

Authorized users can restore them (decryption).

✅ User Authentication

Users must register and log in using a username and password.

Passwords are securely hashed before storing in user.txt.

✅ Role-Based Access Control (RBAC)

Admins can encrypt & decrypt files.

Regular users can only decrypt files.

Prevents unauthorized access to important data.

Installation & Setup

Prerequisites

A C++ compiler (G++/MSVC/Clang)

Windows/Linux/MacOS

Steps

Clone the repository:

git clone https://github.com/your-username/Secure-File-System.git
cd Secure-File-System

Compile the program:

g++ main.cpp encryption.cpp auth.cpp -o SecureFileSystem

Run the program:

./SecureFileSystem

How to Use

Register a User:

Choose 1. Register in the menu.

Enter username, password, and role (admin/user).

Login:

Choose 2. Login and enter your credentials.

Encrypt/Decrypt Files:

Enter a filename and choose 'e' for encryption or 'd' for decryption.

Admins can encrypt & decrypt, regular users can only decrypt.

Code Structure

Secure-File-System/
│── encryption.h       # Encryption function declarations
│── encryption.cpp     # Implements Caesar cipher-based encryption
│── auth.h             # User authentication function declarations
│── auth.cpp           # Implements user authentication (register/login)
│── main.cpp           # Main driver program
│── user.txt           # Stores registered users (hashed passwords)
│── README.md          # Project documentation (this file)

Security Considerations

Passwords are stored hashed using the C++ <functional> hash function.

Role-based access prevents unauthorized file encryption.

The encryption method is basic (Caesar Cipher) and should be upgraded for real-world security.

Future Improvements

🔹 Implement AES/RSA encryption for better security.
🔹 Improve user management (password reset, role changes).
🔹 Use a database instead of a text file for storing user info.

Contributing

Contributions are welcome! Feel free to fork this repository and submit a pull request.

License

This project is licensed under the MIT License.