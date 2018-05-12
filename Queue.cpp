//
// Created by Marek on 11.05.2018.
//

#include "Queue.h"

Queue::Queue(Entry *first, Entry *last, int entries) {
    this->first = first;
    this->last = last;
    this->entries = entries;
}

Queue::Queue() {
    this->first = NULL;
    this->last = NULL;
    this->entries = 0;
};