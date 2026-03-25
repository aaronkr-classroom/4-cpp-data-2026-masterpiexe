#pragma once
#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<vector>
#include"Student_info.h"
#include"grade.h"
#include"median.h"



	double grade(double mid, double fin, const vector<double>&hw)
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


#endif
