//
// SigpipeHandler.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 23 13:56:12 2016 Victor Le
// Last update Sat Apr 23 14:50:15 2016 Victor Le
//

#include <signal.h>
#include "SigpipeHandler.hpp"
#include "SignalError.hpp"

static bool	g_catched = false;

SigpipeHandler::SigpipeHandler(void):
  m_trigger(false)
{}

SigpipeHandler::~SigpipeHandler(void)
{}

static void	sigpipeHandler(int)
{
  g_catched = true;
}

bool	SigpipeHandler::activate(void)
{
  if (!m_trigger)
    {
      if (signal(SIGPIPE, &sigpipeHandler) == SIG_ERR)
	throw SignalError("SIGPIPE");
      m_trigger = true;
    }
  return (m_trigger);
}

bool	SigpipeHandler::isSIGPIPEcatched(void) const
{
  bool	catched = g_catched;

  if (g_catched == true)
    g_catched = false;
  return (catched);
}
