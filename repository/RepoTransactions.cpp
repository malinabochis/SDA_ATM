#include "RepoTransactions.h"


// constructor

RepoTransactions::RepoTransactions() {
    capacity = 10;
    size = 0;
    transaction = new Transaction[capacity];
}


// resize

void RepoTransactions::resize() {
    capacity *= 2;
    Transaction* newArr = new Transaction[capacity];
    for (int i = 0; i < size; i++)
        newArr[i] = transaction[i]; // copy
    delete[] transaction;
    transaction = newArr;
}


// add

void RepoTransactions::add(const Transaction &t) {
    if (size == capacity)
        resize();
    transaction[size++] = t; // "=" operator
}


// size

int RepoTransactions::getSize() const {
    return size;
}


// get

Transaction RepoTransactions::get(int index) const {
    return transaction[index];
}


// destructor
RepoTransactions::~RepoTransactions() {
    delete[] transaction;
}