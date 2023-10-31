#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define maxn 100000000000017    
#define endl "\n"
#define mk make_pair
#define pll pair<ll, ll>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()1
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define uompi unordered_map<int,int> mp
#define uompll unordered_map<ll,ll> mp
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define bitcnt(n) __builtin_popcount(n)
#define mask(i) (1 << (i))
#define bitmask(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
#define f1(i, n) for(int i = 1; i <= n; i++)
#define f0(i, n) for(int i = 0; i < n; i++)
#define fe(x, v) for(auto x : v)
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
ll Mul(ll x, ll n, ll M) {ll ans = 0; for(;n; n /= 2, x = (x + x) % M)  if(n & 1) ans = (ans + x) % M; return ans;}
ll Pow(ll x, ll n, ll M) {ll ans = 1; for(;n; n /= 2, x = Mul(x, x, M)) if(n & 1) ans = Mul(ans, x, M); return ans;}
ll Pow(ll x, ll n) {ll ans = 1; for(;n; n /= 2, x = x * x) if(n & 1) ans = ans * x; return ans;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

template <typename T>
void read(T &p)
{
    cin >> p;
}
 
template <typename T, typename T1>
void read(pair<T, T1> &p)
{
    read(p.ff);
    read(p.ss);
}
 
template <typename T>
void read(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        read(arr[i]);
    }
}
 
template <typename T>
void read(vector<T> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        read(arr[i]);
    }
}
template <typename T>
void out(T& n)
{
    cout << n;
}
template <typename T, typename T1>
void out(pair<T, T1> &p)
{
    cout << "(";
    out(p.ff);
    cout << ",";
    out(p.ss);
    cout << ")";
}
template <typename T>
void out(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        out(arr[i]);
        cout << " ";
    }
}
 
template <typename T>
void out(vector<T> &arr)
{
 
    // cout << "[ ";
    for (ll i = 0; i < arr.size(); i++)
    {
        out(arr[i]);
        cout<<" ";
        // if (i!=arr.size()-1)
            // cout << ", ";
    }
    // cout << " ]";
 
}
template <typename T>
void out(set<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}
 
template <typename T>
void out(multiset<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}
 
template <typename T, typename T1>
void out(map<T,T1> &m)
{
    for (auto i:m)
    {
        out(i.first);
        cout<<" -> ";
        out(i.second);
        cout<<", ";
    }
}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : ";
    out(arg1);
}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : ";
    out(arg1);
    cout << " | ";
    __f(comma + 1, args...);
}
/******************************************************************************************/
void solve(){
    // int n;
    // cin>>n;
    int n;
    read(n);
    // 6 5 2 3 4 1
    // 6 5 1 4 2 3
    // 0 5 1 4 2 3
    // 1 2 3 6 5 4
    // 1 3 0  
    if(n == 1) {
        cout<<1<<endl;
        return ;
    }
    if( n  & 1 ) {
        cout<<-1<<endl;
        return;
    }
    vi ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = n - cnt;
        cnt++;
        ans[++i] = cnt;
        cnt++;
    }
    out(ans);
    cout<<endl;

}

int main(){
    fast 
    ll t;
    cin>>t;
    while(t--){
        solve();
    }

    
}