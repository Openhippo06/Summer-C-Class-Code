#define _CRT_SECURE_NO_WARNINGS
#include "WRassignment4.h"


int main()
{

//Enun of the options used for the program
Options option;
int MAX_Size;
int i = 0;

//First index of the linked list
linked_list *head = NULL;

//These are used in the switch
int size = 0;
int apndNum;
int insrtNum;
int indxNum;
bool validansr = false;

//Asks the user for how big they would like the array size to be
printf("How big would you like to make the array list?\n");

//Makes sure that the array list is at least 1 index
do{

    printf("Size: ");
    scanf(" %d", &MAX_Size);

    if(MAX_Size < 0)
    {
        system("cls");
        printf(RED "Please enter a value greater than 0\n" RESET);
    }
    else {
    {
        validansr = true;
    }
    }

}while(validansr != true);



//Initializes the array list


for(;;)
{

    //Resets back to false everytime so each iteration of the loop still needs a valid answer to proceed
    validansr = false;

    //only runs once, used to tell the user that the array was created succesfully
    if(i == 0)
    {
        printf("Your Linked List has been created!\n");
        i++;
    }

    do{
        //Lists all the options to the user
        printf("\nWhat would you like to do with the Linked List?\n\n");
        printf("Option 0: Append -Insert a given value at the end of the list.\nOption 1: Insert -Insert a given value at a given index of a list. returns 1 if succesful, 0 if not.\n");
        printf("Option 2: Remove -Remove the element found at a given index. Returns 1 if succesful, 0 if not.\nOption 3: Clear -Delete every element in the list.\n");
        printf("Option 4: Get -Return the element at the given index.\nOption 5: Getsize -Return the number of elements in the list\nOption 6: Quit -Quits the program");
        printf("\n\nPlease chose a number associated with one of the options: ");
        scanf(" %d", &option);

        if(option >= 0 && option <= 6)
        {
            validansr = true;
        }
        else
        {
            system("cls");
            printf(RED "Please enter a valid value.\n\n" RESET);
        }
    }while(validansr != true);


    //contains all of the options for the function
    switch(option)
    {
        case append:
            
        system("cls");
            printf("What value would you like to add to the end of the list?\n");
            printf("Value: ");
            scanf(" %d", &apndNum);
            
            system("cls");
            if(size < MAX_Size)
            {
               appendList(&head, &size, apndNum);
            }
            else
            {
                printf(RED "ERROR!!!:" RESET " there is not enough space for the value to fit\n\n");
            }
            break;
        
        //takes a value and an index then replaces the value at the index with the new one
        //Will not create new indexes, only replaces existing ones
        case insert:
            printf("What value would you like to insert and at what index?");
            printf("\nValue: ");
            scanf(" %d", &insrtNum);
            printf("\nIndex: ");
            scanf(" %d", &indxNum);

            //checks for out of bounds index and prints an error
            system("cls");
            if(indxNum > size || indxNum < 0)
            {
                printf(RED "\n0: this task was unsuccessful.\n" RESET);
                printf("\nPossibly index out of bounds\n");
            }
            else 
            {
                ListInsert(&head, indxNum, insrtNum);
                printf("\n1: this task was successful\n");
               
            }
            
            break;

        //Removes an index and shortens the list, all values ahead of the chosen removed index
        //are moved back one index so only the chosen indexs value is deleted
        case remov3:
            printf("What index would you like to remove?\n");
            printf("Index: "); 
            scanf(" %d", &indxNum);

            if(indxNum > size || indxNum < 0 )
            {
                system("cls");
                printf("0: this task was unsuccessful.\n");
            }
            else 
            {
                system("cls");
                removeatIndex(&head, &size, indxNum);
                printf("1: this task was successful.\n");
                
            }

            break;
        
        //Makes a clean slate, nothing is kept from the old list
        case clear:
        
            system("cls");
            listWipe(&head, &size);
            printf("The array list has been wiped.\n");

        break;

        //Prints a value at a given index
        case get:
            
        printf("What Index would you like to print?\n");
        printf("Index: ");
        scanf(" %d", &indxNum);

        system("cls");
        
        //Prints an error if the user tries to read an index that isn't in bounds.
        //Also if the list is empty and they try to read an index it asks them to add values.
        if(indxNum < size && indxNum >= 0)
        {
            getIndex(&head, indxNum);
        }
        else if (size == 0)
        {
            printf(RED "WARNING!!" RESET "  The list is currently empty, please add values to print\n");
        }
        else 
        {
            printf(RED "WARNING!!" RESET "  Index may be out of bounds only chose a number between 0 and %d", (size - 1));
        }   



        /*for(int i = 0; i < arySize; i++)
        {
            printf("%d\n", arrayList[i]);
        }*/

        break;

        //Prints the size of the list and how many more spaces can be used to append new values
        case getsize:

        system("cls");
        printf("The current size of the list is: %d\n", size);
        printf("The maximum size of the list is: %d\n", MAX_Size);
        printf("You still have %d empty slots to use in this array list.\n", (MAX_Size - size));

        break;

        //Frees the memory and ends the program
        case quit:
        
        freeList(&head);
        return 0;
        break;

    }


}


}
