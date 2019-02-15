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
    int N = 10;
    time_t t;
    srand ((unsigned) time(&t));

    printf("the time is %f\n", (double) time(NULL));
    enqueue((double) time(NULL));

    while(heapSize > 0){
        double timeStamp = dequeue().priority;
        int i = rand() %N;
        int j;
        printf("original %lf\n", timeStamp);
        for(j = 0; j < i; j++){
             generateEvent(timeStamp);
        }
    }
