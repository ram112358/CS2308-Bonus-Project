#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Account {
    string Username;
    vector<int> quizHist;
    int grade;
}

class UserAccounts {
private:
    vector<Account> accounts;
    vecctor<string> fileData;
    Account current;
    fstream accountFile("Account.Data", ios::in|ios:: out);
    void loadAccountData(); // load the accounts from the file to the accounts vector
    void storeAccountData(); // stores the accounts vector into the file
public:
    UserAccounts(){
        if (!file) {
            std::cout << "Error opening file" << '\n';
        }
    }

    void logIn(); //
    void enterGrade(int quizNumber, int grade); // enter a grade for a specific quiz out of 100

    void initializeAccount(); // add an account to the file
    void setUpAccount(string username, string password); // prompt the user for a username and password and then call inidializeAccount
    bool testUsername(string input); // tests to see if a username is valid and not in the list
    bool testPassword(string input); //tests to see if a password if valid
}

void UserAccounts::loadAccountData(){
    string temp;
    int tempInt;
    while(getline(accountFile, line)){fileData.push_back(line)}
    for(i = 0; i < fileData.size(); i+=3){
        accounts[i/3].Username = fileData[i];
        stringstream ss(fileData[i+2]);
        while(getline(ss, )){
            stringstream int(temp);
            temp >> tempInt;
            accounts[i/3].quizHist.push_back(tempInt);
        }
    }
}
