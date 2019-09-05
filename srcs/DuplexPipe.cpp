//
// DuplexPipe.cpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:44:24 2016 Victor Le
// Last update Sun Apr 24 15:08:45 2016 Victor Le
//

#include <unistd.h>
#include "DuplexPipe.hpp"
#include "SerialData.hpp"
#include "LogicalError.hpp"
#include "PipeError.hpp"

DuplexPipe::DuplexPipe(const std::string &path, SigpipeHandler &handler):
  m_in(path), m_out(path), m_sigpipeHandler(handler)
{}

DuplexPipe::DuplexPipe(const DuplexPipe &dp):
  m_in(dp.m_in), m_out(dp.m_out), m_sigpipeHandler(dp.m_sigpipeHandler)
{}

DuplexPipe::~DuplexPipe(void)
{}

DuplexPipe	&DuplexPipe::operator=(const DuplexPipe &dp)
{
  if (this != &dp)
    {
      m_in = dp.m_in;
      m_out = dp.m_out;
      m_sigpipeHandler = dp.m_sigpipeHandler;
    }
  return (*this);
}

void	DuplexPipe::closeInput(void)
{
  m_in.closeNamedPipe();
}

void	DuplexPipe::closeOutput(void)
{
  m_out.closeNamedPipe();
}

bool	DuplexPipe::sendOrder(const Order &order)
{
  checkOutputIsOpen();
  SerialData	sd;
  std::string	str;

  sd << order;
  str = sd.getStream().str();
  if (::write(m_out.getFd(), str.c_str(), str.size()) == -1)
    {
      if (m_sigpipeHandler.isSIGPIPEcatched())
	return (false);
      throw PipeError(m_out.getPath());
    }
  return (true);
}

void	DuplexPipe::getOrder(Order &order)
{
  checkInputIsOpen();
  SerialData	sd;
  Order		tmp;

  m_in >> sd;
  sd >> tmp;
  order = tmp;
}

bool	DuplexPipe::sendResult(const std::vector<std::string> &arr)
{
  checkOutputIsOpen();
  SerialData	sd;
  std::string	str;

  sd << arr;
  str = sd.getStream().str();
  if (::write(m_out.getFd(), str.c_str(), str.size()) == -1)
    {
      if (m_sigpipeHandler.isSIGPIPEcatched())
	return (false);
      throw PipeError(m_out.getPath());
    }
  return (true);
}

void	DuplexPipe::getResult(std::vector<std::string> &arr)
{
  checkInputIsOpen();
  SerialData			sd;
  std::vector<std::string>	tmp;

  m_in >> sd;
  sd >> tmp;
  arr = tmp;
}

// Private
void	DuplexPipe::checkOutputIsOpen(void)
{
  if (m_out.getFd() == -1)
    throw LogicalError("The output pipe is close");
}

void	DuplexPipe::checkInputIsOpen(void)
{
  if (m_in.getFd() == -1)
    throw LogicalError("The input pipe is close");
}
