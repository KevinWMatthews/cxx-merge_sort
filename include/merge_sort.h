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
        auto lo = tmp.cbegin();
        auto end = tmp.cend();
        auto mid_index = (std::distance(lo, end)-1) / 2;
        auto mid = lo + mid_index;
        auto hi = mid + 1;

        for (auto& it : data_)
        {
            if (lo > mid)
            {
                it = *hi;
                ++hi;
            }
            else if (hi == end)
            {
                it = *lo;
                ++lo;
            }
            else if (*hi < *lo)
            {
                it = *hi;
                ++hi;
            }
            else
            {
                it = *lo;
                ++lo;
            }
        }
    };
private:
    T& data_;
};

#endif
