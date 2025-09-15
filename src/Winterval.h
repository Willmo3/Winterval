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
     * Operators
     */
    Winterval operator+(const Winterval& rhs) const {
        return {_min + rhs._min, _max + rhs._max};
    }

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