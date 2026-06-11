#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
   
    //Opens the first file and creates the
    //file that will be a duplicate with line numbers
    FILE *old_file = fopen(".\\Text_files\\Assignment1_base.txt", "r");
    FILE *new_file = fopen(".\\Text_files\\Assignment_1Dup.txt", "w");

    //Values used for the fgets and line numbers
    char current[100];
    int i = 1;
  

    //Just incase the file path was entered incorrectly
    if (old_file == NULL)
    {
        printf("Error: File could not be found\n");
        printf("Make sure you inputed the correct path");   
    }

    //Using a while loop since if it doesnt work immedietly 
    //I dont want an unnecessary iteration
    //The loop checks to see if a line is Null, and when it is
    //It stops and exits the loop
    while(fgets(current, sizeof(current), old_file) != NULL)
    {
        //uses fprintf and the new_file pointer to add line numbers
        fprintf(new_file, "Line%d: %s", i, current);
        i++;

    }
    
    printf("The task is completed");
}
