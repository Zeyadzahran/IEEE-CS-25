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
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define vb vector<bool>
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

void solve() {
    int n ,m ;
    cin >> n >> m ;
    vector<vi> grid(n,vi(m,0));
    vector<vb> vis(n,vb(m,0));
    for(int i = 0 ; i< n ;i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            cin >> grid[i][j];
        }
    }
    auto in = [&](int i , int j){
        return i >= 0 and i <n and j >= 0 and j < m and grid[i][j] > 0 ;
    };
    ll sum = 0 ;
   function<ll(int, int)> dfs = [&](int i, int j) -> ll {
    vis[i][j] = true;
    sum += grid[i][j];
    
    for(auto x : drc) {
        int ni = i + x.first, nj = j + x.second;
        if(in(ni, nj) && !vis[ni][nj]) {
            dfs(ni, nj);
        }
    }
    return sum;
};

    ll maxx = 0 ; 
    for(int i = 0 ; i< n ;i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            if(grid[i][j] == 0 or vis[i][j]) continue;
            maxx = max(dfs(i,j),maxx);
            sum = 0 ;
        
        }
    }
    cout << maxx << '\n';
}

int main()
{
    Free_Palastine();

    int t = 1;
    cin >> t;
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
