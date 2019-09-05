//
// InvalidPath.hpp for plazza in /home/sayavo_f/Desktop/builtins
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Wed Apr 20 20:22:27 2016 sayavong frederic
// Last update Thu Apr 21 00:20:44 2016 sayavong frederic
//

#ifndef INVALIDPATH_H_
# define INVALIDPATH_H_

# include <exception>
# include <string>

class	InvalidPath : public std::exception
{
public:
  InvalidPath(const std::string &msg);
  ~InvalidPath(void) throw();
  const char	*what() const throw();
private:
  std::string	_msg;
};

#endif /* !INVALIDPATH_H_ */
