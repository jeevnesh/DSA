//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    
    deque<long long int> dq;
    vector<long long> ans;
    //process first k size window
    for(int i = 0 ; i < k; i++)
    {
        if(a[i]<0)
        {
            dq.push_back(i);
        }
    }
    //store answer if any for first k element
    if(dq.size())
    {
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    //process remaining window
    for(int i = k ; i < n; i++)
    {
        //remove the element which is out of window
        if(!dq.empty() && i-dq.front() >= k)
        {
            dq.pop_front();
        }
        //add negative element index if any in current window
        if(a[i]<0)
        {
            dq.push_back(i);
        }
        //store answer if any for current window
        if(dq.size())
        {
            ans.push_back(a[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
 }