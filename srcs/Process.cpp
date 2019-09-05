//
// Process.cpp for  in /home/steven/rendu/cpp_plazza/srcs
//
// Made by Steven Loo Fat
// Login   <loofat_s@epitech.net>
//
// Started on  Thu Apr 14 11:59:15 2016 Steven Loo Fat
// Last update Sun Apr 24 19:12:31 2016 Steven Loo Fat
//

#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include "Process.hpp"
#include "Plazza.hpp"
#include "Fork_error.hpp"
#include "Thread_error.hpp"
#include "Encryption.hpp"
#include "PipeOut.hpp"
#include "PipeIn.hpp"

std::atomic<int> i{0};

Process::Process(DuplexPipe &input, DuplexPipe &output, const int &_nb_thread):
  pipe_out(output), pipe_in(input), nb_thread(_nb_thread)
{}

Process::Process(const Process &p):
  pipe_out(p.pipe_out), pipe_in(p.pipe_in), nb_thread(p.nb_thread)
{}

Process::~Process()
{}

Process	&Process::operator=(const Process &p)
{
  if (this != &p)
    {
      pipe_out = p.pipe_out;
      pipe_in = p.pipe_in;
      nb_thread = p.nb_thread;
    }
  return (*this);
}

void	Process::decrypt(const std::string &transporter_VFile, const t_info &transporter_info)
{
  std::vector<std::string>	decrypt_data;
  try
    {
      decrypt_data = encryption.decipherFile(transporter_VFile,
					     transporter_info);
    }
  catch (const std::exception &e)
    {
      std::cerr << "./plazza: " << transporter_VFile << ": " << e.what() << std::endl;
    }
  std::lock_guard<std::mutex>	guard(this->mutex);
  pipe_out.sendResult(decrypt_data);
}

void	Process::feed_variable_next(std::string &transporter_VFile, t_info &transporter_info)
{
  std::lock_guard<std::mutex>	guard(this->mutex);

  transporter_VFile = this->tmp_VFile.back();
  transporter_info = this->tmp_info;
  this->tmp_VFile.pop_back();
}

void	Process::destroy_thread(const int &id)
{
  std::lock_guard<std::mutex>	guard(this->mutex);
  std::vector<std::pair<int, std::thread> >::iterator  it = this->vector_thread.begin();

  while (it != this->vector_thread.end() && it->first != id)
    ++it;
  if (it != this->vector_thread.end())
    this->vector_thread .erase(it);
}

int	Process::feed_variable(std::string &transporter_VFile, t_info &transporter_info, const int &id)
{
  if (this->tmp_VFile.size() != 0) // si il reste des ordres ou pas
    feed_variable_next(transporter_VFile, transporter_info);
  else
    {
      // wait_vector(id);
      std::unique_lock<std::mutex> lk(this->mutex);
      if (!this->cv.wait_for(lk, std::chrono::milliseconds(5000), [](){return i == 0;})) // ici
	{
	  destroy_thread(id);
	  return (-1);
	}
      feed_variable_next(transporter_VFile, transporter_info);
    }
  return (0);
}

void	Process::empty_or_not(bool &empty)
{
  std::lock_guard<std::mutex>	guard(this->mutex);

  if (this->tmp_VFile.size() != 0)
    empty = false;
  else
    empty = true;
}

int	Process::launch_decrypt(const int &id)
{
  std::string	transporter_VFile;
  t_info	transporter_info;
  bool		empty;

  empty = false;
  do
    {
      if ((feed_variable(transporter_VFile, transporter_info, id)) == -1)
	return (-1);
      decrypt(transporter_VFile, transporter_info);
      empty_or_not(empty);
    } while (!empty);
  return (0);
}

int	trampoline(void *access, const int &id)
{
  if ((reinterpret_cast<Process*>(access)->launch_decrypt(id)) == -1)
    return (-1);
  return (0);
}

void	Process::child()
{
  bool	quit(false);

  pipe_out.closeInput();
  pipe_in.closeOutput();
  // Pour l'instant cela ne execute qu'un seul ordre.
  while (!quit)
    {
      try
	{
	  this->pipe_in.getOrder(this->order);
	  quit = true;
	  this->tmp_VFile = this->order.getFiles();
	  this->tmp_info = this->order.getInfoType();
	}
      catch (const std::exception &e)
	{}
      if (quit)
	{
	  if (!this->vector_wait.size())
	    {
	      this->cv.notify_all();
	    }
	  for (int i = 0; (i != this->nb_thread); ++i)
	    this->vector_thread.push_back(std::make_pair(i, std::thread(trampoline, this, i)));
	  for (std::vector< std::pair<int, std::thread> >::iterator i = this->vector_thread.begin();
	       i != this->vector_thread.end(); ++i)
	    i->second.join();
	}
    }
}

bool	Process::Init()
{
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      child();
      return (false);
    }
  else if (pid == -1)
    throw Fork_error("failed");
  return (true);
}
