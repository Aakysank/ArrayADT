// ArrayADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T, size_t _capacity>
class SuperArray
{
    T data[_capacity];

    size_t _max_capacity = _capacity;
    size_t _actual_size = 0;
public:

    SuperArray()
    {
        for (int i = 0; i < _max_capacity; i++)
            data[i] = 0;
    }

    ~SuperArray()
    {

    }

    //Time complexity - O(1).
    void append(T& x)
    {
        int final_index = _actual_size; //Time taken 1 unit
        if (_actual_size >= _max_capacity)//Time taken 1 unit
            final_index = _actual_size % _max_capacity;//Time taken 1 unit

        data[final_index] = x;//Time taken 1 unit
        _actual_size++;//Time taken 1 unit
    }

    //Time complexity - O(1).
    void append(T&& x)
    {
        int final_index = _actual_size;//Time taken 1 unit
        if (_actual_size >= _max_capacity)//Time taken 1 unit
            final_index = _actual_size % _max_capacity;//Time taken 1 unit

        data[final_index] = x;//Time taken 1 unit
        _actual_size++;//Time taken 1 unit
    }
    
    //Time complexity
    // Best case - O(1). Worst case - O(n)
    void Insert(int index, T& x)
    {
        for (int i = _actual_size; i > index; i--)//Time taken n+1 units
            data[i] = data[i - 1];
            
        data[index] = x;//Time taken 1 unit
        _actual_size++;//Time taken 1 unit
    }

    //Time complexity
    // Best case - O(1). Worst case - O(n)
    void Insert(int index, T&& x)
    {
        for (int i = _actual_size; i > index; i--)//Time taken n+1 units
            data[i] = data[i - 1];

        data[index] = x;//Time taken 1 unit
        _actual_size++;//Time taken 1 unit
    }

    void Delete(int index)
    {
        for (int i = index; i < _actual_size; i++)//Time taken n+1 units
            data[i] = data[i + 1];

        _actual_size--;//Time taken 1 unit
    }

    size_t getSize() { return _actual_size;}

    size_t getCapacity() { return _max_capacity; }
    
    ostream operator << (ostream& s)
    {
        for (int i = 0; i < _actual_size; i++)
            s << data[i];

        return s;
    }

    int search(T &value)
    {
        //Linear search
        //Time complexity - Best case O(1)
        //Worst case - O(n)
        for (int i = 0; i < _actual_size; i++)
        {
            if (data[i] == value)
                return i;
        }

        //Improving linear search
        //1. Transposition -- move the found element swap to previous index. Step by step time reduction
        //2. Move to front -- move the found element and swap to the start of the array. Drastic reduction in time
       //Transposition
        /*for (int i = 0; i < _actual_size; i++)
        {
            if (data[i] == value)
            {
                if (i != 0)
                {
                    T temp = data[i - 1];
                    data[i - 1] = data[i];
                    data[i] = temp;

                    return i-1;
                }
                else
                    return 0;
            }
        }*/

        //Move to front
        /*for (int i = 0; i < _actual_size; i++)
        {
            if (data[i] == value)
            {
                T temp = data0];
                data[0] = data[i];
                data[i] = temp;

                return 0;
            }
        }*/

        return -1;
    }

    int search(T&& value)
    {
        //Linear search
       //Time complexity - Best case O(1)
       //Worst case - O(n)
        for (int i = 0; i < _actual_size; i++)
        {
            if (data[i] == value)
                return i;
        }

        return -1;
    }
};
int main()
{
    SuperArray<int,5> arr;

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
