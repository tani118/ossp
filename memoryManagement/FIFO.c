#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int n = 20;

    int frames;
    scanf("%d", &frames);

    int frameArr[frames];

    int last = 0;


    int isHit = 0;
    for(int i = 0; i < n; i++){
        isHit = 0;
        for(int j = 0; j < frames; j++){
            if(frameArr[j] == arr[i]){
                isHit = 1;
                break;
            }
        }
        if(!isHit){
            frameArr[last] = arr[i];
            last = (last + 1) % frames;
        }
    }


}