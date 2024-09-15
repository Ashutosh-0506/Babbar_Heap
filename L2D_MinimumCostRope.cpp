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
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        for(auto it:arr)
        {
            pq.push(it);
        }
        long long total=0;
        while(pq.size()>1)
        {
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();

            long long cost=a+b;
            total+=cost;
            pq.push(cost);
        }
        return total;
        
    }
};

int main()
{
    return 0;
}