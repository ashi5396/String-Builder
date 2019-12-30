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
* File Description : This file is main.c and it includes fucntions.h. It performes test cases for each function.
********************************************************************************************************************************************/

//includes
#include "functions.h"

int main(void) {

	/*
		This is a test case for fgets with a specified number.It will read a string from a file and store in an array.
		The array will be printed.
	*/
	printf("******Test case for fgets function******\n");
	FILE *infile = NULL;
	infile = fopen("Test.txt", "r");
	char str_test[50];
	my_fgets(str_test, 13, infile);
	printf("The string that was read from the file with %d characters is: ", 13);
	puts(str_test);

	printf("\n");

	/*
		This is a test case for my_fputs. It will read a string and it will write to a file
	*/
	FILE *outfile = NULL;
	outfile = fopen("Out.txt","w");
	const char *radno = "Hello";
	//my_fputs(radno, outfile);

	/*
		This is a test case for string copying.Has two strings and second string will be copied into
		the first string.
	*/
	char fruit[10] = "Apples";
	char secondFruit[10] = "Orange";
	printf("******Test case for string copying******\n");
	printf("First string is %s\n", fruit);
	printf("Second string is %s\n", secondFruit);
	my_strcpy(fruit, secondFruit);
	printf("After copying the second string into the first string is %s\n", fruit);
	
	printf("\n");

	/*
		This is a test case for string copying.Has two strings and second string will be copied into
		the first string with a specified number
	*/
	char place[50] = "Rome";
	char secondPlace[50] = "England";
	printf("******Test case for string copying with a specified number******\n");
	printf("First string is %s\n", place);
	printf("Second string is %s\n", secondPlace);
	my_strncpy(place, secondPlace,3);
	printf("After copying the second string into the first string with %d number of characters is %s\n", 3,place);

	printf("\n");
	
	/*
		This is a test case for string concatination.Has two strings and second string will be concatinated to
		the first string.
	*/
	char firstName[50] = "Ashi";
	char lastName[50] = "Chamarasinghe";
	printf("******Test case for string appending******\n");
	printf("First string is %s\n", firstName);
	printf("Second string is %s\n", lastName);
	my_strcat(firstName, lastName);
	printf("After appending one string into the other string is %s\n", firstName);

	printf("\n");

	/*
		This is a test case for string concatination.Has two strings and second string will be concatinated to
		the first string with a specified number.
	*/

	char firstColor[20] = "Red";
	char secondColor[20] = "Brown";
	printf("******Test case for string appending with a specified number******\n");
	printf("First string is %s\n", firstColor);
	printf("Second string is %s\n", secondColor);
	my_strncat(firstColor, secondColor,4);
	printf("After appending %d number of characters in a one string into the other string is %s\n", 4, firstColor);

	printf("\n");

	/*
		This is a test case for string comparing. Both strings will be compared and will output which string is great
		than the other.
	*/
	char color[15] = "Blue";
	char aNimal[10] = "Cougar";

	my_strcpy(color, aNimal);
	printf("%c\n", color[4]);
	printf("%s\n", color);
	my_strcat(aNimal, &color[1]);
	printf("%s\n", aNimal);

	printf("******Test case for string comparing******\n");
	printf("First string is %s\n", color);
	printf("Second string is %s\n", aNimal);
	int comp = my_strcmp(color, aNimal);
	if (comp == -1) {
		printf("Second string is greater than the first string\n");
	}
	else if (comp == 1) {
		printf("First string is greater than the second string\n");
	}
	else {
		printf("Both strings are equal\n");
	}
	
	printf("\n");

	/*
		This is a test case for string comparing with a specified number. Both strings will be compared and will output 
		which string is great than the other.
	*/
	char name[20] = "Kadupitige";
	char otherName[20] = "Kadupitzge";
	printf("******Test case for string comparing with a specified number******\n");
	printf("First string is %s\n", name);
	printf("Second string is %s\n", otherName);
	int num = my_strncmp(name, otherName,9);
	if (num == -1) {
		printf("Second string is greater than the first string\n");
	}
	else if (num == 1) {
		printf("First string is greater than the second string\n");
	}
	else {
		printf("Both strings are equal\n");
	}

	printf("\n");

	/*
		This is a test case for string length.String's length will be computed and shown
	*/
	char *myName = "Andy Fallon";
	printf("******Test case for string length******\n");
	printf("Length of the string %s is %d\n", myName, my_strlen(myName));

	return 0;



}