#ifndef QUIZREADER_H
#define QUIZREADER_H
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Account {
    string Username;
    int grade;
}

class UserAccounts {
private:
    vector<Account> accounts;
public:
    void setUpAccount();
    void logIn();
    void initializeAccountList();
    bool testUsername(string input);
    bool testPassword(string input); //tests to see if a password if valid
}
