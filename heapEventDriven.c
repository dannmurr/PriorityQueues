#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<float.h>
#include<time.h>
#include<sys/time.h>

struct Element{
    int label;
    double priority;
};

struct Element heap[10000];
int heapSize;
int counter;

void init() {
    heapSize = 0;
    counter = 0;
    struct Element temp;
    temp.label = counter++;
    temp.priority = -DBL_MAX;
    heap[0] = temp;
}

void enqueue(double epriority) {
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

double increment(){
    return rand() % 48 + 2;
}

void generateEvent(double removedElementTimeStamp){
    double newTime = removedElementTimeStamp + increment();
    enqueue(newTime);
    printf("generated time: %lf\n", newTime);
}

void printHeap(){
    int i;
    printf("[");
    for(i = 1; i < heapSize; i++){
        printf("%d, ", heap[i].priority);
    }
    printf("%d]\n", heap[i].priority);
}

int main(){
    init();
    int N = 3;
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
        printHeap();
    }
    return 0;
}