//
// PipeBase.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:49:53 2016 Victor Le
// Last update Thu Apr 21 00:47:54 2016 Victor Le
//

#ifndef PIPEBASE_HPP_
# define PIPEBASE_HPP_

# include <fcntl.h>
# include <string>

/// Base class for named pipe.
class	PipeBase
{
public:
  enum class PipeFlag: int
    {
      WRITE = O_WRONLY,
      READ = O_RDONLY | O_NONBLOCK
    };

public:
  /// Constructor.
  PipeBase(void);

  /// Constructor.
  /**
     \param path A path.
     \param flag WRITE or READ mode.

     Open a named pipe. Create it before if it does not exists.
  */
  PipeBase(const std::string &path, const PipeFlag &flag);

  /// Copy constructor.
  /**
     \param pb The PipeBase object to copy.
  */
  PipeBase(const PipeBase &pb);

  /// Destructor.
  ~PipeBase(void);

  /// Copy assignment/
  /**
     \param pb The PipeBase object to copy.
  */
  PipeBase	&operator=(const PipeBase &pb);

  /// Get the file descriptor of the current named pipe.
  /**
     \return A file descriptor. -1 if no named pipe is open.
  */
  const int		&getFd(void) const;

  ///Get the path to the current named pipe.
  /**
     \return A path. Empty path if no named pipe is open.
  */
  const std::string	&getPath(void) const;

  /// Open a named pipe. Create it if it does not exists.
  /**
     \param path A path to a named pipe.
     \param flag WRITE or READ mode.

     Throw PipeError if it fails to open/create the named pipe.
  */
  void			openNamedPipe(const std::string &path, const PipeFlag &flag);

  /// Close the current named pipe and delete it.
  /**
     Reset attributs to their initial state. ({-1, ""})
     Do nothing if no named pipe is open.
  */
  void			closeNamedPipe(void);

private:
  int		m_fd;
  std::string	m_path;

  /// Reset object's attributs to their initial state.
  void			resetState(void);

  /// Create a named pipe.
  /**
     It uses the attribut 'm_path' as the name of the new named pipe.
     Throw PipeError if it fails to create the new named pipe.
  */
  void			createNamedPipe(void);
};

#endif /* !PIPEBASE_HPP_ */
