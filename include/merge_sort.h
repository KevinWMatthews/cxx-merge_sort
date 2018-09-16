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
        // Start and end iterators for current merge.
        auto s_begin = source.begin() + begin_index;
        auto s_end = source.begin() + end_index + 1;   // end() iterators traditionally point off the end of the array
        auto t_begin = tmp.begin() + begin_index;
        auto t_end = tmp.begin() + end_index  + 1;

        std::copy(s_begin, s_end, t_begin);

        // Iterators for two halves of the temporary array
        auto t_lower = t_begin;
        auto t_mid = tmp.begin() + mid_index;
        auto t_upper = tmp.begin() + mid_index + 1;

        for(auto it = s_begin; it < s_end; ++it)
        {
            if (t_lower > t_mid)
            {
                *it = *t_upper;
                ++t_upper;
            }
            else if (t_upper == t_end)
            {
                *it = *t_lower;
                ++t_lower;
            }
            else if (*t_upper < *t_lower)
            {
                *it = *t_upper;
                ++t_upper;
            }
            else
            {
                *it = *t_lower;
                ++t_lower;
            }
        }
    };
};

#endif
