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
 * Predicates
 */
bool Winterval::contains(double value) const {
    return value >= _min && value <= _max;
}
