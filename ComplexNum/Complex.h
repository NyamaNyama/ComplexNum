#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

template <typename T>
class Complex {
private:
	T _real, _imaginary;

public:
	Complex();
	Complex(T real);
	Complex(T real, T imaginary);

	T GetReal() const;
	void SetReal(T real);
	T GetImaginary() const;	
	void SetImaginary(T imaginary);

	Complex<T> operator+ (const Complex<T> &comp2) const;
	Complex<T> operator- (const Complex<T> &comp2) const;
	Complex<T> operator* (const Complex<T> &comp2) const;
	Complex<T> operator/ (const Complex<T> &comp2) const;
	T Abs() const;
	Complex<T> Pow(int degree);

	bool isEqual(const Complex<T>& comp2) const;
	bool isEqualFloatInt(T num2) const;

	void Write() const;
 
};
inline Complex<double> operator"" i(long double d) {
	return Complex<double>(0, d);
}
inline Complex<int> operator"" i(unsigned long long int d) {
	return Complex<int>(0, d);
}

template <typename T>
Complex<T>  operator+(const T num, const Complex<T>& comp2) {
	return Complex<T>(comp2.GetReal() + num, comp2.GetImaginary());
}

template <typename T>
Complex<T>  operator-(const T num, const Complex<T>& comp2) {
	return Complex<T>(comp2.GetReal() - num, comp2.GetImaginary());
}

#endif