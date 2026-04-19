#pragma once
namespace Algorithms {

    template<typename E>
    void BubbleSort(E* arr, const int size, bool (*comp)(E,E)) {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (comp(arr[j], arr[j+1]))
                    arr[j], arr[j+1] = arr[j+1], arr[j];
    }

    // template<typename E>
    // int BinarySearch(E* arr, const int size, E elem, bool (*comp)(E,E)) {
    //     int st = 0, dr = size - 1;
    //     while (st <= dr) {
    //         int mid = (st + dr) / 2;
    //         if (arr[mid] == elem) return mid;
    //         if (comp(arr[mid], elem))
    //             st = mid + 1;
    //         else
    //             dr = mid - 1;
    //     }
    //     return -1;
    // }

}
