#include "Validator.h"
#include "Helper.h"
bool isLetter(char word)
{
	if ((word > CAP_LETTER_START && word < CAP_LETTER_CAP) || (word > SMALL_LETTER_START && word < SMALL_LETTER_CAP))
	{
		return true;
	}
	return false;
}
static bool isPasswordValid(string password)
{
	bool lenFlag = false,
		numFlag = false,
		letterFlag = false,
		capLetterFlag = false,
		noSpaceFlag = true;
	if (password.length > 3)
	{
		lenFlag = true;
	}
	if (password.find(" "))
	{
		noSpaceFlag = false;
	}
	int i;
	for (i = 0; i < password.length; i++)
	{
		if (password[i] > SMALL_LETTER_START  && password[i] < SMALL_LETTER_CAP)
		{
			letterFlag = true;
		}
		if (password[i] > CAP_LETTER_START && password[i] < CAP_LETTER_CAP)
		{
			capLetterFlag = true;
		}
		if (password[i] > NUMBER_START && password[i] < NUMBER_END)
		{
			numFlag = true;
		}
	}
	if (noSpaceFlag && numFlag && letterFlag && capLetterFlag && lenFlag)
	{
		return true;
	}
	return false;
}
static bool isUsernameValid(string username)
{
	if (username.find(" ") || username.compare("") == 0 || !isLetter(username[0]))
	{
		return false;
	}
	return true;
}