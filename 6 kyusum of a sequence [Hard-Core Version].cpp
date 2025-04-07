#include <iostream>
#include<vector>

long long int sequence_sum(long long int begin_number, long long int end_number, long long step) {
    if (begin_number > end_number && end_number > 0) return 0;
    if (begin_number == end_number) return begin_number;

    long long int result = 0;

    if (end_number > 0)
    {
        for (long long int i = begin_number; i <= end_number; i += step) result += i;
        return result;
    }

    else
    {
        for (long long int i = begin_number; i >= end_number; i += step) result -= i;
        long long int temp = result;
        for (long long int i = 0; i < 2; ++i) result -= temp;
        return result;
    }
}




int main()
{
  

    return 0;
}