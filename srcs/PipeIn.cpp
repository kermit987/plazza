//
// PipeIn.cpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:47:55 2016 Victor Le
// Last update Sun Apr 24 16:53:06 2016 Victor Le
//

#include <unistd.h>
#include <fcntl.h>
#include "PipeIn.hpp"
#include "PipeError.hpp"

PipeIn::PipeIn(void):
  PipeBase(), m_buffer("")
{}

PipeIn::PipeIn(const std::string &path):
  PipeBase(path, PipeBase::PipeFlag::READ), m_buffer("")
{}

PipeIn::PipeIn(const PipeIn &pi):
  PipeBase(pi), m_buffer(pi.m_buffer.str())
{}

PipeIn::~PipeIn(void)
{}

PipeIn	&PipeIn::operator=(const PipeIn &pi)
{
  if (this != &pi)
    {
      PipeBase::operator=(pi);
      m_buffer.str(pi.m_buffer.str());
    }
  return (*this);
}

void	PipeIn::openNamedPipe(const std::string &path)
{
  PipeBase::openNamedPipe(path, PipeBase::PipeFlag::READ);
  if (fcntl(getFd(), F_SETOWN) < 0 ||
      fcntl(getFd(), F_SETFL, O_ASYNC) < 0)
    throw PipeError(getPath());
}

PipeIn	&PipeIn::operator>>(SerialData &sd)
{
  bufferizeNamedPipe();
  sd << m_buffer;
  return (*this);
}

// Private
void	PipeIn::bufferizeNamedPipe(void)
{
  const int	bufSize(1024);
  char		buffer[bufSize + 1] = {0};

  while (::read(getFd(), buffer, bufSize) > 0)
    m_buffer << buffer;
}
