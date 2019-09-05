//
// Chdir_dir.hpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Thu Apr 21 01:12:07 2016 sayavong frederic
// Last update Thu Apr 21 03:15:31 2016 sayavong frederic
//

#ifndef CHDIR_DIR_H_
# define CHDIR_DIR_H_

# include <string>

class	Chdir_dir
{
  public:
  Chdir_dir();
  ~Chdir_dir();
  static void	move_directory(const std::string str);
  static void	Dir_failed(const std::string str, const std::string error);
  private:
};

#endif /* !CHDIR_DIR_H_ */
