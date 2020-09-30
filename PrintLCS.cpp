#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define UB upper_bound
#define LB lower_bound
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define be(a) (a).begin(),(a).end()
#define deb(x) cout<< #x <<" "<<endl;
#define deb2(x, y) cout<< #x <<" "<< x <<endl<< #y <<" "<<y<<endl
#define fo(i, n) for(long long i=0; i<n; i++)
#define Fo(i, n, k) for(long long i=k; i<n; i++)
#define mod 1000000007
#define int long long

typedef long long ll;

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
typedef vector<pair<int, int>> vll;
typedef unordered_map<int, int> ump;



bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}



int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        string s1, s2;
        cin>>s1>>s2;
        int n = s1.size();
        int m = s2.size();

        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++)dp[i][0] = 0;
        for(int i = 0; i<=m; i++)dp[0][i] = 0;

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string lcs = "";

        int i = n, j = m;

        while(i>0 && j>0)
        {
            if(s1[i-1] == s2[j-1])
            {
                lcs += s1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1]){i--;}
                else j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout<<lcs<<"\n";
    }
    
    return 0;
}
