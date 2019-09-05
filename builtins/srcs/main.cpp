//
// main.cpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Wed Apr 20 17:56:55 2016 sayavong frederic
// Last update Thu Apr 21 02:55:05 2016 sayavong frederic
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include "InvalidPath.hpp"
#include "LS.hpp"
#include "Chdir_dir.hpp"

std::string	cut_path(const std::string str)
{
  std::string	file;
  int		i;

  i = 0;
  while (str[i] != ' ')
    i = i + 1;
  i = i + 1;
  while (str[i] != '\0')
    {
      file += str[i];
      i = i + 1;
    }
  return (file);
}

int		main(int ac, char **av)
{
  std::string	line;

  (void)ac;
  (void)av;
  while (getline(std::cin, line))
    {
      if (line == "ls")
	LS::show_actual_directory();
      if (line.find("cd") != std::string::npos)
	Chdir_dir::move_directory(cut_path(line));
    }
  return (0);
}
