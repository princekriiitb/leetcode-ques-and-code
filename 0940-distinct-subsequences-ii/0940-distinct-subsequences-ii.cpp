// class Solution {
// public:

// void solve(string str,string output,int index,int &ans,vector<string> &demo){
//      //base case
// 	 if(index>=str.length()){
        
		
//         for(int i=0;i<demo.size();i++){
//                  if(output==demo[i])
//                  {
//                  return;
//                  }
//         }
		
        
//         demo.push_back(output);
//         ans++;
// 		 return;
// 	 }

// 	 //exclude
// 	 solve(str,output,index+1,ans,demo);

// 	 //include
// 	 char element=str[index];

// 	 output.push_back(element);

// 	 solve(str,output,index+1,ans,demo);
	 
// }
//     int distinctSubseqII(string s) {
        
//     int ans=0;
// 	string output="";
// 	int index=0;
//     vector<string> demo;
// 	solve(s,output,index,ans,demo);

// 	return ans-1;
//     }
// };

#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        const int MOD = 1e9 + 7;
        std::vector<long long> dp(26, 0);

        for (char ch : s) {
            int idx = ch - 'a';
            
            // Sum of all distinct subsequences formed so far
            long long current_total = 0;
            for (int count : dp) {
                current_total = (current_total + count) % MOD;
            }
            
            // Subsequences ending in current char = (existing total) + (char itself)
            dp[idx] = (current_total + 1) % MOD;
        }

        // Sum up all subsequences ending in any character
        long long total_distinct = 0;
        for (int count : dp) {
            total_distinct = (total_distinct + count) % MOD;
        }

        return total_distinct;
    }
};