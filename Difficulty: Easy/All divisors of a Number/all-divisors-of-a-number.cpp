//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int>v;
	   // vector<int> vec(n+1,0);
    
	    for(int i=1; i*i<=n; i++){
	       // if(vec[i]==-1)continue;
	        
	        if(n%i == 0){
	            v.push_back(i);
	            if(n/i != i)v.push_back(n/i);
	           // cout<<i<<" ";
	        }

	       // for(int j=i; j<=n; j+=i){
	       //     vec[j]=-1;
	       // }
	        
	    }
	    sort(v.begin(), v.end());
	    for(int i=0 ; i<v.size(); i++){cout<<v[i]<<" "; }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends