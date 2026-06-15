#include <stdio.h>

void sum(int A, int B, int *C)
{
    //Tests to see if the other local variables can be altered
    *C = A + B;
    A += 13;
    B += 32;

}


int main()
{


//Variables for the Array portion
char StringArray[30] = "This is the Golden Ratio";
int GldRtio[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};


//Prints the string array by creating a pointer to the first index, then iterates through using the number
//of elements between the 2 pointers
for(char *p = StringArray; p-StringArray <= sizeof(StringArray); p++)
{
    printf("%c", *p);
}

puts("");

//this mean int *i = &GldRtio[0]. Essensially means that its pointing at the first element in the array 
for(int *i = GldRtio; i-GldRtio < 10; i++)
{
    printf("%d\t", *i);
}

puts("");

//Doesn't use a pointer to loop through instead uses a pointer to the element at the jth postition
//while not using square brackets
for(int j = 0; j < 10; j++)
{
    printf("%d\t", *(GldRtio+j));
}

puts("\n\n");

//variables used for the Function portion
int A = 28;
int B = 12;
int C = 15;

//Uses copy by value except for C since Im sending the address of it and the receiver is a pointer to said address
//making it changeable in a seperate function
sum(A, B, &C);

printf("A: %d  B: %d  C: %d", A, B, C);

return 0;
}