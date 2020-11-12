#include <stdio.h>
#include <string.h>

int main() {

    char ciphertext[1000];
    char keywordGuess[20];
    char tempkey[1000];
    char plaintext[1000];
    printf("Enter ciphertext: \n");
    scanf("%s", ciphertext);
    printf("\nEnter your keyword guess, with '-' to indicate no guess:\n");
    scanf("%s", keywordGuess);

    int keyLen = strlen(keywordGuess);
    for (int i=0; i<keyLen;i++) {
        if (keywordGuess[i] == '-')
            keywordGuess[i] = 'a';
    }
    // Replace "no guess" characters with a's
    int cipherLen = strlen(ciphertext);
    int count = 0;
    for (int j=0;j<cipherLen;j++) {
        if (count == keyLen) {
            count = 0;
        }
        tempkey[j] = keywordGuess[count];
        // Create the temp key
        plaintext[j] = ((ciphertext[j] - tempkey[j] + 26)%26 + 'a');
        // Decrypt the ciphertext using the temp key
        count++;
        }
    plaintext[cipherLen] = '\0';
    tempkey[cipherLen] = '\0';
    printf("\n%s", tempkey);
    printf("\n%s", plaintext);
    return 0;
}

