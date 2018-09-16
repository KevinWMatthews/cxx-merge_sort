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
        auto mid_index = (tmp.size()-1) / 2;    // size is 1-based, index is 0-based
        auto mid = lo + mid_index;
        auto hi = mid + 1;
        auto end = tmp.cend();

        for (auto& it : data_)
        {
            // if (lo > mid)
            // {
            //     it = *hi;
            //     ++hi;
            // }
            if (hi == end)
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
