#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<float.h>
#include<time.h>
#include<sys/time.h>
#include "heapEventDriven.h"

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

void populate_heap() {
    int i;
    double randPriority;
    srand(time(0));
    int number_of_iterations = 100000;
    for (i=0; i< number_of_iterations; i++) {
        randPriority = increment_randomly();
        enqueue(randPriority);
        //printf("%d", randPriority);
    }
    //printList();
}

void get_time_to_enqueue() {
    populate_heap();
    printf("List size: %d\n", getHeapSize());
    clock_t start, end;
    srand(time(0));
    double rand = increment_randomly();

    double sum = 0;
    double mean = 0;
    int i;
    for(i=0; i<100; i++){
        start = clock();
        enqueue(rand);
        end = clock();
        sum += (end - start) / (double) CLOCKS_PER_SEC;
        dequeue();
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
}

void get_time_to_dequeue() {
    populate_heap();
    printf("List size: %d\n", getHeapSize());
    clock_t start, end;
    srand(time(0));
    double rand = increment_randomly();

    double sum = 0;
    double mean = 0;
    int i;
    for(i=0; i<100; i++){
        start = clock();
        dequeue();
        end = clock();
        sum += (end - start) / (double) CLOCKS_PER_SEC;
        printf("sum: %lf\n", sum);
        enqueue(rand);
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
}


void simulate_test(){
    init();
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 100000;
    time_t t;
    srand ((unsigned) time(&t));
    enqueue((double) time(NULL));

    while(getHeapSize() > 0 && getHeapSize() < max_number_of_elements){
        double timeStamp = dequeue().priority;
        int j;
        //printf("dequeued: %lf, enqueued: ", timeStamp);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent(timeStamp);
        }
        //printf(" - heap size: %d\n", getHeapSize());
        //printHeap();
    }
}

void get_time_of_simulation() {
    clock_t start, end;
    double sum = 0;
    double mean = 0;
    int i;

    for(i=0; i<100; i++){
        start = clock();
        simulate_test();
        end = clock();

        sum += (end - start) / (double) CLOCKS_PER_SEC;
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
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