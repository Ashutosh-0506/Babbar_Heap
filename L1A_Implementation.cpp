//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;

class Heap
{
    public:
    int n;
    vector<int> v;
    int size;
    Heap(int val)
    {
        n = val;
        v.resize(n + 1);
        size = 0;
    }
    void insert(int val)
    {
        // Step 1: Add the number to the end of the vector and increase the size
        size++;
        int index = size;

        v[index] = val;

        // Step 2: Find the correct position for the value
        while (index > 1)
        {
            int parentIndex = index / 2;

            if (v[parentIndex] < v[index])
            {
                swap(v[parentIndex], v[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }


    void deleteRoot()
    {

        //Step 0: Check
        if(size==0)
        {
            cout<<"Nothing to Delete"<<endl;
            return;
        }

        //Step 1: Replace the Root with the last element
        v[1]=v[size];

        //Step 2: Reduce the size
        size--;

        //Step 3: Find the correct position for the new root replacement

        int index=1;
        while(index<size)
        {
            int leftIndex=2*index;
            int rightIndex=2*index+1;

            if(leftIndex<size && v[leftIndex]>v[index])
            {
                swap(v[leftIndex],v[index]);
                index=leftIndex;
            }
            else if(rightIndex<size && v[rightIndex]>v[index])
            {
                swap(v[rightIndex],v[index]);
                index=rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap pq(20); 
    pq.insert(50);
    pq.insert(55);
    pq.insert(53);
    pq.insert(52);
    pq.insert(54);
    pq.print();
    pq.deleteRoot();
    pq.print();
    pq.deleteRoot();
    pq.print();
    return 0;
}