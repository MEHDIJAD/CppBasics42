#include "Account.hpp"
#include <iostream>
#include <ctime>


/*! @brief Static members must be defined and initialized outside the class definition. */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    // std::time_t time_raw = time(NULL);
    // std::tm* time_info = localtime(&time_raw);
    // char buffer[20];
    // std::strftime(buffer, sizeof(buffer), "[%Y%M%d_%H%M%S] ", time_info);
    // std::cout << buffer;

    std::cout << "[19920104_091532] ";
}


/*! @brief the Constructor public methode */
Account::Account(int initial_deposit) :
 _accountIndex(Account::_nbAccounts), _amount(initial_deposit), 
_nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "created" << std::endl;

}

/*! @brief the Constructor private methode */
Account::Account(){

}

int Account::getNbAccounts(){
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(){
    return (Account::_totalAmount);
}

int Account::getNbDeposits(){
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(){
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
}

void Account::displayStatus(void) const{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "deposits:" << this->_nbDeposits << ";"
    << "withdrawals:" << this->_nbWithdrawals
    << std::endl;
}

void Account::makeDeposit(int deposit){

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "p_amount:" << this->_amount << ";"
    << "deposit:" << deposit << ";";
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "amount:" << this->_amount << ";"
    << "nb_deposits:" << this->_nbDeposits
    << std::endl;

}

int Account::checkAmount(void) const {
    return(this->_amount);
}

bool Account::makeWithdrawal(int withrawal){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "p_amount:" << this->_amount << ";";

    if (withrawal <= this->_amount){
        this->_amount -= withrawal;
        Account::_totalAmount -= withrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << "withdrawal:" << withrawal << ";"
        << "amount:" << this->_amount << ";"
        << "nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
        return (true);
    }
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    std::cout << "amount:" << this->_amount << ";"
    << "closed" << std::endl;
}