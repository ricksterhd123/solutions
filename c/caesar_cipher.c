#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 256

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

int cipherEncrypt(int n)
{
    return mod((n + 3), 26);
}

int cipherDecrypt(int n)
{
    return mod((n - 3), 26);
}

void encryptString(char *plaintext, char *ciphertext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        int plainCode = plaintext[i] - 65;
        if (plainCode >= 0 && plainCode <= 25)
        {
            int cipherCode = cipherEncrypt(plainCode);
            ciphertext[i] = cipherCode + 65;
        } 
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
}

void decryptString(char *ciphertext, char *plaintext)
{
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        int cipherCode = ciphertext[i] - 65;

        if (cipherCode >= 0 && cipherCode <= 25)
        {
            int plainCode = cipherDecrypt(cipherCode);
            plaintext[i] = plainCode + 65;
        } 
        else
        {
            plaintext[i] = ciphertext[i];
        }
    }
}

/*
    Convert lowercase alphabetical characters in a string into uppercase
    Params:
    - char *string -> input string
    - int length -> length of input string
    - char *upperString -> output string (assume they are the same length as the input string)
*/
void stringToUpper(char *string, int length, char *upperString)
{
    for (int i = 0; i < length; i++)
        upperString[i] = toupper(string[i]);
}

int main()
{
    char *str = calloc(sizeof(char), MAX_LENGTH);
    char *ciphertext = calloc(sizeof(char), MAX_LENGTH);
    char *plaintext = calloc(sizeof(char), MAX_LENGTH);

    printf("Please enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
    stringToUpper(str, strlen(str), str);
    printf("Input text: %s\n", str);
    encryptString(str, ciphertext);
    decryptString(ciphertext, plaintext);
    printf("=============ENCRYPT==========\n");
    printf("Cipher text: %s\n", ciphertext);
    printf("=============DECRYPT==========\n");
    printf("Plain text: %s\n", plaintext);
    printf("Comparison: %s", strcmp(str, plaintext) == 0 ? "True" : "False");

    return 0;
}
