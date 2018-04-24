#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Account {
    string Username;
    vector<int> quizzes taken;
    int grade;
};

class UserAccounts {
private:
    vector<Account> accounts;
    Account current;
    fstream file;
public:
    UserAccounts(){
        if (!file) {
            std::cout << "Error opening file" << '\n';
        }
    }

    void logIn();
    void loadAccountData(); // load the accounts from the file to the accounts vector
    void storeAccountData(); // stores the accounts vector into the file
    void enterGrade(int quizNumber, int grade); // enter a grade for a specific quiz out of 100


    void initializeAccount(); // add an account to the file
    void setUpAccount(string username, string password); // prompt the user for a username and password and then call inidializeAccount
    bool testUsername(string input); // tests to see if a username is valid and not in the list
    bool testPassword(string input); //tests to see if a password if valid
}

void UserAccounts::loadAccountData(){

}

bool testUsername(string input)
{
	if(input.length() < 4)
	{
	cout<<"Username length must be at least 4 characters";
	return false;
	}
	return true;
}

bool testPassword(string input)
{
    bool passed = false;
    int length = input.length();
    for(int i = 0; i < length; i++)
    {
        if(isdigit(input[i]))
            passed = true;
    }
    if(input.length() <4)
	{
	cout<<"Password length must be at least 4 characters";
	return false;
	}
	if(passed == false)
        cout << "Password must contain at least one number";
	return passed;
}
