/*Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of 
multiplications.The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).*/
class Solution{
public:
int cost[101][101];
    int helper(int a[],int i,int j)
    {
        if(i==j)
            return 0;
        if(cost[i][j]!=-1)
            return cost[i][j];
        int tans=INT_MAX,tmp=INT_MAX;
        for(int k=i;k<j;k++)
        {
            tmp=helper(a,i,k)+helper(a,k+1,j);
            tmp+=a[i-1]*a[k]*a[j];
            tans=min(tans,tmp);
            
        }
        cost[i][j]=tans;
        return tans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(cost,-1,sizeof(cost));
       return helper(arr,1,N-1);
        // code here
    }
};
