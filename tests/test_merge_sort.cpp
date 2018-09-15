#include "merge_sort.h"
#include "gtest/gtest.h"

#include <algorithm>

using namespace std;

TEST(TestMergeSort, DoNotFailWithEmptyArray)
{
    array<int, 0> data = {};
    MergeSort merge_sort = {data};
    ASSERT_TRUE( is_sorted(data.cbegin(), data.cend()) );
}
