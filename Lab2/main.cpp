#include <iostream>
#include <vector>
#include "set.h"
#include "set.cpp"
#include "setFunctions.h"

using namespace std;

int main()
{
	vector<char> v{'s','f','h','i','a','h'};
	Set<char> s1{ 's','f','g','h','h','i','a', 'b' };
	Set<char> s2{ 'e','d','a','g','b','h','i','a','h' };
	Set<char> s3{ 'a','b','c','d','e','f' };
	Set<char> s4{ 'a','b','c' };
	Set<char> s5{ 'd','e','f', 'g' };

	Set<Set<char>> ss{ s4,s5 };  // Set of Sets s4 and s5

	cout << boolalpha;   // makes the printing of a boolean print true or false instead of 1 or 0

	// Testing your functions by printing the results of calling each.
    // You will need to verify if they are correct.
    // You should also make your own tests to fully verify your functions.

	cout << "Sets s1 and s2\n";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	cout << "\nThe Union of sets s1 and s2\n";
	cout << setUnion(s1, s2) << endl;
	
	cout << "\nThe Intersection of sets s1 and s2\n";
	cout << setIntersection(s1, s2) << endl;
	
	cout << "\nThe Difference of sets s1 and s2\n";
	cout << setDiff(s1, s2) << endl;
	
	cout << "\nThe Symmetric Difference of sets s1 and s2\n";
	cout << setSymDiff(s1, s2) << endl;

	cout << "\nSets s3, s4, s5 and ss\n";
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;
	cout << "ss = " << ss << endl;

	cout << "\nIs s3 a subset of s3\n";
	cout << isSubSet(s3, s3) << endl;
	cout << "\nIs s3 a proper subset of s3\n";
	cout << isProperSubSet(s3, s3) << endl;
	cout << "\nIs s4 a subset of s3\n";
	cout << isSubSet(s4, s3) << endl;
	cout << "\nIs s4 a proper subset of s3\n";
	cout << isProperSubSet(s4, s3) << endl;
	cout << "\nIs s5 a subset of s2\n";
	cout << isSubSet(s5, s2) << endl;
	cout << "\nIs s5 a proper subset of s2\n";
	cout << isProperSubSet(s5, s2) << endl;

	cout << "\nDo the sets in ss make a Partition of s3\n";
	cout << isPartition(ss, s3) << endl;
	
	cout << "\nThe power set P(s3)\n";
	cout << PowerSet(s3) << endl;

	return 0;
}