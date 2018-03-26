#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {

	stack <char> b; //Create a stack to store the chars

	for (auto c : expression) //For-in loop of characters in the string
	{
		//Multiple cases checking to find pairs of brackets
		if (c == '{') 
			b.push('}');
		else if (c == '(')
			b.push(')');
		else if (c == '[')
			b.push(']');

		else {
			//If it isn't one of the cases above, check if the stack is empty.
			//If it is empty, then one of the brackets was found out of order at the start of the string
			//Check if 'c' is equal to the character at the top of the stack
			//If it isn't, then the brackets are out of order; return false;
			if (b.empty() || c != b.top())
				return false;
			//Pop so that b.top() is different and can be checked for the remainder of the string
			b.pop();
		}


	}
	//If no problems were encountered, the stack will be empty at the end
	//Meaning the brackets used were in the correct order and paired correctly
	return b.empty();


}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		string expression;
		cin >> expression;
		bool answer = is_balanced(expression);
		if (answer)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}