#include <stdio.h>

int main() {
    int pages[20], frames[10], time[10];
    int n, f, i, j, pos;
    int faults = 0, count = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check for page hit
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                count++;
                time[j] = count;   // Update recent use
                break;
            }
        }

        // Page fault
        if(found == 0) {
            pos = 0;

            // Find least recently used page
            for(j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }

        // Display frames
        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
