//
// InputReader.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 14:23:31 2016 Victor Le
// Last update Thu Apr 14 11:53:57 2016 Victor Le
//

#ifndef INPUTREADER_HPP_
# define INPUTREADER_HPP_

# include <string>

/// Input reader class
class	InputReader
{
public:
  /// Constructor.
  InputReader(void);

  /// Destructor.
  ~InputReader(void);

  /// Read input from standard input.
  /**
     \return True if it succeed to read input, else false.
  */
  bool			readInput(void);

  /// Give the last input it gets.
  /**
     \return The last input the object gets.
  */
  const std::string	&getInput(void) const;

private:
  std::string	m_input; /**< User input. */
};

#endif /* !INPUTREADER_HPP_ */
