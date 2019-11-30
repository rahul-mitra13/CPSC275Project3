#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 1000
extern char cipher(char c, int direction, int shift);
void main(void){
    char input[1000];//input string
    int dir;//direction of shift
    int size;//size of shift
    char choice = 'Y';//choice when user wants to quit
    int i;//looping variable
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
    while ( choice == 'Y'){
        printf("Do another (Y/N)?\n");
        scanf(" %c", &choice);
        if ( choice == 'N'){
            break;
        }
        printf("Enter a string: \n");
        scanf(" %[^\n]s", input);
        printf("Encrypt (1) or Decrypt(2)\n");
        scanf("%d", &dir);
        printf("Shift:\n");
        scanf("%d", &size);
        for ( i = 0; i < strlen(input); i++){
        if (isalpha(input[i])){
            input[i] = cipher(input[i] , dir, size);
        }
    }
        printf("%s\n", input);
   }
}
/*
char cipher(char c, int direction, int shift){
    int newshift = shift % 26;
    int initialshiftforward = c + newshift;
    int initialshiftbackward = c - newshift;
    int wraparoundgreater = initialshiftforward % 122;
    int wraparoundless = 97 % initialshiftbackward;
    int scaleforward = wraparoundgreater + 96;
    int scalebackward = 123 - wraparoundless;
    if (direction == 1){//encryption
        if ( initialshiftforward > 122){
        c = scaleforward;
        }
        else{
            
            c = initialshiftforward;
        }
    }
    else{//decryption
        if ( initialshiftbackward < 97){
          c = scalebackward;
        }
        else{
            c = initialshiftbackward;
        }
    }
    return c;
}*/
