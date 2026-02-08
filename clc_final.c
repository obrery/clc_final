#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Shows the menu and gets a valid option
char getMenuSelection() {
    char option;

    while (1) {
        printf("Select one of the following items:\n");
        printf("B) Binary Mathematical Operations\n");
        printf("U) Unary Mathematical Operations\n");
        printf("A) Advanced Mathematical Operations\n");
        printf("V) Define variables\n");
        printf("E) Exit\n\n");

        printf("Please select your option (B, U, A, V, E): ");
        scanf(" %c", &option);
        option = toupper(option);

        if (option == 'B' || option == 'U' || option == 'A' ||
            option == 'V' || option == 'E') {
            return option;
        }

        printf("Invalid option. Try again.\n\n");
        while (getchar() != '\n');
    }
}

// Does the binary calculation
float doBinaryCalc(float x, float y, char op) {
    if (op == '+') return x + y;
    if (op == '-') return x - y;
    if (op == '*') return x * y;

    if (op == '/') {
        if (y == 0) {
            printf("Error: Can't divide by zero.\n");
            return 0;
        }
        return x / y;
    }

    printf("Error: Bad operator.\n");
    return 0;
}

// Unary placeholder
void doUnaryCalc() {
    printf("Error: Unary operations not coded.\n\n");
}

// Exit message
void exitMessage() {
    printf("Thanks for using my Simple Calculator. Goodbye!\n");
}

int main(void) {
    double num1, num2, result;
    char op;

    double vars[5] = {0, 0, 0, 0, 0}; // a, b, c, d, e
    char varName;
    int index;

    // Header like Assignment 1
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Omar Brery\n");
    printf("Version: 2\n");
    printf("Date: November 2025\n\n");

    while (1) {
        char option = getMenuSelection();

        if (option == 'B') {
            // Basic binary calculation
            printf("Enter the first number: ");
            scanf("%lf", &num1);

            printf("Enter operation (+, -, *, /): ");
            scanf(" %c", &op);

            printf("Enter the second number: ");
            scanf("%lf", &num2);

            result = doBinaryCalc(num1, num2, op);
            printf("Result: %.2lf\n\n", result);
        }

        else if (option == 'U') {
            doUnaryCalc();
        }

        else if (option == 'V') {
            // Variable storage
            printf("Choose a variable (a, b, c, d, e): ");
            scanf(" %c", &varName);
            varName = tolower(varName);

            if (varName < 'a' || varName > 'e') {
                printf("Error: Only a–e allowed.\n\n");
                continue;
            }

            index = varName - 'a';

            printf("Enter a value for %c: ", varName);
            scanf("%lf", &vars[index]);

            printf("Saved: %c = %.2lf\n\n", varName, vars[index]);
        }

        else if (option == 'A') {
            // Advanced using stored variables
            printf("Choose variable 1 (a–e): ");
            scanf(" %c", &varName);
            varName = tolower(varName);

            if (varName < 'a' || varName > 'e') {
                printf("Error: Only a–e allowed.\n\n");
                continue;
            }
            num1 = vars[varName - 'a'];

            printf("Choose operation (+, -, *, /): ");
            scanf(" %c", &op);

            printf("Choose variable 2 (a–e): ");
            scanf(" %c", &varName);
            varName = tolower(varName);

            if (varName < 'a' || varName > 'e') {
                printf("Error: Only a–e allowed.\n\n");
                continue;
            }
            num2 = vars[varName - 'a'];

            result = doBinaryCalc(num1, num2, op);
            printf("Result: %.2lf\n\n", result);
        }

        else if (option == 'E') {
            exitMessage();
            break;
        }

        while (getchar() != '\n');
    }

    return 0;
}
