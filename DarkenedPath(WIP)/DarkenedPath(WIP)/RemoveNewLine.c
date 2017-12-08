/******************************************************************************/
/*!
\file   RemoveNewLine.c
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
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