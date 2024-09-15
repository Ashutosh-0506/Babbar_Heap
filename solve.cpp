#include <bits/stdc++.h>
using namespace std;

int getOutlierValue(vector<int> &arr) {
    int n=arr.size();
    unordered_map<int,int>mp;
    
    for(auto it:arr)
    {
        mp[it]++;
    }
    int total=accumulate(arr.begin(),arr.end(),0);

    sort(arr.begin(),arr.end());

    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        v[i]=total-arr[i];
    }
    

    int maxx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(v[i]%2==0 && mp.find(v[i]/2)!=mp.end())
        {
            maxx=max(maxx,arr[i]);
        }
    }
    return maxx;
}

int main() {
    vector<int> arr = {4,1,2,1,10,3};  // Example input
    cout << getOutlierValue(arr) << endl;  // Output: 1
    return 0;
}
