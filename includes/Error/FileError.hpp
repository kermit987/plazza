//
// FileError.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 15:06:14 2016 Victor Le
// Last update Wed Apr 20 15:12:15 2016 Victor Le
//

#ifndef FILEERROR_HPP_
# define FILEERROR_HPP_

# include <exception>
# include <string>

/// Exception class.
/**
   To be used when a file cannot be opened.
*/
class	FileError: public std::exception
{
public:
  /// Constructor.
  FileError(void);

  /// Destructor.
  virtual ~FileError(void) throw();

  /// Inherited from std::exception.
  virtual const char	*what(void) const throw();
};

#endif /* !FILEERROR_HPP_ */
