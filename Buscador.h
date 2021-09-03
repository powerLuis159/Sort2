#pragma once
#include <vector>
class Buscador
{
public:
	// devuelve los valores m�s altos.
	std::vector<int> virtual nlargest(int n, std::vector<int> array)=0;
	// devuelve los valores m�s bajos.
	std::vector<int> virtual nsmallest(int n, std::vector<int> array)=0;
	//devuelve el elemento m�s alto
	int virtual topk_element(int n, std::vector<int> array)=0;
	//devuelve el elemento m�s bajo
	int virtual bottomk_element(int n, std::vector<int> array)=0;
};

