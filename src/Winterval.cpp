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

/*
 * Predicates
 */
bool Winterval::contains(double value) const {
    return value >= _min && value <= _max;
}
