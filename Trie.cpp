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


struct trie
{
    bool isEnd;
    unordered_map<char, trie*> mp;

    trie()
    {
        isEnd = false;
    }
};


void insert(trie* root, string str)
{
    trie* curr = root;

    for(char ch: str)
    {
        if(!(curr->mp.count(ch)))
        {
            curr->mp[ch] = new trie;
        }

        curr = curr->mp[ch];
    }

    curr->isEnd = true;
}


bool search(trie* root, string str)
{
    trie* curr = root;
    for(char ch: str)
    {
        if(!curr->mp.count(ch)) return false;

        curr = curr->mp[ch];
    }

    return curr->isEnd;
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
        string str;
        cin>>str;
        trie * root = new trie();

        insert(root, str);

        if(search(root, "asedfg")) cout<<"Present\n";
        else cout<<"Absent\n";

    }
    
    return 0;
}
