//file not fully ready yet
#include "Question.h"

Question::Question(int, string, string, string, string, string)
{

}
string Question::getQuestion()
{
	return _question;
}
string* Question::getAnswers()
{

}
int Question::getCorrectAnswerIndex()
{
	//there was no explanation about that function in the UML, and to be honset, i dont see a reason to its existence anyway.

}
int Question::getId()
{
	return _id;
}