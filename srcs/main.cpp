//
// main.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 09:09:50 2016 Victor Le
// Last update Sun Apr 10 15:09:49 2016 Victor Le
//

#include <iostream>
#include "Plazza.hpp"
#include "ArgParser.hpp"

int		corePart(const int nbThread)
{
  try
    {
      Plazza	plazza(nbThread);

      plazza.run();
    }
  catch (const std::exception &e)
    {
      std::cerr << "./plazza: " << e.what() << std::endl;
      return (1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  ArgParser	argParser;

  if (!argParser.parseArg(ac, av))
    return (1);
  return (corePart(argParser.getNbThread()));
}
