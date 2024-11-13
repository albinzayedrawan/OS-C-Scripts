#include <stdio.h>
#include <stdlib.h>

int main() {

    char *userInput = NULL; // declaring user input 
    size_t inputSize = 0; 
    
    // can be removed, we added it to make sence of the code, and make it user friendly 
    printf("Please input your data here: ");

    // getline function to get user input 
    getline(&userInput, &inputSize, stdin); 
    
    // displays the data that user intered
    printf("You entered: %s", userInput);
    

    return 0;
}