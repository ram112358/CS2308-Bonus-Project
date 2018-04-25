#ifndef QUIZTAKER_H
#define QUIZTAKER_H
#include "QuizReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class QuizTaker {
private:
    std::vector<Question> questions;
    int score;
public:
    QuizTaker(std::vector<Question> qs) {
        questions = qs;
        score = 0;
    }
    int takeQuiz();
};

// Displays the quiz
int QuizTaker::takeQuiz() {
    int answer;
    for ( int i = 0; i < questions.size(); i++) {
        Question currQuestion = questions[i];
        std::cout << currQuestion.title << std::endl;
        for (int i = 0; i < currQuestion.answers.size(); i++) {
          std::cout << i+1 << ") " <<  currQuestion.answers[i] << std::endl;
        }
        std::cout << "User Answer: "; std::cin >> answer;

        if (answer == currQuestion.correct + 1) {
            std::cout << "That is correct!" << '\n';
            score++;
        } else {
            std::cout << "Wrong!" << '\n';
        }
        std::cout << std::endl;
    }
    int percent = static_cast<int>(score / questions.size() * 100);
    std::cout << "Your final score: " << percent << " percent (" << score << "/" << questions.size() << ")" <<'\n';
}

#endif
