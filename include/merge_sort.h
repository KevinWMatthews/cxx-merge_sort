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

    void sort() {
        if (data_.empty())
            return;
        if (data_.size() == 1)
            return;

        T tmp = {data_};
        actual_sort(tmp, 0, data_.size()-1);
    };
private:
    T& data_;

    void actual_sort(T& tmp, size_t begin_index, size_t end_index) {
        if (begin_index == end_index)
            return;

        size_t mid_index = begin_index + (end_index - begin_index) / 2;
        actual_sort(tmp, begin_index, mid_index);
        actual_sort(tmp, mid_index+1, end_index);
        merge(tmp, begin_index, mid_index, end_index);
    };

    void merge(T& tmp, size_t begin_index, size_t mid_index, size_t end_index) {
        // Start and end iterators for current merge.
        auto data_begin = data_.begin() + begin_index;
        auto data_end = data_.begin() + end_index + 1;     // end() iterators traditionally point off the end of the array
        auto tmp_begin = tmp.begin() + begin_index;
        auto tmp_end = tmp.begin() + end_index  + 1;

        // Copy the elements we're working with into the temporary array
        std::copy(data_begin, data_end, tmp_begin);

        // Iterators for two halves of the temporary array
        auto tmp_lower = tmp_begin;
        auto tmp_mid = tmp.begin() + mid_index;
        auto tmp_upper = tmp.begin() + mid_index + 1;

        for(auto it = data_begin; it < data_end; ++it)
        {
            if (tmp_lower > tmp_mid)
            {
                *it = *tmp_upper;
                ++tmp_upper;
            }
            else if (tmp_upper == tmp_end)
            {
                *it = *tmp_lower;
                ++tmp_lower;
            }
            else if (*tmp_upper < *tmp_lower)
            {
                *it = *tmp_upper;
                ++tmp_upper;
            }
            else
            {
                *it = *tmp_lower;
                ++tmp_lower;
            }
        }
    };
};

#endif
