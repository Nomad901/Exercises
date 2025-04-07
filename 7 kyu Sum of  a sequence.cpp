#include <iostream>
#include<vector>

int sequenceSum(int start, int end, int step)
{
    if (start > end) return 0;
    if (start == end) return start;
    int result = 0;

    for (int i = start; i <= end; i += step)
    {
        result += i;
    }


    return result;
}


int main()
{
  

    return 0;
}