#include <iostream>
using namespace std;

void printRLE(string s)
{
	for (int i = 0; s[i] != '\0'; i++) {
		int count = 1;
		while (s[i] == s[i + 1]) {
			i++;
			count++;
		}
		cout << s[i] << count << " ";
	}

	cout << endl;
}

// Driver code
int main()
{
	printRLE("HeeeEELLLLoo");
	printRLE("ccccOddEEE");
	return 0;
}
