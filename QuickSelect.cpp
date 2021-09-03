#include "QuickSelect.h"

int QuickSelect::partition(std::vector<int> &arr, int piv_index, bool ascendente)
{
	int ultimo = arr.size() - 1;
	int valor_pivot = arr[piv_index];
	arr[piv_index] = arr[ultimo];
	arr[ultimo] = valor_pivot;
	int storeindex = 0;
	if (ascendente)
	{
		for (size_t i = 0; i < ultimo; i++)
		{
			if (arr[i] < valor_pivot)
			{
				int temp = arr[storeindex];
				arr[storeindex] = arr[i];
				arr[i] = temp;
				storeindex++;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < ultimo; i++)
		{
			if (arr[i] > valor_pivot)
			{
				int temp = arr[storeindex];
				arr[storeindex] = arr[i];
				arr[i] = temp;
				storeindex++;
			}
		}
	}
	
	int temp = arr[ultimo];
	arr[ultimo] = arr[storeindex];
	arr[storeindex] = temp;
	return storeindex;
}

std::vector<int> QuickSelect::nlargest(int n, std::vector<int> array)
{
	if (array.size() == 0)
	{
		return array;
	}
	if (array.size() == 1)
	{
		return array;
	}
	int pivot_index = array.size() / 2;
	pivot_index = partition(array, pivot_index, false);
	std::vector<int> v(array.begin(), array.begin() + pivot_index);
	if (n == pivot_index)
	{
		return v;
	}
	else if (n < pivot_index)
	{
		return nlargest(n, v);
	}
	else
	{
		std::vector<int> v2(array.begin() + pivot_index, array.end());
		v2 = nlargest(n - pivot_index, v2);
		v.insert(v.end(), v2.begin(), v2.end());
		return v;
	}
	return std::vector<int>();
}

std::vector<int> QuickSelect::nsmallest(int n, std::vector<int> array)
{
	if (array.size() == 0)
	{
		return array;
	}
	if (array.size() == 1)
	{
		return array;
	}
	int pivot_index = array.size() / 2;
	pivot_index = partition(array, pivot_index, true);
	std::vector<int> v(array.begin(), array.begin() + pivot_index);
	if (n == pivot_index)
	{
		return v;
	}
	else if (n < pivot_index)
	{
		return nsmallest(n, v);
	}
	else
	{
		std::vector<int> v2(array.begin() + pivot_index, array.end());
		v2 = nsmallest(n - pivot_index, v2);
		v.insert(v.end(), v2.begin(), v2.end());
		return v;
	}
	return std::vector<int>();
}

int QuickSelect::topk_element(int n, std::vector<int> array)
{
	if (array.size() == 0)
	{
		return -1;
	}
	if (array.size() == 1)
	{
		return array[0];
	}
	int pivot_index = array.size() / 2;
	pivot_index = partition(array, pivot_index, false);
	if (n == pivot_index)
	{
		return array[n];
	}
	else if (n < pivot_index)
	{
		std::vector<int> v(array.begin(), array.begin() + pivot_index);
		return topk_element(n, v);
	}
	else
	{
		std::vector<int> v(array.begin() + pivot_index, array.end());
		return topk_element(n - pivot_index, v);
	}
	return 0;
}

int QuickSelect::bottomk_element(int n, std::vector<int> array)
{
	if (array.size()==0)
	{
		return -1;
	}
	if (array.size()==1)
	{
		return array[0];
	}
	int pivot_index = array.size() / 2;
	pivot_index = partition(array, pivot_index,true);
	if (n==pivot_index)
	{
		return array[n];
	}
	else if (n < pivot_index)
	{
		std::vector<int> v(array.begin(), array.begin() + pivot_index);
		return bottomk_element(n, v);
	}
	else
	{
		std::vector<int> v(array.begin()+pivot_index, array.end());
		return bottomk_element(n-pivot_index, v);
	}
    return 0;
}
