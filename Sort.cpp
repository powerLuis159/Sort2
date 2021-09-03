#include "Sort.h"

void Sort::quick_sort(std::vector<int>& arr)
{
	if (arr.size() <= 1)
	{
		return;
	}

	//escogemos un pivote
	int pivote = arr[0];
	std::vector<int> left, right;
	for (int var : arr)
	{
		if (var < pivote)
			left.push_back(var);
		else if (var > pivote)
			right.push_back(var);
	}
	quick_sort(left);
	quick_sort(right);
	left.push_back(pivote);
	left.insert(left.end(), right.begin(), right.end());
	arr = left;
	return;
}

std::vector<int> Sort::nlargest(int n, std::vector<int> array)
{
	quick_sort(array);
	std::vector<int> resultado;
	resultado.insert(resultado.end(), array.end()-n, array.end());
	return resultado;
}

std::vector<int> Sort::nsmallest(int n, std::vector<int> array)
{
	quick_sort(array);
	std::vector<int> resultado;
	resultado.insert(resultado.end(), array.begin(), array.begin() + n);
	return resultado;
}

int Sort::topk_element(int n, std::vector<int> array)
{
	quick_sort(array);
	return array[array.size()-1-n];
}

int Sort::bottomk_element(int n, std::vector<int> array)
{
	quick_sort(array);
	return array[n];
}

