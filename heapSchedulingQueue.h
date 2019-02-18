#ifndef HEAP_SCHEDULING_H
#define HEAP_SCHEDULING_H

#include <stdio.h>
#include <stdlib.h>

struct Element{
    int label;
    int priority;
};

void init();

void enqueue(int epriority);

struct Element dequeue();

void generateEvent();

void printHeap();

int getHeapSize();

int genrateRandomPriority();

#endif