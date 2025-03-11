#include <iostream>
#include <regex>
#include <cmath>
#include <openssl/sha.h> // For optional hashing

using namespace std;

// Function to calculate password entropy
double calculateEntropy(string password) {
    int length = password.length();
    int charSetSize = 0;

    if (regex_search(password, regex("[a-z]"))) charSetSize += 26;
    if (regex_search(password, regex("[A-Z]"))) charSetSize += 26;
    if (regex_search(password, regex("[0-9]"))) charSetSize += 10;
    if (regex_search(password, regex("[^a-zA-Z0-9]"))) charSetSize += 32; // Special characters

    return length * log2(charSetSize); // Shannon Entropy formula
}

// Function to determine password strength
string checkStrength(string password) {
    double entropy = calculateEntropy(password);
    int length = password.length();

    if (length >= 10 && entropy > 60)
        return "Strong";
    else if (length >= 6 && entropy > 40)
        return "Moderate";
    else
        return "Weak";
}

// Optional: Function to hash the password using SHA-256
string hashPassword(string password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password.c_str(), password.length(), hash);

    string hashed;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        hashed += to_string(hash[i]);

    return hashed;
}

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;

    string strength = checkStrength(password);
    cout << "Password Strength: " << strength << endl;

    // Optional: Display hashed password (for security checks)
    cout << "Hashed Password (SHA-256): " << hashPassword(password) << endl;

    return 0;
}
