#pragma once
#include <vector>
class Ordenadores
{
public:
	// ordenamiento usando quicksort
	void static sort(std::vector<int> &arr);
	// devuelve los valores m�s altos.
	std::vector<int> nlargest(int n, std::vector<int> array);
	// devuelve los valores m�s bajos.
	std::vector<int> nsmallest(int n, std::vector<int> array);
	//devuelve el elemento m�s alto
	int topk_element(int n, std::vector<int> array);
	//devuelve el elemento m�s bajo
	int bottomk_element(int n, std::vector<int> array);
};

