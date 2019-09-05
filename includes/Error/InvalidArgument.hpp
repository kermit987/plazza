//
// InvalidArgument.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 10:03:16 2016 Victor Le
// Last update Sun Apr 10 14:21:06 2016 Victor Le
//

#ifndef INVALIDARGUMENT_HPP_
# define INVALIDARGUMENT_HPP_

# include <exception>
# include <string>

/// Exception class
/**
   To be used when an argument of function is not valid.
*/
class	InvalidArgument: public std::exception
{
public:
  /// Constructor.
  /**
     \param msg The message to be sent with this exception.
  */
  InvalidArgument(const std::string &msg);
  /// Destructor.
  virtual ~InvalidArgument(void) throw();

  /// Inherited from std::exception
  virtual const char	*what(void) const throw();

private:
  const std::string	m_msg; /**< The message associated with this exception. */
};

#endif /* !INVALIDARGUMENT_HPP_ */
