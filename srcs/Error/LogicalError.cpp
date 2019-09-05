//
// LogicalError.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Thu Apr 21 15:20:24 2016 Victor Le
// Last update Thu Apr 21 15:28:16 2016 Victor Le
//

#include "LogicalError.hpp"

LogicalError::LogicalError(const std::string &msg):
  std::exception(), m_msg(msg)
{}

LogicalError::~LogicalError(void) throw()
{}

const char	*LogicalError::what(void) const throw()
{
  std::string	str("Logical Error: ");

  str += m_msg;
  return (str.c_str());
}
