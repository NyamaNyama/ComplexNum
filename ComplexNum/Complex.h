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
#endif