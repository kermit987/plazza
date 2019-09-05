//
// Plazza.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 09:07:20 2016 Victor Le
// Last update Sun Apr 24 17:06:58 2016 Victor Le
//

#include <sys/wait.h>
#include <iostream>
#include "Plazza.hpp"
#include "InvalidArgument.hpp"
#include "InputReader.hpp"
#include "CmdParser.hpp"
#include "SerialData.hpp"
#include "typedefs.hpp"
#include "PipeIn.hpp"
#include "PipeOut.hpp"

Plazza::Plazza(const int nbThread):
  m_nbThread(nbThread), m_process(), m_pipesIn(), m_pipesOut(), m_sigpipeHandler()
{
  if (m_nbThread < 0)
    throw InvalidArgument("Number of thread cannot be negative");
  m_sigpipeHandler.activate();
}

Plazza::~Plazza(void)
{}

void		Plazza::run(void)
{
  InputReader	reader;
  CmdParser	parser;
  t_VOrder	orders;

  std::cout << "$> ";
  while (reader.readInput())
    {
      parser.parseCmd(reader.getInput(), orders);
      if (!execOrders(orders))
	break ;
      orders.clear();
      displayResults();
      std::cout << "$> ";
    }
}

bool				Plazza::execOrders(const t_VOrder &orders)
{
  t_VOrder::const_iterator	it(orders.begin());
  int				idx;

  while (it != orders.end())
    {
      idx = selectProcess();
      if (idx == -1)
	{
	  if (!createProcess("plazzaIn1.pipe", "plazzaOut1.pipe"))
	    return (false);
	  idx = m_process.size() - 1;
	}
      if (m_pipesOut[idx].sendOrder(*it))
	++it;
      else
	{
	  m_pipesIn.back().closeInput();
	  m_pipesOut.back().closeOutput();
	  m_pipesIn.pop_back();
	  m_pipesOut.pop_back();
	  m_process.pop_back();
	  wait(NULL);
	}
    }
  return (true);
}

bool	Plazza::createProcess(const std::string &pathPipeIn, const std::string &pathPipeOut)
{
  DuplexPipe	pipeIn(pathPipeIn, m_sigpipeHandler);
  DuplexPipe	pipeOut(pathPipeOut, m_sigpipeHandler);
  Process	process(pipeOut, pipeIn, m_nbThread);

  m_pipesIn.push_back(pipeIn);
  m_pipesOut.push_back(pipeOut);
  m_process.push_back(process);
  if (!process.Init())
    return (false);
  pipeIn.closeOutput();
  pipeOut.closeInput();
  return (true);
}

int	Plazza::selectProcess(void) const
{
  return (m_process.size() - 1);
}

void	Plazza::displayResults(void)
{
  std::vector<DuplexPipe>::iterator		it(m_pipesIn.begin());
  const std::vector<DuplexPipe>::iterator	itEnd(m_pipesIn.end());
  std::vector<std::string>			tmp;

  while (it != itEnd)
    {
      it->getResult(tmp);
      if (!tmp.empty())
	{
	  dumpArrayResult(tmp);
	  tmp.clear();
	}
      ++it;
    }
}

void	Plazza::dumpArrayResult(const std::vector<std::string> &arr) const
{
  std::vector<std::string>::const_iterator		it(arr.begin());
  const std::vector<std::string>::const_iterator	itEnd(arr.end());

  while (it != itEnd)
    {
      std::cout << *it << std::endl;
      ++it;
    }
}
