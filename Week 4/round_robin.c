#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int time = 0, done;

    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

    } while (!done);

    // Calculate Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
