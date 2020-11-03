#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void swap(unsigned char *a, unsigned char *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int KSA(char *key, unsigned char *S) {

    int len = strlen(key);
    int j = 0;

    for(int i = 0; i < N; i++)
        S[i] = i;

    for(int i = 0; i < N; i++) {
        j = (j + S[i] + key[i % len]) % N;

        swap(&S[i], &S[j]);
    }

    return 0;
}

int PRGA(unsigned char *S1, unsigned char *S2, char *plaintext, unsigned char *ciphertext) {

    int i = 0;
    int j1 = 0;
    int j2 = 0;

    for(size_t n = 0, len = strlen(plaintext); n < len; n++) {
        i = (i + 1) % N;
        j1 = (j1 + S1[i]) % N;

        swap(&S1[i], &S1[j1]);

        j2 = (j2 + S2[i]) % N;

        swap(&S2[i], &S2[j2]);

        int rnd1 = S1[(S1[i] + S1[j1]) % N];
        int rnd2 = S2[(S2[i] + S2[j2]) % N];

        ciphertext[n] = rnd1 ^ rnd2 ^ plaintext[n];

        swap(&S1[S2[j1]],&S1[S2[j2]]);
        swap(&S2[S1[j1]],&S2[S1[j2]]);
    }

    return 0;
}

int RC4( char *plaintext,char *key1,char *key2,unsigned char *ciphertext) {

    unsigned char S1[N],S2[N];
    KSA(key1, S1);
    KSA(key2, S2);

    PRGA(S1,S2, plaintext, ciphertext);

    return 0;
}

int main() {

     unsigned char plaintext[255];
     unsigned char key1[100];
     unsigned char key2[100];

     // senders side
    printf("enter the plaintext\n");
    scanf("%s",plaintext);
     printf("enter the key1\n");
    scanf("%s",key1);
     printf("enter the key2\n");
    scanf("%s",key2);

    unsigned char *ciphertext = malloc(sizeof(int) * strlen(plaintext));

    RC4( plaintext, key1 , key2, ciphertext);

    printf("****************************  Transmitting the message  *******************************\n\n");

    printf("At receiver side: \n");
    printf("The received message is \n");
    for(size_t i = 0, len = strlen(plaintext); i < len; i++)
         printf("%02X ", ciphertext[i]);
    printf("\n\nEnter the keys to decrypt the message\n");
    printf("key1:");
         scanf("%s",&key1);
    printf("key2:");
         scanf("%s",&key2);

    printf("**************************  Decrypting the message ************************************\n\n");

    unsigned char *decryptedtext = malloc(sizeof(int) * strlen(plaintext));

    RC4(ciphertext,key1,key2,decryptedtext);

    for(size_t i = 0, len = strlen(plaintext); i < len; i++)
        printf("%c", decryptedtext[i]);
    printf("\n");

    return 0;
}
