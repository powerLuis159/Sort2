#pragma once
#include "Buscador.h"
class Heap :
    public Buscador
{
	void inline static flotar(std::vector<int> &arr, int pos);
	void inline static hundir(std::vector<int>& arr, int pos);
	void static crear_heap(std::vector<int> &array);
	void static ordenar_heap(std::vector<int> &array);
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

