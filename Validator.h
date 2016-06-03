#include <iostream>
#include <string>
#define SMALL_LETTER_CAP 123
#define SMALL_LETTER_START 96
#define CAP_LETTER_CAP 91
#define CAP_LETTER_START 64
#define NUMBER_START 47
#define NUMBER_END 58
using namespace std;
static bool isPasswordValid(string password);
static bool isUsernameValid(string username);
//functions added separately:
 bool isLetter(char word); //checks if a char is a letter