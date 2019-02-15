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

void enqueue(double x) {
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


double dequeue() {
	struct Node* temp = first;
	if(first == NULL) {
		printf("Queue is Empty\n");
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
	return data;
}

double increment(){
	return rand() % 48 + 2;
}

void generateEvent(double removedElementTimeStamp){
	double newTime = removedElementTimeStamp + increment();
	enqueue(newTime);
	printf("generated time: %lf\n", newTime);
}

void print() {
	struct Node* temp = first;
	while(temp != NULL) {
		printf("%lf --> ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	int N = 3;
	time_t t;
	srand ((unsigned) time(&t));

	printf("the time is %f\n", (double) time(NULL));
	enqueue((double) time(NULL));

	while(first != NULL){
		double timeStamp = dequeue();
		int i = rand() %N;
		int j;
		printf("dequed %lf\n", timeStamp);
		for(j = 0; j < i; j++){
			generateEvent(timeStamp);
		}
		print();
	}
}