#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
 
 
struct Element{
    int label; 
    int priority;
};

struct Element heap[10000];
int heapSize;
int counter;

void init() {
    heapSize = 0;
    counter = 0;
    struct Element *temp; 
    temp->label = counter++;
    temp->priority =-INT_MAX;
    heap[0] = *temp;
}
 
void enqueue(int epriority) {
    heapSize++;
    struct Element temp;
    temp.label = counter++;
    temp.priority = epriority;
    heap[heapSize] = temp; 
    int now = heapSize;
    while (heap[now / 2].priority > epriority) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = temp;
}
 
struct Element dequeue() {
    struct Element minElement, lastElement; 
    int child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {
        child = now * 2;
        if (child != heapSize && heap[child + 1].priority < heap[child].priority) {
            child++;
        }
        if (lastElement.priority > heap[child].priority) {
            heap[now] = heap[child];
        } else 
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}
 
int main() {
    int number_of_elements;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    int iter, element;
    init();
    printf("Enter the elements: ");
    for (iter = 0; iter < number_of_elements; iter++) {
        scanf("%d", &element);
        enqueue(element);
    }
    printf("------------------------------\n" );
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d   ", dequeue().priority);
    }
    printf("\n");
    return 0;
}