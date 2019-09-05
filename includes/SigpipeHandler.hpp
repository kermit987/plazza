//
// SigpipeHandler.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 23 13:55:20 2016 Victor Le
// Last update Sat Apr 23 14:12:16 2016 Victor Le
//

#ifndef SIGPIPEHANDLER_HPP_
# define SIGPIPEHANDLER_HPP_

/// Class which manage SIGPIPE signal.
class	SigpipeHandler
{
public:
  /// Constructor.
  SigpipeHandler(void);

  /// Destructor.
  ~SigpipeHandler(void);

  /// Trigger the SIGPIPE catch.
  /**
     \return Succeed to trigger the SIGPIPE catch signal.
  */
  bool	activate(void);

  /// Return if a SIGPIPE signal is catched.
  /**
     \return If a SIGPIPE signal is catched.
  */
  bool	isSIGPIPEcatched(void) const;

private:
  bool	m_trigger; /**< Indicates if it catches SIGPIPE signal. */
};

#endif /* !SIGPIPEHANDLER_HPP_ */
