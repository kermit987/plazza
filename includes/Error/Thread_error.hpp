//
// Thread_error.hpp for  in /home/steven/rendu/cpp_plazza/includes/Error
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Sun Apr 17 20:17:57 2016 Steven Loo Fat
// Last update Sun Apr 17 20:19:11 2016 Steven Loo Fat
//

#ifndef THREAD_ERROR_HPP_
# define THREAD_ERROR_HPP_

# include <exception>
# include <string>

class	Thread_error: public std::exception
{
public:
  Thread_error(const std::string &msg);
  virtual ~Thread_error(void) throw();

  virtual const char	*what(void) const throw();

private:
  std::string	m_msg;
};

#endif /* !THREAD_ERROR_HPP_ */
