/*
Group Name: Quacking Quizzers
Date: 04/23/18
Assignment: Bonus Project
Course: CS2308
 */
#include <iostream>

using namespace std;

int main(){
    
  int account;
  const int NUM;
  int quizzes[NUM];
  string user;
  string password;
  int quiz;
  ifstream inFile;
  int option;
  
  cout << "Welcome!" << endl;
  cout << "Enter '1' to create an account."<< endl;
  cout<< "If you already have an acount, enter '2' to log in." << endl;
  cin >> account;

  if (account== 1)
    {
      //call function for creating an account
      cout << "create an account";
    }

  if (account==2)
    {
      cout << "Username: ";
      cin >> user;
      cout << endl << "Password: ";
      cin >> password;
      // call function to check is acount is correct (bool)
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
      //call function to view score
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
