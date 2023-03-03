// To, Claire

#include "setFunctions.h"
#include "set.h"
#include "set.cpp"

#include <cmath>

using namespace std;

// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result = s1;
	for (size_t i = 0; i < s2.cardinality(); ++i)
    {
        result.insertElement(s2[i]);
    }
	return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
    for (size_t i = 0; i < s1.cardinality(); ++i)
    {
        if (s2.isElement(s1[i]))
        {
            result.insertElement(s1[i]);
        }
    }
	return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result = s1;
    for (size_t i = 0; i < s2.cardinality(); ++i)
    {
        if (result.isElement(s2[i]))
        {
            result.removeElement(s2[i]);
        }
    }
	return result;
}

// Returns a set that is the symmetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result = s1;
    for (size_t i = 0; i < s2.cardinality(); ++i)
    {
        if (result.isElement(s2[i]))
        {
            result.removeElement(s2[i]);
        }
        else
        {
            result.insertElement(s2[i]);
        }
    }
	return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{
    for (size_t i = 0; i < s1.cardinality(); ++i)
    {
        if (!s2.isElement(s1[i]))
        {
            return false;
        }
    }
	return true;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
    return (isSubSet(s1, s2) && s1 != s2);
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
    int numElem = static_cast<int>(s.cardinality());
    int totalRows = pow(2, numElem);

    vector<vector<int>> matrix;
    for (int i = 0; i < totalRows; ++i)
    {
        vector<int> row;
        int temp = i;
        for (int j = 0; j < numElem; j++)
        {
            row.insert(row.begin(), temp % 2);
            temp /= 2;
        }
        matrix.push_back(row);
    }

    Set<Set<char>> result;
    for (int i = 0; i < totalRows; ++i)
    {
        Set<char> subset;
        for (int j = 0; j < numElem; ++j)
        {
            if (matrix[i][j] == 1)
            {
                subset.insertElement(s[j]);
            }
        }
        result.insertElement(subset);
    }
	return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
    Set<char> u;
    Set<char> intersection;

    for (size_t i = 0; i < p.cardinality(); ++i)
    {
        if (p[i].cardinality() == 0)
        {
            return false;
        }

        for (size_t j = i; j < p.cardinality(); ++j)
        {
            if (setIntersection(p[i], p[j]).cardinality() > 0)
            {
                return false;
            }
        }

        u = setUnion(u, p[i]);
    }

    return (u == s);
}