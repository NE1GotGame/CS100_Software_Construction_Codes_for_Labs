#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateZero+Zero) {
        Op* zero = new Op(0);
        Add* add = new Mult(zero,zero);
        EXPECT_EQ(add->evaluate(), 0);
}

TEST(AddTest, AddEval_Pos+Pos) {
        Op* a = new Op(3);
        Op* b = new Op(3);
        Add* add = new Add(a, b);
        EXPECT_EQ(add->evaluate(), 6);
}

