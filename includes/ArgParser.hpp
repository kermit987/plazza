//
// ArgParser.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 09:13:53 2016 Victor Le
// Last update Thu Apr 14 11:52:14 2016 Victor Le
//

#ifndef ARGPARSER_HPP_
# define ARGPARSER_HPP_

# include <string>

/// Class which parse main argument.
class	ArgParser
{
public:
  /// Basic constructor.
  ArgParser(void);

  /// Destructor.
  ~ArgParser(void);

  /// Parse the argument of main.
  /**
     \param ac 1st argument of main.
     \param av 2nd argument of main.
     \return false on error, else true.
     Display errors.
  */
  bool	parseArg(int ac, char **av);

  /// Get the number of thread the user want.
  /**
     \return The number of thread the user want.
  */
  int	getNbThread(void) const;

private:
  int	m_nbThread; /**< The number of thread the user wants. */

  /// Convert a string into a number and store it in m_nbThread.
  /**
     \param str The string to be converted.
     The string must contains only digits.
     Throw InvalidArgument if it cannot convert.
   */
  void	convertToInt(const std::string &str);
};

#endif /* !ARGPARSER_HPP_ */
