#include <stdio.h>

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int r;
    printf("Enter the number of resource types: ");
    scanf("%d", &r);

    int init[r];
    printf("Enter available resources:\n");
    for(int j = 0; j < r; j++){
        printf("Resource %d: ", j+1);
        scanf("%d", &init[j]);
    }

    int allocation[n][r];
    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i < n; i++){
        printf("Process %d:\n", i+1);
        for(int j = 0; j < r; j++){
            printf("Resource %d: ", j+1);
            scanf("%d", &allocation[i][j]);
        }
    }

    int max[n][r];
    printf("Enter Max Matrix:\n");
    for(int i = 0; i < n; i++){
        printf("Process %d:\n", i+1);
        for(int j = 0; j < r; j++){
            printf("Resource %d: ", j+1);
            scanf("%d", &max[i][j]);
        }
    }

    int done[n];
    for(int i = 0; i < n; i++) done[i] = 0;

    int flag = 1;
    int order[n];
    int k = 0;

    while(flag){
        flag = 0;
        for(int i = 0; i < n; i++){
            if(done[i] == 1)
                continue;
            int need[r];
            for(int j = 0; j < r; j++){
                need[j] = max[i][j] - allocation[i][j];
            }
            int flag2 = 1;
            for(int j = 0; j < r; j++){
                if(need[j] > init[j]){
                    flag2 = 0;
                    break;
                }
            }
            if(flag2){
                for(int j = 0; j < r; j++){
                    init[j] += allocation[i][j];
                }
                order[k++] = i + 1;
                done[i] = 1;
                flag = 1;
            }
        }
    }

    if(k == n){
        printf("Safe Sequence: ");
        for(int i = 0; i < n; i++){
            printf("P%d", order[i]);
            if(i != n-1){
                printf(" -> ");
            }
        }
        printf("\n");
    }
    else{
        printf("No safe sequence found. Deadlock exists.\n");
    }

    return 0;
}