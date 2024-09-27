// memoization
class Solution {
private:
    int f(int n , vector<int> &dp){
        if(n==0)return 1 ; 
        if(n==1)return 1;
        if(dp[n]!=-1){return dp[n];}
        int left = f(n-1,dp) ;//2
        int right = f(n-2,dp);//1
        return dp[n]=left + right ;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
//tabulation
int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
