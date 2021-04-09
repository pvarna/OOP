#include "helpers.h"

bool isLetter(char ch)
{
    return ch == ' ' ||
          (ch >= 'a' && ch <= 'z') ||
          (ch >= 'A' && ch <= 'Z'); 
}