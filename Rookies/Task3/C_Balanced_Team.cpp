
// -------------------- ZEYAD -------------------------
// رُبَّما في الطُّرقِ أحلامٌ تَخبو ** وثُرى الأحزانِ فوقَ القلبِ يُصبو
// لكني أَعلمُ أنَّ دربي عسيرٌ ** وأني إلى مجدي سأَصبو

// قد أَسيرُ وحيداً في الليالي ** والمِحنُ تَزدادُ ثقلاً في الحِمالِ
// لكنَّ في صدري عزيمةً كالسِّراجِ ** تُضيءُ لي الدربَ في ظُلمةِ المحالِ

// ما أثقلتني جِراحُ السنينِ ** ولا أنزلتني عواصفُ اليقينِ
// فقلبي كالنسرِ يَحلقُ في السماءِ ** لا يَهابُ الرياحَ ولا الحزنَ الدفينِ

// فلو جارت الدنيا وساءت حالي ** سأبقى أُصارعُها بروحٍ عالية
// فالعزيمةُ في نفسي كالطودِ شامخة ** تَهدمُ الأسوارَ وتُبقي فيَّ الآمالَ باقية

// ----------------------------------------------------
// Contest: Codeforces Round 350 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/670/problem/D2
// Memory Limit: 256
// Time Limit: 1000
// Start: Sat 12 Oct 2024 04:01:13 PM EEST
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

#define arrn  \
    int n;    \
    cin >> n; \
    vi a(n);  \
    cin >> a;

void Free_Palastine()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void UseFile()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
}

const int MOD = 1000000007;

void solve()
{
    arrn;
    sort(all(a));
    ll l = 0, r = 0, ans = 0 ,maxx = -1;
    for(int i = 0 ; i<n;i++)
    {
        l = i , r = n - 1  ;
        while( l <= r)
        {
            int mid = (l +r )/ 2 ;
            if(a[mid] - a[i] <= 5)
            {
                l = mid + 1 ;
                ans = mid ;
            }
            else
            {
                r = mid - 1 ;
            }
        }
        maxx = max(maxx,ans-i+1);
    }
   
    cout << maxx << endl;
}
/*
1 2 10 12 15 17




*/

int main()
{
    Free_Palastine();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
