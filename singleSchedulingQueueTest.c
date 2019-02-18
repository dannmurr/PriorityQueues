#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<sys/time.h>
#include "singleSchedulingQueue.h"

void simulate_test() {
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 1000;
    srand(time(0));
    enqueue(1);

    while(getListSize() > 0 && getListSize() < max_number_of_elements){
        int priority = dequeue();
        int j;
        printf("dequeued: %d, enqueued: ", priority);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent();
        }
        printList();
    }
}

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

int main() {
    simulate_test();
    //enqueue_to_empty_list();
    //enqueue_multiple_elements_to_list();
    //dequeue_from_empty_list();
    //dequeue_element_from_list();
    //get_list_size_test();
    //generate_random_priority_test();
}