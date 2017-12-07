#include "stdafx.h"

char *RemoveNewLine(char *string)
{
  int length = strlen(string);

  for (int i = 0; i < length; i++)
  {
    if (*(string + i) == '\n')
    {
      *(string + i) = 0;
    }
  }
  return string;
}