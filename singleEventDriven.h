#ifndef SINGLE_EVENT_H
#define SINGLE_EVENT_H

#include <stdio.h>
#include <stdlib.h>

void enqueue(double x);

double dequeue();

void generateEvent(double removedElementTimeStamp);

int getListSize();

double increment_randomly();

void printList();

#endif