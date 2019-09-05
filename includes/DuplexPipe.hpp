//
// DuplexPipe.hpp for plazza in /home/le_l/Workspace/test/DuplexPipe
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Wed Apr 20 22:43:37 2016 Victor Le
// Last update Sun Apr 24 14:39:10 2016 Victor Le
//

#ifndef DUPLEXPIPE_HPP_
# define DUPLEXPIPE_HPP_

# include "PipeIn.hpp"
# include "PipeOut.hpp"
# include "Order.hpp"
# include "SigpipeHandler.hpp"

/// Class to manage operation on named pipe.
class	DuplexPipe
{
public:
  /// Constructor.
  /**
     \param pathIn A path to an named pipe.
     \param handler A SIGPIPE handler object.
  */
  DuplexPipe(const std::string &path, SigpipeHandler &handler);

  /// Copy constructor.
  /**
     \parma dp A DuplexPipe object.
  */
  DuplexPipe(const DuplexPipe &dp);

  /// Destructor.
  ~DuplexPipe(void);

  /// Assignment operator.
  /**
     \param dp A DuplexPipe object to copy.
     \return The current DuplexPipe object.
  */
  DuplexPipe	&operator=(const DuplexPipe &dp);

  /// Close the "input" named pipe.
  void	closeInput(void);

  /// Close the "output" named pipe.
  void	closeOutput(void);

  /// Send an order via the "input" named pipe.
  /**
     \param order An order to send.
     \return If the order is send.

     Throw PipeError if it cannot send order for any other reason else that interrupted by SIGPIPE.
  */
  bool	sendOrder(const Order &order);

  /// Get an order via the "output" named pipe.
  /**
     \param order An order fill with an order to get.

     Can throw errors.
  */
  void	getOrder(Order &order);

  /// Send an array of strings via the "input" named pipe.
  /**
     \param arr An array of strings to send.
     \return If the array is send.

     Throw PipeError if it cannot send order for any other reason else that intterupted by SIGPIPE.
  */
  bool	sendResult(const t_VFile &arr);

  /// Get an array of strings via the "output" named pipe.
  /**
     \param arr An array of strings.

     Can throw errors.
  */
  void	getResult(t_VFile &arr);

private:
  PipeIn		m_in; /**< The input side of named pipe. */
  PipeOut		m_out; /**< The output side of named pipe. */
  SigpipeHandler	&m_sigpipeHandler; /**< A reference on a SIGPIPE handler object. */

  /// Check if 'm_out' is open.
  /**
     \throw LogicalError if it is close.
   */
  void	checkOutputIsOpen(void);

  /// Check if 'm_in' is open.
  /**
     \throw LogicalError if it is close.
   */
  void	checkInputIsOpen(void);
};

#endif /* !DUPLEXPIPE_HPP_ */
