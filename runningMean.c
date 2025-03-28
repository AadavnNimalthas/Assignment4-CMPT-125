/*
 * Running Mean
 * Aadavn Nimalthas
 * March 25th, 2025
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

void WeightedRunningMean(double* measurements, double* weightedRunningMean, int numInRunningMean);

int main(void) {
    char fileName[100];
    int numMeas;
    FILE *file;

    printf("Enter input file name: ");
    scanf("%99s", fileName);

    int attempts = 0;
    while ((file = fopen(fileName, "r")) == NULL && attempts < 3) {
        printf("ERROR: Input file %s not opened\n", fileName);
        if (attempts < 2) {
            printf("Enter the name of the input file: ");
            scanf("%99s", fileName);
        }
        attempts++;
    }

    if (!file) {
        printf("ERROR: too many failures opening input file\n");
        return 1;
    }

    printf("Enter number of data points (1 to 40): ");
    scanf("%d", &numMeas);

    if (numMeas <= 0 || numMeas > 40) {
        printf("Error: numMeas must be between 1 and 40.\n");
        fclose(file);
        return 1;
    }

    double *myMeasurements = (double *)malloc(numMeas * sizeof(double));
    double *myRunningMean = (double *)malloc(numMeas * sizeof(double));

    if (!myMeasurements || !myRunningMean) {
        printf("Memory allocation failed.\n");
        free(myMeasurements);
        free(myRunningMean);
        fclose(file);
        return 1;
    }

    int count = 0;
    while (count < numMeas && fscanf(file, "%lf", &myMeasurements[count]) == 1) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Error: Empty file.\n");
        free(myMeasurements);
        free(myRunningMean);
        return 1;
    }

    WeightedRunningMean(myMeasurements, myRunningMean, count);

    /* Print results (5 per line, 10 characters wide, 2 decimal places) */
    printf("\nWeighted Running Mean:\n");
    for (int i = 0; i < count; i++) {
        printf("%10.2lf ", myRunningMean[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    free(myMeasurements);
    free(myRunningMean);

    return 0;
}

/* Function to compute Weighted Running Mean */
void WeightedRunningMean(double* measurements, double* weightedRunningMean, int numInRunningMean) {
    if (numInRunningMean == 0) return;

    weightedRunningMean[0] = measurements[0];  /* First element */

    for (int k = 1; k < numInRunningMean; k++) {
        weightedRunningMean[k] = (weightedRunningMean[k-1] / 2.0 + measurements[k]) / 1.5;
    }
}
