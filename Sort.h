#pragma once
#include "Buscador.h"
class Sort :
    public Buscador
{
private:
    void static quick_sort(std::vector<int>& arr);
public:
	// devuelve los valores más altos.
	std::vector<int> static nlargest(int n, std::vector<int> array);
	// devuelve los valores más bajos.
	std::vector<int> static nsmallest(int n, std::vector<int> array);
	//devuelve el elemento más alto
	int static topk_element(int n, std::vector<int> array);
	//devuelve el elemento más bajo
	int static bottomk_element(int n, std::vector<int> array);
};

