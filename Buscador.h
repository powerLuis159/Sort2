#pragma once
#include <vector>
class Buscador
{
public:
	// devuelve los valores más altos.
	std::vector<int> virtual nlargest(int n, std::vector<int> array)=0;
	// devuelve los valores más bajos.
	std::vector<int> virtual nsmallest(int n, std::vector<int> array)=0;
	//devuelve el elemento más alto
	int virtual topk_element(int n, std::vector<int> array)=0;
	//devuelve el elemento más bajo
	int virtual bottomk_element(int n, std::vector<int> array)=0;
};

