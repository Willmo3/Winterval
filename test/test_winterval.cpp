//
// Created by will on 9/30/25.
//

#include <math.h>
#include <gtest/gtest.h>

#include "../lib/cereal/archives/json.hpp"
#include "../src/Winterval.hpp"

TEST(winterval, contains) {
    auto winter = Winterval(0, 2);
    ASSERT_TRUE(winter.contains(0));
    ASSERT_FALSE(winter.contains(-1));
    ASSERT_TRUE(winter.contains(1));
}

TEST(winterval, add) {
    auto left = Winterval(0, 2);
    auto right = Winterval(-2, 1);
    auto sum = left + right;

    ASSERT_EQ(-2, sum.min());
    ASSERT_EQ(3, sum.max());
}

TEST(winterval, sub) {
    auto left = Winterval(0, 2);
    auto right = Winterval(-1, 2);
    auto difference = left - right;

    ASSERT_EQ(-2, difference.min());
    ASSERT_EQ(3, difference.max());
}

TEST(winterval, mul) {
    auto left = Winterval(1, 2);
    auto right = Winterval(-2, 1);
    auto mul = left * right;

    ASSERT_EQ(-4, mul.min());
    ASSERT_EQ(2, mul.max());
}

TEST(winterval, div) {
    auto left = Winterval(-1, 2);
    auto right = Winterval(-2, 1);
    auto div = left / right;

    ASSERT_EQ(-INFINITY, div.min());
    ASSERT_EQ(INFINITY, div.max());

    left = Winterval(0, 2);
    div = left / right;

    ASSERT_EQ(-1, div.min());
    ASSERT_EQ(INFINITY, div.max());

    left = Winterval(-2, 0);
    div = left / right;

    ASSERT_EQ(-INFINITY, div.min());
    ASSERT_EQ(1, div.max());

    right = Winterval(0, 0);
    div = left / right;

    ASSERT_EQ(0, div.min());
    ASSERT_EQ(0, div.max());
}

TEST(winterval, tanh) {
    auto left = Winterval(-1, 4).tanh().tanh();
    ASSERT_NEAR(-0.642015, left.min(), 1e-6);
    ASSERT_NEAR(0.761312, left.max(), 1e-6);
}

TEST(winterval, pow) {
    auto base = Winterval(-1, 4);

    auto pow_0 = base.pow(0);
    ASSERT_EQ(1, pow_0.min());
    ASSERT_EQ(1, pow_0.max());

    auto pow_1 = base.pow(1);
    ASSERT_EQ(-1, pow_1.min());
    ASSERT_EQ(4, pow_1.max());

    auto pow_2 = base.pow(2);
    ASSERT_EQ(-4, pow_2.min());
    ASSERT_EQ(16, pow_2.max());

    auto pow_3 = base.pow(3);
    ASSERT_EQ(-1, pow_3.min());
    ASSERT_EQ(64, pow_3.max());
}

TEST(winterval, scalar) {
    auto base = Winterval(-1, 4);

    auto prod = base * 2;
    ASSERT_EQ(-2, prod.min());
    ASSERT_EQ(8, prod.max());

    auto sum = base + 1;
    ASSERT_EQ(0, sum.min());
    ASSERT_EQ(5, sum.max());

    auto difference = base - 3;
    ASSERT_EQ(-4, difference.min());
    ASSERT_EQ(1, difference.max());

    auto quotient = base / 2;
    ASSERT_EQ(-0.5, quotient.min());
    ASSERT_EQ(2, quotient.max());

    auto div = base / 0;
    ASSERT_EQ(-INFINITY, div.min());
    ASSERT_EQ(INFINITY, div.max());
}

TEST(winterval, abs) {
    auto base = Winterval(-6, 4);
    auto abs = base.abs();

    ASSERT_EQ(0, abs.min());
    ASSERT_EQ(6, abs.max());
}

TEST(winterval, mid) {
    auto base = Winterval(-2, 2);
    ASSERT_EQ(0, base.mid());
}

TEST(winterval, radius) {
    ASSERT_EQ(1, Winterval(0, 2).radius());
    ASSERT_EQ(2, Winterval(-2, 2).radius());
    ASSERT_EQ(1.5, Winterval(0, 3).radius());
    ASSERT_EQ(0, Winterval(0, 0).radius());
}

TEST(winterval, serialize) {
    std::stringstream ss;
    // Scoping necessary to ensure data leaves scope.
    {
        cereal::JSONOutputArchive archive(ss);
        auto w = Winterval(-1, 2);
        archive( w );
    }

    cereal::JSONInputArchive archive(ss);
    Winterval w2 = Winterval(0, 0);
    archive( w2 );
    ASSERT_EQ(-1, w2.min());
    ASSERT_EQ(2, w2.max());
}