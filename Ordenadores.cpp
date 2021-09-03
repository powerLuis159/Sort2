#include "Ordenadores.h"


// ordenamiento usando quicksort
void Ordenadores::sort(std::vector<int> &arr)
{
	if (arr.size()<=1)
	{
		return;
	}

	//escogemos un pivote
	int pivote = arr[0];
	std::vector<int> left, right;
	for (int var: arr)
	{
		if (var < pivote)
			left.push_back(var);
		else if(var>pivote)
			right.push_back(var);
	}
	sort(left);
	sort(right);
	left.push_back(pivote);
	left.insert(left.end(), right.begin(), right.end());
	arr = left;
	return;

}


// devuelve los valores más altos.
std::vector<int> Ordenadores::nlargest(int n, std::vector<int> array)
{
	// TODO: Agregar aquí el código de implementación.
	return std::vector<int>();
}

std::vector<int> Ordenadores::nsmallest(int n, std::vector<int> array)
{
	return std::vector<int>();
}

int Ordenadores::topk_element(int n, std::vector<int> array)
{
	return 0;
}

int Ordenadores::bottomk_element(int n, std::vector<int> array)
{
	return 0;
}
