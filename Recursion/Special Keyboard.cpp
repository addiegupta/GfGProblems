/*

GeeksForGeeks: Special Keyboard

Link to Problem: https://practice.geeksforgeeks.org/problems/special-keyboard/0

Difficulty: Medium

Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed. 

If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of key.

Output:

Print maximum number of A's.  Print -1, if N is greater than 75.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 75

Example:

Input:
2
3
7

Output:
3
9

Explanation:

Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing 
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
 
References : https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

*/
#include <bits/stdc++.h>
using namespace std;

// Memoise the results for previous computations
vector<int> dp(76, -1);

int solve(int n) {
	// Type all A's instead of using copy/paste
    if (n < 7) return n;

    int tmp;
    // Value for n does not exist in vector dp
    if (dp[n] == -1) {
    	// Find point (breakpoint) after which only one copy and then multiple pastes would be required
    	// to get maximum length
        for (int i=n-3; i >= 0; i--) {
            // Number of A's if breakpoint is set at i
            tmp = solve(i)*(n-i-1);
            // Store in vector
            dp[n] = max(dp[n], tmp);
        }
    }
    return dp[n];
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin>>n;
	    cout<<solve(n)<<endl;
	}
	return 0;
}