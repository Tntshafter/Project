#include "Question.h"
Question::Question(int id, string question, string corr_answer, string wr_answer_1, string wr_answer_2, string wr_answer_3)
{
	this->_id = id;
	this->_question = question;
	vector<int> slotList; 
	//random selection of slots
	string answers[4] = {corr_answer,wr_answer_1,wr_answer_2,wr_answer_3};
	slotList.push_back(0);
	slotList.push_back(1);
	slotList.push_back(2);
	slotList.push_back(3);
	int i;
	for (i = 0; i < 4; i++)
	{
		int randomNum = rand() % (4 - i);
		this->_answers[slotList[randomNum]] = answers[i];
		//what the line above does, it basically putting every answer in a random slot out of 4,
		//while every slot thats taken is removed from the list (slotList)
		if (i == 0)
		{
			_corrIndex = randomNum; //saving the correct answer index.
		}
		slotList.erase(slotList.begin() + randomNum);

	}
}
string Question::getQuestion()
{
	return _question;
}
string* Question::getAnswers()
{
	return this->_answers;
}
int Question::getCorrectAnswerIndex()
{	
	return _corrIndex;
}
int Question::getId()
{
	return _id;
}