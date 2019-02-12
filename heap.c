#include<stdio.h>
#include<limits.h>
 
 
int heap[10000], heapSize;
void init() {
    heapSize = 0;
    heap[0] = -INT_MAX;
}
 
void enqueue(int element) {
    heapSize++;
    heap[heapSize] = element; 
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}
 
int dequeue() {
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {
        child = now * 2;
        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
        }
        if (lastElement > heap[child]) {
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
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d ", dequeue());
    }
    printf("\n");
    return 0;
}