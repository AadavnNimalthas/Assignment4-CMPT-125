/*
 * Pattern
 * Aadavn Nimalthas
 * March 28th, 2025
 * With the user inputting a number of rows create and display a triangle like pattern with numbers.
 */

#include <stdio.h>

void printARow(int startColNum, const int numOfRow);
void printPattern(int startColNum, const int numRows);

int main() {
    int numRows;
    int attempts = 0;

    do {
        printf("Enter the number of rows: ");
        scanf("%d", &numRows);
        if (numRows < 1 || numRows > 12) {
            printf("ERROR: The number of rows out of range\n");
            printf("       1 <= number of rows <= 12\n");
            attempts++;
        } 
        else {
            break;
        }
    } 
    
    while (attempts < 3);

    if (attempts >= 3) {
        printf("ERROR: Too many tries, attempting to read the number of rows for the pattern.\n");
        return 1;
    }

    int startColNum = (numRows + 1) / 2;
    printPattern(startColNum, numRows);

    return 0;
}

void printARow(int startColNum, const int numOfRow) {
    for (int i = 0; i < startColNum; i++) {
        printf("     ");
    }

    int current = startColNum;
    int elements = numOfRow - startColNum + 1;

    printf("%d", current);

    for (int i = 1; i < elements; i++) {
        current += startColNum + i;
        printf("%5d", current);
    }

    printf("\n");
}

void printPattern(int startColNum, const int numRows) {
    if (startColNum < 1) return;

    printARow(startColNum, numRows);

    printPattern(startColNum - 1, numRows);

    printARow(startColNum, numRows);
}
