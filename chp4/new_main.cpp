#include<iostream>
#include<ios>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<stdexcept>
#include"Student_info.h"
#include"grade.h"

using namespace std;
typedef vector<double>::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;
istream& read_hw(istream&, vector<double>&);

double median(vector<double>);
int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	cout << "For every student, enter: " << endl <<
		"Name Midterm Final HW1,HW2..." << endl;
	
	while (read(cin, record))
	{
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (si_sz i = 0;
		i != students.size(); ++i)
	{
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << "Final grade: " << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;

	}
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



