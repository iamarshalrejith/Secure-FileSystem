//Header file is used to declare clasess,functions etc... can be used in .cpp

#ifndef ENCRYPTION_H  // If ENCRYPTION_H is not defined...
#define ENCRYPTION_H    // Define it
 
#include <string>  // Allows us to use strings
using namespace std;


// Encrypts or decrypts a file.
//@param encrypt If true, the file is encrypted; if false, it is decrypted.
// @return True if successful, false if something went wrong.

bool encryptFile(const string& filename,bool encrypt); // custom function encryptFile

#endif  // End of ENCRYPTION_H