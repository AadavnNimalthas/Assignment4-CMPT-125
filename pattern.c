#include <stdio.h>

void printARow(int startColNum, const int numOfRow);
void printPattern(int startColNum, const int numRows);

int main() {
    int numRows;
    int attempts = 0;

    // Read and validate the number of rows
    do {
        printf("Enter the number of rows: ");
        scanf("%d", &numRows);
        if (numRows < 1 || numRows > 12) {
            printf("ERROR: The number of rows out of range\n");
            printf("    1 <= number of rows <= 12\n");
            attempts++;
        } else {
            break;
        }
    } while (attempts < 3);

    if (attempts >= 3) {
        printf("ERROR: Too many tries, attempting to read the number of rows for the pattern.\n");
        return 1;
    }

    int startColNum = (numRows + 1) / 2;
    printPattern(startColNum, numRows);

    return 0;
}

void printARow(int startColNum, const int numOfRow) {
    // Calculate the number of tabs at the start (startColNum - 1)
    for (int i = 0; i < startColNum - 1; i++) {
        printf("\t");
    }

    int current = startColNum;
    int elements = numOfRow - startColNum + 1;

    // Print the first number
    printf("%d", current);

    // Print subsequent numbers with tabs
    for (int i = 1; i < elements; i++) {
        current += startColNum + i;
        printf("\t%d", current);
    }

    printf("\n");
}

void printPattern(int startColNum, const int numRows) {
    if (startColNum < 1) return;

    // Print the upper part of the pattern
    printARow(startColNum, numRows);
    // Recursively print the inner pattern
    printPattern(startColNum - 1, numRows);
    // Print the lower mirrored part
    printARow(startColNum, numRows);
}