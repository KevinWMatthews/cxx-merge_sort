#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <array>
#include <algorithm>
#include <iterator>

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
        actual_sort(data_, tmp, 0, data_.size()-1);
    };
private:
    T& data_;
    void actual_sort(T& source, T& tmp, size_t begin_index, size_t end_index) {
        if (begin_index == end_index)
            return;

        size_t mid_index = begin_index + (end_index - begin_index) / 2;
        actual_sort(source, tmp, begin_index, mid_index);
        actual_sort(source, tmp, mid_index+1, end_index);
        merge(source, tmp, begin_index, mid_index, end_index);
    };

    void merge(T& source, T& tmp, size_t begin_index, size_t mid_index, size_t end_index) {
        auto begin = tmp.cbegin() + begin_index;
        auto mid = begin + mid_index;
        auto end = begin + end_index + 1;   // end() iterators actually point off the end of the array

        // Iterators for two halves of array
        auto lower = begin;
        auto upper = mid + 1;

        for (auto& it : source)
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
};

#endif
