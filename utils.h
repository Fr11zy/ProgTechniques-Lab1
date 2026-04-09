/**
 * @file utils.h
 * @brief Утилиты для чтения и записи данных из CSV.
 */
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "passenger.h"

std::vector<Passenger> readData(const std::string& filename);
void writeData(const std::string& filename, const std::vector<Passenger>& data);

#endif // UTILS_H