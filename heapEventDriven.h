#ifndef HEAP_EVENT_H
#define HEAP_EVENT_H

#include <stdio.h>
#include <stdlib.h>

struct Element{
    int label;
    double priority;
};

void init();

void enqueue(int epriority);

struct Element dequeue();

void generateEvent();

double increment_randomly();

void printHeap();

int getHeapSize();

int genrateRandomPriority();

#endif