// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif
//#include "Collatz.h"

using namespace std;
int cache[999999];

// ------------
// collatz_read
// ------------

int collatz_recur (int n);

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int max = 1;
    cache[0] = 1;
    int y = 1;
    for (;y < 999999; y++)
    {
        cache[y] = 0;
    }
    if (j < i)
    {
	   j = j ^ i;
	   i = j ^ i;
	   j = j ^ i;
    }
    for (; j >= (j + i)/2 && j > 1; j--)
    {
        int justincase = 0;
        if ( j > 999999)
            justincase = collatz_recur (j);
        else if ( cache[j-1] == 0)
	       collatz_recur (j);
        if ( j > 999999 && justincase > max)
            max = justincase;
        if (cache[j-1] > max)
	       max = cache[j-1];
    }
    //cout << "return" << endl;
    return max;
   }


// -------------:
// collatz_recur
// -------------

int collatz_recur (int n)
{
    if (n < 1)
        return 0;
    if (n > 999999)
    {
        //cout << n << endl;
        if (n %2 == 0)
            return 1 + collatz_recur (n/2);
        else
            return 1 + collatz_recur (n*3+1);
    }
    if(cache[n-1] == 0)
    {
        if (n %2 == 0)
            cache[n-1] = 1 + collatz_recur (n/2);
        else
            cache[n-1] = 1 + collatz_recur (n*3 + 1);
    }
    return cache[n-1];
}
// -------------:
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
