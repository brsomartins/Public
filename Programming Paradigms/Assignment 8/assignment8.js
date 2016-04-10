////////////////////////////////////////////////////////////
//  CSCE 3193
//  Fall 2015
//  Assignment 8
//  Name: Breno Soares Martins
////////////////////////////////////////////////////////////


//  You must complete the implementation of the six functions below.
//  In all cases where it is given that the arguments to a function are
//  numbers (or an array of numbers), you can assume that the correct types
//  of values are passed as arguments and don't have to check for the wrong
//  types or invalid input in the script used for testing.


////////////////////////////////////////////////////////////
//  Recursion

function recSum(n) {
	//  Write the body of recSum so that it takes a positive integer
	//  n as an argument and returns the integer which is the sum
	//  of the integers from 1 to n.
	//  For example, recSum(5) returns 15, and recSum(40) returns
	//  820.
	//  THIS FUNCTION MUST USE RECURSION OR 60% WILL BE DEDUCTED
	//  (e.g. there must not be any loops).  Also, for full credit
	//  you must not define inner functions (i.e. recSum must be
	//  the recursive function) and it must not use more than one parameter.

	if (n > 0) {
		return n + recSum(n-1);
	} else {
		return 0;
	}
}

function findMin(a) {
	//  Write the body of findMin so that it takes a single argument
	//  which is an array of integers (whose length can be assumed
	//  to be at least 1). findMin should return the smallest integer
	//  in the input array. 
	//  For example, findMin([8,22,4,58,481]) should return 4, and
	//  findMin([23,4438,23,5,14,3,583,24,7]) should return 3.
	//  THIS FUNCTION MUST USE RECURSION OR 60% WILL BE DEDUCTED
	//  (e.g. there must not be any loops).  Also, for full credit
	//  you must not define inner functions (i.e. recSum must be
	//  the recursive function) and it must not use more than one parameter.
	//  See http://www.w3schools.com/jsref/jsref_obj_array.asp for useful
	//  array functions in JavaScript.

	if (a.length > 1) {
		if (a[0] >= a[1]) {
			a.splice(0, 1);
		} else {
			a.splice(1, 1);
		}

		return findMin(a);
	} else {
		return a[0];
	}
}

function reverseString(s) {
	//  Write the body of reverseString so that it takes a single argument
	//  which is a string (which may be the empty string), and returns
	//  a string which is the reverse of the input string.
	//  For example, reverseString('abc') returns 'cba', and 
	//  reverseString('This is a string') returns 'gnirts a si sihT'.
	//  THIS FUNCTION MUST USE RECURSION OR 60% WILL BE DEDUCTED
	//  (e.g. there must not be any loops).  Also, for full credit
	//  you must not define inner functions (i.e. recSum must be
	//  the recursive function) and it must not use more than one parameter.
	//  See http://www.w3schools.com/jsref/jsref_obj_string.asp for useful
	//  string functions in JavaScript.

	if (s.length > 0) {
		var lastChar = s.charAt(s.length - 1);
		s = s.substring(0, s.length - 1);
		return lastChar + reverseString(s);
	} else {
		return "";
	}
}


////////////////////////////////////////////////////////////
//  Higher order functions

function applyToArray(a) {
	//  Write the body of applyToArray so that it takes a single
	//  argument which is an array and returns a new function.
	//  
	//  Input: The argument 'a' can be assumed to be an array
	//  (which may or may not be empty).
	//
	//  Output: applyToArray must return a function which itself takes a
	//  single argument which can be assumed to be a function (which
	//  we will call 'f'). 'f' can be assumed to take a single
	//  argument and return a single value.  The function returned
	//  by applyToArray should return an array which is the result of
	//  applying the function f individually to each element of array a.
	//  
	//  Examples: Given the definitions of add2 and mult4 at the bottom
	//  of this page, if var fx = applyToArray([1,2,3,4]), then f1(add2)
	//  returns [3,4,5,6], if var fx = applyToArray([10,-20,8,0]),
	//  fx(mult4) returns [40,-80,32,0], and if var fx = applyToArray([]),
	//  fx(add2) returns []

	return function(f) {
		var array = [];

		for (var i = 0; i < a.length; i++) {
			array.push(f(a[i]));
		}

		return array;
	}
}

function getMax(f1, f2) {
	//  Write the body of getMax so that it takes two functions as arguments
	//  and returns a new function.
	//
	//  Input: Arguments f1 and f2 are assumed to be functions which each take
	//  a single integer argument and return a single integer.
	//
	//  Output: The function returned by getMax must take a single argument, an
	//  integer (which we will call 'i'), and return the maximum of f1(i) and f2(i).
	//
	//  Examples: Given the definitions of add2 and mult4 at the bottom of
	//  this page, if var fx = getMax(mult4,square), then fx(2) = 8,
	//  fx(3) = 12, fx(4) = 16, and fx(5) = 25.

	return function(i) {
		if (f1(i) >= f2(i)) {
			return f1(i);
		} else {
			return f2(i);
		}
	}
}


////////////////////////////////////////////////////////////
//  Common closure

function makeClosure(f) {
	//  Write the body of makeClosure so that it takes a single argument and
	//  returns an array of exactly two functions.
	//
	//  Input: The argument f can be assumed to be a function which takes a
	//  single argument which is an integer and returns a single integer.
	//
	//  Output: makeClosure should return an array of exactly two functions
	//  which we will call f1 and f2.  These two functions should be contained
	//  in a closure which also defines a shared variable named 'max' (i.e.
	//  'max' is accessible to both).  'max' should be initialied to 0 by
	//  makeClosure.  f1 should be a function which takes a single integer
	//  argument and, if and only if its value is greater than max, sets max
	//  equal to that value.  f2 should take no arguments and return the result
	//  of calling f with max as its argument.
	//
	//  Examples:  var closure = makeClosure(add2);
	//	console.log(closure[1]());  // max = 0, output = 2
	//	closure[0](3);				// max = 3
	//	console.log(closure[1]());	// max = 3, output = 5
	//	closure[0](2);				// max = 3;
	//	console.log(closure[1]());	// max = 3, output = 5
	//	closure[0](10);				// max = 10;
	//	console.log(closure[1]());	// max = 10; output = 12;

	var max = 0;

	this.f1 = function(x) {
		if (x > max) {
			max = x;
		}
	}

	this.f2 = function() {
		return f(max);
	}

	a = [f1, f2];

	return a;
}


////////////////////////////////////////////////////////////
//  Auxiliary functions (used for testing)

function add2(j) {
	return j+2;
}

function mult4(i) {
	return i*4;
}

function square(i) {
	return i*i;
}