#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

int main(int argc , char **argv){
    Queue Q;
    Q.headPtr=NULL;
    Q.tailPtr=NULL;
    Q.size=0;
    int i,topay,n=1;

    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            if(Q.size>0){
                printf("Customer No.%d\n",n++);
                topay=dequeue(&Q);
            }
            else{
                printf("\n*** NO ORDER ***\n");
            }
        }
        else{
            enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
            i++;
        }
    }
    printf("==============================\n");
    printf("There're %d order in queue\n",Q.size);
    return 0;
}