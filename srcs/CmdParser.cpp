//
// CmdParser.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 15:45:08 2016 Victor Le
// Last update Tue Apr 12 15:32:46 2016 Victor Le
//

#include <iostream>
#include <sstream>
#include "CmdParser.hpp"
#include "typedefs.hpp"
#include "BadCmd.hpp"

CmdParser::CmdParser(void)
{}

CmdParser::~CmdParser(void)
{}

bool			CmdParser::parseCmd(const std::string &cmd, std::vector<Order> &orders)
{
  std::stringstream	ss(cmd);
  unsigned int		i(0);
  Order			order;

  if (!cmd.empty())
    {
      skipBlank(cmd, i);
      while (i < cmd.size())
	{
	  try
	    {
	      order = getOrder(cmd, i);
	      orders.push_back(order);
	    }
	  catch (const std::exception &e)
	    {
	      std::cout << "Plazza: " << e.what() << std::endl;
	    }
	  if (i < cmd.size() && cmd[i] == ';')
	    ++i;
	  skipBlank(cmd, i);
	}
      return (!orders.empty());
    }
  return (false);
}

// Private
t_info		CmdParser::isInfoType(const std::string &str)
{
  std::string	strInfo[] = {"EMAIL_ADDRESS", "PHONE_NUMBER", "IP_ADDRESS"};
  t_info	vlInfo[] = {EMAIL_ADDRESS, PHONE_NUMBER, IP_ADDRESS, NO_INFO};
  int		i(0);

  while (i < 3 && strInfo[i] != str)
    ++i;
  return (vlInfo[i]);
}

bool	CmdParser::isBlank(const char c)
{
  return (c == ' ' || c == '\t');
}

void	CmdParser::skipBlank(const std::string &str, unsigned int &i)
{
  while (i < str.size() && isBlank(str[i]))
    ++i;
}

std::string	CmdParser::getNextToken(const std::string &str, unsigned int &i)
{
  unsigned int	end(i);
  std::string	token;

  while (end < str.size() && !isBlank(str[end]) && str[end] != ';')
    ++end;
  token = str.substr(i, end - i);
  i = end;
  return (token);
}

Order		CmdParser::getOrder(const std::string &cmd, unsigned int &i)
{
  std::string	token;
  Order		order;

  while (i < cmd.size() && cmd[i] != ';')
    {
      token = getNextToken(cmd, i);
      if (!setOrder(order, token))
	{
	  throw BadCmd("Cannot order more than 1 information.");
	  while (i < cmd.size() && cmd[i] != ';')
	    ++i;
	}
      skipBlank(cmd, i);
    }
  if (order.getInfoType() == NO_INFO)
    throw BadCmd("Missing information to search.");
  else if (order.getFiles().empty())
    throw BadCmd("Missing file to indicate where to search informations.");
  return (order);
}

bool	CmdParser::setOrder(Order &order, const std::string &token)
{
  if (order.getInfoType() != NO_INFO)
    {
      if (isInfoType(token) != NO_INFO)
	return (false);
      order.addFile(token);
      return (true);
    }
  order.setInfoType(isInfoType(token));
  if (order.getInfoType() == NO_INFO)
    order.addFile(token);
  return (true);
}
