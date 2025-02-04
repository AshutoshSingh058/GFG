//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    // Code here
	    vector<int>v;
	    vector<int> vec(n+1,0);
	    for(int i=2; i<=n; i++){
	        if(vec[i]==-1)continue;
	        
	        if(n%i == 0)v.push_back(i);
	        for(int j=i; j<=n; j+=i){
	            vec[j]=-1;
	        }
	        
	    }
	   // if(v.size() )
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends