#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

#define endl       '\n'
#define spc        printf(" ")
#define nln        printf("\n")                     ///printnewline
#define fast_IO    ios_base::sync_with_stdio(false);
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min
#define sqr(x)     (x)*(x)

#define z(x)       fabs(x)<EPS
#define iqu(x,y)   z(fabs(x-y))

#define rep(i,a,b)  for(i=a;i<=b;i++)
#define rep0(i,n)   for(i=0;i<n;i++)
#define rep1(i,n)   for(i=1;i<=n;i++)               ///looping
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define rev0(i,n)   for(i=n-1;i>=0;i--)
#define rev1(i,n)   for(i=n;i>=1;i--)
#define forstl(i,v) for(i=0;i<v.size();i++)
#define forit(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(p)      p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define sz(c)      (int)c.size()
#define pb(x)      push_back(x)                     ///STL defines
#define mp(x,y)    make_pair(x,y)
#define xx         first
#define yy         second
#define _itr(v)    __typeof(v.begin())

#define LLI        long long int
#define i64        long long int
#define i64u       unsigned long long int
#define LLU        unsigned long long int
#define Double     long double
#define PI         acos(-1.0)                        ///PI er value

typedef vector<int>     vi;
typedef vector<i64>     vll;
typedef vector<string>  vs;
typedef pair<int, int>  pii;
typedef pair<i64, i64>  pll;

#define check(n, pos)  (bool)(n & (1LL<<(pos)))      ///CHECK
#define biton(n, pos)  (n | (1LL<<(pos)))            ///ON     }-bit opr.
#define bitoff(n, pos) (n & ~(1LL<<(pos)))           ///OFF

// reading and writing case
#define readcase  int cas,kase=0;CI(cas);while((cas--)&&(++kase))
#define printcase printf("Case %d:",kase)

//debugging infinite variable
bool deb_mode = 0;
#define debug(a...) if(deb_mode){cout<<"Line= "<<__LINE__<<" -> ";Dbug,a,#a;Dbug.printall();cout<<endl;}
class debugger {
    vector<string> vars;
public:
    template<typename T> debugger& operator , ( const T v ) { stringstream ss; ss << v, vars.push_back( ss.str() ); return *this; }
    void printall() { int j = 0, l = vars.size(); for( int i = 0; i < ( l - 1 ); i++ ) { if( i )cout << ", "; for( j; j < vars[l - 1].size(); j++ ) { if( vars[l - 1][j] == ',' ) {j++; break;} cout << vars[l - 1][j]; } cout << " = " << vars[i]; } vars.clear(); }
} Dbug;

///STL printing output stream overloading
template <typename T1, typename T2> inline ostream& operator << ( ostream& os, const pair<T1, T2>& p ) { return os << "(" << p.first << "," << p.second << ")"; }
template <typename T> inline ostream &operator << ( ostream & os, const vector<T>& v ) { bool first = true; os << "{"; for( unsigned int i = 0; i < v.size(); i++ ) { if( !first ) os << ","; os << v[i]; first = false; } return os << "}"; }
template <typename T> inline ostream &operator << (  ostream & os, const set<T>& v ) { bool first = true; os << "{"; for ( typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii ) { if( !first ) os << ","; os << *ii; first = false; } return os << "}"; }
template <typename T1, typename T2> inline ostream &operator << ( ostream & os, const map<T1, T2>& v ) { bool first = true; os << "{"; for ( typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii ) { if( !first ) os << ","; os << *ii ; first = false; } return os << "}"; }

template <typename T> void getarray( T a[], int b, int e ) { for( int i = b; i < e + b; i++ ) cin >> a[i]; }
template <typename T> void printarray( T a[], int b, int e ) { for( int i = b; i < e - 1 + b; i++ ) cout << a[i] << " "; if( e - 1 + b >= 0 ) cout << a[e - 1 + b] << endl; }
template <typename T> void printV( vector<T> v ) { int sz = v.size(); if( sz ) cout << v[0]; for( int i = 1; i < sz; i++ ) cout << " " << v[i]; nln; }

template <typename T> T gcd( T a, T b ) { if( b == 0 ) return a; return gcd( b, a % b ); }
template <typename T> T BigMod ( T b, T p, T m ) { if ( p == 0 ) return 1; if ( p % 2 == 0 ) { T s = BigMod( b, p / 2, m ); return ( ( s % m ) * ( s % m ) ) % m; } return ( ( b % m ) * ( BigMod( b, p - 1, m ) % m ) ) % m; }
template <typename T> T ModInv ( T b, T m ) { return BigMod( b, m - 2, m ); }

template<class T> inline void read( T &x ) { bool Minus = 0; char c; for( c = getchar(); c <= 32; c = getchar() ) ; if( c == '-' ) Minus = 1, c = getchar(); for( x = 0; c > 32; c = getchar() ) x = x * 10 + c - '0'; if( Minus ) x = -x; }
char getc() { char c; for( c = getchar(); c <= 32; c = getchar() ); return c; }  ///input char with buffering
int CI( int &_x ) { return scanf( "%d", &_x ); }
int CI( int &_x, int &_y ) { return scanf( "%d %d", &_x, &_y ); }
int CI( int &_x, int &_y, int &_z ) { return scanf( "%d %d %d", &_x, &_y, &_z ); }
int CI( int &_a, int &_b, int &_c, int &_d ) { return scanf( "%d %d %d %d", &_a, &_b, &_c, &_d ); }

template <class T> string toString( T n ) { ostringstream oss; oss << n; return oss.str(); }
int toInt( string s ) { int r = 0; istringstream sin( s ); sin >> r; return r; }
i64 toLong( string s ) { i64 r = 0; istringstream sin( s ); sin >> r; return r; }
bool isVowel( char ch ) { ch = tolower( ch ); if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )return true; return false; }
bool isUpper( char c ) { return c >= 'A' && c <= 'Z'; }
bool isLower( char c ) { return c >= 'a' && c <= 'z'; }

int dr8[8] = { +1, -1, +0, +0, +1, -1, -1, +1};   ///8 direction move
int dc8[8] = { +0, +0, -1, +1, +1, +1, -1, -1};
int dr4[4] = { +0, +0, +1, -1};                   ///4 direction move
int dc4[4] = { -1, +1, +0, +0};                   ///or adjacent dir.
int kn8r[8] = { +1, +2, +2, +1, -1, -2, -2, -1};  ///knight moves
int kn8c[8] = { +2, +1, -1, -2, -2, -1, +1, +2};

const double EPS = 1e-9;                         ///constants
const int INF = ( 1 << 30 ) - 1;
const i64 LINF = ( 1ll << 62 ) - 1;
const int mod = ( int )1e9 + 7;
const int MAX = ( int )1e5;
///____________________________Main Coding Starts From Here________________________///



int arr[MAX];

struct info {
    i64 prop, sum;
} tree[MAX * 3];

void init( int node, int b, int e ) {
    if( b == e ) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    init( Left, b, mid );
    init( Right, mid + 1, e );
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update( int node, int b, int e, int i, int j, i64 x ) {
    if ( i > e || j < b )return;
    if ( b >= i && e <= j ) {
        tree[node].sum += ( ( e - b + 1 ) * x );
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = ( node * 2 ) + 1;
    int mid = ( b + e ) / 2;
    update( Left, b, mid, i, j, x );
    update( Right, mid + 1, e, i, j, x );
    tree[node].sum = tree[Left].sum + tree[Right].sum + ( e - b + 1 ) * tree[node].prop;
}


int query( int node, int b, int e, int i, int j, int carry = 0 ) {
    if( i > e || j < b )
        return 0;

    if( b >= i and e <= j )
        return tree[node].sum + carry * ( e - b + 1 );

    int Left = node << 1;
    int Right = ( node << 1 ) + 1;
    int mid = ( b + e ) >> 1;
    int p1 = query( Left, b, mid,  i, j,   carry + tree[node].prop );
    int p2 = query( Right, mid + 1, e, i, j, carry + tree[node].prop );
    return p1 + p2;
}

int main() {
    int n, i;
    cin >> n;
    rep1( i, n )
    cin >> arr[i];
    init( 1, 1, n );
    update( 1, 1, n, 2, 4, 6 );
    cout << query( 1, 1, n, 1, 3, 0 ) << endl;
    update( 1, 1, n, 2, 3, 5 );
    cout << query( 1, 1, n, 2, 4, 0 ) << endl;
    return 0;
}
