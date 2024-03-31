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


    void append(T& x)
    {
        int final_index = _actual_size;
        if (_actual_size >= _max_capacity)
            final_index = _actual_size % _max_capacity;

        data[final_index] = x;
        _actual_size++;
    }

    void append(T&& x)
    {
        int final_index = _actual_size;
        if (_actual_size >= _max_capacity)
            final_index = _actual_size % _max_capacity;

        data[final_index] = x;
        _actual_size++;
    }
    
    void Insert(int index, T& x)
    {
        for (int i = _actual_size; i > index; i--)
            data[i] = data[i - 1];
            
        data[index] = x;
        _actual_size++;
    }

    void Insert(int index, T&& x)
    {
        for (int i = _actual_size; i > index; i--)
            data[i] = data[i - 1];

        data[index] = x;
        _actual_size++;
    }

    void Delete(int index)
    {
        for (int i = index; i < _actual_size; i++)
            data[i] = data[i + 1];

        _actual_size--;
    }

    size_t getSize() { return _actual_size;}

    size_t getCapacity() { return _max_capacity; }
    
    ostream operator << (ostream& s)
    {
        for (int i = 0; i < _actual_size; i++)
            s << data[i];

        return s;
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
