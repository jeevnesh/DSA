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
        // brute force
        
        //step 1: calculate and store the sum of each subarray in a vector
        vector<int> sumStore;
        for(int i = 0 ; i < N; i++)
        {
            int sum = 0;
            for(int j = i; j < N; j++)
            {
                sum += nums[j]; 
                sumStore.push_back(sum);
            }
        }
        
        //step 2: sort the vector in ascendinf order
        sort(sumStore.begin() , sumStore.end());
        
        //step 3: return the answer
        return sumStore[sumStore.size()-K];
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