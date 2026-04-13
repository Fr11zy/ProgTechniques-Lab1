/**
 * @file utils.cpp
 * @brief Реализация утилит для работы с файлами.
 */
#include "utils.h"
#include <fstream>
#include <iostream>
#include <cstdio>

std::vector<Passenger> readData(const std::string& filename) {
    std::vector<Passenger> data;
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << "\n";
        return data;
    }

    char buffer[512];
    if (fgets(buffer, sizeof(buffer), file) == nullptr) {
        fclose(file);
        return data;
    }

    char date[256];
    int number;
    char name[256];
    char seat[256];

    while (fscanf(file, "%255[^,],%d,%255[^,],%255[^\r\n] ", date, &number, name, seat) == 4) {
        Passenger p;
        p.flightDate = date;
        p.flightNumber = number;
        p.fullName = name;
        p.seatNumber = seat;
        data.push_back(p);
    }

    fclose(file);
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