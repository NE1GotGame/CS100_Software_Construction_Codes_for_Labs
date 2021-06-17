#include "base.hpp"
#include <string>

class Add : public Base {
        private:
                Base* LHS;
                Base* RHS;
        public:
                /*constructer*/
                Add(Base* object1, Base* object2) : Base() {
                        this->LHS = object1;
                        this->RHS = object2;
                }
                /*Member Function*/
                virtual double evaluate() {
                        return LHS->evaluate() +  RHS->evaluate();
                }
                virtual std::string stringify() {
                        return LHS->stringify() + " +  " + RHS->stringify();
                        }
};

