#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (n <= 2)
			cout << 1 << endl;
		else
		{
			n -= 2;
			cout << n / k + (n % k != 0) +1 << endl;
		}
	}
}
