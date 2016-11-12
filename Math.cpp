#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define ll long long int
#define mod 1000000007
ll gcd(ll a , ll b){
    if(b > a) swap(a , b);
    if(b == 0) return a;
    return gcd(b , a % b);
}
ll ansx;
ll ansy;
ll r0;
ll r1;
ll c;
ll g;
void exteuc(ll r0, ll r1, ll *ansx , ll *ansy)
{
    if (r0 == 0)
    {
        *ansx = 0;
        *ansy = 1;
        return;
    }
    ll x1, y1;
    exteuc(r1 % r0 , r0 , &x1 , &y1);
    *ansx = y1 - (r1 / r0) * x1;
    *ansy = x1;
}
void possol(ll r0 , ll r1 , ll c, ll *resx , ll *resy){
    exteuc(r0 , r1 , &ansx , &ansy);
    g = gcd(r0 , r1);
    double val1 = (double)(ansx) * (double)c / (double)(r1);
    val1 = -val1;
    double val2 = (double)(ansy) * (double)c / (double)(r0);
    val1 = ceil(val1);
    val2 = floor(val2);
    ll ss = val1;
    ll ff = val2;
    for(ll i = ss; i <= ff; i ++){
        ll newx = ansx * c + r1 * i / g;
        ll newy = ansy * c - r0 * i / g;
        cout << newx << " " << newy << endl;
        if(newx >= 0 && newy >= 0){
            *resx = newx;
            *resy = newy;
        }
    }
}
ll mulmod(ll a,ll b,ll c){
    ll x = 0 , y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;    //a*b might overflow
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
long long pow_mod(long long b,long long e)
{
    long long ans=1;
    b%=mod;
    while(e>0)
    {
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans%mod;
}
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int gpsum(int a , long long n){
    if(a == 1){
        return (n % mod);
    }
    return mult(add(power(a , n % (mod - 1)) , mod - 1) , power(a - 1 , mod - 2));
}
ll fact[201000];
ll invfact[201000];
ll choose(ll n, ll r)
{
    ll res = 0;
    res = ((fact[n] * invfact[r])%mod * invfact[n - r])%mod;
    if(res < 0) res += mod;
    return res;
}
/*
 //in int main
 choose(n , r) = nCr
 fact[0] = 1;
 for (ll i = 1; i < 200010; ++i)
 {
 fact[i] = (fact[i - 1] * i)%mod;
 if(fact[i] < 0) fact[i] += mod;
 }
 invfact[200009] = pow_mod(fact[200009], mod - 2);
 for (ll i = 200008; i >= 0; --i)
 {
 invfact[i] = (invfact[i + 1] * (i + 1))%mod;
 if(invfact[i] < 0) invfact[i] += mod;
 }
 */
map< ll , ll > mm;
void primeFactors(ll n)
{
    ll ct = 0;
    while (n%2 == 0)
    {
        ct ++;
        n = n/2;
    }
    mm[2] += ct;
    ct = 0;
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        ct = 0;
        while (n%i == 0)
        {
            ct ++;
            n = n/i;
        }
        mm[i] += ct;
    }
    if (n > 2)
        mm[n] ++;
}
ll InverseEuler(ll n, ll mod)
{
    return pow_mod(n,mod-2);
}
ll C(ll n, ll r)
{
    vector<ll> f(n + 1,1);
    for(ll i = 2; i <= n; i++ )
        f[i]= (f[i-1]*i) % mod;
    return (f[n]*((InverseEuler(f[r], mod) * InverseEuler(f[n-r], mod)) % mod)) % mod;
}
bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
    ll x = mulmod(a, d, n);
    if (x == 1  || x == n-1)
        return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
bool isPrime(ll n, ll iterations)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < iterations; i++)
        if (miillerTest(d, n) == false)
            return false;
    return true;
}
ll PollardRho(ll n)
{
    srand(time(NULL));
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    ll x = (rand()%(n-2))+2;
    ll y = x;
    ll c = (rand()%(n-1))+1;
    ll d = 1;
    while (d==1)
    {
        x = (mulmod(x, 2, n) + c + n)%n;
        y = (mulmod(y, 2, n) + c + n)%n;
        y = (mulmod(y, 2, n) + c + n)%n;
        d = gcd(abs(x-y), n);
        if (d==n) return PollardRho(n);
    }
    return d;
}
//calculating phi and lowest prime factor in O(n)
const int N = 10000000;
int lp[N + 1];
int phi[N + 1];
vector<int> pr;
void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
//bitwise sieve implementation
#define MAX 100000128
int flagArr[MAX >> 6];
int arrVal[MAX];
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))
void Sieve()
{
    int i,j,k;
    for(i = 3 ; i < sqrt(MAX - 64) ; i+=2)
    {
        if(!ifComp(i))
        {
            for(j = i * i , k = i << 1 ; j < (MAX - 64) ; j += k)
                isComp(j);
        }
    }
    arrVal[2]=1;
    for(i = 3 ; i < MAX - 64 ; i++)
    {
        if(i % 2 && !ifComp(i))
        {
            arrVal[i] = arrVal[i-1] + 1;
        }
        else
            arrVal[i] = arrVal[i-1];
    }
}
//Prime between two numbers
int main() {
    vector<int> primes;
    primes.push_back(2);
    
    for (int i = 3; i <= 32000; i+=2) {
        bool isprime = true;
        int cap = sqrt(i) + 1;
        
        vector<int>::iterator p;
        for (p = primes.begin(); p != primes.end(); p++) {
            if (*p >= cap) break;
            if (i % *p == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) primes.push_back(i);
    }
    
    int T,N,M;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        if (t) cout << endl;
        
        cin >> M >> N;
        if (M < 2) M = 2;
        
        int cap = sqrt(N) + 1;
        
        set<int> notprime;
        notprime.clear();
        
        vector<int>::iterator p;
        for (p = primes.begin(); p != primes.end(); p++) {
            
            if (*p >= cap) break;
            int start;
            
            if (*p >= M) start = (*p)*2;
            else start = M + ((*p - M % *p) % *p);
            
            for (int j = start; j <= N; j += *p) {
                notprime.insert(j);
            }
        }
        
        for (int i = M; i <= N; i++) {
            if (notprime.count(i) == 0) {
                cout << i << endl;
            }
        }
        
    }
    return 0;
}
///////Lagrange INterpolation
/*for(ll i = 0; i < s; i ++) cin >> a[i];
for(ll i = s; i < s + c; i ++){
    double val = 0;
    for(ll j = 0; j < s; j ++){
        double p = 1;
        for(ll k = 0; k < s; k ++) if(j != k) p *= ((double)i - (double)k) / ((double)j - (double)k);
            val += ((double)a[j] * p);
            }
    cout << roundl(val) << " ";
    }
*/
