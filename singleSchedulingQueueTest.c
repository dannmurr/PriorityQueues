#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<sys/time.h>
#include "singleSchedulingQueue.h"

void simulate() {
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

int main() {
    simulate();
}
