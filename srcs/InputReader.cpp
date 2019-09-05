//
// InputReader.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 14:27:24 2016 Victor Le
// Last update Sun Apr 10 15:42:58 2016 Victor Le
//

#include <iostream>
#include "InputReader.hpp"

InputReader::InputReader(void)
{}

InputReader::~InputReader(void)
{}

bool	InputReader::readInput(void)
{
  std::getline(std::cin, m_input);
  return (std::cin);
}

const std::string	&InputReader::getInput(void) const
{
  return (m_input);
}
