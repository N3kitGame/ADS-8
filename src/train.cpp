// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    if (!first) {
        Cage* item = new Cage;
        item->light = light;
        first = item;
        last = item;
    }
    else {
        Cage* item = new Cage;
        item->light = light;
        last->next = item;
        item->prev = last;
        last = item;
    }
    last->next = first;
    first->prev = last;
}

int Train::getLength() {
    Cage* item = first;
    if (item->light == false) {
        item->light = true;
    }
    int rez = 0;
    int countitem = 0;
    while (true) {
        item = item->next;
        countitem += 1;
        countOp += 1;
        while (item->light == false) {
            item = item->next;
            countitem += 1;
            countOp += 1;
        }
        item->light = false;
        rez = countitem;
        while (countitem != 0) {
            item = item->prev;
            countitem -= 1;
            countOp += 1;    
        }
        if (item->light == false) {
            return rez;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}

