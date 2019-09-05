//
// BadCmd.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Mon Apr 11 17:07:33 2016 Victor Le
// Last update Sun Apr 17 18:26:08 2016 Steven Loo Fat
//

#ifndef BADCMD_HPP_
# define BADCMD_HPP_

# include <exception>
# include <string>

/// Exception class.
/**
   To be used when a comand is not valid.
*/
class	BadCmd: public std::exception
{
public:
  /// Constructor.
  /**
     \param msg The message to associate with the exception.
  */
  BadCmd(const std::string &msg);
  /// Destructor.
  virtual ~BadCmd(void) throw();

  /// Inherited from std::exception.
  virtual const char	*what(void) const throw();

private:
  const std::string	m_msg; /**< The message associated with this exception. */
};

#endif /* !BADCMD_HPP_ */
