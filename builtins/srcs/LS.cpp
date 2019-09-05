//
// Know_file.cpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Thu Apr 21 00:55:15 2016 sayavong frederic
// Last update Thu Apr 21 03:16:57 2016 sayavong frederic
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include "LS.hpp"
#include "InvalidPath.hpp"
#include "Chdir_dir.hpp"

LS::LS()
{}

LS::~LS()
{}

void		LS::Dir_failed(const std::string str)
{
  try
    {
      throw InvalidPath(str);
    }
  catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
}

void		LS::show_actual_directory()
{
  DIR		*direct;
  struct dirent	*directory;

  direct = opendir(".");
  if (direct == NULL)
    Chdir_dir::Dir_failed(".", "Directory failed");
  else
    {
      while ((directory = readdir(direct)) != NULL)
	std::cout << directory->d_name << std::endl;
      closedir(direct);
    }
}
