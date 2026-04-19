#ifndef SDA_ATM_ORDEREDSET_H
#define SDA_ATM_ORDEREDSET_H
#include "OrderedSet.tpp"
#pragma once

template <typename E>
class OrderedSet {
private:
    E* elems;
    int size;
    int capacity;
    bool (*comparator)(E,E);
    void resize();
public:
    OrderedSet(bool (*comp)(E,E));
    OrderedSet(const OrderedSet& source);
    void add(E elem);
    int search_position(E elem);
    bool ifExist(E elem);
    int noElems();
    E getAt(int position);
    int remove(E elem);
    ~OrderedSet();
};

#endif //SDA_ATM_ORDEREDSET_H