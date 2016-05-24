//
// Created by nikita on 24.05.16.
//

#include <vector>
template < typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
    if (arr.empty())
    {
        return false;
    }
    const T * elemPtr = &arr[0];
    for (auto const& elem : arr)
    {
        if (less(*elemPtr, elem))
        {
            elemPtr = &elem;
        }
    }
    maxValue = *elemPtr;
    return true;
};