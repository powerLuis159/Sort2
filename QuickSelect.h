#pragma once
#include "Buscador.h"
class QuickSelect :
    public Buscador
{
	int static partition(std::vector<int> &arr, int piv_index, bool ascendente);
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

