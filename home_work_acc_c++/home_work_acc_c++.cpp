#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

//习题3-2 

using namespace std;
int main()
{
	double x;
	vector<double> homework;
	while (cin >> x) {
		homework.push_back(x);
	}
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	int num;
	if (size < 4) {
		cout << "You must enter more than 4 numbers!" << endl;
		return 1;
	}else if(size % 4 != 0) {
		cout << "Count of your numbers must be 4 "
			"or multiple of 4!" << endl;
		return 1;
	}else {
		num = size / 4;
	}
	sort(homework.begin(),homework.end(),greater<double>());
	for (int i = 0; i < size; i+=num) {
		for (int j = 0; j < num; ++j) {
			cout << homework[i + j] << "," ;
		}
		cout <<  endl;
	}
	
	return 0;
}