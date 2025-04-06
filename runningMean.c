/*
 * Running Mean
 * Aadavn Nimalthas
 * March 25th, 2025
 *
 * Displays the weighted running mean
 */

#include <stdio.h>
#include <stdlib.h>

void WeightedRunningMean(double* measurements, double* weightedRunningMean, int numInRunningMean) {
    if (numInRunningMean <= 0) return;
    weightedRunningMean[0] = measurements[0];
    for (int k = 1; k < numInRunningMean; k++) {
        weightedRunningMean[k] = (weightedRunningMean[k-1] / 2.0 + measurements[k]) / 1.5;
    }
}

int main() {
    char filename[256];
    FILE *filep = NULL;
    int attempts = 0;
    int numMeas = 0;
    int num_attempts = 0;

    do {
        printf("Enter the name of the input file: ");
        if (scanf("%255s", filename) != 1) {
            fprintf(stderr, "Error reading filename\n");
            exit(1);
        }
        filep = fopen(filename, "r");
        if (filep) break;
        else {
            fprintf(stderr, "ERROR: Input file %s not opened\n", filename);
            attempts++;
        }
    }
    while (attempts < 3);

    if (attempts >= 3) {
        fprintf(stderr, "ERROR: too many failures opening input file\n");
        exit(1);
    }


    do {
        printf("Enter the number of measurements: ");
        if (scanf("%d", &numMeas) != 1) {
            fprintf(stderr, "Invalid input for numMeas\n");
            while (getchar() != '\n');
            numMeas = 0;
        }
        if (numMeas <= 0 || numMeas > 40) {
            fprintf(stderr, "ERROR: numMeas is out of range\n");
            fprintf(stderr, "       enter 0<numMeas<=40\n");
            num_attempts++;
        }
        else break;
    }
    while (num_attempts < 3);

    if (num_attempts >= 3) {
        fprintf(stderr, "ERROR: too many failures reading the number of measurements\n");
        fclose(filep);
        exit(1);
    }

    double *myMeasurementsp = malloc(numMeas * sizeof(double));
    double *myRunningMeanp = malloc(numMeas * sizeof(double));
    if (!myMeasurementsp || !myRunningMeanp) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(filep);
        exit(1);
    }

    int actualCount = 0;
    double value;
    while (actualCount < numMeas && fscanf(filep, "%lf", &value) == 1) {
        myMeasurementsp[actualCount++] = value;
    }
    fclose(filep);

    if (actualCount == 0) {
        fprintf(stderr, "ERROR: input file is empty\n");
        free(myMeasurementsp);
        free(myRunningMeanp);
        exit(1);
    }

    if (actualCount < numMeas) {
        fprintf(stderr, "ERROR: fewer than numMeas measurements in the file\n");
    }

    WeightedRunningMean(myMeasurementsp, myRunningMeanp, actualCount);

    printf("The running sums are\n");
    for (int i = 0; i < actualCount; i++) {
        printf("%10.2f", myRunningMeanp[i]);
        if ((i + 1) % 5 == 0 || i == actualCount - 1) {
            printf("\n");
        }
    }

    free(myMeasurementsp);
    free(myRunningMeanp);

    return 0;
}