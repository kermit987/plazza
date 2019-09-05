//
// Process.hpp for  in /home/steven/rendu/cpp_plazza/srcs
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Thu Apr 14 11:58:07 2016 Steven Loo Fat
// Last update Sun Apr 24 19:12:28 2016 Steven Loo Fat
//

#ifndef PROCESS_H_
# define PROCESS_H_

# include <mutex>
# include <string>
# include <thread>
# include <condition_variable>
# include "Order.hpp"
# include "typedefs.hpp"
# include "Encryption.hpp"
# include "DuplexPipe.hpp"

class Process
{
public:
  Process(DuplexPipe &, DuplexPipe &, const int &);
  Process(const Process &);
  ~Process();
  Process	&operator=(const Process &);
public:
  bool	Init();
  void	child();
  int	launch_decrypt(const int &);
  int	feed_variable(std::string &, t_info &, const int &);
  void	decrypt(const std::string &, const t_info &);
  void	empty_or_not(bool &);
  void	wait_vector(int);
  void	wait_vector(int, std::thread);
  void	feed_variable_next(std::string &, t_info &);
  void	destroy_thread(const int &);
private:
  std::mutex			mutex;
  std::condition_variable	cv;
  Order				order; // pour le pipeout
  DuplexPipe			&pipe_out;
  DuplexPipe			&pipe_in;
  int				nb_thread;
  Encryption			encryption;   // avoir access au fonction
  t_VFile			tmp_VFile;
  t_info			tmp_info;
  std::vector<std::string>	decrypt_data; // resultat en gros
  std::vector< std::pair<int, std::thread> >	vector_thread;
  std::vector<int>				vector_wait;
  std::vector<std::condition_variable>		vector_condition;
};

#endif // _PROCESS_H_
