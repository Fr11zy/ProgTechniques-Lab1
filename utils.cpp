/**
 * @file utils.cpp
 * @brief Реализация утилит для работы с файлами.
 */
#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Passenger> readData(const std::string& filename) {
    std::vector<Passenger> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << "\n";
        return data;
    }

    std::string line, word;
    std::getline(file, line); // Пропуск заголовка

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Passenger p;
        
        std::getline(ss, p.flightDate, ',');
        
        std::getline(ss, word, ',');
        p.flightNumber = std::stoi(word);
        
        std::getline(ss, p.fullName, ',');
        std::getline(ss, p.seatNumber, ',');
        
        data.push_back(p);
    }
    return data;
}

void writeData(const std::string& filename, const std::vector<Passenger>& data) {
    std::ofstream file(filename);
    file << "FlightDate,FlightNumber,FullName,SeatNumber\n";
    for (const auto& p : data) {
        file << p.flightDate << "," << p.flightNumber << "," 
             << p.fullName << "," << p.seatNumber << "\n";
    }
}