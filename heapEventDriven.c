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
    temp.priority =-DBL_MAX;
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
   struct timeval stop, start;
 

double increment(){
    time_t t;
    srand ((unsigned) time(&t));
    return rand() % 50;
}

void generateEvent(double removedElementTimeStamp){
    enqueue(removedElementTimeStamp + increment());
}

int main(){
    int number_of_elements = 1;
    int iter;
    double element;
    init();

    enqueue(0.0);

    generateEvent(dequeue().priority);

    while(heapSize > 1){

    }


    for (iter = 0; iter < number_of_elements; iter++) {
        struct Element temp = dequeue(); 
        printf("%f %d\n", temp.priority, temp.label);
    }


    return 0;
}

