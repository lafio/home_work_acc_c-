﻿#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	cout << "Please input your name:";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	cout << "Please enter your midterm and final exam grades:";
	double midterm, final;
	cin >> midterm >> final;
	cout << "Enter all your homework grades,"
		"followed by end-of-file:";
	double x;
	vector<double> homework;
	while (cin >> x) {
		homework.push_back(x);
	}
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades."
			"Please try again." << endl;
		return 1;
	}
	sort(homework.begin(),homework.end());
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
		: homework[mid];
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
	return 0;
}