#ifndef SINGLE_SHCEDULING_H
#define SINGLE_SHCEDULING_H

#include <stdio.h>
#include <stdlib.h>

void enqueue(int x);

int dequeue();

int getListSize();

void generateEvent();

int genrateRandomPriority();

void printList();

#endif