//
// PipeOut.cpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:49:16 2016 Victor Le
// Last update Thu Apr 21 14:02:05 2016 Victor Le
//

#include "PipeOut.hpp"

PipeOut::PipeOut(void):
  PipeBase()
{}

PipeOut::PipeOut(const std::string &path):
  PipeBase(path, PipeBase::PipeFlag::WRITE)
{}

PipeOut::PipeOut(const PipeOut &po):
  PipeBase(po)
{}

PipeOut::~PipeOut(void)
{}

PipeOut	&PipeOut::operator=(const PipeOut &po)
{
  if (this != &po)
    PipeBase::operator=(po);
  return (*this);
}

void	PipeOut::openNamedFile(const std::string &path)
{
  PipeBase::openNamedPipe(path, PipeBase::PipeFlag::WRITE);
}
