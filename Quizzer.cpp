/*
Group Name: Quacking Quizzers
Date: 04/23/18
Assignment: Bonus Project
Course: CS2308
 */
#include <iostream>
#include<fstream>
#include"QuizReader.h"
#include"UserAccounts.h"

using namespace std;

int main(){

  const int NUM = 3;
  string username;
  string password;
  int quiz;
  ifstream inFile;
  int option;
  UserAccounts account();

  cout << "Welcome!" << endl;
  cout << "Enter '1' to create an account."<< endl;
  cout<< "If you already have an acount, enter '2' to log in." << endl;
  cin >> option;

  if (option== 1)
    {
      cout << "Create an account" << endl;
      account.setUpAccount();
    }

  if (option==2)
    {
      cout << "Username: ";
      cin >> username;
      cout << endl << "Password: ";
      cin >> password;
      while (account.logIn(username, password)){
            cout << "Username: ";
            cin >> username;
            cout << endl << "Password: ";
            cin >> password;
      }
    }

  cout << "Hello! Enter in which quiz you would like to take" << endl;
  for (int i=0; i<NUM; i++)
    {
      cout << i << ". Quiz " << i;
    }
  cin >> quiz;

//call function to view and take quiz



  cout << "Would you like to view your scores or take another quiz?" << endl;
  cout << "1.View my scores" << endl;
  cout << "2.Take another quiz" << endl;
  cin >> option;

  if(option==1)
    {
        account.displayGrades();
    }
  else if(option==2)
    {
    cout << "Hello! Enter in which quiz you would like to take" << endl;
      for (int i=0; i<NUM; i++)
    {
      cout << i << ". Quiz " << i;

    }

  cin >> quiz;
    }



    return 0;
}
