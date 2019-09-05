//
// SignalError.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 23 14:59:18 2016 Victor Le
// Last update Sat Apr 23 15:01:53 2016 Victor Le
//

#include <cstring>
#include <errno.h>
#include <string>
#include "SignalError.hpp"

SignalError::SignalError(const std::string &signalName):
  std::exception(), m_signalName(signalName)
{}

SignalError::~SignalError(void) throw()
{}

const char	*SignalError::what(void) const throw()
{
  std::string	msg("Signal Error: ");

  msg += m_signalName;
  msg += ": ";
  msg += strerror(errno);
  return (msg.c_str());
}
