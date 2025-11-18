// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	/*! @brief An alias for the Account class itself. */
	typedef Account		t;

	/*! @brief Gets the total number of accounts. */
	static int	getNbAccounts( void );

	/*! @brief Gets the total amount of money in all accounts. */
	static int	getTotalAmount( void );

	/*! @brief Gets the total number of deposits made across all accounts. */
	static int	getNbDeposits( void );

	/*! @brief Gets the total numberf of withdrawals made across all accounts. */
	static int	getNbWithdrawals( void );

	/*! @brief Displays summary information for all accounts (total acc/$, dep, with).
	*/
	static void	displayAccountsInfos( void );

	/*! @brief Constructs a new Account object with an initial deposit. */
	Account( int initial_deposit );
	/*! @brief Destroys the Account object. */
	~Account( void );

	/*! @brief Makes a deposit into the account. */
	void	makeDeposit( int deposit );

	/*! @brief Attempts to make a withdrawal from the account. */
	bool	makeWithdrawal( int withdrawal );

	/*! @brief Returns the current balance of the account. */
	int		checkAmount( void ) const;

	/*! @brief Displays the current status of this account 
	   in a [index, amount, dep, with] format. */
	void	displayStatus( void ) const;



private:

	/*! @brief The total number of accounts. */
	static int	_nbAccounts;

	/*! @brief The total amount of money in all accounts. */
	static int	_totalAmount;

	/*! @brief The total number of deposits made across all accounts. */
	static int	_totalNbDeposits;

	/*! @brief The total number of withdrawals made across all accounts. */
	static int	_totalNbWithdrawals;


	/*! @brief Displays the current timestamp in the format [YYYYMMDD_HHMMSS]. */
	static void	_displayTimestamp( void );

	/*! @brief The unique index of this account. */
	int				_accountIndex;

	/*! @brief The current balance of this account. */
	int				_amount;

	/*! @brief The number of deposits made into this account. */
	int				_nbDeposits;
	
	/*! @brief The number of withdrawals made from this account. */
	int				_nbWithdrawals;

	/*! @brief Private default constructor, not to be used directly. */
	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
