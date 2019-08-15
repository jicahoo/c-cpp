#include <boost/optional.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;
int main()
{
	boost::optional<bool> oEmpty(boost::none), oTrue(true), oFalse(false);
	if (!oEmpty) {
		cout << "None\n" ;
	}
	cout << (oEmpty ? *oEmpty : "none")<< "\n";
	cout <<  *oTrue << "\n";
}
