#include<stdio.h>
#include<conio.h>

#define MAXSIZE 10

int arr[MAXSIZE];
int front = 0;
int rear = -1;

void insert(){
    int n;
    if(rear <MAXSIZE){
       printf("enter the num: "); 
        scanf("%d", &n);
        rear++;
        arr[rear] = n;
    } else { 
         printf("underflow\n");
    }
}
void delete() {
    if (front < rear) {
        printf("Popped element: %d\n", arr[front]);
        front++;
    } else {
         printf("underflow\n");
    }
}
void display(){
    if (front < rear) {
         printf("Stack elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
    } else {
         printf("underflow\n");
    }
    printf("\n");
}

int main(){
    int choice;
    do{
        printf("1. Push \n2. pop \n3. Display\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
                
        }
    } while(choice != 4);
    

    return 0;
}