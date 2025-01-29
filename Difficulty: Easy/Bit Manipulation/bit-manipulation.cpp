//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int n, int i) {
        // your code here
        i--;
        bool n1 = (n & (1<<i))!=0;
        long long int n2 = (n | (1<<i));
        long long int n3 = (n & (~(1<<i)));
        cout<<n1<<" "<<n2<<" "<<n3<<" ";
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends