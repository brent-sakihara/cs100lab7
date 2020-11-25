#ifndef FACTORY_TEST
#define FACTORY_TEST

#include "gtest/gtest.h"
#include "factory.hpp"
#include "base.hpp"
//add, multiply, and invalid input

TEST(FactoryTest, FactoryAdd){
	char* test_val[4];
	test_val[0] = "./test";
	test_val[1] = "32";
	test_val[2] = "+";
	test_val[3] = "49";
	Factory* calculator = new Factory();
	Base* point = nullptr;
	point = calculator->parse(test_val, 4);
	EXPECT_EQ(point->evaluate(), 81);
	EXPECT_EQ(point->stringify(), "(32.000000 + 49.000000)");
}

TEST(FactoryTest, FactoryMultiply){
        char* test_val[4];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "*";
        test_val[3] = "49";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 4);
        EXPECT_EQ(point->evaluate(), 1568);
	EXPECT_EQ(point->stringify(), "(32.000000 * 49.000000)");
}

TEST(FactoryTest, FactoryAddMultiplyCombo){
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "+";
        test_val[3] = "49";
	test_val[4] = "*";
	test_val[5] = "2.4";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 6);
        EXPECT_EQ(point->evaluate(), 162);
	EXPECT_EQ(point->stringify(), "((32.000000 + 49.000000) * 2.000000)");
}

TEST(FactoryTest, FactoryAddMultiplyDivideCombo){
        char* test_val[8];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "+";
        test_val[3] = "49";
        test_val[4] = "*";
        test_val[5] = "2.4";
	test_val[6] = "/";
	test_val[7] = "4";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 8);
        EXPECT_NEAR(point->evaluate(), 40.5, 0.000001);
}

TEST(FactoryTest, FactoryAddMultiplyDivideSubtractCombo){
        char* test_val[10];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "+";
        test_val[3] = "49";
        test_val[4] = "*";
        test_val[5] = "2.4";
        test_val[6] = "/";
        test_val[7] = "4";
	test_val[8] = "-";
	test_val[9] = "34";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 10);
        EXPECT_NEAR(point->evaluate(), 6.5, 0.000001);
}

TEST(FactoryTest, FactoryPowMultiplyDivideCombo){
        char* test_val[8];
        test_val[0] = "./test";
        test_val[1] = "32.4";
        test_val[2] = "**";
        test_val[3] = "3";
        test_val[4] = "*";
        test_val[5] = "2.4";
        test_val[6] = "/";
        test_val[7] = "4";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 8);
        EXPECT_NEAR(point->evaluate(), 16384, 0.000001);
	EXPECT_EQ(point->stringify(), "(((32.000000 ** 3.000000) * 2.000000) / 4.000000)");
}

TEST(FactoryTest, FactoryInvalidInputExecutableOnly){
	char* test_val[1];
	test_val[0] = "./test";
	Factory* calculator = new Factory();
	Base* point = nullptr;
	point = calculator->parse(test_val, 1);
	EXPECT_EQ(point, nullptr);
}

TEST(FactoryTest, FactoryInvalidInputWrongExecutableName){
        char* test_val[1];
        test_val[0] = "./hello";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 1);
        EXPECT_EQ(point, nullptr);
}

TEST(FactoryTest, FactoryInvalidInputForNumber){
	char* test_val[8];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "+";
        test_val[3] = "-";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 4);
        EXPECT_EQ(point, nullptr);	
}

TEST(FactoryTest, FactoryInvalidInputForSign) {
	char* test_val[4];
        test_val[0] = "./test";
        test_val[1] = "32";
        test_val[2] = "59.2";
	test_val[3] = "9";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 4);
        EXPECT_EQ(point, nullptr);
}

TEST(FactoryTest, FactoryInvalidInputForSignAndNumbers) {
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "-";
        test_val[2] = "59.2";
        test_val[3] = "+";
	test_val[4] = "24";
	test_val[5] = "*";
        Factory* calculator = new Factory();
        Base* point = nullptr;
        point = calculator->parse(test_val, 6);
        EXPECT_EQ(point, nullptr);
}

TEST(SubtractTest, subTwoOne) {
	Factory* test = new Factory();
	char* test_val[4];
	test_val[0] = "./test";
	test_val[1] = "2";
	test_val[2] = "-";
	test_val[3] = "1";
	Base* p = nullptr;
	p = test->parse(test_val, 4);
	EXPECT_EQ(p->evaluate(), 1);
}

TEST(SubtractTest, subPow) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "2";
        test_val[2] = "-";
        test_val[3] = "1";
	test_val[4] = "**";
        test_val[5] = "5";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 1);
}

TEST(SubtractTest, subPow2) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "2";
        test_val[4] = "**";
        test_val[5] = "3";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 27);
}

TEST(SubtractTest, subPow3) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "8";
        test_val[2] = "-";
        test_val[3] = "1";
        test_val[4] = "**";
        test_val[5] = "2";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 49);
	EXPECT_EQ(p->stringify(), "((8.000000 - 1.000000) ** 2.000000)");
}

TEST(DivideTest, dividePow) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "6";
        test_val[2] = "/";
        test_val[3] = "3";
        test_val[4] = "**";
        test_val[5] = "3";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 8);
}

TEST(DivideTest,divide) {
        Factory* test = new Factory();
        char* test_val[4];
        test_val[0] = "./test";
        test_val[1] = "8";
        test_val[2] = "/";
        test_val[3] = "2";
        Base* p = nullptr;
        p = test->parse(test_val, 4);
        EXPECT_EQ(p->evaluate(), 4);
}

TEST(DivideTest, dividePow2) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "8";
        test_val[2] = "/";
        test_val[3] = "1";
        test_val[4] = "**";
        test_val[5] = "2";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 64);
}

TEST(DivideTest, dividePow3) {
        Factory* test = new Factory();
        char* test_val[8];
        test_val[0] = "./test";
        test_val[1] = "4";
        test_val[2] = "/";
        test_val[3] = "2";
        test_val[4] = "**";
        test_val[5] = "4";
	test_val[6] = "/";
	test_val[7] = "4";
        Base* p = nullptr;
        p = test->parse(test_val, 8);
        EXPECT_EQ(p->evaluate(), 4);
	EXPECT_EQ(p->stringify(), "(((4.000000 / 2.000000) ** 4.000000) / 4.000000)");
}

TEST(DivideTest,pow) {
        Factory* test = new Factory();
        char* test_val[4];
        test_val[0] = "./test";
        test_val[1] = "4";
        test_val[2] = "**";
        test_val[3] = "3";
        Base* p = nullptr;
        p = test->parse(test_val, 4);
        EXPECT_EQ(p->evaluate(), 64);
}

TEST(DivideTest, subDiv) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "9";
        test_val[2] = "-";
        test_val[3] = "1";
        test_val[4] = "/";
        test_val[5] = "2";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 4);
}

TEST(DivideTest, subDiv2) {
        Factory* test = new Factory();
        char* test_val[6];
        test_val[0] = "./test";
        test_val[1] = "10";
        test_val[2] = "/";
        test_val[3] = "5";
        test_val[4] = "-";
        test_val[5] = "2";
        Base* p = nullptr;
        p = test->parse(test_val, 6);
        EXPECT_EQ(p->evaluate(), 0);
}

TEST(DivideTest, subDiv3) {
        Factory* test = new Factory();
        char* test_val[8];
        test_val[0] = "./test";
        test_val[1] = "45";
        test_val[2] = "-";
        test_val[3] = "3";
        test_val[4] = "/";
        test_val[5] = "2";
        test_val[6] = "-";
        test_val[7] = "10";
        Base* p = nullptr;
        p = test->parse(test_val, 8);
        EXPECT_EQ(p->evaluate(), 11);
        EXPECT_EQ(p->stringify(), "(((45.000000 - 3.000000) / 2.000000) - 10.000000)");
}

TEST(DivideTest, allOps) {
        Factory* test = new Factory();
        char* test_val[12];
        test_val[0] = "./test";
        test_val[1] = "2";
        test_val[2] = "*";
        test_val[3] = "4";
        test_val[4] = "-";
        test_val[5] = "5";
        test_val[6] = "+";
        test_val[7] = "7";
	test_val[8] = "/";
	test_val[9] = "2";
	test_val[10] = "**";
	test_val[11] = "3";
        Base* p = nullptr;
        p = test->parse(test_val, 12);
        EXPECT_EQ(p->evaluate(), 125);
}

TEST(DivideTest, manyoftheOps) {
        Factory* test = new Factory();
        char* test_val[10];
        test_val[0] = "./test";
        test_val[1] = "9";
        test_val[2] = "/";
        test_val[3] = "3";
        test_val[4] = "+";
        test_val[5] = "3";
        test_val[6] = "/";
        test_val[7] = "3";
        test_val[8] = "-";
        test_val[9] = "1";
        Base* p = nullptr;
        p = test->parse(test_val, 10);
        EXPECT_EQ(p->evaluate(), 1);
}



#endif
