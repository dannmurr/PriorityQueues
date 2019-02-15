#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

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

void generateEvent(){
    int newPriority = rand()% 10 + 1;
    enqueue(newPriority);
    printf("generated priority: %d\n", newPriority);
}

void printHeap(){
    int i;
    printf("[");
    for(i = 1; i < heapSize; i++){
        printf("%d, ", heap[i].priority);
    }
    printf("%d]\n", heap[i].priority);
}

int main() {
    init();
    int N = 3;
    srand(time(0));
    enqueue(1);

    while(heapSize > 0){
        int priority = dequeue().priority;
        int i = rand() %N;
        int j;
        printf("dequeued %d\n", priority);
        for(j = 0; j < i; j++){
            generateEvent();
        }
        printHeap();
    }
    return 0;
}