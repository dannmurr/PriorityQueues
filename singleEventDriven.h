#ifndef SINGLE_EVENT_H
#define SINGLE_EVENT_H

#include <stdio.h>
#include <stdlib.h>

void enqueue(double x);

double dequeue();

void generateEvent(double removedElementTimeStamp);

int getListSize();

double generate_psuedo_random();

void printList();

void flush_list();

#endif