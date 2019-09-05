//
// LogicalError.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Thu Apr 21 15:18:29 2016 Victor Le
// Last update Thu Apr 21 15:27:36 2016 Victor Le
//

#ifndef LOGICALERROR_HPP_
# define LOGICALERROR_HPP_

# include <exception>
# include <string>

/// Exception class.
/**
   Use when something illogical occured.
*/
class	LogicalError: public std::exception
{
public:
  /// Constructor.
  /**
     \param msg The message associated with this exception.
  */
  LogicalError(const std::string &msg);

  /// Destructor.
  virtual ~LogicalError(void) throw();

  /// Inherit from std::exception
  virtual const char	*what(void) const throw();

private:
  std::string	m_msg; /**< The message associated with the exception. */
};

#endif /* !LOGICALERROR_HPP_ */
