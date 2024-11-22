/******************
Name: Zohar Perets
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    int userChoice;
    //Variables for case 1
    char eyes1, nose1, mouth1;
    int faceSize1 = 0;
    do {
        printf("Choose an option:\n"
            "\t1. Happy Face\n"
            "\t2. Balanced Number\n"
            "\t3. Generous Number\n"
            "\t4. Circle Of Joy\n"
            "\t5. Happy Numbers\n"
            "\t6. Festival Of Laughter\n"
            "\t7. Exit\n");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1: {
                // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
                /* Example:
                * n = 3:
                * 0   0
                *   o
                * \___/
                */
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c", &eyes1);
                scanf(" %c", &nose1);
                scanf(" %c", &mouth1);

                printf("Enter face size:\n");
                scanf("%d", &faceSize1);
                // Check face size validation
                while (faceSize1 <= 0 || faceSize1 % 2 == 0) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d", &faceSize1);
                }
                // Print the happy face
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < faceSize1 + 2; j++) {
                        if (i == 0) {
                            // First row: Eyes
                            if (j == 1) {
                                printf("%c", eyes1); // Left eye
                            } else if (j == faceSize1+1) {
                                printf("%c", eyes1); // Right eye
                            } else {
                                printf(" ");
                            }
                        } else if (i == 1) {
                            // Middle row: Nose
                            if (j == (faceSize1+1) / 2) {
                                printf("%c", nose1);
                            } else {
                                printf(" ");
                            }
                        } else if (i == 2) {
                            // Last row: Mouth
                            if (j == 0) {
                                printf("\\");
                            } else if (j == faceSize1 + 1) {
                                printf("/");
                            } else {
                                printf("%c", mouth1);
                            }
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case 2: {
                // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
                // and the sum of all digits to the right of the middle digit(s) are equal
                /* Examples:
                Balanced: 1533, 450810, 99
                Not blanced: 1552, 34
                Please notice: the number has to be bigger than 0.
                */
            }

            // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
            /* Examples:
            Abudant: 12, 20, 24
            Not Abudant: 3, 7, 10
            Please notice: the number has to be bigger than 0.
            */

            // Case 4: determine wether a number is a prime.
            /* Examples:
            This one brings joy: 3, 5, 11
            This one does not bring joy: 15, 8, 99
            Please notice: the number has to be bigger than 0.
            */


            // Happy numbers: Print all the happy numbers between 1 to the given number.
            // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
            /* Examples:
            Happy :) : 7, 10
            Not Happy :( : 5, 9
            Please notice: the number has to be bigger than 0.
            */

            // Festival of Laughter: Prints all the numbers between 1 the given number:
            // and replace with "Smile!" every number that divided by the given smile number
            // and replace with "Cheer!" every number that divided by the given cheer number
            // and replace with "Festival!" every number that divided by both of them
            /* Example:
            6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
            */
            default: {
                printf("This option is not available, please try again.\n");
            }
        }
    } while (userChoice != 7);
    return 0;
}
