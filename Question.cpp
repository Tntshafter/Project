#include "Question.h"
Question::Question(int id, string question, string corr_answer, string wr_answer_1, string wr_answer_2, string wr_answer_3)
{
	this->_id = id;
}
string Question::getQuestion()
{
	return _question;
}
string* Question::getAnswers()
{
	//i am not sure if i should copy the list and return a new one. waiting for answers.
	return this->_answers;
}
int Question::getCorrectAnswerIndex()
{
	//there was no explanation about that function in the UML, and to be honset, i dont see a reason to its existence anyway.
	//slot 0 it is, as the declaring function requires
	return CORRECT_ANSWER_INDEX;
}
int Question::getId()
{
	return _id;
}