#include <iostream>
#include <ctime>
#include "PriorityQueue.h"

using namespace std;

#define MAX 20000

void testQueue() {
    Queue *queue = new Queue();
    PriorityQueue *manager = new PriorityQueue();
    manager->pqueue_insert(queue, (string *) "test0", 1);
    manager->pqueue_insert(queue, (string *) "test1", 2);
    manager->pqueue_insert(queue, (string *) "test2", 3);
    manager->pqueue_insert(queue, (string *) "test3", 4);
    manager->pqueue_insert(queue, (string *) "test4", 5);

    while (!manager->isEmpty(queue)) {
        cout << manager->pqueue_extractMin(queue) << endl;
    }

    cout << "Finished test1" << endl;

    manager->pqueue_insert(queue, (string *) "test0", 1);
    manager->pqueue_insert(queue, (string *) "test1", 2);
    manager->pqueue_insert(queue, (string *) "test2", 3);
    manager->pqueue_insert(queue, (string *) "test3", 4);
    manager->pqueue_insert(queue, (string *) "test4", 5);
    manager->pqueue_decreaseKey(queue, (string *) "test2", 6);

    while (!manager->isEmpty(queue)) {
        cout << manager->pqueue_extractMin(queue) << endl;
    }
    cout << "Finished test2" << endl;

    manager->pqueue_destroy(queue);

    cout << "Finished test3" << endl;

}


char *randomString(int size) {
    int i;
    char *str = (char *) malloc((size + 1) * sizeof(char));
    for (i = 0; i < size; ++i) {
        str[i] = (rand() % 26) + 'A';
    }
    str[size] = '\0';
    return str;
}


void testMain() {
    try {
        PriorityQueue *manager = new PriorityQueue();
        int i;
        char *strings[MAX];
        clock_t tic, toc;

        srand(time(NULL));

        for (i = 0; i < MAX; ++i) {
            strings[i] = randomString(8);
        }

        Queue *pq = new Queue();

        tic = clock();
        for (i = 0; i < MAX; ++i) {
            manager->pqueue_insert(pq, reinterpret_cast<string *>(strings[i]), rand() % 100);
        }
        toc = clock();

        cout << " insertion time : " << (float) (toc - tic) / CLOCKS_PER_SEC << " seconds " << endl;

        tic = clock();
        for (i = 0; i < MAX; ++i) {
            manager->pqueue_extractMin(pq);
        }
        toc = clock();

        cout << " extract time : " << (float) (toc - tic) / CLOCKS_PER_SEC << " seconds" << endl;

        for (i = 0; i < MAX; ++i) {
            free(strings[i]);
        }
        manager->pqueue_destroy(pq);
    } catch (exception e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main(int argc, char **argv) {
    testQueue();
//    testMain();
    return 0;
}