//
// Created by will on 9/15/25.
//

#ifndef WINTERVAL_WINTERVAL_H
#define WINTERVAL_WINTERVAL_H
#include <cstdint>
#include <string>

/**
 * @brief Intervals defined with support for operator overloading.
 * Intended for use in simple numeric abstract interpretation.
 *
 * @author Will Morris
 */
class Winterval {
public:
    /**
     * @param min minimum value in interval, inclusive.
     * @param max Maximum value in interval, inclusive.
     */
    Winterval(double min, double max);
    ~Winterval();

    /*
     * Accessors
     */
    double min() const;
    double max() const;
    std::string to_string() const;

    /*
     * Overloaded numeric operations
     */
    Winterval operator+(const Winterval& rhs) const;
    Winterval operator-(const Winterval& rhs) const;
    Winterval operator*(const Winterval& rhs) const;
    Winterval operator/(const Winterval& rhs) const;

    /*
     * Other numeric functions.
     */
    Winterval tanh() const;

    /**
     * Compute an interval to some constant power.
     * @param power Power to raise the interval to.
     * Note that we require unsigned integer powers to conform with the standards of interval arithmetic.
     *
     * @return a new interval equal to this one raised to power
     */
    Winterval pow(uint32_t power) const;

    /**
     * @brief Inclusive bounds check.
     * @param value Value to check if in interval
     * @return Whether value is in the interval.
     */
    bool contains(double value) const;
private:
    double _min;
    double _max;
};


#endif //WINTERVAL_WINTERVAL_H