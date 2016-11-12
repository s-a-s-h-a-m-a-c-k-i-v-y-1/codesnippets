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
#define LSOne(S) (S & (-S))
using namespace std;

typedef long long ll;

// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
ll B1[100005], B2[100005];

// Array size
int N;

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)	{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

int main()  {
	int T, C, p, q, cmd;
	ll v;

	scanf("%d", &T);
	while (T--)	{
		// C -> No. of operations
		scanf("%d %d", &N, &C);
		memset(B1, 0, (N+1) * sizeof(ll));
		memset(B2, 0, (N+1) * sizeof(ll));
		while (C--)	{
			scanf("%d %d %d", &cmd, &p, &q);
			// cmd is 0 for a range update and 1 for a range query
			if (cmd == 0)   {
                		scanf("%lld", &v);
                		range_update(p, q, v);
			} else
                		printf("%lld\n", range_query(p, q));
		}
	}

    return 0;
}
