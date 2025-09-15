//
// Created by will on 9/15/25.
//

#include "Winterval.h"

#include <algorithm>
#include <cmath>
#include <vector>

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
Winterval Winterval::operator*(const Winterval &rhs) const {
    double values[4];
    values[0] = _min * rhs._min;
    values[1] = _max * rhs._min;
    values[2] = _min * rhs._max;
    values[3] = _max * rhs._max;

    return{
        *std::min_element(values, values + 4),
        *std::max_element(values, values + 4),
    };
}
Winterval Winterval::operator/(const Winterval &rhs) const {
    std::vector<double> candidate_values;

    // Edge case: [0,0] defines only the value 0 -- not one infinitesimal more.
    // We return the interval 0, 0 in this case.
    if (rhs._min == rhs._max && rhs._min == 0) {
        return { 0, 0 };
    }

    // First, check if 0 in interval.
    if (rhs._max == 0) {
        // if max = 0, approaching from left -- negative infinitesimal
        // negative / -inf = inf
        if (_min < 0) {
            candidate_values.push_back(INFINITY);
        }
        // positive / -inf = -inf
        if (_max > 0) {
            candidate_values.push_back(-INFINITY);
        }
    } else if (rhs.contains(0)) {
        // negative / inf = -inf
        if (_min < 0) {
            candidate_values.push_back(-INFINITY);
        }
        // positive / inf = inf
        if (_max > 0) {
            candidate_values.push_back(INFINITY);
        }
    }

    // We now add the boundaries of a / the boundaries of b to the interval, as with multiplication.
    // Skip zero boundaries, as we will have already covered this.
    if (rhs._min != 0) {
        candidate_values.push_back(_min / rhs._min);
        candidate_values.push_back(_max / rhs._min);
    } else if (rhs._max != 0) {
        candidate_values.push_back(_min / rhs._max);
        candidate_values.push_back(_max / rhs._max);
    }

    return {
        *std::ranges::min_element(candidate_values),
        *std::ranges::max_element(candidate_values),
    };
}

/*
 * Predicates
 */
bool Winterval::contains(double value) const {
    return value >= _min && value <= _max;
}
