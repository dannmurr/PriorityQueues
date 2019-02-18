#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include "heapSchedulingQueue.h"

void simulate_test() {
    init();
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 1000;
    srand(time(0));
    enqueue(1);

    while(getHeapSize() > 0 && getHeapSize() < max_number_of_elements){
        int priority = dequeue().priority;
        int j;
        printf("dequeued: %d, enqueued: ", priority);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent();
        }
        printf(" - heap size: %d\n", getHeapSize());
        printHeap();
    }
}

void enqueue_to_empty_heap() {
    init();
    printHeap();
    enqueue(9);
    printHeap();
}

void enqueue_multiple_elements_to_heap() {
    init(); printHeap();
    enqueue(9); printHeap();
    enqueue(8); printHeap();
    enqueue(2); printHeap();
    enqueue(6); printHeap();
    enqueue(5); printHeap();
    enqueue(7); printHeap();
}

void dequeue_from_empty_heap() {
    init();
    printHeap();
    dequeue();
    printHeap();
}

void dequeue_from_heap() {
    init(); printHeap();
    enqueue(9); printHeap();
    enqueue(8); printHeap();
    enqueue(2); printHeap();
    enqueue(6); printHeap();
    enqueue(5); printHeap();
    enqueue(7); printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
}

void get_heap_size_test() {
    enqueue(10); enqueue(5); enqueue(8);
    printHeap();
    printf("Expected 3 elements - result %d elements", getHeapSize());
}

void generate_random_priority_test() {
    int i;
    int sum = 0;
    int num_of_elements = 1000000;
    int randInt;
    srand(time(0));

    for (i=0; i < num_of_elements; i++) {
        randInt = genrateRandomPriority();
        sum += randInt;
        printf("%d ", randInt);
    }
    double actualAverage = (double) sum / num_of_elements;
    printf("\nExpected %lf - result %lf", 5.5, actualAverage);
}


int main() {
    //simulate_test();
    //enqueue_to_empty_heap();
    //enqueue_multiple_elements_to_heap();
    //dequeue_from_empty_heap();
    //dequeue_from_heap();
    //get_heap_size_test();
    generate_random_priority_test();
}