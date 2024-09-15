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

void heapify(vector<int> &v, int n, int index)
{
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;

    if (left < n && v[left] > v[largest])
    {
        largest = left;
    }
    if (right < n && v[right] > v[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(v[largest], v[index]);
        heapify(v, n, largest);
        
    }
    return;
}
int main()
{
    vector<int> v = {-1, 10, 1, 90, 22, 55, 0, 32};
    int n = v.size();
    for (int i = n/2; i >0; i--)
    {
        heapify(v, n, i);
    }

    for (int i = 1; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}