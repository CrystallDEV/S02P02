//
// Created by Marek on 11.05.2018.
//

#include "Entry.h"

Entry::Entry(string *pString, float d) {
    this->value = pString;
    this->priority = d;
    this->next_entry = NULL;
}

Entry::Entry(string *s, float d, Entry *next) {
    this->value = s;
    this->priority = d;
    this->next_entry = next;
}