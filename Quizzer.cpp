/*
Group Name: Quacking Quizzers
Date: 04/23/18
Assignment: Bonus Project
Course: CS2308
 */
#include <iostream>
#include <vector>
#include <string>
#include "QuizReader.h"
#include "QuizTaker.h"
#include "UserAccounts.h"

using namespace std;

int main(){

    const int NUM = 3;
    string username;
    string password;
    int quiz;
    int option;
    bool cont;
    int finalScore = 0;
    UserAccounts account;

    string quizFiles[NUM] = {"quiz1.quiz", "quiz2.quiz", "quiz3.quiz"};

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
      cout << "Password: ";
      cin >> password;
      while (!account.logIn(username, password)){
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

      }
    }
    do {
        cont = false;
        cout << "Hello! Enter in which quiz you would like to take" << endl;
        for (int i=0; i<NUM; i++)
        {
          cout << i+1 << ". Quiz " << i+1 << endl;

        }
        cin >> quiz;
        QuizReader quizReader;
        quizReader.readFile(quizFiles[quiz-1]);
        QuizTaker quizTaker(quizReader.getQuestions());
        finalScore = quizTaker.takeQuiz();
        account.enterGrade(quiz, finalScore);

        bool gradecont;
        do {
            gradecont = false;
            cout << endl;
            cout << "Would you like to view your scores or take another quiz?" << endl;
            cout << "1.View my scores" << endl;
            cout << "2.Take another quiz" << endl;
            cout << "3.Quit" << endl;
            cin >> option;

            if(option==1)
            {
                account.displayGrades();
                gradecont = true;
            }
            else if(option==2)
            {
                cont = true;
            }
        } while (gradecont);

    } while (cont);
    account.storeAccountData();
    std::cout << "Thank you for playing!" << '\n';
    return 0;
}
