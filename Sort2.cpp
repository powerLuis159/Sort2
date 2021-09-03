// Sort2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "Ordenadores.h"
#include "Sort.h"
#include "QuickSelect.h"
#include "Heap.h"

int main()
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,1'000'000);
    //prueba con 2 a la n
    int n = pow(2, 8);
    //numero de pruebas
    int n_t = 100;
    std::vector<int> arreglo(n, 0);
    std::uniform_int_distribution<int> dist(1,1000);
    //indices K de busqueda
    std::vector<int> ks;
    for (size_t i = 0; i < n_t; i++)
    {
        ks.push_back(dist(generator));
    }

    std::chrono::steady_clock::time_point ts1, ts2, tq1, tq2, th1, th2;
    std::chrono::duration<double> tts, ttq, tth;
    auto time = std::chrono::high_resolution_clock::now();
    tts = ttq = tth = std::chrono::duration_cast<std::chrono::duration<double>>(time - time);
    //Testing
    for (size_t i = 0; i < n_t; i++)
    {
        std::vector<int> arr_temp(n,0);
        for (int& val : arr_temp)
        {
            val = distribution(generator);
        }

        ts1 = std::chrono::high_resolution_clock::now();
        auto result = Sort::bottomk_element(ks[i], arr_temp);
        ts2 = std::chrono::high_resolution_clock::now();
        tts += std::chrono::duration_cast<std::chrono::duration<double>>(ts2 - ts1);

        tq1 = std::chrono::high_resolution_clock::now();
        auto result2 = QuickSelect::bottomk_element(ks[i], arr_temp);
        tq2 = std::chrono::high_resolution_clock::now();
        ttq += std::chrono::duration_cast<std::chrono::duration<double>>(tq2 - tq1);

        th1 = std::chrono::high_resolution_clock::now();
        auto result3 = Heap::bottomk_element(ks[i], arr_temp);
        th2 = std::chrono::high_resolution_clock::now();
        tth += std::chrono::duration_cast<std::chrono::duration<double>>(th2 - th1);
    }
   
    std::cout << "Sort: " << tts.count()*10 << "segundos" << std::endl;
    

    std::cout << "Quick_select: " << ttq.count()*10 << "segundos" << std::endl;
    
 
    std::cout << "Heap: " << tth.count()*10 << "segundos" << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
