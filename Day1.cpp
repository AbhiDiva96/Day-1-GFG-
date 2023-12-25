#include<bits/stdc++.h>
 using namespace std;

             int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
         if(n==1)return matrix[0][0];
         
        int m = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<vector<int>>InnerMat(n-1, vector<int>(n-1));
            int p = 0;
            for(int j=1; j<n; j++){
                int q = 0;
                for(int k=0; k<n; k++){
                    if(k==i){
                        continue;
                    }
                    InnerMat[p][q++] = matrix[j][k];
                }
                p++;
            }
            ans+=(matrix[m][i])*(determinantOfMatrix(InnerMat,n-1))*((i&1)?-1:1);
        }
        return ans;
    };

int main(){
       int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
      
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

    
        int result = determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    
return 0;
}
