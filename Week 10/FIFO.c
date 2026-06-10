#include <stdio.h>

int main() {
    int pages[20], frames[10];
    int n, f, i, j;
    int pageFaults = 0, index = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1 (empty)
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already exists in frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found, replace using FIFO
        if(found == 0) {
            frames[index] = pages[i];
            index = (index + 1) % f;   // Move to next frame
            pageFaults++;
        }

        // Display current frames
        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", pageFaults);

    return 0;
}
