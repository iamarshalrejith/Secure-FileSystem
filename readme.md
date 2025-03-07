# Secure File System
A security-focused file management system implementing encryption, authentication, and role-based access control (RBAC).

## Overview
Secure File System enhances file security by providing encryption, user authentication, and controlled access based on user roles. The system ensures that only authorized users can encrypt and decrypt files, protecting sensitive data from unauthorized access.

## About
Secure File System is a C++ project designed to safeguard files through encryption and access control mechanisms. It enables users to:
- Encrypt and decrypt files using Caesar cipher encryption.
- Authenticate users securely with hashed passwords.
- Implement Role-Based Access Control (RBAC), where only admins can encrypt files, while regular users can only decrypt.

## Features
✅ **File Encryption & Decryption** (Caesar Cipher-based security)
✅ **User Authentication** (Hashed passwords for security)
✅ **Role-Based Access Control** (Admins can encrypt, users can decrypt)
✅ **Command-Line Interface** (Simple and easy to use)

## Getting Started
### Clone the Repository
```sh
git clone https://github.com/iamarshalrejith/Secure-FileSystem.git
cd Secure-FileSystem
```

### Compile the Project
Ensure you have a C++ compiler installed (G++ recommended).
```sh
g++ -o secure_fs main.cpp encryption.cpp auth.cpp
```

### Run the Application
```sh
./secure_fs
```

## Prerequisites
Ensure you have the following installed:
- C++ Compiler (GCC/MinGW for Windows, Clang for macOS, etc.)
- Git (for version control)

## File Structure
```
Secure-FileSystem/
│── encryption.h      # Encryption function declarations
│── encryption.cpp    # File encryption & decryption logic
│── auth.h            # User authentication function declarations
│── auth.cpp          # User authentication implementation
│── main.cpp          # Main application logic
│── user.txt          # Stores registered users (hashed passwords)
│── sample.txt        # Sample file for testing
│── LICENSE.txt       # MIT License
│── readme.md         # Project documentation
```

## Contributing
We welcome contributions! Follow these steps:
1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`.
3. Make your changes and commit them: `git commit -am 'Add new feature'`.
4. Push to your fork: `git push origin feature-name`.
5. Open a Pull Request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.

