#include <stdio.h>

int isPagePresent(int frame[], int ref, int n){
    for(int i = 0; i < n; i++){
        if(frame[i] == ref)
            return 1;
    }
    return 0;
}

int giveIndex(int arr[], int frame[], int frames, int n, int idx){
    int res = -1;
    int farthest = idx;
    for(int i = 0; i < frames; i++){
        int j;
        for(j = idx + 1; j < n; j++){
            if(frame[i] == arr[j]){
                if(j > farthest){
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if(j == n){
            // The page is not going to be used again.
            return i;
        }
    }
    if(res == -1){
        return 0;
    } else {
        return res;
    }
}

int main(){
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int frames;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frameArr[frames];
    for(int i = 0; i < frames; i++){
        frameArr[i] = -1;
    }

    int faults = 0;

    for(int i = 0; i < n; i++){
        printf("Reference page: %d\t", arr[i]);
        if(!isPagePresent(frameArr, arr[i], frames)){
            faults++;
            int indexToReplace = -1;
            for(int j = 0; j < frames; j++){
                if(frameArr[j] == -1){
                    indexToReplace = j;
                    break;
                }
            }
            if(indexToReplace == -1){
                indexToReplace = giveIndex(arr, frameArr, frames, n, i);
            }
            frameArr[indexToReplace] = arr[i];
            printf("Page Fault\t");
        } else {
            printf("Page Hit\t");
        }
        printf("Frames: ");
        for(int j = 0; j < frames; j++){
            if(frameArr[j] != -1)
                printf("%d ", frameArr[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}