//
// PipeError.cpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 23:24:04 2016 Victor Le
// Last update Wed Apr 20 23:30:14 2016 Victor Le
//

#include <cstring>
#include <errno.h>
#include "PipeError.hpp"

PipeError::PipeError(const std::string &path):
  std::exception(), m_path(path)
{}

PipeError::~PipeError(void) throw()
{}

const char	*PipeError::what(void) const throw()
{
  std::string	str(std::string("Pipe Error: ") + m_path + ": " + strerror(errno));

  return (str.c_str());
}
