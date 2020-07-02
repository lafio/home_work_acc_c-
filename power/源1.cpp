#include <iostream>
using namespace std;

double power(double x, int n) {
	double val = 1.0;
	while (n--)
		val *= x;
	return val;
}

int main() {
	//int value = 0;
	//cout<<"Enter an 8 bit binary number:"
	double pow;
	pow = power(5, 2);
	cout << pow << endl;
	return 0;
}