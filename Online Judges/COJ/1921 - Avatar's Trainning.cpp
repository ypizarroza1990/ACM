#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXC = 150009;

long long N, i, j, last, sz=0;
long long area;

struct event {
    long long start, lo, hi, flag;
    bool operator < ( const event &e ) const { return start < e.start; }
};

vector< event > ls;

/* Segment Tree */
long long times[4 * MAXC], amount[4 * MAXC];
vector< pair< long long , long long > > coords;

    void update( long node, long long lo, long long hi,
    		long long start, long long end, long long value ) {

        if ( lo > end || hi < start || lo > hi )
            return ;

        if ( lo >= start && hi <= end )
            times[node] += value;
        else {
        	long long mid = ( lo + hi ) / 2;
            update( 2 * node, lo, mid,         start, end, value );
            update( 2 * node + 1, mid + 1, hi, start, end, value );
        }

        if ( times[node] == 0 )
             if ( lo == hi )
                  amount[node] = 0;
             else amount[node] = amount[2 * node] + amount[2 * node + 1];
        else amount[node] = coords[hi].first - coords[lo - 1].first;
    }

int main() {

    scanf( "%lld", &N );
    for ( i = 0; i < N; i++ ) {

       long long x1, x2, y1, y2;
        scanf( "%lld %lld %lld %lld", &x1, &x2, &y1, &y2 );

        if ( x1 > x2 ) swap( x1, x2 );
        if ( y1 > y2 ) swap( y1, y2 );

        ls.push_back( (event){ x1, y1, y2, 1 } );
        ls.push_back( (event){ x2, y1, y2, -1 } );
    }

    sort( ls.begin(), ls.end() );

    /* Compress */
    for ( i = 0; i < ls.size(); i++ ) {
        coords.push_back( make_pair( ls[i].lo, i + 1 ) );
        coords.push_back( make_pair( ls[i].hi, -(i + 1) ) );
    }

    sort( coords.begin(), coords.end() );
    for ( i = 0; i < coords.size(); i = j ) {
        for ( j = i; j < coords.size() && coords[j].first == coords[i].first; j++ ) {
            long long idx = coords[j].second;
            if ( idx > 0 )
                 ls[idx - 1].lo = sz;
            else ls[-idx - 1].hi = sz;
        }
        coords[sz++].first = coords[i].first;
    }

    /* Sweep-Line */
    last = ls[0].start;
    for ( i = 0; i < ls.size(); i++ ) {
        area += (unsigned long long)( ls[i].start - last ) * amount[1];
        last = ls[i].start;
        update( 1, 0, sz - 1, ls[i].lo + 1, ls[i].hi, ls[i].flag );
    }

    printf( "%lld\n", area );

    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXC = 150009;

long long N, i, j, last, sz=0;
long long area;

struct event {
    long long start, lo, hi, flag;
    bool operator < ( const event &e ) const { return start < e.start; }
};

vector< event > ls;

/* Segment Tree */
long long times[4 * MAXC], amount[4 * MAXC];
vector< pair< long long , long long > > coords;

    void update( long node, long long lo, long long hi,
    		long long start, long long end, long long value ) {

        if ( lo > end || hi < start || lo > hi )
            return ;

        if ( lo >= start && hi <= end )
            times[node] += value;
        else {
        	long long mid = ( lo + hi ) / 2;
            update( 2 * node, lo, mid,         start, end, value );
            update( 2 * node + 1, mid + 1, hi, start, end, value );
        }

        if ( times[node] == 0 )
             if ( lo == hi )
                  amount[node] = 0;
             else amount[node] = amount[2 * node] + amount[2 * node + 1];
        else amount[node] = coords[hi].first - coords[lo - 1].first;
    }

int main() {

    scanf( "%lld", &N );
    for ( i = 0; i < N; i++ ) {

       long long x1, x2, y1, y2;
        scanf( "%lld %lld %lld %lld", &x1, &x2, &y1, &y2 );

        if ( x1 > x2 ) swap( x1, x2 );
        if ( y1 > y2 ) swap( y1, y2 );

        ls.push_back( (event){ x1, y1, y2, 1 } );
        ls.push_back( (event){ x2, y1, y2, -1 } );
    }

    sort( ls.begin(), ls.end() );

    /* Compress */
    for ( i = 0; i < ls.size(); i++ ) {
        coords.push_back( make_pair( ls[i].lo, i + 1 ) );
        coords.push_back( make_pair( ls[i].hi, -(i + 1) ) );
    }

    sort( coords.begin(), coords.end() );
    for ( i = 0; i < coords.size(); i = j ) {
        for ( j = i; j < coords.size() && coords[j].first == coords[i].first; j++ ) {
            long long idx = coords[j].second;
            if ( idx > 0 )
                 ls[idx - 1].lo = sz;
            else ls[-idx - 1].hi = sz;
        }
        coords[sz++].first = coords[i].first;
    }

    /* Sweep-Line */
    last = ls[0].start;
    for ( i = 0; i < ls.size(); i++ ) {
        area += (unsigned long long)( ls[i].start - last ) * amount[1];
        last = ls[i].start;
        update( 1, 0, sz - 1, ls[i].lo + 1, ls[i].hi, ls[i].flag );
    }

    printf( "%lld\n", area );

    return 0;
}
