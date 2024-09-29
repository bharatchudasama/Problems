//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// basic reccursion solution for geek training 
// expect to have a TLE  
class Solution {
private:
    int f(vector<vector<int>>& arr, int day,int pickp ){
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
        for(int i = 0 ; i<3 ; i++){
            if(i != pickp ){
                int points = arr[day][i] + f(arr,day-1,i);
                maxi = max(maxi , points);
            }
        }
        return maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        return f(arr,n-1,3);
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