#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include "singleEventDriven.h"

void enqueue_to_empty_list() {
    time_t t;
    srand ((unsigned) time(&t));
    printList();
    enqueue((double) time(NULL));
    printList();
}

void enqueue_multiple_elements_to_list() {
    time_t t;
    srand ((unsigned) time(&t));
    printList();
    enqueue((double) time(NULL));
    enqueue((double) time(NULL) + 1);
    enqueue((double) time(NULL) + 2);
    printList();
}

void dequeue_from_empty_list() {
    dequeue();
}

void dequeue_element_from_list() {
    enqueue((double) time(NULL));
    enqueue((double) time(NULL) + 10);
    printList();
    enqueue((double) time(NULL) + 2);
    printList();
    printf("After dequeue element: "); dequeue();
    printList();
}

void get_list_size_test() {
    enqueue((double) time(NULL));
    enqueue((double) time(NULL) + 1);
    enqueue((double) time(NULL) + 2);
    printf("Expected 3 elements - result %d elements", getListSize());
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


void populate_list() {
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

void clean_list() {
    while (getListSize() > 0) {
        dequeue();
    }
}

void get_time_to_enqueue() {
    populate_list();
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
    clean_list();
}


void get_time_to_dequeue() {
    populate_list();
    printf("List size: %d\n", getListSize());
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
    clean_list();
}


int simulate_test(){
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 100000;
    time_t t;
    srand ((unsigned) time(&t));
    enqueue((double) time(NULL));

    while(getListSize() > 0 && getListSize() < max_number_of_elements){
        double timeStamp = dequeue();
        int j;
        //printf("dequeued: %lf, enqueued: ", timeStamp);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent(timeStamp);
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