#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt_vigenere_cipher(char *message, char *key);

int main(void) {
  printf("%s", encrypt_vigenere_cipher("attack at dawn", "lemonlemonlemo"));
}

char *encrypt_vigenere_cipher(char *message, char *key) {
  int message_length = strlen(message);
  char *encrypted_message = (char *)malloc(sizeof(char) * message_length);

  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == ' ') {
      encrypted_message[i] = ' ';
    }
    
    if ((int)'A' <= (int)message[i] && (int)message[i] <= (int)'Z') {
      int standard_point = (int)'A';
      encrypted_message[i] = standard_point + ((int)message[i] + (int)key[i] - standard_point * 2) % 26;
    }
    
    if ((int)'a' <= (int)message[i] && (int)message[i] <= (int)'z') {
      int standard_point = (int)'a';
      encrypted_message[i] = standard_point + ((int)message[i] + (int)key[i] - standard_point * 2) % 26;
    }
  }
  
  return encrypted_message;
}
