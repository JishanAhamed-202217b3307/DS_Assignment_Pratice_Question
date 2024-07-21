#include <stdio.h>
#include <stdlib.h> // For exit()

void main() {
    int n, a[10], b[10], t[10], w[10], g[11], i;
    float att = 0, awt = 0;

    // Initialize arrays
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        t[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Number of processes must be between 1 and 10.\n");
        exit(1);
    }

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the completion time for the first process
    g[0] = a[0] + b[0];

    // Calculate the completion time for each process
    for (i = 1; i < n; i++) {
        g[i] = g[i - 1] + b[i];
    }
    g[n] = g[n - 1] + b[n - 1]; // Completion time of the last process

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i];
        t[i] = g[i] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt = awt / n;
    att = att / n;

    // Print the results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t%d\t\t%d\n", i + 1, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    // No need for getch(), exit cleanly
}
