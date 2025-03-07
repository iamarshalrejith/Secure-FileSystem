#include "encryption.h" // Include header file to use the functions we declared
#include <fstream>  // For file handling (reading and writing files)
#include <cctype>   // Used for character operations like toUpper, toLower
#include <iostream> // For error messages

using namespace std;

bool performCaesarCipher(string& content, bool encrypt) {
    int shift = encrypt ? 3 : -3;
    for (char& ch : content) {
        if (isalpha(ch)) {  // Using cctype library -> isalpha
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base); // Ensure shift wraps correctly
        }
    }
    return true;  // Return true to indicate success
}

//logic
// Convert 'B' to a zero-based index: 'B' - 'A' = 1
// Apply shift (+3): (1 + 3) = 4, which corresponds to 'E'
// Ensure the result stays in the A-Z range using (ch - base + shift + 26) % 26
// If we didn't use % 26, shifting 'Z' would go beyond 'Z' (out of range)
// Adding 26 prevents negative values when decrypting (e.g., 'B' - 3 would be -2)
// Convert back: 4 + 'A' = 'E' (shifted character)


// Decryption example for 'B' with shift -3
// Step 1: Convert 'B' to zero-based index → 'B' - 'A' = 1
// Step 2: Apply shift (-3): (1 - 3 + 26) % 26 = 24
// Step 3: Convert back: 24 + 'A' = 'Y'
// So, 'B' decrypts to 'Y' after shifting backward by 3 places

bool encryptFile(const string& filename, bool encrypt) {
    ifstream inFile(filename);   // Open the input file
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return false;
    }

    // Read content from file
    string content((istreambuf_iterator<char>(inFile)), {}); // Store file content in `content`
    inFile.close();

    if (performCaesarCipher(content, encrypt)) {
        // Create an output file and write the modified content
        string outputFilename = encrypt ? "Encrypted_" + filename : "Decrypted_" + filename;
        ofstream outFile(outputFilename);

        if (!outFile) {
            cerr << "Error: Unable to create output file!" << endl;
            return false;
        }

        outFile << content; // Write encrypted/decrypted content to the output file
        outFile.close();
        cout << (encrypt ? "Encryption" : "Decryption") << " completed successfully. Output: " << outputFilename << endl;
        return true;
    }

    return false; // 🔹 Added return in case of failure
}