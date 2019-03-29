#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<float.h>
#include<time.h>
#include<sys/time.h>
#include "heapEventDriven.h"

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

void enqueue_to_empty_heap() {
    init();
    printHeap();
    enqueue(generate_psuedo_random());
    printHeap();
}

void enqueue_multiple_elements_to_heap() {
    init(); printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
}

void dequeue_from_empty_heap() {
    init();
    printHeap();
    dequeue();
    printHeap();
}

void dequeue_from_heap() {
    init(); printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    enqueue(generate_psuedo_random());     printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
    dequeue();  printHeap();
}

void get_heap_size_test() {
    enqueue(generate_psuedo_random());
    enqueue(generate_psuedo_random());
    enqueue(generate_psuedo_random());
    printHeap();
    printf("Expected 3 elements - result %d elements", getHeapSize());
}

void generate_random_priority_test() {
    int i;
    int sum = 0;
    int num_of_elements = 1000000;
    int randInt;

    for (i=0; i < num_of_elements; i++) {
        randInt = generate_psuedo_random();
        sum += randInt;
        printf("%d ", randInt);
    }
    double actualAverage = (double) sum / num_of_elements;
    printf("\nExpected %lf - result %lf", 500000000.0, actualAverage);
}

void populate_heap() {
    int i;
    double randPriority;
    srand(POPULATION_SEED);
    int number_of_iterations = 100000;
    for (i=0; i< number_of_iterations; i++) {
        randPriority = generate_psuedo_random();
        enqueue(randPriority);
        //printf("%d", randPriority);
    }
    //printList();
}

void get_time_to_enqueue() {
    populate_heap();
    printf("List size: %d\n", getHeapSize());
    clock_t start, end;
    double sum = 0;
    double mean = 0;
    int i;

    for(i=0; i<100; i++){
        srand48(seeds[i]);
        double rand = generate_psuedo_random();

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
    double sum = 0;
    double mean = 0;
    int i;

    for(i=0; i<100; i++){
        start = clock();
        dequeue();
        end = clock();
        sum += (end - start) / (double) CLOCKS_PER_SEC;
        printf("sum: %lf\n", sum);

        srand48(seeds[i]);
        double rand = generate_psuedo_random();
        enqueue(rand);
    }
    mean = sum / 100;
    printf("\n\n%lf\n", mean);
}

void simulate_test(long seed){
    init();
    int number_of_enqueued_elements = 3;
    int max_number_of_elements = 1000;
    srand48(seed);

    double initial_event = generate_psuedo_random();
    enqueue(initial_event);

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
    long seed;

    for(i=0; i<100; i++){
        seed = seeds[i];
        start = clock();
        simulate_test(seed);
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