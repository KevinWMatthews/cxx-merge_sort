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
        if (data_.empty())
            return;
        if (data_.size() == 1)
            return;

        T tmp = {data_};
        if (tmp.at(1) < tmp.at(0))
        {
            data_.at(0) = tmp.at(1);
            data_.at(1) = tmp.at(0);
        }
    };
private:
    T& data_;
};

#endif
