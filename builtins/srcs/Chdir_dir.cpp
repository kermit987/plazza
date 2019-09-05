//
// Chdir_dir.cpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Thu Apr 21 01:34:18 2016 sayavong frederic
// Last update Thu Apr 21 03:15:42 2016 sayavong frederic
//

#include <unistd.h>
#include <errno.h>
#include <iostream>
#include "Chdir_dir.hpp"
#include "InvalidPath.hpp"

Chdir_dir::Chdir_dir()
{}

Chdir_dir::~Chdir_dir()
{}

void            Chdir_dir::Dir_failed(const std::string str, const std::string error)
{
  try
    {
      throw InvalidPath(error);
    }
  catch (const std::exception &e)
    {
      std::cout << str << " : " << e.what() << std::endl;
    }
}

void	Chdir_dir::move_directory(const std::string str)
{
  int	m;

  std::cout << str << std::endl;
  if ((m = chdir(str.c_str())) == -1)
    Chdir_dir::Dir_failed(str, "Wrong path");
}
