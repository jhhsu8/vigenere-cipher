#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Implement a program that encrypts messages using Vigenère’s cipher.*/
int main(int argc, string argv[]) {
    
    //Only accept an alphbetical string (key) as a command-line argument
    string key = argv[1];

    if (argc == 2) {

        for (int j = 0, m = strlen(key); j < m; j++) {

            if (!isalpha(key[j])) {

                printf("Use alphabets only\n");
                return 1;
            }
        }
        string input;

        printf("Enter a message: ");

        input = GetString();

        int count = 0;
        int key_index, input_index, new_input_index, new_input_ascii;

        for (int i = 0, n = strlen(input); i < n; i++) {

            //Extract each ASCII character from the message
            int input_ascii = input[i];

            //Extract each ASCII character from the key according to the input length
            int key_ascii = key[count % strlen(key)];

            if (isupper(input_ascii)) {

                //Convert each uppercase input/key character into 0 - 25 indexes
                int upper_ascii = toupper(key_ascii);
                input_index = input_ascii - 65;
                key_index = upper_ascii - 65;

                //Shift each index by the integer (key) and the key is maintained at 1 (a) to 26 (z)
                new_input_index = (input_index + key_index) % 26;
                new_input_ascii = new_input_index + 65;

                count++;
                
            } else if (islower(input_ascii)) {
                
                //Convert each lowercase input/key character into 0 - 25 indexes
                int lower_ascii = tolower(key_ascii);
                input_index = input_ascii - 97;
                key_index = lower_ascii - 97;

                //Shift each index by the integer (key) and the key is maintained at 1 (a) to 26 (z)
                new_input_index = (input_index + key_index) % 26;
                new_input_ascii = new_input_index + 97;
                count++;

            } else {
                
                //Non-alphabet characters remain unchanged
                new_input_ascii = input_ascii;
            }
            printf("%c", (char) new_input_ascii;
        }
        printf("\n");
    } else {
        printf("./vigenere <add key here>\n");
        return 1;
    }
    return 0;
}