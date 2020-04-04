#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

//习题3-4

using namespace std;
int main()
{
	string x;
	vector<string> words;
	vector<double> boxes;
	bool same_word = false;
	cout << "Input a lot of words,enter ctr+z to end!" << endl;
	while (cin >> x) {
		for (int i = 0; i < words.size(); i++) {
			if (x == words[i]) {
				boxes[i] = x.length();
				same_word = true;
				break;
			}
		}
		if (same_word == false) {
			words.push_back(x);
			boxes.push_back(x.length());
		}
	}
	sort(boxes.begin(), boxes.end(), greater<int>());
	cout << "max length string's length:" << boxes[0] << endl;
	int end = boxes.back();
	cout << "min length string's length:" << end << endl;
	return 0;
}