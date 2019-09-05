//
// FileError.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 15:09:08 2016 Victor Le
// Last update Sat Apr 23 09:21:45 2016 Victor Le
//

#include <cstring>
#include <errno.h>
#include "FileError.hpp"

FileError::FileError(void)
{}

FileError::~FileError(void) throw()
{}

const char	*FileError::what(void) const throw()
{
  std::string	msg("File error: ");

  msg += strerror(errno);
  return (msg.c_str());
}
