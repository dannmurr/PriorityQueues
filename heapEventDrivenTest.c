#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<float.h>
#include<time.h>
#include<sys/time.h>
#include "heapEventDriven.h"

int simulate_test(){
    init();
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 1000;
    time_t t;
    srand ((unsigned) time(&t));
    enqueue((double) time(NULL));

    while(getHeapSize() > 0 && getHeapSize() < max_number_of_elements){
        double timeStamp = dequeue().priority;
        int j;
        printf("dequeued: %lf, enqueued: ", timeStamp);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent(timeStamp);
        }
        printf(" - heap size: %d\n", getHeapSize());
        //printHeap();
    }
}

void enqueue_to_empty_heap() {
    init();
    printHeap();
    enqueue((double) time(NULL));
    printHeap();
}

void enqueue_multiple_elements_to_heap() {
    init(); printHeap();
    enqueue((double) time(NULL));     printHeap();
    enqueue((double) time(NULL) + 9); printHeap();
    enqueue((double) time(NULL) + 8); printHeap();
    enqueue((double) time(NULL) + 2); printHeap();
    enqueue((double) time(NULL) + 6); printHeap();
    enqueue((double) time(NULL) + 5); printHeap();
    enqueue((double) time(NULL) + 7); printHeap();
}

void dequeue_from_empty_heap() {
    init();
    printHeap();
    dequeue();
    printHeap();
}

void dequeue_from_heap() {
    init(); printHeap();
    enqueue((double) time(NULL));     printHeap();
    enqueue((double) time(NULL) + 9); printHeap();
    enqueue((double) time(NULL) + 8); printHeap();
    enqueue((double) time(NULL) + 2); printHeap();
    enqueue((double) time(NULL) + 6); printHeap();
    enqueue((double) time(NULL) + 5); printHeap();
    enqueue((double) time(NULL) + 7); printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
}

void get_heap_size_test() {
    enqueue((double) time(NULL) + 9);
    enqueue((double) time(NULL) + 3);
    enqueue((double) time(NULL) + 6);
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
        randInt = increment_randomly();
        sum += randInt;
        printf("%d ", randInt);
    }
    double actualAverage = (double) sum / num_of_elements;
    printf("\nExpected %lf - result %lf", 50.5, actualAverage);
}

create_populated_heap() {
    init();
    int num_of_iterations = 100000;
    int i = 0;
    double randPriority;
    srand(time(0));

    printHeap();
    while(i < num_of_iterations) {
        randPriority = increment_randomly();
        enqueue(randPriority);
        i++;
    }
    printHeap();
}

void get_time_to_enqueue() {
    create_populated_heap();
    clock_t start, end;
    start = clock();
    double randPriority;
    randPriority = increment_randomly();
    enqueue(randPriority);
    end = clock();
    double time_to_enqueue = (end - start) / (double) CLOCKS_PER_SEC;
    printf("\n\n%lf", time_to_enqueue);
}

void get_time_to_dequeue() {
    create_populated_heap();
    clock_t start, end;
    start = clock();
    dequeue();
    end = clock();
    double time_to_enqueue = (end - start) / (double) CLOCKS_PER_SEC;
    printf("\n\n%lf", time_to_enqueue);
}

int main() {
    //simulate_test();
    //enqueue_to_empty_heap();
    //enqueue_multiple_elements_to_heap();
    //dequeue_from_empty_heap();
    //dequeue_from_heap();
    //get_heap_size_test();
    //generate_random_priority_test();
    //get_time_to_enqueue();
    get_time_to_dequeue();
}