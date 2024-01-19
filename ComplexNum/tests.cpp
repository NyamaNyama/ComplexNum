#include "Complex.h"
#include <cassert>
#include <iostream>
#include<cmath>

int main() {
	Complex<double> com0(0, 0);
	Complex<double> com1(5, 10);
	Complex<double> com2(1, 2);
	Complex<double> com3(3, 0);
	Complex<double> com4(5.3);

	//Test + - * / operations
	
	//+
	assert((com1 + com2).isEqual(Complex<double>(6, 12)));

	//-
	assert((com1 - com2).isEqual(Complex<double>(4, 8)));

	//*
	assert((com1 * com2).isEqual(Complex<double>(-15, 20)));

	///
	assert((com1 / com2).isEqual(Complex<double>(5)));

	//Test equality to float and int number
	assert(com1.isEqualFloatInt(32));

	//Test Pow
	assert(com2.Pow(2).isEqual(Complex<double>(-3, 4)));

	//Test abs
	assert(std::abs(com2.Abs() - std::sqrt(5)) < 10e-9);
	
	//Test div by zero
	try {
		(com1 / com0);
		assert(false);
	}
	catch (const std::runtime_error& e) {
		assert(std::string(e.what()) == "Division by zero");
	}



	//same for integer

	Complex<int> com5(0, 0);
	Complex<int> com6(5, 10);
	Complex<int> com7(1, 2);
	Complex<int> com8(3, 0);
	Complex<int> com9(5);

	//Test + - * / operations

	//+
	assert((com6 + com7).isEqual(Complex<int>(6, 12)));

	//-
	assert((com6 - com7).isEqual(Complex<int>(4, 8)));

	//*
	assert((com6 * com7).isEqual(Complex<int>(-15, 20)));

	///
	assert((com6 / com7).isEqual(Complex<int>(5)));

	//Test equality to float and int number
	assert(com6.isEqualFloatInt(32));

	//Test Pow
	assert(com7.Pow(2).isEqual(Complex<int>(-3, 4)));

	//Test abs
	assert(std::abs(com7.Abs() - std::sqrt(5)) < 10e-9);

	//Test div by zero
	try {
		(com6 / com5);
		assert(false);
	}
	catch (const std::runtime_error& e) {
		assert(std::string(e.what()) == "Division by zero");
	}

}