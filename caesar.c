/*
*Rahul Mitra
*/
/*Included libraries*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
/*Max size of input string*/
#define MAXSIZE 1000
/*
External function written in assembly 
* IN: c is a single lower-case alphabetic character
* IN: direction is 0 for encrypt, 1 for decrypt
* IN: shift is a positive integer for the amount to be shifted
* OUT: the correct encrypted/decrypted character
* SIDE-EFFECTS: none
*/
extern char cipher(char c, int direction, int shift);
void main(void){
    char input[1000];//input string
    int dir;//direction of shift
    int size;//size of shift
    char choice = 'Y';//choice variable
    int i;//looping variable
    char lowercase;//to store the lower case characters
    printf("Enter a string: \n");
    scanf(" %[^\n]s", input);//to take input line by line
    printf("Encrypt (1) or Decrypt(2)\n");
    scanf("%d", &dir);
    printf("Shift:\n");
    scanf("%d", &size);
    for ( i = 0; i < strlen(input); i++){
        if (isalpha(input[i])){//pass only alphabetic characters to the function
            lowercase = tolower(input[i]);
            input[i] = cipher(tolower(input[i]) , dir, size);
        }
    }
    printf("%s\n", input);
    while ( choice == 'Y'){//continue until the user wants to quit
        printf("Do another (Y/N)?\n");
        scanf(" %c", &choice);
        if ( choice == 'N'){
            break;
        }
        //do the same stuff as above
        printf("Enter a string: \n");
        scanf(" %[^\n]s", input);
        printf("Encrypt (1) or Decrypt(2)\n");
        scanf("%d", &dir);
        printf("Shift:\n");
        scanf("%d", &size);
        for ( i = 0; i < strlen(input); i++){
        if (isalpha(input[i])){
            input[i] = cipher(tolower(input[i]) , dir, size);
        }
    }
        printf("%s\n", input);
   }
}
