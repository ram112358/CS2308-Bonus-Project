#ifndef QUIZREADER_H
#define QUIZREADER_H
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Account {
    string Username;
    vector<int> quizzes taken;
    int grade;
}

class UserAccounts {
private:
    vector<Account> accounts;
    Account current;
public:
    void logIn();
    void loadAccountData(); // load the accounts from the file to the accounts vector
    void storeAccountData(); // stores the accounts vector into the file
    void enterGrade(int quizNumber, int grade); // enter a grade for a specific quiz out of 100


    void initializeAccount(); // add an account to the file
    void setUpAccount(string username, string password); // prompt the user for a username and password and then call inidializeAccount
    bool testUsername(string input); // tests to see if a username is valid and not in the list
    bool testPassword(string input); //tests to see if a password if valid
}
