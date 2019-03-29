#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include "singleEventDriven.h"

#define POPULATION_SEED  61631
#define ARRAY_SIZE 1000
long* seeds[ARRAY_SIZE] = {
        48975, 52866, 72658, 16642, 40468, 20400, 98519, 21137, 61286, 80042,
        49914, 30625, 11265, 19779, 86687, 77363, 24884, 42422, 53252, 99174,
        19923, 40258, 72127, 84762, 61524, 18873, 92096, 44020, 63001, 59276,
        89777, 03345, 41177, 10827, 96182, 25951, 72894, 42070, 48280, 57182,
        41627, 73590, 65559, 94823, 85273, 97949, 51590, 84410, 98468, 37490,
        20588, 39550, 71647, 27157, 58572, 87226, 55109, 22302, 51943, 38112,
        48080, 31501, 85015, 81889, 12772, 74364, 70610, 07550, 13449, 64350,
        49603, 48721, 80488, 16577, 57889, 53967, 99443, 80636, 27944, 82107,
        25104, 98403, 15390, 22528, 20564, 86852, 50555, 40495, 21278, 45867,
        42479, 12397, 81300, 82372, 24561, 55532, 92096 , 54427, 70137, 16886,
};

void enqueue_to_empty_list() {
    printList(generate_psuedo_random());
    enqueue((double) time(NULL));
    printList();
}

void enqueue_multiple_elements_to_list() {
    printList();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    printList();
}

void dequeue_from_empty_list() {
    dequeue();
}

void dequeue_element_from_list() {
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    printList();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    printList();
    printf("After dequeue element: ");
    dequeue();                             printList();
}

void get_list_size_test() {
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    printf("Expected 3 elements - result %d elements", getListSize());
}

void generate_random_priority_test() {
    int i;
    double sum = 0;
    int num_of_elements = 1000000;
    double randInt;

    for (i=0; i < num_of_elements; i++) {
        randInt = generate_psuedo_random();
        sum += randInt;
        printf("%lf ", randInt);
    }
    double actualAverage = (double) sum / num_of_elements;
    printf("\nExpected %lf - result %lf", 500000000.0, actualAverage);
}


void populate_list() {
    int i;
    double randPriority;
    srand48(POPULATION_SEED);
    int number_of_iterations = 1000;

    for (i=0; i< number_of_iterations; i++) {
        randPriority = generate_psuedo_random();
        enqueue(randPriority);
        //printf("%lf ", randPriority);
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
    double rand;
    double sum = 0;
    double mean = 0;
    int i;
    long seed;

    for(i=0; i<100; i++){
        srand48(seeds[i]);
        rand = generate_psuedo_random();

        start = clock();
        enqueue(rand);
        end = clock();

        sum += (end - start) / (double) CLOCKS_PER_SEC;
        dequeue();
        //printf("%lf, ", rand);
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
    clean_list();
}


void get_time_to_dequeue() {
    populate_list();
    printf("List size: %d\n", getListSize());
    clock_t start, end;
    double rand;

    double sum = 0;
    double mean = 0;
    int i;
    for(i=0; i<100; i++){
        start = clock();
        dequeue();
        end = clock();

        sum += (end - start) / (double) CLOCKS_PER_SEC;

        srand48(seeds[i]);
        rand = generate_psuedo_random();
        enqueue(rand);
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
    clean_list();
}


int simulate_test(long seed){
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 1000;
    srand48(seed);
    double initial_event = generate_psuedo_random();
    enqueue(initial_event);

    while(getListSize() > 0 && getListSize() < max_number_of_elements){
        double timeStamp = dequeue();
        int j;
        //printf("dequeued: %lf, enqueued: ", timeStamp);
        for(j = 0; j < number_of_enqueued_elements; j++){
            generateEvent(timeStamp);
        }
        printList();
    }
}

/*
 * Running the simulation for 100 times
 * for each time, a specific seed is used
 * to create random events
 * seeds are 0 -> 99
 * the mean of the results is taking as the final result
 * */
void get_time_of_simulation() {
    clock_t start, end;
    double sum = 0;
    double mean = 0;
    int i;
    long seed;

    for(i=0; i<100; i++){
        seed = seeds[i];
        start = clock();
        simulate_test(seed);
        end = clock();
        sum += (end - start) / (double) CLOCKS_PER_SEC;
        flush_list();
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
    clean_list();
}

int main() {
    //simulate_test(1);
    //enqueue_to_empty_list();
    //enqueue_multiple_elements_to_list();
    //dequeue_from_empty_list();
    //dequeue_element_from_list();
    //get_list_size_test();
    //generate_random_priority_test();
    //get_time_to_enqueue();
    //get_time_to_dequeue()
    get_time_of_simulation();
    //populate_list();
}