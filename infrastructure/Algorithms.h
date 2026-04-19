#ifndef SDA_ATM_BUBBLESORT_H
#define SDA_ATM_BUBBLESORT_H

namespace Algorithms {
    template<typename E>
    void BubbleSort(E* arr, int size, bool (*comp)(E,E));

    // template<typename E>
    // int BinarySearch(E* arr, int size, E elem, bool (*comp)(E,E));
}

#include "Algorithms.tpp"
#endif
