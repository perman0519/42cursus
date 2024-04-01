#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750

// void    f()
// {
//     system("leaks a.out");
// }

int main(int, char**)
{
    // atexit(f);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//


    Array<float> test(20);
    float *f = new float[20];

    for (int i = 0; i < 20; i++)
    {
        const float value = static_cast<float>(rand());
        test[i] = value;
        f[i] = value;
    }
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << test[i] << " " << f[i] << std::endl;
    }
    std::cout << test.size() << std::endl;
    delete [] f;
    return 0;
}
