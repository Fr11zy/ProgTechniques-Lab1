/**
 * @file sort_alg.h
 * @brief Объявление функций сортировки.
 */
#ifndef SORTALG_H
#define SORTALG_H

#include <vector>
#include "passenger.h"


/**
 * @brief Сортировка пузырьком
 * @param arr Ссылка на вектор для сортировки
 */
void bubbleSort(std::vector<Passenger>& arr);

/**
 * @brief Сортировка простой вставкой
 * @param arr Ссылка на вектор для сортировки
 */
void insertionSort(std::vector<Passenger>& arr);

/**
 * @brief Пирамидальная сортировка
 * @param arr Ссылка на вектор для сортировки
 */
void heapSort(std::vector<Passenger>& arr);

#endif // SORTALG_H