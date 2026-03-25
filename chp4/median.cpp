#include<vector>
#include<algorithm>
#include<stdexcept>
typedef vector<double>::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;

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
