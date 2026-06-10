#include <stdio.h>

int main() {
    int pages[20], frames[10];
    int n, f, i, j, k, pos;
    int faults = 0, found, farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        // Check for page hit
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0) {

            // Check for empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    faults++;
                    found = 1;
                    break;
                }
            }

            // Replace page using Optimal algorithm
            if(found == 0) {
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++) {
                    index = -1;

                    // Find next use of current frame page
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    // If page is never used again
                    if(index == -1) {
                        pos = j;
                        break;
                    }

                    // Find page used farthest in future
                    if(index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                faults++;
            }
        }

        // Display frames
        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
