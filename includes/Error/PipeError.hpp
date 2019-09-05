//
// PipeError.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 23:22:35 2016 Victor Le
// Last update Wed Apr 20 23:44:34 2016 Victor Le
//

#ifndef PIPEERROR_HPP_
# define PIPEERROR_HPP_

# include <exception>
# include <string>

/// Exception class.
/**
   To be used when an error occured when using named pipe.
*/
class	PipeError: public std::exception
{
public:
  /// Constructor.
  /**
     \param path The path to a named pipe.
  */
  PipeError(const std::string &path);

  /// Destructor.
  virtual ~PipeError(void) throw();

  /// Inherited from std::exception.
  virtual const char	*what(void) const throw();

private:
  const std::string	m_path; /**< Path to the concerned named pipe. */
};

#endif /* !PIPEERROR_HPP_ */
