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
using namespace std;

void heapify(vector<int> &v, int n, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && v[largest] < v[left])
    {
        largest = left;
    }

    if (right <= n && v[largest] < v[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(v[largest], v[index]);
        heapify(v, n, largest);
    }
}

void HeapSort(vector<int>& v)
{
    int n = v.size()-1;  // 1-based index, so ignore v[0]

    // Step 1: Build a max heap
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(v, n, i);
    }

    int size = n;

    // Step 2: Perform heap sort3.
    while (size > 1)
    {
        // Swap root and the last element
        swap(v[1], v[size]);

        // Decrement the size
        size--;

        // Place the root at its correct position
        heapify(v, size, 1);
    }
}

int main()
{
    vector<int> v = {-1, 4,5,3,1,2}; 
    int n = v.size();
    HeapSort(v);
    for (int i = 1; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
