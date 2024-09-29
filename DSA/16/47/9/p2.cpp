//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// ggek training memoization approach 
class Solution {
private:
    int f(vector<vector<int>>& dp,vector<vector<int>>& arr, int day,int pickp ){
        int maxi = 0;
        if(day==0){
            for(int i = 0 ; i<3 ; i++){
                if(i!=pickp){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            return maxi;
            
        }
        maxi = 0 ; 
        if(dp[day][pickp] != -1 ){return dp[day][pickp];}
        for(int i = 0 ; i<3 ; i++){
            if(i != pickp ){
                int points = arr[day][i] + f(dp,arr,day-1,i);
                maxi = max(maxi , points);
                
            }
        }
        return dp[day][pickp] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(4, -1));
        return f(dp,arr,n-1,3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends