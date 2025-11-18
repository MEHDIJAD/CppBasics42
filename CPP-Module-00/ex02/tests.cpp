// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	/*! @brief Alias for a vector of Account object
	s. */
	typedef std::vector<Account::t>	accounts_t;
	/*! @brief Alias for a vector of integers. */
	typedef std::vector<int>	ints_t;

	/*! @brief Alias for a pair of iterators, one for accounts_t and one for ints_t. */
	typedef std::pair<accounts_t::iterator, ints_t::iterator>  acc_int_t;

	/*!
	 * @brief an array of initial deposits to create some accounts.
	 */
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	/**
	 * @brief Calculates the number of elements in the amounts array.
	 * sizeof(amounts) gives the total size of the array in bytes, and sizeof(int) gives the size of a single integer. 
	 * Dividing them gives the count of integers.
	 */
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	/*!
	 * @brief Constructs the vector of accounts using initial balances from the amounts array.
	 *
	 * This variable is initialized using the `std::vector`'s range constructor.
	 * This special constructor iterates through a sequence of elements and creates
	 * a copy of each one inside the new vector.
	 *
	 * The range is defined by two pointers, 'first' and 'last':
	 * - The 'first' pointer is `amounts`, which points to the start of the array data.
	 * - The 'last' pointer is `amounts + amounts_size`, which points to the memory
	 *   address immediately after the final element of the array.
	 *! and this will init constructor of Accounts
	 */
	accounts_t				accounts( amounts, amounts + amounts_size );

	/*! @brief  Creates an iterator acc_begin that points to the beginning of the accounts vector. */
	accounts_t::iterator	acc_begin	= accounts.begin();

	/*! @brief Creates an iterator acc_end that points to the position after the end of the accounts*/
	accounts_t::iterator	acc_end		= accounts.end();

	/*! @brief An array of deposit amounts to be applied to the accounts. */
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };

	/*! @brief The total number of elements in the deposit amounts array. */
	size_t const		d_size( sizeof(d) / sizeof(int) );

	/*! @brief A vector of integers holding the deposit amounts. */
	ints_t				deposits( d, d + d_size );

	/*! @brief An iterator pointing to the beginning of the deposits vector. */
	ints_t::iterator	dep_begin	= deposits.begin();

	/*! @brief An iterator pointing to the end of the deposits vector. */
	ints_t::iterator	dep_end		= deposits.end();
	
	/*! @brief An array of withdrawal amounts to be applied to the accounts. */
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };

	/*! @brief The total number of elements in the withdrawal amounts array. */
	size_t const		w_size( sizeof(w) / sizeof(int) );

	/*! @brief A vector of integers holding the withdrawal amounts. */
	ints_t				withdrawals( w, w + w_size );

	/*! @brief An iterator pointing to the beginning of the withdrawals vector. */
	ints_t::iterator	wit_begin	= withdrawals.begin();

	/*! @brief An iterator pointing to the end of the withdrawals vector. */
	ints_t::iterator	wit_end		= withdrawals.end();
	

	Account::displayAccountsInfos();

	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();

	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
