//
// InvalidPath.cpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Wed Apr 20 20:24:34 2016 sayavong frederic
// Last update Thu Apr 21 00:21:34 2016 sayavong frederic
//

#include "InvalidPath.hpp"

InvalidPath::InvalidPath(const std::string &msg) : std::exception(), _msg(msg)
{}

InvalidPath::~InvalidPath(void) throw()
{}

const char	*InvalidPath::what(void) const throw ()
{
  return (_msg.c_str());
}
