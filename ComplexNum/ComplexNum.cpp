#include <iostream>
#include "Complex.h"
#include<cmath>
//template<typename T>
//class Complex
//{
//private:
//    T real, imaginary;
//    const double epsilon = 1e-9;
//public:
//    Complex(): real(0), imaginary(0){}
//    Complex(T real, T imaginary) {
//        this->real = real;
//        this->imaginary = imaginary;
//    }
//    void SetReal(T re)
//    {
//         real = re;
//    }
//    void SetImaginary(T im)
//    {
//       imaginary = im;
//    }
//    T GetReal() const{
//        return real;
//    }
//    T GetImaginary() const{
//        return imaginary;
//    }
//    Complex<T> operator +(const Complex<T> &comp1)  {
//        T newreal = real + comp1.real;
//        T newimaginary = imaginary + comp1.imaginary;
//        Complex newComplex;
//        newComplex.SetImaginary(newimaginary);
//        newComplex.SetReal(newreal);
//        return newComplex;
//
//    }
//    Complex<T> operator -(const Complex<T> &comp1) {
//        T newreal = real - comp1.real;
//        T newimaginary = imaginary - comp1.imaginary;
//        Complex newComplex;
//        newComplex.SetImaginary(newimaginary);
//        newComplex.SetReal(newreal);
//        return newComplex;
//
//    }
//
//    Complex<T> operator *(const Complex<T> &comp1) {
//        T newreal = (real * comp1.real) - (imaginary*comp1.imaginary);
//        T newimaginary = real*comp1.imaginary + imaginary*comp1.real;
//        Complex newComplex;
//        newComplex.SetImaginary(newimaginary);
//        newComplex.SetReal(newreal);
//        return newComplex;
//
//    }
//    Complex<T> operator /(const Complex<T> &comp1) {
//        T newreal = ( (real * comp1.real) + (imaginary * comp1.imaginary) ) / ( (comp1.real*comp1.real) + (comp1.imaginary * comp1.imaginary) );
//        T newimaginary = ( (imaginary*comp1.real) - (real*comp1.imaginary) ) / ((comp1.real * comp1.real) + (comp1.imaginary * comp1.imaginary));
//        return Complex<T>(newreal, newimaginary);
//
//    }
//    
//    T Abs() {
//        return std::sqrt(std::pow(real, 2) + std::pow(imaginary, 2));
//    }
//    //тут с радианами беда
//    void Pow(int degree) {
//        T f = atan(imaginary / real);
//        T z = pow(Abs(),degree);
//        real = z * cos(f * degree);
//        imaginary = z * sin(f * degree);
//
//    }
//        
//    void Write() {
//        if (imaginary < 0) {
//            std::cout << real << imaginary << "i\n";
//        }
//        else {
//            std::cout << real << " + "  << imaginary << "i\n";
//        }
//    }
//
//};
//
//
//int main() {
//    Complex test = new Complex();
//    test.SetImaginary(2);
//    test.SetReal(1);
//    test.WriteComplex();
//    Complex test2;
//    test2.SetImaginary(4);
//    test2.SetReal(3);
//    Complex test3;
//    test3 = test + test2;
//    test3.WriteComplex();
//    test.SetReal(2);
//    test.SetImaginary(3);
//    test2.SetReal(5);
//    test2.SetImaginary(4);
//    test3 = test * test2;
//    test3.WriteComplex();
//
//    test.SetReal(1);
//    test.SetImaginary(3);
//    test2.SetReal(4);
//    test2.SetImaginary(-2);
//    test3 = test * test2;
//    test3.WriteComplex();
//
//    test.SetReal(3);
//    test.SetImaginary(-2);
//    test2.SetReal(4);
//    test2.SetImaginary(1);
//    test3 = test * test2;
//    test3.WriteComplex();
//
//    test.SetReal(2);
//    test.SetImaginary(1);
//    test2.SetReal(2);
//    test2.SetImaginary(-1);
//    test3 = test / test2;
//    test3.WriteComplex();
//    Complex test4;
//    test4.SetReal(3);
//    test4.SetImaginary(4);
//    std::cout << test4.ComplexModule();
//
//}
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
void Complex<T>::SetImaginary(T real) {
	_imaginary = imaginary;
}

template <typename T>
Complex<T> Complex<T>:: operator+(const Complex<T>& comp2) const {
	return Complex<T>(this->_real + comp2._real, this->_imaginary + comp2._imaginary)
}

template <typename T>
Complex<T> Complex<T>:: operator-(const Complex<T>& comp2) const {
	return Complex<T>(this->_real - comp2._real, this->_imaginary - comp2._imaginary)
}

template <typename T>
Complex<T> Complex<T>:: operator*(const Complex<T>& comp2) const {
	T newReal = (this->_real * comp2._real + this->_imaginary * comp2._imaginary);
	T newIm = (this->_imaginary * comp2._real + this->_real * comp2._imaginary);
	return Complex<T>(newReal, newIm);
}

template <typename T>
Complex<T> Complex<T>:: operator/(const Complex<T>& comp2) const {
	if (std::abs(comp2._real) < epsilon && std::abs(comp2._imaginary) < epsilon) {
		throw std::runtime_error("Division by zero");
	}
	T newReal = (this->_real * comp2._real + this->_imaginary * comp2._imaginary) / (pow(comp2._real, 2) + pow(comp2._imaginary, 2));
	T newIm = (this->_imaginary * comp2._real + this->_real * comp2._imaginary) / (pow(comp2._real, 2) + pow(comp2._imaginary, 2));
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
	return (std::abs(this->_real-comp2._real) < epsilon && std::abs(this->_imaginary - comp2._imaginary) < epsilon)
}

template<typename T>
bool Complex<T>::isEqualFloatInt(T num2) const {
	return (this->_real == num2 && this->_real < epsilon)
}

template<typename T>
void Complex<T>::Write() const {
	if (this->_imaginary < 0) {
		std::cout << real << imaginary << "i\n";
	}
	else {
		std::cout << real <<'+'<< imaginary << "i\n";
	}
}

template
class Complex<double>;

template
class Complex<int>;

