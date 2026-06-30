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

//This is the initailized linked list
typedef struct linked_list{
    struct linked_list *next;
    int value;
}linked_list;


void appendList(linked_list **head, int *size, int value)
{
    
    linked_list *newValue = (linked_list *)malloc(sizeof(linked_list));
    newValue->value = value;
    newValue->next = NULL;
    
    if(*head == NULL)
    {
        (*size)++;
        *head = newValue;
        
    }
    else
    {

        linked_list *current = *head;\
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newValue;
        (*size)++;
    }


}

void ListInsert(linked_list **head, int index, int num)
{
    linked_list *current = *head;

    for(int i = 0; i < index; i++)
    {
        //hops to the next node and finally ends on the desired index
        current = current->next;
    }

    current->value = num;
}

//This function removes an index then shifts all the values that were ahead of the index back by one
void removeatIndex(linked_list **head, int *size, int index)
{

    linked_list *toDelete;
    linked_list *current = *head;

    //Only if the first index gets removed
    if(index == 0)
    {
    *head = current->next;
    free(current);
    return;
    }

    for(int i = index; i < index -1; i++)
    {
        //temp = current;
        current = current->next;
    }
    
    //Gets to the index right before the one planned to be removed then sets the toDelete to the index thats going to be 
    //removed, then current->next becomes toDeletes next successfully isolating toDelete while keeping coherency
    //which allows a nice free of the the memory
    
    toDelete = current->next;
    
    if(toDelete->next == NULL)
    {
        current->next = NULL;
    }
    else 
    {
        current->next = toDelete->next;
    }
    
    
    free(toDelete);
    //First decreases "size" then reallocates storage to size so it will be one index shorter
    (*size)--;
    
    
}

void getIndex(linked_list **head, int index)
{

    linked_list *current = *head;

    //loops through the list because i cant just point to the index i want
    for(int i = 0; i < index; i++)
    {
        //hops to the next node and finally ends on the desired index
        current = current->next;
    }

    printf("Value at index [%d]: %d\n", index, current->value);

}


//This frees all the memory of the list, virtually the same as the freelist function but it sets size to 0 
//So you can make the list anew
void listWipe(linked_list **head, int *size)
{
    linked_list *current = *head;
    linked_list *next;

    //loops through the list and frees all the values until it reaches a null
    while(current != NULL)
    {
        next = current->next;
        free(current); 
        current = next;
    }

    *head = NULL;
   
    (*size) = 0;
}

void freeList(linked_list **head)
{
    linked_list *current = *head;
    linked_list *next;

    //loops through the list and frees all the values until it reaches a null
    while(current != NULL)
    {
        next = current->next;  
        free(current);         
        current = next;        
    }

    //was freed in the loop so it needs to not point to freed memory
    *head = NULL;  
}