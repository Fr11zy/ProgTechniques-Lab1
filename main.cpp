/**
 * @file main.cpp
 * @brief Главный файл тестирования алгоритмов сортировки.
 */
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "passenger.h"
#include "sorts.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Загрузка данных из input.csv..." << endl;
    vector<Passenger> allData = readData("input.csv");
    if (allData.empty()) return 1;

    vector<int> sizes = {100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000};
    ofstream results("sort_times.csv");
    results << "Size,Bubble,Insertion,Heap,StdSort\n";

    cout << "\nБенчмарк запущен:\n";
    cout << setw(10) << "Size" << setw(15) << "Bubble" << setw(15) << "Insertion" 
         << setw(15) << "Heap" << setw(15) << "std::sort" << endl;

    for (int n : sizes) {
        if (n > allData.size()) break;
        
        vector<Passenger> dataSlice(allData.begin(), allData.begin() + n);
        double timeBubble = -1, timeInsert = -1;

        // Bubble Sort 
        if (n <= 25000) {
            vector<Passenger> testData = dataSlice;
            auto start = high_resolution_clock::now();
            bubbleSort(testData);
            auto stop = high_resolution_clock::now();
            timeBubble = duration_cast<milliseconds>(stop - start).count();
        }

        // Insertion Sort
        if (n <= 25000) {
            vector<Passenger> testData = dataSlice;
            auto start = high_resolution_clock::now();
            insertionSort(testData);
            auto stop = high_resolution_clock::now();
            timeInsert = duration_cast<milliseconds>(stop - start).count();
        }

        // Heap Sort
        vector<Passenger> testDataHeap = dataSlice;
        auto startH = high_resolution_clock::now();
        heapSort(testDataHeap);
        auto stopH = high_resolution_clock::now();
        double timeHeap = duration_cast<milliseconds>(stopH - startH).count();

        // std::sort
        vector<Passenger> testDataStd = dataSlice;
        auto startS = high_resolution_clock::now();
        sort(testDataStd.begin(), testDataStd.end());
        auto stopS = high_resolution_clock::now();
        double timeStd = duration_cast<milliseconds>(stopS - startS).count();

        // Сохраним отсортированный образец
        if (n == 1000) writeData("sorted_output.csv", testDataStd);

        cout << setw(10) << n << setw(15) << timeBubble << setw(15) << timeInsert 
             << setw(15) << timeHeap << setw(15) << timeStd << endl;
             
        results << n << "," << timeBubble << "," << timeInsert << "," << timeHeap << "," << timeStd << "\n";
    }

    results.close();
    cout << "\nРезультаты сохранены в sort_times.csv" << endl;
    return 0;
}