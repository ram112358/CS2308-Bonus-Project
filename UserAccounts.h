#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Account {
    string Username;
    string Password;
    vector<int> quizHist;
    int grade;
};

class UserAccounts {
private:
    vector<Account> accounts;
    vector<string> fileData;
    Account* current;
    fstream accountFile;

    void loadAccountData(); // load the accounts from the file to the accounts vector
    void storeAccountData(); // stores the accounts vector into the file
    void initializeAccount(string username, string password); // add an account to the file and then logs in
    bool testUsername(string input); // tests to see if a username is valid and not in the list
    bool testPassword(string input); //tests to see if a password if valid
public:
    UserAccounts(){
        accountFile.open("Account.Data", fstream::in | fstream::out);
        if (!accountFile) {
            std::cout << "Error opening file" << '\n';
        }
        loadAccountData();
    }
    ~UserAccounts(){
        storeAccountData();
    }

    bool logIn(string username, string password); // takes username and password and matches them to an account, sets current
    void enterGrade(int quizNumber, int grade); // enter a grade for a specific quiz out of 100
    void displayGrades(); // displays the quizzes taken
    void setUpAccount(); // prompt the user for a username and password and then call inidializeAccount
};

void UserAccounts::loadAccountData(){
    string temp;
    int tempInt;
    accountFile.clear();
    accountFile.seekg(0);
    while(getline(accountFile, temp)){fileData.push_back(temp);}
    for(int i = 0; i < fileData.size(); i+=3){
        accounts[i/3].Username = fileData[i];
        accounts[i/3].Password = fileData[i+1];

        accounts[i/3].quizHist.clear();
        stringstream ss(fileData[i+2]);
        while(getline(ss, temp,'/')){
            stringstream (temp) >> tempInt;
            accounts[i/3].quizHist.push_back(tempInt);
        }

        int tempGrade = 0;
        int quizzesTaken = 0;
        for (int j = 0; j < accounts[i/3].quizHist.size(); j++){
            if (accounts[i/3].quizHist[j] != 200){
                tempGrade += accounts[i/3].quizHist[j];
                quizzesTaken++;
            }
        }
        accounts[i/3].grade = tempGrade/quizzesTaken;
    }
}

void UserAccounts::storeAccountData(){
    string temp;
    accountFile.clear();
    accountFile.seekp(0);
    for (int i = 0; i < 3*accounts.size(); i+=3){
        fileData[i] = accounts[i/3].Username;
        fileData[i+1] = accounts[i/3].Password;
        temp = "";
        for (int j = 0; j<accounts[i/3].quizHist.size(); j++){
            stringstream ss;
            ss << accounts[i/3].quizHist[j];
            temp.append(ss.str());
            if (j = accounts[i/3].quizHist.size()-1)
                temp.append("/");
        }
        fileData[i+2] = temp;
    }
    for (int i = 0; i < fileData.size(); i ++){
        accountFile << fileData[i] << endl;
    }
}

void UserAccounts::initializeAccount(string username, string password){
    Account temp;
    temp.Username = username;
    temp.Password = password;
    accounts.push_back(temp);
    logIn(username, password);
}

bool UserAccounts::testUsername(string input){
    for(int i = 0; i < fileData.size(); i++)
    {
        if(Account[i].Username == input)
        {
            cout << "Duplicate username" << endl;
            return false;
        }
    }
	if(input.length() <4)
	{
	cout<<"Username length must be at least 4 characters";
	return false;
	}
	return true;
}

bool UserAccounts::testPassword(string input){
    bool passed = false;
    int length = input.length();
    for(int i = 0; i < length; i++){
        if(isdigit(input[i]))
        passed = true;
    }
    if(input.length() <4){
        cout<<"Password length must be at least 4 characters";
        return false;
    }
    if(passed == false)
    cout << "Password must contain at least one number";
    return passed;
}

bool UserAccounts::logIn(string username, string password){
    for (int i = 0; i < accounts.size(); i++){
        if (accounts[i].Username == username && accounts[i].Password == password){
            current = &accounts[i];
            return true;
        }
    }
    cout << "Please enter the right username and password." << endl;
    return false;
}

void UserAccounts::enterGrade(int quizNumber, int quizGrade){
    int tempGrade = 0;
    int quizzesTaken = 0;

    if (quizNumber > current->quizHist.size()){
        for (int i = 0; i < quizNumber - current->quizHist.size(); i++){
            current->quizHist.push_back(200);
        }
    }

    current->quizHist[quizNumber - 1] = quizGrade;

    for (int i = 0; i < current->quizHist.size(); i++){
        if (current->quizHist[i] != 200){
            tempGrade += current->quizHist[i];
            quizzesTaken++;
        }
    }
    current->grade = tempGrade/quizzesTaken;
}

void UserAccounts::displayGrades(){
    for (int i = 0; i < current->quizHist.size(); i++){
        if (current->quizHist[i] != 200){
            cout << "Quiz #" << i+1 << ": " << current->quizHist[i];
        }
    }
}

void UserAccounts::setUpAccount(){}

#endif
