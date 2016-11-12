#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define ll long long int
#define mod 1000000007
ll nextPowerOf2(ll n){
    n--;n |= n >> 1;n |= n >> 2;n |= n >> 4;n |= n >> 8;n |= n >> 16;n++;return n;
}
bool isPerfectSquare(ll n){
    if (n < 0)return false;ll tst = (ll)(sqrt(n) + 0.5);return tst*tst == n;
}
bool triangle(ll a, ll b, ll c){
    return ((a+b)>c&&(b+c)>a&&(a+c)>b);
}
ll chartoint(char c){
    switch(c){case '1':return 1;break;case '2':return 2;break;case '3':return 3;break;case '4':return 4;break;case '5':return 5;break;case '6':return 6;break;case '7':return 7;break;case '8':return 8;break;case '9':return 9;break;default: return 0;break;}
}
bool ispuppercase(char c){
    ll val = (ll)c;
    if(val >= 65 && val <= 90) return 1;
    return 0;
}
bool islowercase(char c){
    ll val = (ll)c;
    if(val >= 97 && val <= 122) return 1;
    return 0;
}
ll isnum(char s){
    if(s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9'||s=='0') return 1; return 0;
}
bool isvowel(char c){
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'||c=='y');
}
//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
//int x=(n & -n);
//int x=pow(2,floor(log(n)/log(2)));
// (val & (val - 1)) == 0 - - > check for power of two
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
