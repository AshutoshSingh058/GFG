//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int fun(int i){
        if(i%4==0)return i;
        else if(i%4==1) return 1;
        else if(i%4==2) return i+1;
        else return 0;
    }
    
    int findXOR(int l, int r) {
        // complete the function here
        l--;
       int xl=fun(l), xr= fun(r);
       return xl^xr;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends