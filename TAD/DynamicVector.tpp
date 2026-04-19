#include <exception>

#include "DynamicVector.h"

template<typename T>
void DynamicVector<T>::resize() {
    this->capacity *= 2;
    T* newElems = new T[this->capacity];

    // Copiem elementele vechi in noua "casa"
    for (int i = 0; i < this->size; i++) {
        newElems[i] = this->elems[i];
    }

    // Stergem casa veche ca sa nu avem memory leaks!
    delete[] this->elems;

    // Actualizam pointerul
    this->elems = newElems;
}

template<typename T>
DynamicVector<T>::DynamicVector() {
    this->capacity = 10;
    this->size = 0;
    this->elems = new T[this->capacity];
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elems;
}

template<typename T>
void DynamicVector<T>::push_back(T elem) {
    // Verificam daca dulapul e plin
    if (this->size == this->capacity) {
        this->resize();
    }
    // Adaugam pe prima pozitie libera, apoi crestem size-ul
    this->elems[this->size++] = elem;
}

template<typename T>
void DynamicVector<T>::erase(int index) {
    if (index < 0 || index >= this->size) {
        throw std::exception(); // Index invalid
    }

    // Mutam toti vecinii din dreapta cu o pozitie la stanga
    for (int i = index; i < this->size - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }

    this->size--; // Am sters un element, deci scadem dimensiunea
}

template<typename T>
int DynamicVector<T>::getSize() const {
    return this->size;
}

//Supraincarcarea operatorului [] (Pentru accesare usoara gen vector[i])
template<typename T>
T& DynamicVector<T>::operator[](int index) {
    // Returnam elementul prin referinta ca sa poata fi si modificat!
    return this->elems[index];
}