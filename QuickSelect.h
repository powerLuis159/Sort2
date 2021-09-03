#pragma once
#include "Buscador.h"
class QuickSelect :
    public Buscador
{
	int static partition(std::vector<int> &arr, int piv_index, bool ascendente);
public:
	// devuelve los valores m�s altos.
	std::vector<int> static nlargest(int n, std::vector<int> array);
	// devuelve los valores m�s bajos.
	std::vector<int> static nsmallest(int n, std::vector<int> array);
	//devuelve el elemento m�s alto
	int static topk_element(int n, std::vector<int> array);
	//devuelve el elemento m�s bajo
	int static bottomk_element(int n, std::vector<int> array);
};

