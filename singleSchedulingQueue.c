#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<sys/time.h>

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

int dequeue() {
	struct Node* temp = first;
	if(first == NULL) {
		printf("Queue is Empty\n");
		return NULL;
	}
	if(first == last) {
		first = NULL;
		last = NULL;
	}
	else {
		first = first->next;
	}
	int data = temp->data;
	free(temp);
	return data;
}

void generateEvent(){
	int newPriority = rand()% 10 + 1;
	enqueue(newPriority);
	printf("generated priority: %d\n", newPriority);
}

void print() {
	struct Node* temp = first;
	while(temp != NULL) {
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	int N = 3;
	srand(time(0));
	enqueue(1);

	while(first != NULL){
		int priority = dequeue();
		int i = rand() %N;
		int j;
		printf("dequed %d\n", priority);
		for(j = 0; j < i; j++){
			generateEvent();
		}
		print();
	}
}