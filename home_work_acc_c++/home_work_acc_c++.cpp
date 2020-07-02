#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <istream>
#include <stdexcept>
#include "median.h"
//4.1

using namespace std;
struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
istream read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {
		cout << setw(maxlen + 1) << students[i].name;
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}