#ifndef __INTMOD_H_
#define __INTMOD_H_

#include <iostream>
using std::ostream;
using std::cout;

// you can assume n is an integer >= 2
template<int n>
class IntMod {

public:

	// Default constructor. Should initialize value to 0
	IntMod() {
		value = 0;
	}

	// Value constructor. Accepts any (positive or negative) integer
	// not necessarily within [0..n-1]
	IntMod(int v) {
		if (v < 0) {
			int count = 0;
			if (n < v * -1) {
				while (count * n < (v * -1)) {
					++count;
				}
			}
			else {
				count = n;
			}
			value = (v + (count*n)) % n;
		}
		else {
			value = v % n;
		}
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Returns the value of this IntMod as an integer, in
	// the range 0..n-1
	int toInt() const {
		return value;
	}

	// Overloaded + operator for adding two IntMods.
	// The two operands must be of same type i.e. same value of n in IntMod<n>
	// otherwise would not compile.
	// For technical reasons they are defined inside the class body
	// even though they are friends; see e.g. https://en.cppreference.com/w/cpp/language/friend#Template_friend_operators
	friend IntMod operator+(const IntMod& lhs, const IntMod& rhs) {
		int sum = lhs.toInt() + rhs.toInt();
		if (sum < 0) {
			int count = 0;
			if (n < sum * -1) {
				while (count * n < (sum * -1)) {
					++count;
				}
			}
			else {
				count = n;
			}
			sum = (sum + (count * n)) % n;
		}
		else {
			sum = sum % n;
		}
		return sum;
	}

	// Overloaded * operator for multiplying two IntMods.
	friend IntMod operator*(const IntMod& lhs, const IntMod& rhs) {
		int sum = lhs.toInt() * rhs.toInt();
		if (sum < 0) {
			int count = 0;
			if (n < sum * -1) {
				while (count * n < (sum * -1)) {
					++count;
				}
			}
			else {
				count = n;
			}
			sum = (sum + (count * n)) % n;
		}
		else {
			sum = sum % n;
		}
		return sum;
	}

	// Overloaded == operator for comparing two IntMods.
	friend bool operator==(const IntMod& lhs, const IntMod& rhs) {
		if (lhs.toInt() == rhs.toInt()) {
			return true;
		}
		else {
			return false;
		}
	}

	// Return the multiplicative inverse of the current number mod n
	// (note that this is a member function).
	// An inverse of a number x, modulo n, is a number y such that
	// x*y mod n == 1.
	// It is sufficient to simply test the above condition
	// for each number in 1,2,...,n-1. You don't need to implement any
	// "better" algorithms.
	// If the inverse does not exist, throw a std::domain_error exception.
	IntMod inverse() {
		exists = false;
		int inverse = 0;
		for (int i = 1; i <= n - 1; i++) {
			if ((value * i) % n == 1) {
				inverse = i;
				exists = true;
			}
		}
			if (exists == false) {
				throw std::domain_error("Exception caught here");
			}
		return inverse;
	}


	// Overloaded << operator, printing the IntMod like an integer
	friend ostream& operator<<(ostream& os, const IntMod& p) {
		os << p.toInt();
		return os;
	}

private:
	// TODO: add any private variables/functions needed
	int value;
	bool exists;
};

#endif /* __INTMOD_H_ */
