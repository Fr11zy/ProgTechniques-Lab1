/**
 * @file passenger.h
 * @brief Описание структуры данных пассажира и перегрузка операторов сравнения.
 */
#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

/**
 * @struct Passenger
 * @brief Данные о пассажире авиарейса (Вариант 11).
 */

struct Passenger {
    int flightNumber;       
    std::string flightDate; 
    std::string fullName;    
    std::string seatNumber; 

    /**
     * @brief Перегрузка оператора <
     * @details Сравнение по полям: дата рейса -> номер рейса -> ФИО -> номер места.
     */
    bool operator<(const Passenger& p) const {
        if (flightDate != p.flightDate) return flightDate < p.flightDate;
        if (flightNumber != p.flightNumber) return flightNumber < p.flightNumber;
        if (fullName != p.fullName) return fullName < p.fullName;
        return seatNumber < p.seatNumber;
    }

    bool operator>(const Passenger& p) const { return p < *this; }
    bool operator<=(const Passenger& p) const { return !(*this > p); }
    bool operator>=(const Passenger& p) const { return !(*this < p); }
    bool operator==(const Passenger& p) const {
        return flightDate == p.flightDate && flightNumber == p.flightNumber &&
               fullName == p.fullName && seatNumber == p.seatNumber;
    }
    bool operator!=(const Passenger& p) const { return !(*this == p);}
};

#endif // PASSENGER_H