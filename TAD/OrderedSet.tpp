#pragma once
#include "OrderedSet.h"

//resize()

template<typename E>
void OrderedSet<E>::resize() {
    capacity *= 2;
    E *newElems = new E[capacity];
    for (int i = 0; i < size; i++)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

//constructor

template<typename E>
OrderedSet<E>::OrderedSet(bool(*comp)(E, E)) {
    capacity = 10;
    size = 0;
    elems = new E[capacity];
    comparator = comp;
}

//copy constructor

template<typename E>
OrderedSet<E>::OrderedSet(const OrderedSet &source) {
    capacity = source.capacity;
    size = source.size;
    comparator = source.comparator;
    elems = new E[capacity];
    for (int i = 0; i < size; i++)
        elems[i] = source.elems[i];
}

//search_position_for_elem (insertion position)

template<typename E>
int OrderedSet<E>::search_position(E elem) {
    int i = 0;
    while (i < size && comparator(elems[i], elem)) //searching in an ordered set means comparing the value of each element starting from the beginning, until the sign between the current one and elem is >, meaning elem should be put on position i
        i++;
    return i;
}

//ifExist

template<typename E>
bool OrderedSet<E>::ifExist(E elem) {
    int position = search_position(elem);
    return (position < size && elems[position] == elem);
}

//add

template<typename E>
void OrderedSet<E>::add(E elem) {
    if (ifExist(elem)) return;
    if (size == capacity) resize();
    int position = search_position(elem);
    for (int i = size; i > position; i--)
        elems[i] = elems[i-1];
    elems[position] = elem;
    size++;
}

//noElems

template<typename E>
int OrderedSet<E>::noElems() {
    return size;
}

template<typename E>
E OrderedSet<E>::getAt(int position) {
    return elems[position];
}

template<typename E>
int OrderedSet<E>::remove(E elem) {
    int position = search_position(elem);
    if (position >= size || elems[position] != elem)
        return 0;
    for (int i = position; i < size-1; ++i)
        elems[i] = elems[i+1];
    size--;
    return 1;
}

template<typename E>
OrderedSet<E>::~OrderedSet() {
    delete[] elems;
}
