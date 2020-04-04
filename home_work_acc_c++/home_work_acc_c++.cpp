#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

//习题3-3

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
				boxes[i]++;
				same_word = true;
				break;
			}
		}
		if (same_word == false) {
			words.push_back(x);
			boxes.push_back(1);
		}
	}
	for (int j = 0; j < boxes.size(); ++j) {
		cout << words[j] << ":" << boxes[j] << endl;
	}
	return 0;
}