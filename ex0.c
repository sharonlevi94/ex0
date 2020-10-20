/*
 ============================================================================
 Name        : ex0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _GNU_SOURCE
#define MAX_FILE_NAME_LEN  1000
#define STUDENT_NAME  50

void terminate(FILE* p2file);
FILE* open_file();

int main()
{
	FILE* file_one = open_file();
	FILE* file_two = open_file();
	//FILE* output = open_file();

char name1[STUDENT_NAME];
char name2[STUDENT_NAME];
fscanf(file_one,"%s",name1);
fscanf(file_two,"%s",name2);
printf("%s %s\n",name1,name2);
int grade;
fscanf(file_one,"%d",grade);
printf("%d",grade);
/*int grade;
while(file_one != NULL && file_two != NULL)
{
	if(strcmp(name1,name2) < 0 )
	{
		fprintf(output,"%s",name1);
		printf("%s",name1);

	}
}*/

			fclose(file_one);
			fclose(file_two);
	return EXIT_SUCCESS;
}
/*=======================================================*/
void terminate(FILE* p2file)
{
	if (p2file == NULL) {
		printf("can't open file\n");
		exit(1);
	}
if(p2file!=NULL)
{
	printf("open file success\n");
}
}
//--------------------------------
FILE* open_file()
{
	size_t file_name_len = 0;
    char* file_one_name =NULL;
	printf("Enter File Name:");
	getline(&file_one_name, &file_name_len, stdin);

	int i=0;
	while(file_one_name[i]!='\n')
	{
		i++;
	}
	file_one_name[i]=NULL;

				FILE* p2file=fopen(file_one_name, "r+");
				terminate(p2file);
				free(file_one_name);

	return p2file;
}

