#include "gtest/gtest.h"
#include "Methods.h"

TEST(operatorSum, expectedSum) {
    ComplexNumber a, b, sum;

    //1-ая проверка
    a.real = 6.9;
    a.imaginary = 0;

    b.real = 0;
    b.imaginary = 9.6;
    sum = a + b;
    EXPECT_DOUBLE_EQ(sum.real, 6.9);
    EXPECT_DOUBLE_EQ(sum.imaginary, 9.6);

    a.real = -25.52;
    a.imaginary = -14.88;
    sum += a;
    EXPECT_DOUBLE_EQ(sum.real, -18.62);
    EXPECT_DOUBLE_EQ(sum.imaginary, -5.28);
}

TEST(operatorSub, expectedSub) {
    ComplexNumber a, b, sub;
    a.real = 13.87;
    a.imaginary = 7;

    b.real = -0.31;
    b.imaginary = 4.01;
    sub = a - b;
    EXPECT_DOUBLE_EQ(sub.real, 14.18);
    EXPECT_DOUBLE_EQ(sub.imaginary, 2.99);

    a.real = 228;
    a.imaginary = -0.337;
    sub -= a;
    EXPECT_DOUBLE_EQ(sub.real, -213.82);
    EXPECT_DOUBLE_EQ(sub.imaginary, 3.327);

    a.real = -213.82;
    a.imaginary = 0.327;
    sub -= a;
    EXPECT_DOUBLE_EQ(sub.real, 0);
    EXPECT_DOUBLE_EQ(sub.imaginary, 3);
}

TEST(operatorMul, expectedMul) {
    ComplexNumber a, b, Mul;
    a.real = 2;
    a.imaginary = 3;
    b.real = 5;
    b.imaginary = -7;
    Mul = a * b;
    EXPECT_DOUBLE_EQ(Mul.real, 31);
    EXPECT_DOUBLE_EQ(Mul.imaginary, 1);

    a.real = 0;
    a.imaginary = -2;
    Mul *= a;
    EXPECT_DOUBLE_EQ(Mul.real, 2);
    EXPECT_DOUBLE_EQ(Mul.imaginary, -62);
}

TEST(operatorDivision, expectedDivision) {
    ComplexNumber a, b, result;
    a.real = 1;
    a.imaginary = 3;

    b.real = 1;
    b.imaginary = 1;
    result = a / b;
    EXPECT_DOUBLE_EQ(result.real, 2);
    EXPECT_DOUBLE_EQ(result.imaginary, 1);

    a.real = 1;
    a.imaginary = 3;
    result /= a;
    EXPECT_DOUBLE_EQ(result.real, 0.5);
    EXPECT_DOUBLE_EQ(result.imaginary, -0.5);
}

TEST(operatorDivision, expectedDivisionByZeroException) {
    ComplexNumber a, b, c;

    a.real = -10;
    a.imaginary = 20;

    b.real = 0;
    b.imaginary = 0;

    std::string err;
    try {
        c = a / b;
    }     catch (std::logic_error& exception) {
        //testing::internal::CaptureStdout();
        err = exception.what();
    }

    EXPECT_EQ(err, "Выражение делится на ноль!");

}

TEST(operatorOut, expectedOutput) {
    ComplexNumber a;

    a.real = 0;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "0\n");

    a.real = 121212.32;
    a.imaginary = 69;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "121212.32+69i\n");

    a.real = -121212.32;
    a.imaginary = -69;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-121212.32-69i\n");

    a.real = 525.9;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "525.9\n");

    a.real = -525.9;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-525.9\n");

    a.real = 0;
    a.imaginary = 1137.4;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1137.4i\n");

    a.real = 0;
    a.imaginary = -1137.4;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1137.4i\n");

    a.real = 1;
    a.imaginary = 1;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1+i\n");

    a.real = -1;
    a.imaginary = -1;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1-i\n");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}