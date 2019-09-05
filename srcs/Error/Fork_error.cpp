//
// Fork_error.cpp for  in /home/steven/rendu/cpp_plazza/includes/Error
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Sun Apr 17 19:50:26 2016 Steven Loo Fat
// Last update Sun Apr 24 17:31:22 2016 Victor Le
//

#include "Fork_error.hpp"

Fork_error::Fork_error(const std::string &msg): m_msg(msg)
{

}

Fork_error::~Fork_error() {}

const char	*Fork_error::what(void) const throw()
{
  std::string	str("Error: fork() failed ");

  str += m_msg;
    return (str.c_str());
}
