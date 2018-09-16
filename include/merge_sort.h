#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <array>

// Sort an array using a naive merge sort algorithm.
template<class T>
class MergeSort
{
public:
    MergeSort(T& data) : data_{data} {};
    // Need to define this in the header file unless we implement inheritance
    void sort() {
        if ( !data_.size() )
            return;

        T tmp = {data_};
        if (tmp[1] < tmp[0])
        {
            data_[0] = tmp[1];
            data_[1] = tmp[0];
        }
    };
private:
    T& data_;
};

#endif
