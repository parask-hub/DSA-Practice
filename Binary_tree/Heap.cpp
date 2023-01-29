#include <iostream>
using namespace std;

// IMPLEMENTATION OF MAX HEAP

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int d)
    {
        size = size + 1;
        int index = size;
        arr[index] = d;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    // DELETION IS  ALWAYS OF ROOT NODE
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << " Deletion can not be done ! " << endl;
            return;
        }
        // 1. last node ko root node ki jagah daalo
        arr[1] = arr[size];
        // 2. last node ko hta do
        size--;
        // 3. nodes ko uski sahi jagah lagao
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size and arr[i] < arr[leftindex])
            {
                swap(arr[leftindex], arr[i]);
                i = leftindex;
            }
            else if (rightindex < size and arr[rightindex] > arr[i])
            {
                swap(arr[rightindex], arr[i]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.display();
}