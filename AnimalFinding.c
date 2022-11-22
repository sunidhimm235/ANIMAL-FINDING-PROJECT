#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Added a larger buffer size.
#define SIZE 100000+1

int main() {
    
    // Declared char pointer array to store animal pattern and allocated it's memory in heap using malloc function.
    // Declared an integer to store the number of sections to process.
    char * S = (char *) malloc(sizeof(char) * SIZE);
    int N = 0;

    // Took input for animal pattern and the number of sections.
    scanf("%s", S);
    scanf("%d", &N);

    // Created for loop to run the program/process until the number of sections.
    for(int x = 0; x < N; x++) {
        
        // Created one more char array for holding park section and allocated it's memory in heap using malloc function.
        char * parkSection = (char *) malloc(sizeof(char) * SIZE);
        // Created one more integer 'count' to hold the number of times animal pattern is presented in the current park section.
        int count = 0;
        
        // Used fgets() to take the input for park section with the white space.
        fgets(parkSection, SIZE, stdin);

        // Used for loop to go through every character in the array until it hits terminator.
        // int 'y' is for park section string, int 'z' is for animal pattern string
        // 'y' increases every time, but 'z' only increases when park section of 'y' is equal to animal pattern of 'z'.
        for(int y = 0, z = 0; parkSection[y] != '\0'; y++) {
            
            // If-else condition to check if current character of park section matches the current character of animal pattern.
            if(parkSection[y] == S[z]) { // If it does, then it will increase z by one.
                z++;
            } else { // If it doesn't, then it will initialize z with zero.
                z = 0;
            }
            
            // One more if statement to check if z is equals to the length of animal pattern array.
            if(z == strlen(S)) { // If it is, then it will increase count by one, initialize z with 0, and initialize y with length of animal pattern array minus one.
                count++;
                z = 0;
                y -= (strlen(S) - 1);
            }
        }
        
        // Lastly, the program will print out the total count of animal pattern presented in park section.
        printf("%d\n", count);
        
        // Used free() to deallocate the memory from heap.
        free(parkSection);

    }
    
    // Used free() to deallocate the memory from heap.
    free(S);

    return 0;
}