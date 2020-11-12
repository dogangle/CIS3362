#include <stdio.h>
#include <string.h>

int main() {

    int testkey[2][2];
    char ciphertext[1000];
    char plaintext[1000];

    printf("Enter ciphertext to be decrypted: \n");
    scanf("%s", ciphertext);
    // Get ciphertext

    int cipherLen = strlen(ciphertext);
    // Generate all possible 2x2 matrix for brute-force decryption
    for (int i=0; i<26; i++) {
        testkey[0][0] = i;

        for (int j=0; j<26; j++) {
            testkey[0][1] = j;

            for (int k=0; k<26; k++) {
                testkey[1][0] = k;

                for (int p=0; p<26; p++) {
                    testkey[1][1] = p;
                    // printf("\n\n%d\t%d\n%d\t%d", testkey[0][0], testkey[0][1], testkey[1][0], testkey[1][1]);
                    // Test to make sure matrix was filled in properly

                    for (int w=0; w<cipherLen; w=w+2) {

                        plaintext[w] = ((testkey[0][0] * (ciphertext[w] - 'A')) + (testkey[0][1] * (ciphertext[w+1] - 'A'))) % 26 + 'A';
                        plaintext[w+1] = ((testkey[1][0] * (ciphertext[w] - 'A')) + (testkey[1][1] * (ciphertext[w+1] - 'A'))) % 26 + 'A';
                        // Decrypt using current test matrix

                    }
                    plaintext[cipherLen] = '\0';
                    for (int a=0; a<cipherLen;a++) {

                        if (plaintext[a] == 'E' && plaintext[a-1] == 'H' && plaintext[a-2] == 'T') {
                            printf("\n\n%d\t%d\n%d\t%d\n\n", testkey[0][0], testkey[0][1], testkey[1][0], testkey[1][1]);
                            printf("%s\n\n", plaintext);
                            // Print out the decrypted text + decryption key if the decrypted text contains the string 'THE'

                        }

                    }
                }
            }
        }
    }
    return 0;
}

