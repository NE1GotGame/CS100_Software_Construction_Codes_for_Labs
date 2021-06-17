#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>


class Pow : public Base {
    private:
        Base* base;
        Base* power;
    public:
        Pow(Base* base, Base* power) : base(base), power(power), Base() { this->setValue(evaluate()); }
        virtual double evaluate() { return pow(base->getValue(), power->getValue()); }
        virtual std::string stringify() { return base->stringify() + std::string(" ** ") + power->stringify(); }
        virtual Iterator* create_iterator() { return new BinaryIterator(this); }
        virtual Base* get_left() { return base; }
        virtual Base* get_right() { return power; }
        virtual void accept(CountVisitor* cv) { cv->visit_pow(); }
};

#endif // __POW_HPP__