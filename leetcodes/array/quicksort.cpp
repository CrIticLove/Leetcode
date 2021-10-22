#include <vector>
#include <iostream>
using namespace std;

void quicksort(vector<int> &vec, int left, int right);

int main()
{
	vector<int> v = {5, 7, 8, 6, 9, 4, 2, 3, 1};
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << "  ";
	}
	cout << endl;
	quicksort(v, 0, v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << "  ";
	}
	return 0;
}

void quicksort(vector<int> &vec, int left, int right)
{
	if (right - left < 2)
	{
		return;
	}

	int j = right;

	int flag = left;
	int i;
	for (i = left + 1; i < j; ++i)
	{
		if (vec[i] > vec[flag])
		{
			j--;
			swap(vec[i], vec[j]);
			i--;
		}
	}
	swap(vec[i - 1], vec[flag]);
	quicksort(vec, left, i - 1);
	quicksort(vec, i, right);
}