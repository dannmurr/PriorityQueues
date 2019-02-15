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
    struct Element temp; 
    temp.label = counter++;
    temp.priority =-INT_MAX;
    heap[0] = temp;
}
 
void enqueue(int epriority) {
    printf("debug1");
    heapSize++;
    struct Element temp;
    temp.label = counter++;
    temp.priority = epriority;
    heap[heapSize] = temp; 
    int now = heapSize;
    printf("debug");
    while (heap[now / 2].priority > epriority) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = temp;
}

void generateEvent(){
    int newPriority = rand()% 10 + 1;
    enqueue(newPriority);
    printf("generated priority: %d\n", newPriority);
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
 
void printHeap(){
    int i;
    printf("[");
    for(i = 1; i < heapSize + 1; i++){
        printf("%d, ", heap[i].priority);
    }
    printf("]\n");
}

int main() {
    int iter;
    init();
    int N = 3;
    srand(time(0));

    enqueue(1);
    printf("heapsize: %d\n", heapSize);

    while(heapSize > 0){
        int priority = dequeue().priority;
        int i = rand() %N;
        int j;
        printf("original %d\n", priority);
        for(j = 0; j < i; j++){
             generateEvent();
        }
        printHeap();
    }

    return 0;
}