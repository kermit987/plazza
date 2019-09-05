//
// Plazza.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 09:07:21 2016 Victor Le
// Last update Sun Apr 24 14:55:31 2016 Victor Le
//

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

# include <vector>
# include "typedefs.hpp"
# include "Process.hpp"
# include "DuplexPipe.hpp"
# include "SigpipeHandler.hpp"

/// Core class of the program.
class	Plazza
{
public:
  /// Basic constructor.
  /**
     \param nbThread The number of thread that will have each process.
  */
  Plazza(const int nbThread);

  /// Destructor.
  ~Plazza(void);

  /// Run the program.
  void		run(void);

private:
  const int			m_nbThread; /**< The number of thread that a process will have. */
  std::vector<Process>		m_process; /**< All child process. */
  std::vector<DuplexPipe>	m_pipesIn; /**< All pipes use to send Order to Processes. */
  std::vector<DuplexPipe>	m_pipesOut; /**< All pipes use to get result from Processes. */
  SigpipeHandler		m_sigpipeHandler; /**< A SIGPIPE signal handler for DuplexPipes. */

  /// Execute the orders it receive.
  /**
     \param orders Receive orders.

     \return The FATHER process returns true. The CHILD process returns false.
   */
  bool		execOrders(const t_VOrder &orders);

  /// Create a new process.
  /**
     \param pathPipeIn Path to the pipe of input.
     \param pathPipeOut Path to the pipe of output.

     \remark This method creates a new process via fork().
     \return The FATHER process returns true. The CHILD process returns false.
  */
  bool		createProcess(const std::string &pathPipeIn, const std::string &pathPipeOut);

  /// Select process.
  /**
     \return The index of the selected process.
   */
  int		selectProcess(void) const;

  /// Read what is on input pipe and display it.
  void		displayResults(void);

  /// Display an array of string.
  /**
     \param arr An array to display.
  */
  void		dumpArrayResult(const std::vector<std::string> &arr) const;
};

#endif /* !PLAZZA_HPP_ */
