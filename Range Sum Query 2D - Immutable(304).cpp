/*Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).*/

class NumMatrix {
public:
    vector<vector<int>> leftsum;
    int prevsum=0;
    NumMatrix(vector<vector<int>>& matrix) {
        
        leftsum.resize((int)matrix.size(),vector<int> (matrix[0].size(),0));
       
        
        for(int i=0;i<matrix.size();i++)
        {
            prevsum=0;
            for(int j=0;j<matrix[0].size();j++)
            {
                prevsum+=matrix[i][j];
                leftsum[i][j]=prevsum;
                if(i-1>=0)
                    leftsum[i][j]+=leftsum[i-1][j];
              
            }
          
        }
      
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans=leftsum[row2][col2];
   
        if(col1-1>=0)
        {
            ans-=leftsum[row2][col1-1];
        }
        
        if(row1-1>=0)
        {
            ans-=(leftsum[row1-1][col2]);
            
            if(col1-1>=0)
                ans+=leftsum[row1-1][col1-1];
        }
        
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
