#ifndef QUIZREADER_H
#define QUIZREADER_H
#include <fstream>
#include <string>
#include <vector>

struct Question {
    std::string title;
    std::vector<std::string> answers;
    int correct;
}

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
}

// Takes a quiz file and parses it into a vector of questions
QuizReader::readFile(std::string filename) {
    
}

#endif
