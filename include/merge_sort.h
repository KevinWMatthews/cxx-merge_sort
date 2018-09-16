#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <array>
#include <algorithm>

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

        // Boundary conditions
        auto begin = tmp.cbegin();
        auto end = tmp.cend();
        auto mid_index = (std::distance(begin, end)-1) / 2;
        auto mid = begin + mid_index;

        // Iterators for two halves of array
        auto lower = begin;
        auto upper = mid + 1;

        for (auto& it : data_)
        {
            if (lower > mid)
            {
                it = *upper;
                ++upper;
            }
            else if (upper == end)
            {
                it = *lower;
                ++lower;
            }
            else if (*upper < *lower)
            {
                it = *upper;
                ++upper;
            }
            else
            {
                it = *lower;
                ++lower;
            }
        }
    };
private:
    T& data_;
};

#endif
