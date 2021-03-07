#include "Node.h"

typedef struct {
	OrderPtr headPtr,tailPtr;
	int size;
}Queue;

void check_input(int price){
    int input,check=0;
    printf("You have to pay %d\n",price);
    while(check!=1){
        printf("Cash: ");
        scanf("%d",&input);
        if(input>=price){
            if(input>price){
                printf("Change is %d\n",input-price);
            }
            check=1;
            printf("--- Thank you ---\n\n");
        }
        else{
            printf("--- Please try again ---\n");
            continue;
        }
    }
}

void enqueue(Queue *Q,int x,int y){
    OrderPtr new_node;
    new_node=(OrderPtr)malloc(sizeof(Order));
    if(new_node){
        new_node->order_number=x;
        new_node->queue=y;
        new_node->nextPtr=NULL;

        if(Q->headPtr==NULL){
            Q->headPtr=new_node;
        }
        else{
            Q->tailPtr->nextPtr=new_node;
        }
        Q->tailPtr = new_node;
        Q->size++;
        printf("=== My order is %d ===\n",new_node->order_number);
    }

    else{
        printf("\n-- Out of memories --\n");
    }
}

int dequeue(Queue *Q){
    int value_order_number,value_queue,price,topay;
    OrderPtr t;
    
    if(Q->size>0){
        t=Q->headPtr;
        value_order_number = t->order_number;
        value_queue = t->queue;
         
        Q->headPtr = t->nextPtr;
        if(Q->size==1){
            Q->tailPtr=NULL;
        }
        Q->size--;
        free(t);
        
        switch(value_order_number){
            case 1:
                printf("Your order is Ramen\n");
                price = 100;
                topay = price * value_queue;
                check_input(topay);
                break;
            case 2:
                printf("Your order is Somtum\n");
                price = 50;
                topay = price * value_queue;
                check_input(topay);
                break;
            case 3:
                printf("Your order is Fried Chicken\n");
                price = 60;
                topay = price * value_queue;
                check_input(topay);
                break;
            default:
                printf("\n*** No order in the menu ***\n\n");
                break;
            }
        return topay;
    }
    return 0;
}