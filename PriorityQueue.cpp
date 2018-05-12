//
// Created by Marek on 11.05.2018.
//
#include <iostream>
#include "PriorityQueue.h"

using namespace std;


void logError(string *message) {
    cout << "ERROR: " << message << endl;
}


void PriorityQueue::pqueue_insert(Queue *pq, string *value, float p) {
    Entry *newEntry = new Entry(value, p);

    if (pq->entries == 0) {
        pq->first = newEntry;
        pq->last = newEntry;
        pq->entries = 1;
        return;
    }

    if (newEntry->priority >= pq->last->priority) {
        Entry *lastEntry = pq->last;
        lastEntry->next_entry = newEntry;
        pq->last = newEntry;
    } else if (newEntry->priority <= pq->first->priority) {
        Entry *firstStoredEvent = pq->first;
        pq->first = newEntry;
        newEntry->next_entry = firstStoredEvent;
    } else {
        Entry *currentEvent = pq->first;
        while (currentEvent->next_entry != NULL) {
            if (newEntry->priority <= currentEvent->next_entry->priority) {
                if (newEntry->priority >= currentEvent->priority) {
                    Entry *next = currentEvent->next_entry;
                    currentEvent->next_entry = newEntry;
                    newEntry->next_entry = next;
                    break;
                }
            }
            currentEvent = currentEvent->next_entry;
        }
    }
    pq->entries++;
}

string *PriorityQueue::pqueue_extractMin(Queue *pq) {
    if (pq->entries == 0) {
//        this->logError((string *) "No entries found.\n");
        return NULL;
    }
    Entry *currentEntry = pq->first;
    pq->first = currentEntry->next_entry;
    string *val = currentEntry->value;

    if (pq->entries == 1) {
        pq->first = NULL;
        pq->last = NULL;
    }
    //Debugging values
    float priority = currentEntry->priority;
    cout << "Value: " << val << " Priority: " << priority << endl;
    pqueue_remove(pq, val);
    return val;
}

void PriorityQueue::pqueue_decreaseKey(Queue *pq, string *value, float p) {
    //TODO improve? -> dont delete, change value and pointer in queue
    pqueue_remove(pq, value);
    pqueue_insert(pq, value, p);
}

void PriorityQueue::pqueue_remove(Queue *pq, string *value) {
    Entry *currentEntry = pq->first;
    Entry *previousEntry = NULL;
    if (currentEntry == NULL) {
        return;
    }

    while (currentEntry->next_entry != NULL) {
        if (currentEntry->value == value) {
            if (previousEntry == NULL) {
                pq->first = currentEntry->next_entry;
                free(currentEntry);
                break;
            }
            previousEntry->next_entry = currentEntry->next_entry;
            free(currentEntry);
            break;
        }
        previousEntry = currentEntry;
        currentEntry = currentEntry->next_entry;
    }
    pq->entries--;
}

void PriorityQueue::pqueue_destroy(Queue *pq) {
    if (pq) {
        if (pq->first) { //free all elements
            Entry *current = pq->first;
            while (current->next_entry) {
                Entry *element = current;
                current = current->next_entry;
                free(element);
            }
        }
//            pq = NULL; //TODO check if needed
        free(pq);
    }
}

bool PriorityQueue::isEmpty(Queue *pQueue) {
    return pQueue->entries > 0;
}