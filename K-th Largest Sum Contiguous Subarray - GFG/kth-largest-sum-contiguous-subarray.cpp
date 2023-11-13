//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<algorithm>
class Solution{
public:
    int kthLargest(vector<int> &nums,int N,int K){
        // minHeap approach
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i = 0 ; i < N; i++)
        {
            int sum = 0;
            for(int j = i; j < N; j++)
            {
                sum += nums[j]; 
                if(minHeap.size() < K)
                    minHeap.push(sum);
                else 
                {
                    if(sum > minHeap.top())
                    {
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
            }
        }
        
        // return the answer
        return minHeap.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends