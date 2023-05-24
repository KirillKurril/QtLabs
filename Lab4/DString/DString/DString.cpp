#include<iostream>
#define CRT_SECURE_NO_WARNINGS
int main() {
    char str[] = "Hello, world! How are you?";
    char delimiters[] = " ,!?";
    char* token = strtok(str, delimiters);

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }
 }
