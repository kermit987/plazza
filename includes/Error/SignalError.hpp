//
// SignalError.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 23:22:35 2016 Victor Le
// Last update Sat Apr 23 14:59:02 2016 Victor Le
//

#ifndef SIGNALERROR_HPP_
# define SIGNALERROR_HPP_

# include <exception>
# include <string>

/// Exception class.
/**
   To be used when an error occured when signal syscall.
*/
class	SignalError: public std::exception
{
public:
  /// Constructor.
  /**
     \param signalName The name of a signal.
  */
  SignalError(const std::string &signalName);

  /// Destructor.
  virtual ~SignalError(void) throw();

  /// Inherited from std::exception.
  virtual const char	*what(void) const throw();

private:
  const std::string	m_signalName; /**< Name of a signal. */
};

#endif /* !SIGNALERROR_HPP_ */
