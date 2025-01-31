//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int i=0, count =0;
        while( (1<<i) <= n){
            
            int cyclelength = 1<<(i+1);
            int fullcycle = n /cyclelength;
            
            count +=fullcycle*(cyclelength/2);
            
            int remainder = n% cyclelength ;
            if(remainder>= (cyclelength/2)){
                count+= remainder - (cyclelength/2)+1;
            }
            i++;
        }
        return count;
    }
};




//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends