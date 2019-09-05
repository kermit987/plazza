//
// PipeBase.cpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:52:13 2016 Victor Le
// Last update Sat Apr 23 15:18:50 2016 Victor Le
//

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include "PipeBase.hpp"
#include "PipeError.hpp"

PipeBase::PipeBase(void):
  m_fd(-1), m_path("")
{}

PipeBase::PipeBase(const std::string &path, const PipeFlag &flag):
  m_fd(-1), m_path("")
{
  openNamedPipe(path, flag);
}

PipeBase::PipeBase(const PipeBase &pb):
  m_fd(pb.m_fd), m_path(pb.m_path)
{}

PipeBase::~PipeBase(void)
{}

PipeBase	&PipeBase::operator=(const PipeBase &pb)
{
  if (this != &pb)
    {
      m_fd = pb.m_fd;
      m_path = pb.m_path;
    }
  return (*this);
}

const int	&PipeBase::getFd(void) const
{
  return (m_fd);
}

const std::string	&PipeBase::getPath(void) const
{
  return (m_path);
}

void	PipeBase::openNamedPipe(const std::string &path, const PipeFlag &flag)
{
  closeNamedPipe();
  m_path = path;
  if (access(m_path.c_str(), F_OK) == -1)
    createNamedPipe();
  if ((m_fd = open(m_path.c_str(), static_cast<int>(flag))) == -1)
    throw PipeError(m_path);
}

void	PipeBase::closeNamedPipe(void)
{
  if (m_fd != -1)
    {
      close(m_fd);
      unlink(m_path.c_str());
      resetState();
    }
}

// Private
void	PipeBase::resetState(void)
{
  m_fd = -1;
  m_path.clear();
}

void	PipeBase::createNamedPipe(void)
{
  const int	mode(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  if (mkfifo(m_path.c_str(), mode) == -1)
    throw PipeError(m_path);
}
