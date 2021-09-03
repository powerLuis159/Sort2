#include "Heap.h"

inline void Heap::flotar(std::vector<int> &arr, int pos)
{
    while (pos > 0 && arr[(pos-1) / 2] < arr[pos])
    {
        int temp = arr[(pos-1) / 2];
        arr[(pos-1) / 2] = arr[pos];
        arr[pos] = temp;
        pos = (pos-1) / 2;
    }
}

inline void Heap::hundir(std::vector<int>& arr, int pos)
{
    int idx = 0;
    int left,right;
    while (idx <= (pos - 1) / 2)
    {
        left = idx * 2 + 1;
        right = idx * 2 + 2;
        if (left<pos && arr[idx] < arr[left])
        {
            if (right < pos && arr[left] < arr[right])
            {
                int temp = arr[idx];
                arr[idx] = arr[right];
                arr[right] = temp;
                idx = right;
            }
            else
            {
                int temp = arr[idx];
                arr[idx] = arr[left];
                arr[left] = temp;
                idx = left;
            }
        }
        else
        {
            if (right < pos && arr[idx] < arr[right])
            {
                int temp = arr[idx];
                arr[idx] = arr[right];
                arr[right] = temp;
                idx = right;
            }
            else
            {
                return;
            }
        }
    }
}

void Heap::crear_heap(std::vector<int> &array)
{
    for (int tamaño=0;tamaño<array.size();tamaño++ )
    {
        flotar(array, tamaño);
    }
    return;
}

void Heap::ordenar_heap(std::vector<int> &array)
{
    for (size_t tamaño = array.size()-1; tamaño > 0; tamaño--)
    {
        //cambiar ultimo por el primero
        int temp = array[0];
        array[0] = array[tamaño];
        array[tamaño] = temp;

        hundir(array, tamaño);
    }
    return;
}

std::vector<int> Heap::nlargest(int n, std::vector<int> array)
{
    crear_heap(array);
    ordenar_heap(array);
    std::vector<int> resultado;
    resultado.insert(resultado.end(), array.end() - n, array.end());
    return resultado;
}

std::vector<int> Heap::nsmallest(int n, std::vector<int> array)
{
    crear_heap(array);
    ordenar_heap(array);
    std::vector<int> resultado;
    resultado.insert(resultado.end(), array.begin(), array.begin() + n);
    return resultado;
}

int Heap::topk_element(int n, std::vector<int> array)
{
    crear_heap(array);
    ordenar_heap(array);
    return array[array.size() - 1 - n];
}

int Heap::bottomk_element(int n, std::vector<int> array)
{
    crear_heap(array);
    ordenar_heap(array);
    return array[n];;
}
