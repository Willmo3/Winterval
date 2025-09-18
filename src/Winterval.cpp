//
// Created by will on 9/15/25.
//

#include "Winterval.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
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

/*
 * Winterval binary operations.
 */
bool Winterval::operator==(Winterval rhs) const {
    return _min == rhs._min && _max == rhs._max;
}
Winterval Winterval::operator+(Winterval rhs) const {
    return {_min + rhs._min, _max + rhs._max};
}
Winterval Winterval::operator-(Winterval rhs) const {
    return {_min - rhs._max, _max - rhs._min};
}
Winterval Winterval::operator*(Winterval rhs) const {
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
Winterval Winterval::operator/(Winterval rhs) const {
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
 * Winterval scalar operations.
 */
Winterval Winterval::operator+(double rhs) const {
    return {_min + rhs, _max + rhs};
}
Winterval Winterval::operator-(double rhs) const {
    return {_min - rhs, _max - rhs};
}
Winterval Winterval::operator*(double rhs) const {
    return {_min * rhs, _max * rhs};
}
Winterval Winterval::operator/(double rhs) const {
    if (rhs == 0) {
        return {_min * INFINITY, _max * INFINITY};
    }
    return {_min / rhs, _max / rhs};
}

/*
 * Other numeric operations
 */
Winterval Winterval::tanh() const {
    return { std::tanh(_min), std::tanh(_max) };
}
Winterval Winterval::pow(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Attempted interval exponentiation with negative power!");
    }
    // Any values to the 0 power = 1, hence any interval to this power will be reduced to this space.
    if (power == 0) {
        return {1, 1};
    }

    // Exponentiation over an odd power is monotonic.
    if (power % 2 == 1) {
        return { std::pow(_min, power), std::pow(_max, power) };
    }

    // Otherwise, we have an even power.

    // Start with a sound bound for the n-1st exponentiation.
    auto odd_subinterval = Winterval(std::pow(_min, power - 1), std::pow(_max, power - 1));
    // Then, perform the last operation using the general rules for interval multiply.
    return odd_subinterval * Winterval(_min, _max);
}

/*
 * Predicates
 */
bool Winterval::contains(double value) const {
    return value >= _min && value <= _max;
}

/*
 * Operators
 */
std::ostream& operator<<(std::ostream& os, Winterval rhs) {
    os << "[" << std::to_string(rhs.min()) << ", " << std::to_string(rhs.max()) << "]";
    return os;
}