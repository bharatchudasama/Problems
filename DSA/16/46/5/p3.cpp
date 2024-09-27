#include <bits/stdc++.h>
using namespace std;

// space optimizated
// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev = 0,prev1= 0;
        for(int i = 1 ; i<n ;i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = prev1 + abs(height[i] - height[i-2]);
            }
            int curr = min(fs,ss);
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}