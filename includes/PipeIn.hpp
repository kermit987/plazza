//
// PipeIn.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:46:53 2016 Victor Le
// Last update Thu Apr 21 15:47:10 2016 Victor Le
//

#ifndef PIPEIN_HPP_
# define PIPEIN_HPP_

# include <sstream>
# include <string>
# include "PipeBase.hpp"
# include "SerialData.hpp"

/// Class which manage input side of a named pipe.
class	PipeIn: public PipeBase
{
public:
  /// Constructor.
  PipeIn(void);

  /// Constructor. Open a named pipe. Create it if necessary.
  /**
     \param path A path to a named pipe.
  */
  PipeIn(const std::string &path);

  /// Copy constructor.
  /**
     \param pi The PipeIn object to copy.
  */
  PipeIn(const PipeIn &pi);

  /// Destructor.
  virtual ~PipeIn(void);

  /// Assignment operator.
  /**
     \param pi The PipeIn object to copy.
  */
  PipeIn		&operator=(const PipeIn &pi);

  /// Open a named pipe to get data from it. Create it if necessary.
  /**
     \param path A path to a named pipe.

     Throw PipeError if it fails to open/create the named pipe.
  */
  void			openNamedPipe(const std::string &path);

  /// Operator>> overload. Fill the data with part of the buffer.
  /**
     \param sd A data serialiazer.
     \return The current PipeIn object.
  */
  PipeIn		&operator>>(SerialData &sd);

private:
  std::stringstream	m_buffer; /**< Buffer of what contains the named pipe. */

  /// Bufferize the contents of the named pipe.
  void			bufferizeNamedPipe(void);
};

#endif /* !PIPEIN_HPP_ */
