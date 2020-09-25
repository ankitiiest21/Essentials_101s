//maxDotProduct finds the maximum dot product between any two subsequences of two arrays..


int dp[505][505];

int solve(vector<int>& a, vector<int>& b, int i,int j){
       if(i==a.size()||j==b.size())
           return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int val1=solve(a,b,i+1,j+1)+a[i]*b[j];
        int val2=solve(a,b,i,j+1);
        int val3=solve(a,b,i+1,j);
        return dp[i][j]=max(val1,max(val2,val3));
    }
    
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size(),m=nums2.size(),max1=INT_MIN,min1=INT_MAX,max2=INT_MIN,min2=INT_MAX;
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++)
              dp[i][j]=-1;
      }
      bool flag[4];
      memset(flag,false,sizeof(flag));
      for(int i=0;i<4;i++) flag[i]=false;
      for(int i=0;i<n;i++){
          if(nums1[i]<0)
             flag[0]=true;
          else
             flag[1]=true;
          max1=max(max1,nums1[i]);
          min1=min(min1,nums1[i]);
      }
      for(int i=0;i<m;i++){
          if(nums2[i]<0)
             flag[2]=true;
          else
             flag[3]=true;
          max2=max(max2,nums2[i]);
          min2=min(min2,nums2[i]);
      }
      if(!flag[1]&&!flag[2])
         return max1*min2;
      else if(!flag[0]&&!flag[3])
          return min1*max2;
      else
          return solve(nums1,nums2,0,0);
    }
