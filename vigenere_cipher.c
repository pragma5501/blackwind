#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt_vigenere_cipher(char *message, char *key);
char *decrypt_vigenere_cipher(char *message, char *key);
int main(void) {
  char message[] = "attack at dawn";
  char key[] = "lemonlemonlemo";
  char *encrypted_message = encrypt_vigenere_cipher(message, key);
  char *decrypted_message = decrypt_vigenere_cipher(encrypted_message, key);

  printf("%s\n", encrypted_message);
  printf("%s\n", decrypted_message);
}

char *encrypt_vigenere_cipher(char *message, char *key) {
  int message_length = strlen(message);
  char *encrypted_message = (char *)malloc(sizeof(char) * message_length);

  for (int i = 0; i < message_length; i++) {
    if (message[i] == ' ') {
      encrypted_message[i] = ' ';
    }

    if ((int)'A' <= (int)message[i] && (int)message[i] <= (int)'Z') {
      int standard_point = (int)'A';
      encrypted_message[i] =standard_point + ((int)message[i] + (int)key[i] - standard_point * 2) % 26;
    }

    if ((int)'a' <= (int)message[i] && (int)message[i] <= (int)'z') {
      int standard_point = (int)'a';
      encrypted_message[i] =standard_point + ((int)message[i] + (int)key[i] - standard_point * 2) % 26;
    }
  }
  return encrypted_message;
}

char *decrypt_vigenere_cipher(char *message, char *key) {
  int message_length = strlen(message);
  char *decrypted_message = (char *)malloc(sizeof(char) * message_length);

  for (int i = 0; i < message_length; i++) {
    if (message[i] == ' ') {
      decrypted_message[i] = ' ';
    }

    if ((int)'A' <= (int)message[i] && (int)message[i] <= (int)'Z') {
      int standard_point = (int)'A';
      
      if((int)message[i] - (int)key[i] >= 0) {
        decrypted_message[i] = standard_point + ((int)message[i] - (int)key[i] ) % 26;
      }
      else {
        decrypted_message[i] = standard_point + ((int)message[i] - (int)key[i] ) % 26 + 26;
      }
    }

    if ((int)'a' <= (int)message[i] && (int)message[i] <= (int)'z') {
      int standard_point = (int)'a';
      
      if((int)message[i] - (int)key[i] >= 0) {
        decrypted_message[i] = standard_point + ((int)message[i] - (int)key[i] ) % 26;
      }
      else {
        decrypted_message[i] = standard_point + ((int)message[i] - (int)key[i] ) % 26 + 26;
      }
    }
  }
  return decrypted_message;
}
