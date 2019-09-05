//
// BadCmd.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Mon Apr 11 17:08:36 2016 Victor Le
// Last update Sun Apr 24 17:31:58 2016 Victor Le
//

#include "BadCmd.hpp"

BadCmd::BadCmd(const std::string &msg):
  m_msg(msg)
{}

BadCmd::~BadCmd(void)
{}

const char	*BadCmd::what(void) const throw()
{
  std::string	str("Bad command: ");

  str += m_msg;
  return (str.c_str());
}
