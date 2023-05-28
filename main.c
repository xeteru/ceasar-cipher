#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

char *encrypt(char string[], int shift) {
  printf("\nThe encrypted the message is:\n");
  
  for (int i = 0; i < strlen(string); i++) {
    if (isalpha(string[i])) {
        if (islower(string[i]) && string[i] + shift <= 'z') {
        string[i] = (string[i] + shift);
        printf("%c", string[i]);
      }
      else if (isupper(string[i]) && string[i] + shift <= 'Z') {
        string[i] = (string[i] + shift);
        printf("%c", string[i]);
      }
      else if (islower(string[i]) && string[i] + shift > 'z') {
        string[i] = (string[i] + shift) - 26;
        printf("%c", string[i]);
      }
      else if (isupper(string[i]) && string[i] + shift > 'Z') {
        string[i] = (string[i] + shift) - 26;
        printf("%c", string[i]);
      }
    }
    else {
      printf("%c", string[i]);
    }
  }
  return string;
}

char *decrypt(char string[], int shift) {
  printf("\nThe decrypted the message is:\n");
  for (int i = 0; i < strlen(string); i++) {
    if (isalpha(string[i])) {
        if (islower(string[i]) && string[i] - shift >= 'a') {
        string[i] = (string[i] - shift);
        printf("%c", string[i]);
      }
      else if (isupper(string[i]) && string[i] - shift >= 'A') {
        string[i] = (string[i] - shift);
        printf("%c", string[i]);
      }
      else if (islower(string[i]) && string[i] - shift < 'a') {
        string[i] = (string[i] - shift) + 26;
        printf("%c", string[i]);
      }
      else if (isupper(string[i]) && string[i] - shift < 'A') {
        string[i] = (string[i] - shift) + 26;
        printf("%c", string[i]);
      }
    }
    else {
      printf("%c", string[i]);
    }
  }
  return string;
}

int main(void) {
  printf("Enter a message: \n");
  char caesar[MAX];
  fgets(caesar, MAX, stdin);

  printf("Enter a shift: ");
  int shift;
  scanf("%d", &shift);
  
  decrypt(encrypt(caesar, shift), shift);

  return 0;
}