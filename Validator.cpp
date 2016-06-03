#include "Validator.h"
#include "Helper.h"
bool isLetter(char word)
{
	if ((word > 64 && word < 91) || (word > 96 && word < 123))
	{
		return true;
	}
	return false;
}
static bool isPasswordValid(string password)
{

}
static bool isUsernameValid(string username)
{
	if (username.find(" ") || username.compare("") == 0 || !isLetter(username[0]))
	{
		return false;
	}
	return true;
}