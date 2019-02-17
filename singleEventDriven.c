#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

struct Node {
	double data;
	struct Node* next;
};
struct Node* first = NULL;
struct Node* last = NULL;
int list_size = 0;

void enqueue(double x) {
	struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	if(first == NULL || first->data > temp->data){
		temp->next = first;
		first = temp;
		list_size++;
		return;
	}
	struct Node *current = first;
	while(current->next != NULL && current->next->data <= temp->data){
		current = current->next;
	}
	temp->next = current->next;
	current->next = temp;
	list_size++;
}

double dequeue() {
	struct Node* temp = first;
	if(first == NULL) {
		printf("Queue is Empty\n");
		list_size = 0;
		return -1;
	}
	if(first == last) {
		first = NULL;
		last = NULL;
	}
	else {
		first = first->next;
	}
	double data = temp->data;
	free(temp);
	list_size--;
	return data;
}

int getListSize() {
	return list_size;
}

double increment_randomly(){
	return rand() % 98 + 2;
}

void generateEvent(double removedElementTimeStamp){
	double newTime = removedElementTimeStamp + increment_randomly();
	enqueue(newTime);
	printf(" %lf ", newTime);

}

void printList() {
	struct Node* temp = first;
	printf("list size: %d\n", list_size);
	if(first == NULL) {
		printf("List is empty");
	}
	while(temp != NULL) {
		printf("%lf --> ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
