//
// PipeOut.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:48:19 2016 Victor Le
// Last update Thu Apr 21 01:04:25 2016 Victor Le
//

#ifndef PIPEOUT_HPP_
# define PIPEOUT_HPP_

# include "PipeBase.hpp"

/// Class which manage output side of a named pipe.
class	PipeOut: public PipeBase
{
public:
  /// Constructor.
  PipeOut(void);

  /// Constructor. Open a named pipe. Create it if necessary.
  /**
     \param path A path to a named pipe.
  */
  PipeOut(const std::string &path);

  /// Copy constructor.
  /**
     \param po The PipeOut object to copy.
  */
  PipeOut(const PipeOut &po);

  /// Destructor.
  virtual ~PipeOut(void);

  /// Assignment operator.
  /**
     \param po The PipeOut object to copy.
  */
  PipeOut	&operator=(const PipeOut &po);

  /// Open a named pipe to send data into it. Create it if necessary.
  /**
     \param path A path to a named pipe.

     Throw PipeError it it fails to open/create the named pipe.
  */
  void		openNamedFile(const std::string &path);

  //tmp
  PipeOut	&operator<<(const std::string &str);
};

#endif /* !PIPEOUT_HPP_ */
