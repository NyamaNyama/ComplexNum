#include <iostream>
#include "Complex.h"
#include<cmath>
constexpr double epsilon = 1e-9;
template <typename T>
Complex<T>::Complex() : _real(0), _imaginary(0) {}

template <typename T>
Complex<T>::Complex(T real) : _real(real), _imaginary(0) {};

template <typename T>
Complex<T>::Complex(T real, T imaginary) : _real(real), _imaginary(imaginary) {};

template <typename T>
T Complex<T>::GetReal() const {
	return _real;
}

template <typename T>
void Complex<T>::SetReal(T real) {
	_real = real;
}

template <typename T>
T Complex<T>::GetImaginary() const {
	return _imaginary;
}

template <typename T>
void Complex<T>::SetImaginary(T imaginary) {
	_imaginary = imaginary;
}

template <typename T>
Complex<T> Complex<T>:: operator+(const Complex<T>& comp2) const {
	return Complex<T>(this->_real + comp2._real, this->_imaginary + comp2._imaginary);
}

template <typename T>
Complex<T> Complex<T>:: operator-(const Complex<T>& comp2) const {
	return Complex<T>(this->_real - comp2._real, this->_imaginary - comp2._imaginary);
}

template <typename T>
Complex<T> Complex<T>:: operator*(const Complex<T>& comp2) const {
	T newReal = (this->_real * comp2._real - this->_imaginary * comp2._imaginary);
	T newIm = (this->_imaginary * comp2._real + this->_real * comp2._imaginary);
	return Complex<T>(newReal, newIm);
}

template <typename T>
Complex<T> Complex<T>:: operator/(const Complex<T>& comp2) const {
	if (std::abs(comp2._real) < epsilon && std::abs(comp2._imaginary) < epsilon) {
		throw std::runtime_error("Division by zero");
	}
	T newReal = (this->_real * comp2._real + this->_imaginary * comp2._imaginary) / (pow(comp2._real, 2) + pow(comp2._imaginary, 2));
	T newIm = (this->_imaginary * comp2._real - this->_real * comp2._imaginary) / (pow(comp2._real, 2) + pow(comp2._imaginary, 2));
	return Complex<T>(newReal, newIm);
}

template <typename T>
T Complex<T>::Abs() const {
	return std::sqrt(pow(this->_real, 2) + pow(this->_imaginary, 2));
}

template <typename T>
Complex<T> Complex<T>::Pow(int degree) {
	T newReal = pow(this->Abs(), degree) * std::cos(degree * std::acos(this->_real / this->Abs()));
	T newIm = pow(this->Abs(), degree) * std::sin(degree * std::acos(this->_real / this->Abs()));
	return Complex<T>(newReal, newIm);
}

template <typename T>
bool Complex<T>::isEqual(const Complex<T>& comp2) const {
	return (std::abs(this->_real - comp2._real) < epsilon && (std::abs(this->_imaginary - comp2._imaginary) < epsilon));
}

template<typename T>
bool Complex<T>::isEqualFloatInt(T num2) const {
	return ((std::abs(this->_real - num2) < epsilon) && (std::abs(this->_imaginary) < epsilon));
}

template<typename T>
void Complex<T>::Write() const {
	if (this->_imaginary < 0) {
		std::cout << this->_real << this->_imaginary << "i\n";
	}
	else {
		std::cout << this->_real <<'+'<< this->_imaginary << "i\n";
	}
}

template
class Complex<double>;

template
class Complex<int>;

