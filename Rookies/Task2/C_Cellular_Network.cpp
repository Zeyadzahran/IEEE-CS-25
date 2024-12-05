// -------------------- ZEYAD -------------------------
// رُبَّما في الطُّرقِ أحلامٌ تَخبو ** وثُرى الأحزانِ فوقَ القلبِ يُصبو
//لكني أَعلمُ أنَّ دربي عسيرٌ ** وأني إلى مجدي سأَصبو
 
//قد أَسيرُ وحيداً في الليالي ** والمِحنُ تَزدادُ ثقلاً في الحِمالِ
//لكنَّ في صدري عزيمةً كالسِّراجِ ** تُضيءُ لي الدربَ في ظُلمةِ المحالِ
 
//ما أثقلتني جِراحُ السنينِ ** ولا أنزلتني عواصفُ اليقينِ
//فقلبي كالنسرِ يَحلقُ في السماءِ ** لا يَهابُ الرياحَ ولا الحزنَ الدفينِ
 
//فلو جارت الدنيا وساءت حالي ** سأبقى أُصارعُها بروحٍ عالية
//فالعزيمةُ في نفسي كالطودِ شامخة ** تَهدمُ الأسوارَ وتُبقي فيَّ الآمالَ باقية
 
// ----------------------------------------------------
// Contest: Codeforces Round 350 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/670/problem/D2
// Memory Limit: 256
// Time Limit: 1000
// Start: Sat 12 Oct 2024 04:01:13 PM EEST
#include <cmath>
#include <functional>
#ifdef ZEYAD
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#include <bits/stdc++.h>
#define ll   long long
#define ull  unsigned ll
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<ll>
#define vvll vector<vll>
#define vs   vector<string>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v)  v.begin(), v.end()
#define makeUnique(v)  v.erase(unique(all(v)), v.end())
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);

#define arrn int n; cin >> n; vi a(n); cin >> a;

void Free_Palastine();
void UseFile();

const int MOD = 1000000007;

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    cin >> a >> b ;
    ll ans = 0;

    for (auto i : a) {
        auto it = lower_bound(all(b), i);
        ll dist = INT_MAX;
        if (it != b.end()) dist = min(dist, abs(*it - i)); 
        if (it != b.begin()) dist = min(dist, abs(*(prev(it)) - i)); 
        
        ans = max(ans, dist);
    }
    cout << ans << endl;
    

}

int main() {
    Free_Palastine();

     int t = 1 ;
    // cin >> t;
    while (t--) solve();
    return 0;
}

void Free_Palastine() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}
