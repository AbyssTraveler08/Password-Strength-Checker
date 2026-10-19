<div align="center">

# 🔐 Password Strength Checker

**A C++ command-line project for exploring password complexity, character sets, entropy estimates, and SHA-256 hashing.**

<img src="https://img.shields.io/badge/C%2B%2B-11-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++11" />
<img src="https://img.shields.io/badge/Focus-Security%20Education-0A66C2?style=for-the-badge" alt="Security education" />
<img src="https://img.shields.io/badge/Interface-CLI-475569?style=for-the-badge" alt="CLI" />

</div>

---

## 🔎 Overview

Password Strength Checker is a small C++ program that estimates password strength from its length and the character classes it contains. It labels an entered password as **Weak**, **Moderate**, or **Strong** and demonstrates a SHA-256 hashing function.

The project is intended for learning about password policy and basic cryptographic APIs. Its score is a simplified estimate—not a full password-security assessment.

## ✨ Features

- Detects lowercase letters, uppercase letters, digits, and special characters.
- Estimates character-set entropy using password length and character-set size.
- Classifies the password as Weak, Moderate, or Strong with predefined thresholds.
- Demonstrates SHA-256 hashing through OpenSSL.
- Uses standard C++ input, regular expressions, and mathematical functions.
- Runs locally from a terminal without sending the entered value to a remote service.

## 🧰 Requirements

- C++11-compatible compiler such as g++.
- OpenSSL development headers and crypto library.
- macOS or Linux recommended; install the matching OpenSSL development package for your system.

## ⚙️ Installation and usage

### 1. Clone the repository

~~~bash
git clone https://github.com/AbyssTraveler08/Password-Strength-Checker.git
cd Password-Strength-Checker
~~~

### 2. Compile

~~~bash
g++ -std=c++11 password-strength-checker.cpp -o password_checker -lcrypto
~~~

If the compiler cannot find OpenSSL headers or libraries, install the OpenSSL development package and configure your compiler's include/library paths for your operating system.

### 3. Run

~~~bash
./password_checker
~~~

Enter a test password when prompted. The program displays its estimated strength and a SHA-256-derived output.

## 🧠 How strength is estimated

~~~text
estimated entropy = password length × log2(character-set size)
~~~

| Classification | Current rule |
|---|---|
| **Strong** | Length of at least 10 characters and estimated entropy above 60 |
| **Moderate** | Length of at least 6 characters and estimated entropy above 40 |
| **Weak** | Does not meet either threshold |

These are simple educational heuristics. They do not account for dictionary words, leaked-password databases, common patterns, keyboard sequences, or an attacker's guessing strategy.

## 📁 Repository contents

- **password-strength-checker.cpp** — main program, entropy estimate, strength classification, and SHA-256 demonstration.
- **Password_Strength_Checker_Report.pdf** — accompanying project report.
- **LICENSE** — repository license.

## 🔐 Security notes and limitations

- Do not use this program as the sole measure of whether a real password is safe to reuse. Use unique passwords from a password manager and enable multi-factor authentication where available.
- Plain SHA-256 is not suitable for password storage. Production authentication systems should use a password-hashing function such as Argon2id, scrypt, or bcrypt with appropriate salts and parameters.
- The current hashing output is a programming demonstration, not an authentication mechanism.
- The program reads input with token-based console input, so passwords containing whitespace are not handled as one value.
- The estimated score can overstate or understate actual password strength.

## 🗺️ Possible improvements

- Add tests for boundary conditions and character-set detection.
- Add a masked terminal prompt.
- Add dictionary/common-password checks without transmitting secrets.
- Improve hash output formatting and separate strength checking from hashing.
- Add guidance based on current password policy recommendations.

## 👤 Author

**Amar Kant Yadav** · [GitHub profile](https://github.com/AbyssTraveler08)

## 📄 License

See the repository's LICENSE file.

---

<div align="center">Built for learning secure programming and password-security fundamentals.</div>
