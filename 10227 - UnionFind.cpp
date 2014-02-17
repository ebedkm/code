#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

#define REP(X, Y) for (int (X) = 0; (X) < (Y); ++(X))
#define FOR(X, Y, Z) for (int (X) = (Y); (X) <= (Z); ++(X))
#define RFOR(X, Y, Z) for (int (X) = (Y); (X) >= (Z); --(X))
#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define RESET(C, V) memset(C, V, sizeof(C))
#define PB push_back
#define MP make_pair
#define A first
#define B second
#define MX(Z, Y) Z = max((Z), (Y))
#define MN(X, Y) X = min((X), (Y))
#define FORIT(X, Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); X++)
#define RFORIT(X, Y) for(typeof((Y).rbegin()) X = (Y).rbegin(); X != (Y).rend(); X++)
#define INTINF 2147483647
#define LLINF 9223372036854775807LL

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PI;

class UnionFind {                                              // OOP style
private:
  VI p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {


    int tc;
    int T = 1;
    bool flag = false;
    char input[128];
    gets(input);
    sscanf(input,"%d",&tc);
    gets(input);
    while(tc--){
        int H[105][105];
        memset(H, 0, sizeof(H));
        gets(input);
        int P, T;
        sscanf(input,"%d%d",&P,&T);
        UnionFind UF(P);
        int a, b;

        while(gets(input) && sscanf(input, "%d%d", &a, &b)==2){
            a--;b--;
            H[a][b] = 1;
        }

        for(int i=0;i<P-1; i++){
            for(int j=i+1;j<P;j++){
                bool cek = true;
                for(int k=0;k<T;k++){
                    if(H[i][k] != H[j][k]) cek = false;
                }
                if(cek) {
                    UF.unionSet(i, j);
                }
            }
        }
        cout << UF.numDisjointSets() << endl;
        if(tc) cout << endl;
    }
  return 0;
}

