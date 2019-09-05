//
// SerializeError.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Tue Apr 12 02:15:42 2016 Victor Le
// Last update Sun Apr 24 17:30:57 2016 Victor Le
//

#include "SerializeError.hpp"

SerializeError::SerializeError(const std::string &msg, const bool rethrow):
  std::exception(), m_msg(msg), m_rethrow(rethrow)
{}

SerializeError::~SerializeError(void)
{}

const char	*SerializeError::what(void) const throw()
{
  std::string	str("Serialization error: ");

  str += m_msg;
  return (str.c_str());
}

bool	SerializeError::needRethrow(void) const
{
  return (m_rethrow);
}
