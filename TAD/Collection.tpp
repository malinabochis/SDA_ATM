#pragma once //parte de linking pt IDE pt proiect, versiunile noi functioneaza fara el
#include <exception>

#include "Collection.h"

// here is the representation

// costructor

template<typename E>
Collection<E>::Collection() {
    capacity = 10;
    length = 0;
    elems = new Pair<E>[capacity];
}


// copy constructor => cand vreau sa transmit ca parametru o colectie

template<typename E>
Collection<E>::Collection(const Collection &source) {
    capacity = source.capacity;
    length = source.length;
    elems = new Pair<E>[capacity];
    for (int i = 0; i < length; i++)
        elems[i] = source.elems[i];
}


// "=" operator
template<typename E>
Collection<E>& Collection<E>::operator=(const Collection &source) {
    if (this == &source) // this este adresa lui Collection<E>::operator=
        return *this;

    delete[] this->elems;

    this->length = source.size();
    this->capacity = source.capacity;

    this->elems = new E[this->capacity];
    for (int i = 0; i < length; i++)
        this->elems[i] = source.elems[i];

    return *this;
}


// add

template <typename E>
void Collection<E>::add(E elem) {
    for (int i = 0; i < length; i++)
        if (elems[i].elem == elem) { //elems[i].elem este obiectul Pair de pe pozitia i, care in structura sa are variabila numita elems
            ++elems[i].freq; //elems[i].elem este obiectul Pair de pe pozitia i, care in structura sa are variabila numita freq
            return;
        }
    if (length == capacity)
        resize();
    elems[length].elem = elem;
    elems[length].freq = 1;
    ++length;
}

// elems = pointer catre inceputul array-ului
// elems[i] = acceseaza obiectul pair de la pozitia i
// .elems = deschide si acceseaza variabila numita elem care este de tipul E


// remove

template <typename E>
bool Collection<E>::remove(E elem) {
    for (int i = 0; i < length; i++) {
        if (elems[i].elem == elem) {
            --elems[i].freq;
            if (elems[i].freq == 0) {
                elems[i] = elems[length - 1]; // mut ultimul element in locul acum gol pentru eficienta, in loc sa ii pun pe toti sa se mute cu un rand la stanga (intr-o colectie nu conteaza ordinea elementelor)
                --length;
            }
            return true;
        }
    }
    return false;
}


// search

template <typename E>
bool Collection<E>::search(E elem) const {
    for (int i = 0; i < length; i++)
        if (elems[i].elem == elem)
            return true;
    return false;
}


//noOccurrences

template<typename E>
int Collection<E>::noOccurrences(E elem) const {
    for (int i = 0; i < length; i++)
        if (elems[i].elem == elem)
            return elems[i].freq;
    return 0;
}


// size

template<typename E>
int Collection<E>::size() const {
    int total = 0;
    for (int i = 0; i < length; i++)
        total += elems[i].freq;
    return total;
}


// getAt

template <typename E>
E Collection<E>::getAt(const int position) const {
    if (position < 0 || position >= size())
        throw std::exception();

    int count = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < elems[i].freq; j++) {
            if (count == position)
                return elems[i].elem;
            count++;
        }
    }

    throw std::exception();
}


// resize

template <typename E>
void Collection<E>::resize() {
    capacity *= 2;
    Pair<E>* newElems = new Pair<E>[capacity];
    for (int i = 0; i < length; i++)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

// destructor
template <typename E>
Collection<E>::~Collection() {
    delete[] elems;
}