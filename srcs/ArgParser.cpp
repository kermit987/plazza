//
// ArgParser.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 09:15:00 2016 Victor Le
// Last update Thu Apr 14 17:33:05 2016 Victor Le
//

#include <sstream>
#include <string>
#include <iostream>
#include "ArgParser.hpp"
#include "InvalidArgument.hpp"
#include "Regex.hpp"

ArgParser::ArgParser(void): m_nbThread(0)
{}

ArgParser::~ArgParser(void)
{}

bool	ArgParser::parseArg(int ac, char **av)
{
  if (ac != 2)
    {
      std::cerr << "Usage: " << av[0] << " <nb_thread>" << std::endl;
      return (false);
    }
  try
    {
      convertToInt(av[1]);
    }
  catch (std::exception &e)
    {
      std::cerr << av[0] << ": " << e.what() << std::endl;
      return (false);
    }
  return (true);
}

int	ArgParser::getNbThread(void) const
{
  return (m_nbThread);
}

//Private
void			ArgParser::convertToInt(const std::string &str)
{
  std::stringstream	ss;
  Regex			regex("^[[:digit:]]+$", REG_NOSUB | REG_EXTENDED);

  try
    {
      if (!regex.tryMatch(str))
	throw InvalidArgument("Argument is not only composed of digits");
    }
  catch (std::exception &e)
    {
      regex.manualDeletion();
      throw ;
    }
  ss << str;
  ss >> m_nbThread;
  if (m_nbThread < 1)
    throw InvalidArgument("The number of thread cannot be negative or null");
}
