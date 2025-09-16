//
// Created by will on 9/15/25.
//

#ifndef WINTERVAL_WINTERVAL_H
#define WINTERVAL_WINTERVAL_H
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
    // TODO: as more flux functions are needed, add them here.
    /**
     * Compute the hyperbolic tangent of an interval.
     * Since tanh is monotonic, it is sufficient to apply it to the lower, upper bounds (i.e. optimal conditions on boundary)
     * @return A new interval whose value is the hyperbolic tangent of this interval.
     */
    Winterval tanh() const;

    /**
     * Compute an interval to some constant power.
     * @param power Power to raise the interval to.
     * Note that for intervals, integer powers should always be nonnegative -- we represent as an int to comply with idiomatic Cpp.
     *
     * @return a new interval equal to this one raised to power
     */
    Winterval pow(int power) const;

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