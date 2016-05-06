#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXC = 1 << 17;
int N, i, j, last, sz;
long long area;
struct event {
	long start, lo, hi, flag;
	bool operator < ( const event &e ) const { return
			start < e.start; }
};
vector< event > ls;
/* Segment Tree */
long times[3 * MAXC], amount[3 * MAXC];
vector< pair< long, long > > coords;
void update( int node, int lo, int hi,
		int start, int end, long value ) {
	if ( lo > end || hi < start || lo > hi )
		return ;
	if ( lo >= start && hi <= end )
		times[node] += value;
	else {
		int mid = ( lo + hi ) / 2;
		update( 2 * node, lo, mid, start, end,
				value );
		update( 2 * node + 1, mid + 1, hi, start,
				end, value );
	}
	if ( times[node] == 0 )
		if ( lo == hi )
			amount[node] = 0;
		else amount[node] = amount[2 * node] +
				amount[2 * node + 1];
	else amount[node] = coords[hi].first -
			coords[lo - 1].first;
}
int main() {
	scanf( "%d", &N );
	for ( i = 0; i < N; i++ ) {
		int x1, x2, y1, y2;
		scanf( "%d %d %d %d", &x2, &y1, &x1, &y2 );
		if ( x1 > x2 ) swap( x1, x2 );
		if ( y1 > y2 ) swap( y1, y2 );
		ls.push_back( (event){ x1, y1, y2, 1 } );
		ls.push_back( (event){ x2, y1, y2, -1 } );
	}
	sort( ls.begin(), ls.end() );
	/* Compress */
	for ( i = 0; i < ls.size(); i++ ) {
		coords.push_back( make_pair( ls[i].lo,
				i + 1 ) );
		coords.push_back( make_pair( ls[i].hi,
				-(i + 1) ) );
	}
	sort( coords.begin(), coords.end() );
	for ( i = 0; i < coords.size(); i = j ) {
		for ( j = i; j < coords.size() &&
		coords[j].first == coords[i].first; j++ ) {
			int idx = coords[j].second;
			if ( idx > 0 )
				ls[idx - 1].lo = sz;
			else ls[-idx - 1].hi = sz;
		}
		coords[sz++].first = coords[i].first;
	}
	/* Sweep-Line */
	last = ls[0].start;
	for ( i = 0; i < ls.size(); i++ ) {
		area += ( ls[i].start - last ) *
				amount[1];
		last = ls[i].start;
		update( 1, 0, sz - 1, ls[i].lo + 1,
				ls[i].hi, ls[i].flag );
	}
	printf( "%lld\n", area );
}

