#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front=-1,rear=-1;
int isFull() {
	return(rear + 1) % MAX_SIZE == front;
	}
int isEmpty(){
	return front == -1;
	}
void enqueue(int value){
	if(isFull()){
		printf("Queue is full!, Cannot Enqueue %d\n",value);
		return;
	}
if(isEmpty()){
	front=rear=0;
}else{
	rear=(rear + 1) % MAX_SIZE;
	}
		queue[rear]=value;
		printf("Enqueued %d \n",value);
	}
void dequeue(){
	if (isEmpty()){
		printf("Queue is empty!,Cannot dequeue\n");
		return;
	}
		printf("Dequeued %d\n",queue[front]);
	if(front==rear){
		front=rear=-1;
	}else{
		front=(front+1)%MAX_SIZE;
	}
    }
void display(){
	if ( isEmpty()){
		printf("Queue is Empty!\n");
		return;
	}
		printf("Queue elements: ");
		int i = front;
	while(1){
		printf("%d ",queue[i]);
		if(i == rear)
			break;
		i= (i+1) % MAX_SIZE;
		}
		printf("\n");
	}
	int main(){
		int choice,value;
	while(1){
		printf("\nCircular Queue Operations Menu:\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display Queue\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the value to enqueue:");
			scanf("%d",&value);
			enqueue(value);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Exiting program.\n");
			return 0;
		default:
			printf("Invalid choice ! PLease try again.\n");
			}
		}
		
	return 0;
}
		

	
	
	
	
	
	
	
	
	
	
	
	
	
