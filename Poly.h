#include <iostream>
#include <vector>
using std::ostream;
using std::vector;

// templated class for a polynomial, with coefficients of type T
// The type T is assumed to have a zero element 0
// Furthermore T is assumed to have implemented:
//   the + operator;
//   the == operator;
//   the << operator.
template<typename T>
class Polynomial {
public:

	// Default constructor. Constructs the polynomial "0"
	Polynomial() {
		degreeVar = 0;
	}

	// Value constructor. Constructs a polynomial based on the vector
	// of coefficients, in descending order of exponents.
	// For example, if coef contains {0,6,8,9,4}, then it constructs
	// the polynomial 6x^3 + 8x^2 + 9x + 4
	Polynomial(vector<T> other) {
		
		if (other.at(0) == 0) {
			while (other.at(0) == 0) {
				other.erase(other.begin());
			}
		}
			degreeVar = other.size()-1;
		

		for (auto it = other.begin(); it != other.end(); it++) {
				coefficient.push_back(*it);
		}

	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Return the degree of the polynomial.
	int degree() const {
		return degreeVar;
	}

	// Return the coefficient of the x^i term. If i is negative or
	// larger than the degree, 0 is returned.
	T getCoef(int i) const {
		T coef = 0;
		try {
			if (i < 0 || i > degreeVar) {
				throw std::domain_error("Exception out of bounds");
				//won't allow me to handle the exception this way not sure as to why
			}
			else if ((degreeVar == 0) && (coefficient.size() == 0)) {
				coef = 0;
			}
			else {
				coef = coefficient.at(degreeVar - i);
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Exception here" << std::endl;
		}
		return coef;
	}

	// Addition of two polynomials. This time it is a member function
	Polynomial operator+(const Polynomial& other) const {
		int difference = 0;
		Polynomial <T> tmp_poly;

		if (degreeVar > other.degreeVar) {

			tmp_poly.degreeVar = degreeVar;
			difference = degreeVar - other.degreeVar;

			for (int i = 0; i <difference; i++) {
				tmp_poly.coefficient.push_back(coefficient.at(i));
			}
			for (int i = 0; i <= other.degreeVar; i++) {
				tmp_poly.coefficient.push_back(coefficient.at(i+difference) + other.coefficient.at(i));
			}
		}
		else {

			difference = other.degreeVar - degreeVar;

			for (int i = 0; i < difference; i++) {
				tmp_poly.coefficient.push_back(other.coefficient.at(i));
			}
			tmp_poly.degreeVar = other.degreeVar;
			for (int i = 0; i <= degreeVar; i++) {
				tmp_poly.coefficient.push_back(coefficient.at(i) + other.coefficient.at(i+difference));
			}
		}
		
		Polynomial<T> p(tmp_poly.coefficient);
		return p;
	}

	// Print the polynomial, in descending order of coefficients and
	// with the usual "x^..." terms.
	// It is not necessary to print it "pretty".
	// For example, if the polynomial is 2x^4 + x^3 - 5x - 1, it is
	// sufficient to print it as 2x^4 + 1x^3 + 0x^2 + -5x^1 + -1x^0
	// Minor formatting differences will be accepted.
	// If you print it pretty you get up to 5 bonus marks (out of 100
	// for this task). See the testPrintPretty() test case.
	// (This bonus part may not be as easy as it seems...)
	friend ostream& operator<<(ostream& os, const Polynomial<T>& p) {
		
		for (int i = p.degree(); i >= 0; i--) {
		if (p.getCoef(i) == 0 && i==0) {
			os << 0;
			os << "x^";
			os << (i);
		}else if (p.getCoef(i) == 0) {
				os << p.getCoef(i);
				os << "x^";
				os << (i);
				os << " + ";
		}else if (0 == i) {
				os << p.getCoef(i);
				os << "x^";
				os << (i);
			}
			else {
				os << p.getCoef(i);
				os << "x^";
				os << (i);
				os << " + ";
			}
		}
			return os;
		
	}
	
private:
	// TODO: add any private variables/functions needed
	vector <T> coefficient;
	int degreeVar;
	vector <T> polynomialSum;
};
