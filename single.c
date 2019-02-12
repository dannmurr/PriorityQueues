#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
 struct Node {
	int data;
	struct Node* next;
};
struct Node* first = NULL;
struct Node* last = NULL;

void enqueue(int x) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(first == NULL && last == NULL){
		first = temp;
		last = temp;
		return;
	}
	last->next = temp;
	last = temp;
}


void dequeue() {
	struct Node* temp = first;
	if(first == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(first == last) {
		first = NULL;
		last = NULL;
	}
	else {
		first = first->next;
	}
	free(temp);
}

int getFirst() {
	if(first == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	return first->data;
}

void print() {
	struct Node* temp = first;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	enqueue(2); print(); 
	enqueue(4); print();
	enqueue(6); print();
	dequeue();  print();
	enqueue(8); print();
	dequeue(); print();
	dequeue(); print();
	dequeue(); print();
	dequeue(); print();

}
