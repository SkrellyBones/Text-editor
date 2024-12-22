#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#define MAX_LENGTH 256

int main() {
    FILE *fptr;
    
    char text[128];
    char length[MAX_LENGTH];
    char filename[MAX_LENGTH];
    char yesor;
    char command[5];
    bool infunc;
    int lengthint = 0; // Initialize lengthint to 0
     printf("Would you like to list all files in this directory? (Y/N): ");
     scanf("%s", &yesor);
     if (yesor == 'Y'){    
     DIR *d;
     struct dirent *dir;
     d= opendir(".");
     if (d){
        while ((dir = readdir(d)) !=NULL) {
            printf("%s \n", dir->d_name);
        }
        closedir(d);
     }
     
     }
        //  #how
    printf("What would you like to do? (R/W/LD)")
    scanf("%s", &command)
     while (infunc != TRUE){
    if (command == 'R'){
             printf("Please enter name of your desired text file: ");
    scanf("%s", filename);
    fptr = fopen(filename, "rb");
    
    if (fgets(text, sizeof(text), fptr) != NULL) {
        text[strcspn(text, "\n")] = '\0'; // Remove the trailing newline character
        printf("Contents of text file: %s\n", text);
    }
    fclose(fptr);

    }
    else if (command == 'W'){
        
    }
    else if (command == 'W')

     }
    
   
   
}

int write(){
     printf("Please enter name of your desired text file: ");
    scanf("%s", filename);
    fptr = fopen(filename, "rb");
    
    if (fgets(text, sizeof(text), fptr) != NULL) {
        text[strcspn(text, "\n")] = '\0';
        // Remove the trailing newline character
        printf("Contents of text file: %s\n", text);
    }
    fclose(fptr);
     fptr = fopen(filename, "w");
    
    while (lengthint <= 0) {
        printf("How many characters?: ");
        fgets(length, sizeof(length), stdin);
        lengthint = atoi(length);

    if (lengthint <= 0) {
        printf("Invalid input. Please enter a valid number of characters.\n");
        }
    }

    char newtext[lengthint + 1];
    strncpy(newtext, text, lengthint); // Copy 'lengthint' characters 
    //from 'text' to 'newtext'
    newtext[lengthint] = '\0'; // Null-terminate the 'newtext' string

    printf("Type new contents of text file: ");
    fgets(newtext, MAX_LENGTH, stdin);

    size_t len = strlen(newtext);
    if (len > 0 && newtext[len - 1] == '\n') {
        newtext[len - 1] = '\0';
        len--;
    }

    if (len > lengthint) {
        newtext[lengthint] = '\0';
    } else if (len < lengthint) {
        size_t remaining = lengthint - len;
        if (remaining <= MAX_LENGTH - len - 1) {
            strncat(newtext, " ", remaining);
        }
    }

    printf("Contents of text file: %s\n", newtext);
    fprintf(fptr, "%s", newtext);
    fclose(fptr);

    return 0;

}