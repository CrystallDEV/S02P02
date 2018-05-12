//
// Created by Marek on 11.05.2018.
//
#ifndef S02P02_QUEUE_H
#define S02P02_QUEUE_H

#include "Entry.h"

class Queue {
public:
    Entry *first;
    Entry *last;
    int entries;

    Queue(Entry *first, Entry *last, int entries);

    Queue();
};

#endif //S02P02_QUEUE_H