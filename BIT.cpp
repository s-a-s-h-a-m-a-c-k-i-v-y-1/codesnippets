#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define ll long long int
#define mod 1000000007
// #define LSOne(S) (S & (-S))

// class BIT {
// 	int* ft, size;
// public:
// 	// initialize a BIT of n elements to zero
// 	BIT(int n) {
// 		size = n;
// 		ft = new int[n+1];
// 	}

// 	~BIT()	{
// 		delete [] ft;
// 	}

// 	// returns sum of the range [1...b]
// 	int sum(int b) {
// 		int sum = 0;
// 		for (; b; b -= LSOne(b)) sum += ft[b];
// 		return sum;
// 	}

// 	// returns sum of the range [a...b]
// 	int sum(int a, int b) {
// 		return sum(b) - (a == 1 ? 0 : sum(a - 1));
// 	}

// 	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
// 	// i.e., increment or decrement kth element by a value v
// 	void update(int k, int v) {
// 		for (; k <= size; k += LSOne(k)) ft[k] += v;
// 	}
            
//         // Range update: Adds v to each element in [i...j] in the array
//         void range_update(int i, int j, int v)	{
// 	update(i, v);
// 	update(j + 1, -v);
//         }
	
//     // divide each original frequency by c
// 	void scaleDown(int c){
//         for (int i=1 ; i<=size ; i++) ft[i] /= c;
//     }

//     // multiply each original frequency by c
//     void scaleUp(int c){
//         for (int i=1 ; i<=size ; i++) ft[i] *= c;
//     }
// };

// int main()  {
//     BIT b(10);
//     printf("%d\n", b.sum(10));

//     b.update(5, 10);
//     printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));

//     b.scaleUp(2);
//     printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));

//     b.scaleDown(2);
//     printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));

//     return 0;
// }
ll n;
#define LSOne(S) (S & (-S))
ll B1[100005], B2[100005];
ll query(ll* ft, int b)	{
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}
// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(ll* ft, int k, ll v) {
    for (; k <= n; k += LSOne(k)) ft[k] += v;
}
// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)	{
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}
void convert(ll arr[], ll n)
{
    ll temp[n];
    for (ll i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
    for (ll i=0; i<n; i++) arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
}
        //memset(B1, 0, (n+1) * sizeof(ll));
        //memset(B2, 0, (n+1) * sizeof(ll));
