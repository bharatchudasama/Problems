//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//memoization method 
// } Driver Code Ends
class Solution {
    private:
        int f(int n , int k ,vector<int>&arr ,vector<int>& dp){
            if(n==0){return 0 ; }
            if(dp[n]!=-1){return dp[n];}
            int mins=INT_MAX;
            for(int i = 1 ; i <= k ; i++){
                if(n-i>=0){
                    int jump = f(n-i,k,arr,dp)+ abs(arr[n]-arr[n-i]);
                    mins= min(jump,mins);
                }
            }
                return dp[n]=mins;
        }
    public:
        int minimizeCost(int k, vector<int>& arr) {
         
            int n = arr.size();
            vector<int> dp(n+1,-1);
            return f(n-1,k,arr,dp);
        }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends