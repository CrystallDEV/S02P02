//
// Created by Marek on 11.05.2018.
//

#ifndef S02P02_PRIORITYQUEUE_H
#define S02P02_PRIORITYQUEUE_H

#include "Queue.h"
#include "Entry.h"

using namespace std;

class PriorityQueue {
/**
 * Logs an error
 * @param message
 */
private:
    void logError(string *message);


/**
 * inserts a new element into the queue
 * @param pq
 * @param value
 * @param p
 */
public:
    void pqueue_insert(Queue *pq, string *value, float p);

/**
 * returns the element value with the highest priority
 * @param pq
 * @return
 */
public:
    string *pqueue_extractMin(Queue *pq);

/**
 * changes the priority of an element within the queue
 * @param pq
 * @param value
 * @param p
 */
public:
    void pqueue_decreaseKey(Queue *pq, string *value, float p);

/**
 * removes an element of the queue by the given value
 * @param pq
 * @param value
 */
public:
    void pqueue_remove(Queue *pq, string *value);

/**
 * destroy's the queue
 * @param pq
 */
public:
    void pqueue_destroy(Queue *pq);

/**
 * Returns if a queue is empty
 * @return
 */
public:
    bool isEmpty(Queue *q);
};

#endif //S02P02_PRIORITYQUEUE_H
