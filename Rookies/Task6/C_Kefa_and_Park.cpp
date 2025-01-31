// -------------------- ZEYAD -------------------------
// رُبَّما في الطُّرقِ أحلامٌ تَخبو ** وثُرى الأحزانِ فوقَ القلبِ يُصبو
// لكني أَعلمُ أنَّ دربي عسيرٌ ** وأني إلى مجدي سأَصبو

// قد أَسيرُ وحيداً في الليالي ** والمِحنُ تَزدادُ ثقلاً في الحِمالِ
// لكنَّ في صدري عزيمةً كالسِّراجِ ** تُضيءُ لي الدربَ في ظُلمةِ المحالِ

// ما أثقلتني جِراحُ السنينِ ** ولا أنزلتني عواصفُ اليقينِ
// فقلبي كالنسرِ يَحلقُ في السماءِ ** لا يَهابُ الرياحَ ولا الحزنَ الدفينِ

// فلو جارت الدنيا وساءت حالي ** سأبقى أُصارعُها بروحٍ عالية
// فالعزيمةُ في نفسي كالطودِ شامخة ** تَهدمُ الأسوارَ وتُبقي فيَّ الآمالَ باقية

#include <cmath>
#include <functional>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define makeUnique(v) v.erase(unique(all(v)), v.end())
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T>
istream &operator>>(istream &is, vector<T> &v);
ll nPr(ll n, ll r);
ll nCr(ll n, ll r);
vvll prefixSum2D(vvll& a);
ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a);

#define arrn  \
    int n;    \
    cin >> n; \
    vi a(n);  \
    cin >> a;

void Free_Palastine();
void UseFile();
const int MOD = 1000000007;
const pii drc[]
{
    {-1,0},
    {0,1} ,
    {1,0} ,
    {0,-1}
};

#define maxNodes 100009  
int n ,m ;
int valied = 0 ;
 
void dfs (int root ,int cns ,vector<vi>&edges,vi &cats,vector<bool> &vis)
{
    vis[root] = 1 ;
    //==
    if(cats[root]) cns++;
    else cns = 0 ;
    if( cns == m+1) return ;
    //==
 
    bool leaf = 1 ;
    for(auto child : edges[root]) 
    {
        if(!vis[child])
        {
             leaf = 0 ;
        dfs(child,cns,edges,cats,vis);
        }
       
    }
    if(leaf) {
        valied++;
    }
    }
void solve()
{   
    cin>>n>>m;
    vector<vi>graph(n);
    vi cats(n);
    vector<bool>visted(n);
    cin>>cats;
    for( int i = 1 ; i <n;i++)
    {
        int u , v ;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0,0,graph,cats,visted);
    cout<<valied;
 
}

int main()
{
    Free_Palastine();

    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

void Free_Palastine()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (const auto &i : v)
        os << i << ' ';
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
ll nPr(ll n, ll r) {
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}
 
ll nCr(ll n, ll r) {
    ll ans = 1;
    ll div = 1; // r! 
    for (ll i = r + 1; i <= n; i++) {
        ans = ans * i;
        ans /= div;
        div++;
    }
    return ans;
}
vvll prefixSum2D(vvll& a) {
    vvll b(a.size(), vll(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++)
    {
        for (int j = 1; j < a.size(); j++)
        {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}
 
ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}
