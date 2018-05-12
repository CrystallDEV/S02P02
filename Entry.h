//
// Created by Marek on 11.05.2018.
//

#ifndef S02P02_ENTRY_H
#define S02P02_ENTRY_H

#include <cstdlib>
#include <string>

using namespace std;

class Entry {
public:
    float priority;
    string *value;
    Entry *next_entry;

    Entry(string *s, float d, Entry *next);

    Entry(string *s, float d);

};


#endif //S02P02_ENTRY_H
