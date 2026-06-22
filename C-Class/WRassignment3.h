#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOLD "\033"
#define RED "\033[0;31m"
#define RESET "\033[0m"


typedef enum Options{
    append,
    insert,
    remov3,
    clear,
    get,
    getsize,
    quit
} Options;

//Appends a given value to the end of the list, but doesnt go past the initial max size that the user specified
void appendList(int **arrayList, int *size, int value)
{
    if(*size == 0)
    {
        (*arrayList)[*size] = value;
        (*size)++;
    }
    else 
    { 
        //Reallocates the list and makes it one size bigger
        *arrayList = (int *)realloc(*arrayList, *size * sizeof(int));
        (*arrayList)[*size] = value;
        (*size)++;
    }
    
}

//This function removes an index then shifts all the values that were ahead of the index back by one
void removeatIndex(int **arrayList, int *size, int index)
{
    for(int i = index; i < *size - 1; i++)
    {
        (*arrayList)[i] = (*arrayList)[i + 1];
    }
    
    //First decreases "size" then reallocates storage to size so it will be one index shorter
    (*size)--;
    *arrayList = (int *)realloc(*arrayList, *size * sizeof(int));
    
}


//This function deletes everything in the arraylist
//It takes the pointer and the size of the array then reallocates the storage to only include one value
//Getting rid of the rest
void arrayWipe(int **arrayList, int *size)
{
    
    *arrayList = (int *)realloc(*arrayList, 1 * sizeof(int));
   
    (*size) = 0;
}