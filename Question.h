#include <string>
using namespace std;
class Question
{
public:
	Question(int,string,string,string,string,string);
	string getQuestion();
	string* getAnswers();
	int getCorrectAnswerIndex();
	int getId();
private:
	string _question;
	string _answers[4];
	int _id;

};