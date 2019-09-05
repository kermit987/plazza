//
// InvalidArgument.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 10:04:20 2016 Victor Le
// Last update Sun Apr 10 11:19:10 2016 Victor Le
//

#include "InvalidArgument.hpp"

InvalidArgument::InvalidArgument(const std::string &msg):
  std::exception(), m_msg(msg)
{}

InvalidArgument::~InvalidArgument(void) throw()
{}

const char	*InvalidArgument::what(void) const throw()
{
  return (m_msg.c_str());
}
