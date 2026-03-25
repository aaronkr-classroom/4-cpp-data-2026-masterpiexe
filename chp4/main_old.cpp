#include<iostream>
#include<ios>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;
typedef vector<double>::size_type vec_sz;
istream& read_hw(istream&, vector<double>&);
double grade(double, double, const vector<double>&);
double grade(double, double, double);
double median(vector<double> );
int main()
{
	string name;
	cin >> name;
	cout << "hello, " << name << "!" << endl;

	cout << "Midterm + Final grades: ";
	double midterm, final;
	cin >> midterm >> final;

	vector<double> homework;

	read_hw(cin, homework);


	double final_grade = grade(midterm,final,homework);
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3) << final_grade << setprecision(prec) << endl;

	return 0;
}
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		hw.clear();

		double x;
		while (in >> x)
		{
			hw.push_back(x);
		}
		in.clear();

	}
	return in;
}
double grade(double mid, double fin, const vector<double>& hw)
{
	if (hw.size() == 0)
	{
		throw domain_error("no homework!");

		return grade(mid, fin, median(hw));
	}
}
double grade(double midterm, double final, double homework)
{
	return midterm * 0.2 + final * 0.4 + homework + 0.4;
}
double median(vector<double> vec)
{
	vec_sz size = vec.size();
	if (size == 0)
	{
		throw domain_error("Median of empty vector!");
		return 1;
	}
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0
		? (vec[mid] + vec[mid - 1]) / 2//return value if true
		: vec[mid];//return value if false
}
