//
// Fork_error.hpp for  in /home/steven/rendu/cpp_plazza/includes/Error
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Sun Apr 17 19:36:46 2016 Steven Loo Fat
// Last update Sun Apr 17 22:43:41 2016 Steven Loo Fat
//

#ifndef FORK_ERROR_
# define FORK_ERROR_

# include <exception>
# include <string>

class	Fork_error: public std::exception
{
public:
  Fork_error();
  Fork_error(const std::string &);
  virtual ~Fork_error() throw();
  virtual const char	*what(void) const throw();
private:
  const std::string	m_msg;
};

#endif	// !FORK_ERROR_HPP_
