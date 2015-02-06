// CreateTests.c++

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;
int Collatz_find_max (int i, int j);
int collatz_eval (int i, int j);
void createTest ()
{
	int amount = 0;
	int max = Collatz_find_max (1, 999999);
	for (;amount < 100; amount+=2)
	{
		if ((max % 2) == 0)
		{

			max = max / 2;
        }
        else
        {
            max = max*3 + 1;
        }
		cout << max + 50  << " " << max - 50 << endl;
		cout << max - 100 << " " << max + 100 << endl;
	}
}

int collatz_eval (int i, int j) {
    int max = 1;
    assert ( i > 0);
    assert ( j > 0);
    //assert ( i <= j );
    assert ( i <= 1000000);
    assert ( j <= 1000000);
 
    for (; i < j;i++)
    {
	int n = i;
	int c = 1;
    	while (n > 1) {
            if ((n % 2) == 0)
                n = n/2;
            else
                n = 3*n + 1;
        ++c;}
	assert ( c != 0);
  	if ( c > max)
	    max = c;
    }
    assert (max != 0);
    return max;}

int Collatz_find_max (int i, int j) {
    int max = 1;
    assert ( i > 0);
    assert ( j > 0);
    assert ( i <= 1000000);
    assert ( j <= 1000000);
 	int maxv = i;
    for (; i < j;i++)
    {
		int n = i;
		int c = 1;
    	while (n > 1) {
    		//cout << "infinite"<<endl;
            if ((n % 2) == 0)
                n = n/2;
            else
                n = 3*n + 1;
        ++c;}
		assert ( c != 0);
  		if ( c > max)
  		{
	    	max = c;
	   		maxv = i;
    	}
	}
    assert (max != 0);
    return maxv;}

int main () {
    createTest();
    return 0;}