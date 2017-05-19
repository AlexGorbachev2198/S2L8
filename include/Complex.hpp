#include <iostream>
using namespace std;
class Complex
{
	double Actual, Imaginary;
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);
	~Complex();
	double Get_Actual()
	{
		return Actual;
	}
	double Get_Imaginary()
	{
		return Imaginary;
	}
	Complex * Summ(Complex *first, Complex * second);
	Complex * Sub(Complex *first, Complex * second);
	Complex * Mult(Complex *first, int K);
	Complex * Div(Complex *first, int K);
	void Print();
	void mult_complex(Complex * first);
	
	Complex& operator = (Complex &c)
	{
		Actual = c.Actual;
		Imaginary = c.Imaginary;
        return (*this);
	}
    Complex& operator +=  (Complex &c)
	{
		Actual += c.Actual;
		Imaginary += c.Imaginary;
		return *this;
	}
	Complex operator + (const Complex &c)
	{
		return Complex(Actual + c.Actual, Imaginary + c.Imaginary);
	}
	Complex&operator -=(const Complex &c) {
		Actual -= c.Actual;
		Imaginary -= c.Imaginary;
		return *this;
	}
	Complex operator - (const Complex &c)
	{
		return Complex(Actual - c.Actual, Imaginary - c.Imaginary);
	}
	Complex operator *=(Complex &c) {
		double a = Actual, b = Imaginary, x = c.Actual, y = c.Imaginary;
		Actual = a*x - b*y;
		Imaginary = b*x + a*y;
		return *this;
	}
	Complex operator * (const Complex &c)
	{
		return Complex(Actual * c.Actual - Imaginary * c.Imaginary, Actual * c.Imaginary + Imaginary * c.Actual);
	}
	Complex operator /=(Complex &c) {
		Complex t(Actual, Imaginary);
		double r = c.Actual * c.Actual + c.Imaginary * c.Imaginary;
		Actual = (t.Actual * c.Actual + t.Imaginary * c.Imaginary) / r;
		Imaginary = (t.Imaginary * c.Actual - t.Actual * c.Imaginary) / r;
		return *this;
	}
	Complex operator / (const Complex &c)
	{
		Complex temp;
        double r = c.Actual * c.Actual + c.Imaginary * c.Imaginary;
		temp.Actual = (Actual * c.Actual + Imaginary * c.Imaginary) / r;
		temp.Imaginary = (Imaginary* c.Actual - Actual * c.Imaginary) / r;
		return temp;
	}
    friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator >> (istream &, Complex &);
	friend bool operator ==(const Complex, const Complex);
};
bool operator == (const Complex first, const Complex second) {
	return (first.Actual == second.Actual && first.Imaginary  == second.Imaginary);

}
ostream& operator<< (ostream &out, const Complex &c)
{
	if (c.Actual == 0 && c.Imaginary == 0) cout << "There is no complex!" << endl;
	else if (c.Actual != 0 && c.Imaginary == 0) cout << c.Actual << endl;
	else if (c.Actual == 0 && c.Imaginary != 0) cout << c.Imaginary << "i" << endl;
	else if (c.Imaginary > 0)cout << c.Actual << " + " << c.Imaginary << "i" << endl;
	else if (c.Imaginary < 0) cout << c.Actual << " - " << -c.Imaginary << "i" << endl;
	return out;
}
istream& operator >> (istream &in, Complex &c)
{
	in >> c.Actual >> c.Imaginary;
	return in;
}

Complex::Complex()
{}
Complex::Complex(double a)
{
	Actual = a;
	Imaginary = 0;
}
Complex::Complex(double a, double i)
{
	Actual = a;
	Imaginary = i;
}
Complex * Complex::Summ(Complex *first, Complex * second)
{
	Complex * buff = new Complex(first->Get_Actual() + second->Get_Actual(), first->Get_Imaginary() + second->Get_Imaginary());
	return buff;
}
Complex * Complex::Sub(Complex *first, Complex * second)
{
	Complex * buff = new Complex(first->Get_Actual() - second->Get_Actual(), first->Get_Imaginary() - second->Get_Imaginary());
	return buff;
}
Complex * Complex::Mult(Complex *first, int K)
{
	Complex * buff = new Complex(first->Get_Actual() * K, first->Get_Imaginary() * K);
	return buff;
}
Complex * Complex::Div(Complex *first, int K)
{
	try {
		if (K == 0) throw true;
		Complex * buff = new Complex(first->Get_Actual() / K, first->Get_Imaginary() / K);
		return buff;
	}
	catch (bool i)
	{
		cout << "Error!" << endl;
	}
	return nullptr;
}
void Complex::mult_complex(Complex * first)
{
	double Actual1 = this->Actual*first->Get_Actual() - this->Imaginary*first->Get_Imaginary();
	double Imaginary1 = this->Actual*first->Get_Imaginary() + this->Imaginary*first->Get_Actual();
	this->Actual = Actual1;
	this->Imaginary = Imaginary1;
}
void Complex::Print()
{
	if (this->Get_Actual() == 0 && this->Get_Imaginary() == 0) cout << "There is no complex!" << endl;
	else if (this->Get_Actual() != 0 && this->Get_Imaginary() == 0) cout << Actual << endl;
	else if (this->Get_Actual() == 0 && this->Get_Imaginary() != 0) cout << Imaginary << "i" << endl;
	else if (this->Get_Imaginary() > 0)cout << this->Get_Actual() << " + " << Imaginary << "i" << endl;
	else if (this->Get_Imaginary() < 0) cout << this->Get_Actual() << " - " << -Imaginary << "i" << endl;
}
Complex::~Complex()
{
}
