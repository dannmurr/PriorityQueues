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
	temp->data = x; 
	//temp->next = NULL;
	if(first == NULL || first->data > temp->data){
		temp->next = first;
		first = temp;
		return;
	}
	struct Node *current = first;
	while(current->next != NULL && current->next->data <= temp->data){
		current = current->next;
	}
	temp->next = current->next;
	current->next = temp;
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
	enqueue(1); print(); 
	enqueue(3); print();
	enqueue(2); print();
	enqueue(2); print();
	dequeue();  print();
	dequeue(); print();
	dequeue(); print();
	dequeue(); print();
}
