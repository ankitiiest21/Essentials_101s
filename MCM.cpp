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


int MCM(vector<int> arr, int n)
{
    // if(i>=j) return 0;

    // int ans = INT_MAX;

    // for(int k = i; k<j; k++)
    // {
    //     int temp_ans = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];

    //     ans = min(ans, temp_ans);
    // }

    // return ans;

    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i = 1; i<n-1; i++) dp[i][i+1] = arr[i-1] * arr[i] * arr[i+1];

    for(int gap = 3; gap<n; gap++)
    {

        for(int i = 1; i<=n-gap; i++)
        {

            int j = gap + i - 1;

            dp[i][j] = INT_MAX;

            for(int k = i; k<j; k++)
            {
                dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j] );
            }
        }

    }

    return dp[1][n-1];
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
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i = 0; i<n; i++)cin>>arr[i];

        cout<<MCM(arr, n)<<"\n";
    }
    
    return 0;
}
