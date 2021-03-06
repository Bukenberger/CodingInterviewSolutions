/*
 *	@file		StringsAndArrays_Problem4.hpp
 *  @date		2020-12-19
 *	@author		Teran Bukenberger
 *
 *  @brief		Given a string, write a function to check if it is a permutation of a palindrome.
 *				A palindrome is a word or phrase that is the same forwards and backwards. A permutation
 *				is a rearrangement of letters. The palindrome does not need to be limited to just
 *				dictionary words.
 *
 *				EXAMPLE
 *
 *				Input: Tact Coa
 *				Output: True (NOTE: permutations: "taco cat", "atco cta", etc.)
 */

#include "StringsAndArrays_Problem4.hpp"

 /* Include any other headers you may wish to use */
#include <map>
#include <stdexcept>

bool palindrome_permutation( const std::string& str ) {

	std::map<char, int> occurrences;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it != ' ')
			occurrences[tolower( *it )]++;
	}

	bool foundOdd = false;
	for (auto k : occurrences) {
		if (k.second % 2 != 0) {
			if (foundOdd)
				return false;
			foundOdd = true;
		}
	}

	return true;
}