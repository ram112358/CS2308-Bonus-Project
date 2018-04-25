#ifndef QUIZREADER_H
#define QUIZREADER_H
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

struct Question {
    std::string title;
    std::vector<std::string> answers;
    int correct;
};

class QuizReader {
private:
    std::string title;
    std::vector<Question> questions;
public:
    QuizReader() {}
    void readFile(std::string filename);
    std::vector<Question> getQuestions() {
        return questions;
    }
    std::string getTitle() {
        return title;
    }
};

// Takes a quiz file and parses it into a vector of questions
void QuizReader::readFile(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening quiz file" << '\n';
    }
    std::string currLine;
    std::getline(file, currLine);
    title = currLine;

    while (std::getline(file, currLine)) {
        Question* q = new Question();
        q->title = currLine;
        std::getline(file, currLine);

        std::stringstream ss(currLine);
        std::string answer;
        std::vector<std::string> tokens;
        while (getline(ss, answer, '/')) {
            tokens.push_back(answer);
        }
        q->answers = tokens;

        for (int i=0; i < q->answers.size(); i++) {
            if (q->answers[i][0] == '~');
            q->answers[i].substr(1, std::string::npos);
            q->correct = i;
        }
        questions.push_back(*q);
    }
}

#endif
