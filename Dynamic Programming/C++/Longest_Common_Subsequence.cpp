/*
Problem name :- Longest Common Subsequence
Problem :- Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Solution Approach:-
Bottom-up DP utilizes a matrix m where we track LCS sizes for each combination of i and j.
If a[i] == b[j], LCS for i and j would be 1 plus LCS till the i-1 and j-1 indexes.
Otherwise, we will take the largest LCS if we skip a charracter from one of the string (max(m[i - 1][j], m[i][j - 1]).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        int dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n1; i++)
        {
            for(int j=0; j<=n2; j++)
            {
                if(i==0 || j== 0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution s;
    string text1, text2;
    text1 = "abcde";
    text2 = "ace";
    cout<<s.longestCommonSubsequence(text1, text2)<<endl;
    return 0;
}
