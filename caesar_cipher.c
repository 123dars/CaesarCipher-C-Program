#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            message[i] = (ch - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int shift) {
    encrypt(message, 26 - (shift % 26)); // Decryption is reverse of encryption
}

int main() {
    char message[1000];
    int shift, choice;

    printf("Caesar Cipher Program\n");
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character if any
    size_t len = strlen(message);
    if (message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    printf("Enter shift value: ");
    scanf("%d", &shift);

    printf("Choose:\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

