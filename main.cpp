#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

int globalsum = 0;
void arrSum(const int* array, int position, int count);

void func()
{
    for (int i = 0; i < 1000; i++)
    {
        std::cout << i << std::endl;
    }
}
int main()
{   
    
    const int size = 20;
    int arr[size] = {5, 3, 2, 4, 8, 9, 6, 1, 1, 7, 9, 3, 8, 2, 6, 3, 5, 5, 4, 7};    
    
    std::vector<std::thread> thrd;
    if (size % 4 == 0)
    {
        int step = size / 4;        
        for (int i = 0; i < size; i += step)
        {
            thrd.push_back(std::thread(arrSum, arr, i, step));
        }
    }
    
   std::for_each(thrd.begin(), thrd.end(), [] (std::thread &t)
         { t.join(); });

    std::cout << globalsum << std::endl;
    return 0;
}

void arrSum(const int *array, int position, int count)
{
    int sum = 0;
    for (int i = position; i < position + count; i++)
    {
        sum += array[i];
    }
    globalsum += sum;
}