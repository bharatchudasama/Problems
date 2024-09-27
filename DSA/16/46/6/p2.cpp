//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//tabulation method 
// } Driver Code Ends
class Solution {

    public:
        int minimizeCost(int k, vector<int>& arr) {
            int n = arr.size();
            vector<int> dp(n,-1);
            dp[0] = 0;
    
        // Loop through the array to fill in the dp array
            for (int i = 1; i < n; i++) {
                int mmSteps = INT_MAX;
        
                // Loop to try all possible jumps from '1' to 'k'
                for (int j = 1; j <= k; j++) {
                    if (i - j >= 0) {
                        int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                        mmSteps = min(jump, mmSteps);
                    }
                }
                dp[i] = mmSteps;
            }
            return dp[n - 1]; // The result is stored in the last element of dp
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