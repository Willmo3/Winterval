//
// Created by will on 9/15/25.
//

#include "Winterval.h"

/*
 * Constructors
 */
Winterval::Winterval(double min, double max): _min(min), _max(max) {}
Winterval::~Winterval() = default;

/*
 * Accessors
 */
double Winterval::min() const {
    return _min;
}
double Winterval::max() const {
    return _max;
}
std::string Winterval::to_string() const {
    return std::to_string(_min) + " " + std::to_string(_max);
}

/*
 * Operators
 */
Winterval Winterval::operator+(const Winterval &rhs) const {
    return {_min + rhs._min, _max + rhs._max};
}
Winterval Winterval::operator-(const Winterval &rhs) const {
    return {_min - rhs._max, _max - rhs._min};
}


/*
 * Predicates
 */
bool Winterval::contains(double value) const {
    return value >= _min && value <= _max;
}
