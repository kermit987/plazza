//
// SerializeError.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Tue Apr 12 02:12:48 2016 Victor Le
// Last update Thu Apr 21 16:10:34 2016 Victor Le
//

#ifndef SERIALIZEERROR_HPP_
# define SERIALIZEERROR_HPP_

# include <exception>
# include <string>

/// Exception class
/**
   To be used when an error of un/serialization occured.
*/
class	SerializeError: public std::exception
{
public:
  /// Constructor.
  /**
     \param msg The message to associate with the exception.
     \param rethrow Indicates if the exception needs to be rethrow.
  */
  SerializeError(const std::string &msg, const bool rethrow = true);

  /// Destructor.
  virtual ~SerializeError(void) throw();

  /// Inherited from std::exception.
  virtual const char	*what(void) const throw();

  /// Indicates if this exception need to be rethrow.
  bool	needRethrow(void) const;

private:
  std::string	m_msg; /**< The message associated with the exception. */
  bool		m_rethrow; /**< Indicates if this exception need to be rethrow. */
};

#endif /* !SERIALIZEERROR_HPP_ */
