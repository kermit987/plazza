//
// Thread_error.cpp for  in /home/steven/rendu/cpp_plazza/includes/Error
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Sun Apr 17 20:13:26 2016 Steven Loo Fat
// Last update Sun Apr 24 17:30:15 2016 Victor Le
//

#include "Thread_error.hpp"

Thread_error::Thread_error(const std::string &msg): m_msg(msg)
{

}

Thread_error::~Thread_error() {}

const char	*Thread_error::what(void) const throw()
{
  std::string	str("Error: can't create a thread: ");

  str += m_msg;
  return (str.c_str());
}
