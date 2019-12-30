/******************************************************************************************************************************************************
* Programmer:   Kadupitige Ashi Chamarasinghe
* Class :       CptS 121, FAll 2018; Lab Section 13
* Professor :   Andrew O'Fallon
* Programming Assignment : Bonus Assignment (Strings)
* Date :        November 23, 2018
* Description : This program consits different string library functions. Each function will have a speficic task and the test cases for these functions will be perfomed
*               in the main. Functions are:
*               1.*my_fgets()
*               2. my_fputs()
*               3.*my_strcpy()
*               4.*my_strncpy()
*               5.*my_strcat()
*               6.*my_strncat()
*               7.my_strcmp()
*               8.my_strncmp()
*               9.my_strlen()
* File Description : This file is fucntions.c.Includes fucntion definitions and includes functions.h
********************************************************************************************************************************************/

//includes
#include "functions.h"

/*************************************************************************
* Function: char *my_fgets()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: Reads at most one less than the number of characters specified 
*              by n, into the array pointed to by s, from the input pointed to 
*              by stream. 
* Input parameters: pointer to a string, number, file name
* Returns: string pointer
* Preconditions: A file name and a string with specified number will be
*                inputed
* Postconditions: After reading from the file, string will be stored in the
*                 array
**************************************************************************/
char *my_fgets(char *s, int num, FILE *stream) {
	int c = 0, i = 0;

	if (num <= 0)
		return s;

	while (i < num - 1 && ((c = getc(stream)) != EOF)) {
		s[i] = c;
		i++;
		if (c == '\n') {
		break;
		}
	}
	s[i] = '\0';

	if (i > 0) {
		return s;
	}
	else {
		return NULL; 
	}
}

/*************************************************************************
* Function: int my_fputs()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: Writes s to the output specified by stream. If the function is 
               successful, then it returns the number of characters written to 
			   the output; otherwise it returns MY_EOF.
* Input parameters: pointer to a string, file name
* Returns: number of characters
* Preconditions: A file name and a string will be inputed
* Postconditions: String will be written into the file and numbe of characters
*                 will be returned
**************************************************************************/
int my_fputs(const char *s, FILE *stream) {
	int found = 0, count = 0;
	for (int j = 0; *s != '\0'; j++){
		fprintf(stream, "%c", s[j]);
		count++;
		found = 1;
	}
	if (found == 1) {
		return count;
	}
	else {
		return MY_EOF;
	}
}

/*************************************************************************
* Function: char *my_strcpy()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: Copies all characters in the array pointed to by source into
the array pointed to by destination.
* Input parameters: pointer to a destination, pointer to source
* Returns: destination pointer
* Preconditions: Two strings will be inputed (one for destination and one
*                for source)
* Postconditions: Source array will be copied to the destination array
**************************************************************************/
char *my_strcpy(char *destination, const char *source){
	while (*source != '\0') {
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return destination;
}

/*************************************************************************
* Function: char *my_strncpy()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: Copies no more than n characters from the string pointed to
by source into the array pointed to by destination.
* Input parameters: pointer to a destination, pointer to source, number
* Returns: destination pointer
* Preconditions: Two strings will be inputed (one for destination and one
*                for source) and a number to copy n characters
* Postconditions: Source array will be copied to the destination array
**************************************************************************/
char *my_strncpy(char *destination, const char *source, int n) {
	int i = 0;
	while (i < n && *source != '\0') {
		*destination = *source;
		source++;
		destination++;
		i++;
	}
	*destination = '\0';
	return destination;
}

/*************************************************************************
* Function: char *my_strcat()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description:This function appends a copy of the string pointed to by source
*             to the end of the string pointed to by destination.
* Input parameters: pointer to a destination, pointer to source
* Returns: destination pointer
* Preconditions: Two strings will be inputed (one for destination and one
*                for source)
* Postconditions: the destination array will be return after the concatenation
**************************************************************************/
char *my_strcat(char *destination, const char *source) {
	int length = 0 , i= 0;
	length = my_strlen(destination);
	while (*source) {
		destination[length + i] = *source;
		source++;
		i++;
	}
	destination[length + i] = 0;
	return destination;
}

/*************************************************************************
* Function: char *my_strncat()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description:This function appends no more than n characters from the string
*                  pointed to by source to the end of the array pointed to by
*                  destination.
* Input parameters: pointer to a destination, pointer to source
* Returns: destination pointer
* Preconditions: Two strings will be inputed (one for destination and one
*                for source) and a number
* Postconditions: the destination array will be return after the concatenation
****************************************************************************/
char *my_strncat(char *destination, const char *source, int n) {
	 
	int length = 0, i = 0;
	length= my_strlen(destination);

	while ((i<n) && *source) {
		destination[length + i] = *source;
		source++;
		i++;
	}
	destination[length + i] = 0;

	return destination;
}

/*************************************************************************
* Function: int my_strcmp()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description:This function compares the string pointed to by s1 to the
*             string pointed to by s2.
* Input parameters: pointer to a string, another pointer to string
* Returns: compared value (0 if both strings are equal, 1 if first string
*          is greater than the second, -1 otherwise)
* Preconditions: Two strings will be inputed
* Postconditions: Check if strings are equal or one string is greater than/ less
*                 than the other string
****************************************************************************/
int my_strcmp(const char *s1, const char *s2) {
	int difference =0;
	while (*s1!= '\0' || *s2!= '\0') {
		difference = *s1- *s2;
		if (difference != 0) {
			if (difference < 0) {
				return -1;
			}
			return 1;	
		}
		s1++;
		s2++;
	}
	return 0;
}

/*************************************************************************
* Function: int my_strncmp()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: This function compares no more than n characters from the string
*              pointed to by s1 to the string pointed to by s2.
* Input parameters: pointer to a string, another pointer to string, number
* Returns: compared value (0 if both strings are equal, 1 if first string
*          is greater than the second, -1 otherwise)
* Preconditions: Two strings will be inputed
* Postconditions: Check if strings are equal or one string is greater than/ less
*                 than the other string
****************************************************************************/
int my_strncmp(const char *s1, const char *s2, int n) {
	int i = 0, difference = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n) {
		difference = *s1 - *s2;
		if (difference != 0) {
			if (difference < 0) {
				return -1;
			}
			return 1;
		}
		s1++;
		s2++;
	}
	return 0;
}

/*************************************************************************
* Function: int my_strlen()
* Date Created: November 24, 2018
* Date Last Modified: December 5, 2018
* Description: This function function calculates the length of the string
*              pointed to by s. The computation of length does NOT include
*              the null character.
* Input parameters: string pointer
* Returns: length of the string
* Preconditions: A string will be inputed
* Postconditions: Length of the string is outputed
**************************************************************************/
int my_strlen(const char *s) {
	int length = 0;

	while (s[length] != '\0'){
		length++;
    }
	return length;
}