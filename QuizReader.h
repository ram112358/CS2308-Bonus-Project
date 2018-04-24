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

//shows the vector of questions to the user***********************************
void showQuestions(std::string "quiz1.quiz")
{
  int answer = 0;
  int total = 0;

  ifstream fin;
  fin.open("quiz1.quiz");
  for ( int i = 0; i < showQuestions.size(); i++)
    {

      int score = Questions.size();
  cout << showQuestions[i]  << endl;
      cin >> answer;

      //if the answer is wrong, do not get the total
      if (answer == //right answer)
  {
   total += answer;
  }

     }
      int score;
      sscore = (total/showQuestions.size());
      ofstream fout;
      //output scores into a text file
      fout.open("showScores.txt");
      fout << "total for quiz: " <<  score;

      //displaying the score when the user is done with the quiz
      cout << "Your score is " << score;

}
//*****************************************************************************



#endif
