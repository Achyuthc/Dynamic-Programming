/*Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the 
subsequence are sorted in increasing order i.e. increasing subsequence. */

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int sum[n+1];
	    memset(sum,0,sizeof(sum));
	    //int lis[n+1];
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        //lis[i]=1;
	        sum[i]=arr[i];
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[j]<arr[i]&&sum[i]<sum[j]+arr[i])
	            {
	               
	                sum[i]=sum[j]+arr[i];
	            }
	        }
	        //cout<<sum[i]<<" ";
	        ans=max(ans,sum[i]);
	    }
	    return ans;
	}  
};
