//
// typedefs.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Mon Apr 11 11:40:28 2016 Victor Le
// Last update Sun Apr 17 17:43:39 2016 Steven Loo Fat
//

#ifndef TYPEDEFS_HPP_
# define TYPEDEFS_HPP_

# include <string>
# include <iterator>
# include <pthread.h>
# include <vector>
# include <list>

class Order;
class Process;

typedef std::vector<std::string>			t_VFile;
typedef std::vector<std::string>			t_VToken;
typedef std::istream_iterator<std::string>		t_IStrIterator;
typedef std::vector<Order>				t_VOrder;
typedef std::list<std::pair<Process *,pthread_t *> >	t_list_of_pair;
typedef std::pair<Process *, pthread_t *>		t_pair;

#endif /* !TYPEDEFS_HPP_ */
