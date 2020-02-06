#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<sys/time.h>
#include "singleSchedulingQueue.h"

void enqueue_to_empty_list() {
    printList();
    enqueue(106);
    printList();
}

void enqueue_multiple_elements_to_list() {
    printList();
    enqueue(106);
    enqueue(190);
    enqueue(8);
    printList();
}

void dequeue_from_empty_list() {
    dequeue();
}

void dequeue_element_from_list() {
    enqueue(106); enqueue(190); enqueue(8);
    printList();
    printf("After dequeue element: "); dequeue();
    printList();
}

void get_list_size_test() {
    enqueue(106); enqueue(190); enqueue(8);
    printf("Expected 3 elements - result %d elements", getListSize());
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
    printf("\nExpected %d - result %lf", 5.5, actualAverage);
}

void populate_list() {
    int i, randPriority;
    srand(time(0));
    int number_of_iterations = 10000;
    for (i=0; i< number_of_iterations; i++) {
        randPriority = genrateRandomPriority();
        enqueue(randPriority);
        //printf("%d", randPriority);
    }
    printList();
}

void clean_list() {
    while (getListSize() > 0) {
        dequeue();
    }
}

void get_time_to_enqueue() {
    populate_list();
    clock_t start, end;
    double time_to_enqueue;
    srand(time(0));
    int rand = genrateRandomPriority();

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
    clean_list();
}

void get_time_to_dequeue() {
    populate_list();
    printf("List size: %d\n", getListSize());
    clock_t start, end;
    srand(time(0));
    int rand = genrateRandomPriority();

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
    clean_list();
}

void simulate_test() {
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 100000;
    srand(time(0));
    enqueue(1);

    while(getListSize() > 0 && getListSize() < max_number_of_elements){
        int priority = dequeue();
        int j;
        //printf("dequeued: %d, enqueued: ", priority);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent();
        }
        //printList();
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
    clean_list();
}

int main() {
    //simulate_test();
    //enqueue_to_empty_list();
    //enqueue_multiple_elements_to_list();
    //dequeue_from_empty_list();
    //dequeue_element_from_list();
    //get_list_size_test();
    //generate_random_priority_test();
    //get_time_to_enqueue();
    //get_time_to_dequeue()
    get_time_of_simulation();
}