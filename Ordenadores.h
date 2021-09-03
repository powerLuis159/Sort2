#pragma once
#include <vector>
class Ordenadores
{
public:
	// ordenamiento usando quicksort
	void static sort(std::vector<int> &arr);
	// devuelve los valores más altos.
	std::vector<int> nlargest(int n, std::vector<int> array);
	// devuelve los valores más bajos.
	std::vector<int> nsmallest(int n, std::vector<int> array);
	//devuelve el elemento más alto
	int topk_element(int n, std::vector<int> array);
	//devuelve el elemento más bajo
	int bottomk_element(int n, std::vector<int> array);
};

