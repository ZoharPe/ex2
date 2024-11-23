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
    int faceSize1;
    //Variables for case 2
    int harmonyNumber2, harmonyNumberSize2 = 0, harmonyNumberRightSum2 = 0, harmonyNumberLeftSum2 = 0;
    //Variables for case 3
    int generousNumber3, dividersSum3 = 0;
    //Variables for case 4
    int number4, reveresedNumber4 = 0, flag4 = 0;
    //Variables for case 5
    int number5, squereDigitsSum5 = 0, numberTemp5, digitTemp5;

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
                            } else if (j == faceSize1 + 1) {
                                printf("%c", eyes1); // Right eye
                            } else {
                                printf(" ");
                            }
                        } else if (i == 1) {
                            // Middle row: Nose
                            if (j == (faceSize1 + 1) / 2) {
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
                printf("Enter a number: :\n");
                scanf("%d", &harmonyNumber2);
                // Check validation
                while (harmonyNumber2 < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &harmonyNumber2);
                }
                //Get the number og digits in the given harmony number
                for (int temp = harmonyNumber2; temp > 0; temp /= 10) {
                    harmonyNumberSize2++;
                }
                printf("harmonyNumberSize2 %d:\n", harmonyNumberSize2);
                //Sum the right digits
                for (int i = 0; i <= harmonyNumberSize2; i++) {
                    if (i < harmonyNumberSize2 / 2) {
                        harmonyNumberRightSum2 += harmonyNumber2 % 10;
                    } else if (i > harmonyNumberSize2 / 2) {
                        harmonyNumberLeftSum2 += harmonyNumber2 % 10;
                    }
                    harmonyNumber2 = harmonyNumber2 % 10;
                }
                printf("%d\n", harmonyNumberRightSum2);
                printf("%d\n", harmonyNumberLeftSum2);

                if (harmonyNumberRightSum2 == harmonyNumberLeftSum2) {
                    printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
                //Cleanup for our next uses
                harmonyNumberSize2 = 0, harmonyNumberRightSum2 = 0, harmonyNumberLeftSum2 = 0;
                break;
            }
            case 3: {
                // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
                /* Examples:
                Abudant: 12, 20, 24
                Not Abudant: 3, 7, 10
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number: :\n");
                scanf("%d", &generousNumber3);
                // Check validation
                while (generousNumber3 < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &generousNumber3);
                }

                for (int i = 1; i < generousNumber3; i++) {
                    if (generousNumber3 % i == 0)
                        dividersSum3 += i;
                }
                if (generousNumber3 < dividersSum3) {
                    printf("This number is generous!\n");
                } else {
                    printf("This number does not share.\n");
                }
                dividersSum3 = 0;
                break;
            }

            case 4: {
                // Case 4: determine wether a number is a prime.
                /* Examples:
                This one brings joy: 3, 5, 11
                This one does not bring joy: 15, 8, 99
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number: :\n");
                scanf("%d", &number4);
                // Check validation
                while (number4 < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number4);
                }
                //Special case
                if (number4 == 1) {
                    printf("The circle remains incomplete.\n");
                    flag4 = 1;
                    break;
                }
                if (flag4 == 1) {
                    //Cleanup
                    reveresedNumber4 = 0, flag4 = 0;
                    break;
                }
                //Check if the number is prime
                for (int i = 2; i < number4; i++) {
                    if ((number4 % i) == 0) {
                        printf("The circle remains incomplete.\n");
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 1) {
                    //Cleanup
                    reveresedNumber4 = 0, flag4 = 0;
                    break;
                }
                //Reverse the given num
                while (number4 > 0) {
                    reveresedNumber4 = reveresedNumber4 * 10 + number4 % 10;
                    number4 /= 10;
                }
                printf("%d\n", reveresedNumber4);
                //Check if the reversed number is prime
                for (int i = 2; i < reveresedNumber4; i++) {
                    if ((number4 % i) == 0) {
                        printf("%d\n", i);
                        printf("The circle remains incomplete.\n");
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 1) {
                    //Cleanup
                    reveresedNumber4 = 0, flag4 = 0;
                    break;
                }
                printf("This number completes the circle of joy!\n");
                //Cleanup
                reveresedNumber4 = 0, flag4 = 0;
                break;
            }
            case 5: {
                // Happy numbers: Print all the happy numbers between 1 to the given number.
                // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
                /* Examples:
                Happy :) : 7, 10
                Not Happy :( : 5, 9
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number: :\n");
                scanf("%d", &number5);
                // Check validation
                while (number5 < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number5);
                }
                printf("Happy numbers between 1 and %d: ", number5);
                // Iterate all numbers from 1 to the given number - number5
                for (int i = 1; i <= number5; i++) {
                    numberTemp5 = i;
                    squereDigitsSum5;
                    // Check if the current number is happy - According to a little research ive made: every unhappy number eventually reaches to be 4 after a few "loops"
                    while (numberTemp5 != 1 && numberTemp5 != 4) {
                        squereDigitsSum5 = 0;
                        // Calculate the sum of the squares of the digits
                        while (numberTemp5 > 0) {
                            int digitTemp5 = numberTemp5 % 10; // Extract the last digit
                            squereDigitsSum5 += digitTemp5 * digitTemp5;
                            numberTemp5 /= 10;
                        }
                        numberTemp5 = squereDigitsSum5;
                    }
                    // If the number ends at 1, it is a happy number
                    if (numberTemp5 == 1) {
                        printf("%d ", i);
                    }
                }
                //Clenup
                squereDigitsSum5 = 0, numberTemp5 = 0;
                printf("\n");
                break;
            }

            case 6: {
                // Festival of Laughter: Prints all the numbers between 1 the given number:
                // and replace with "Smile!" every number that divided by the given smile number
                // and replace with "Cheer!" every number that divided by the given cheer number
                // and replace with "Festival!" every number that divided by both of them
                /* Example:
                6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
                */
            }
            default: {
                printf("This option is not available, please try again.\n");
            }
        }
    } while (userChoice != 7);
    return 0;
}
