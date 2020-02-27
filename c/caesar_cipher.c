#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 256

int cipherEncrypt(int n)
{
    return (n + 3) % 26;
}

int cipherDecrypt(int n)
{
    return (n - 3) % 26;
}

char* encryptString(char *plaintext, char *ciphertext)
{
    for (int i = 0; i < strlen(plaintext)-1; i++)
    {
        int plainCode = toupper(plaintext[i]) - 65;
        if (plainCode >= 0 && plainCode <= 25)
        {
            int cipherCode = cipherEncrypt(plainCode);
            ciphertext[i] = cipherCode + 65;
        } 
        else
        {
            ciphertext[i] = ' ';
        }
    }
}

char* decryptString(char *ciphertext, char *plaintext)
{
    for (int i = 0; i < strlen(ciphertext)-1; i++)
    {
        int cipherCode = toupper(ciphertext[i]) - 65;
        if (cipherCode >= 0 && cipherCode <= 25)
        {
            int plainCode = cipherDecrypt(cipherCode);
            plaintext[i] = cipherCode + 65;
        } 
        else
        {
            plaintext[i] = ' ';
        }
    }
}

int main()
{
    char str[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char plaintext[MAX_LENGTH];

    printf("Please enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    printf("Plain text: %s\n", str);

    encryptString(str, ciphertext);
    printf("Cipher text: %s\n", ciphertext);
    decryptString(ciphertext, plaintext);
    printf("Plain text decrypted: %s\n", plaintext);

    printf("%i", cipherEncrypt(cipherDecrypt(25)));
    return 0;
}
