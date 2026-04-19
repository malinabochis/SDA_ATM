#ifndef SDA_ATM_ORDEREDSET_H
#define SDA_ATM_ORDEREDSET_H

#pragma once

template <typename E>
class OrderedSet {
private:
    E* elems;
    int size;
    int capacity;
    bool (*comparator)(const E&,const E&);
    void resize();
public:
    OrderedSet(bool (*comp)(const E&, const E&));
    OrderedSet(const OrderedSet& source);
    void add(E elem);
    int search_position(E elem);
    bool ifExist(E elem);
    [[nodiscard]] int noElems() const;
    E getAt(int position);
    int remove(E elem);
    ~OrderedSet();
};
#include "OrderedSet.tpp"
#endif //SDA_ATM_ORDEREDSET_H