//
// Caesar.cpp for plazza in /home/sayavo_f/Desktop/algo/chiffrage/srcs
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Sat Apr 16 16:13:46 2016 sayavong frederic
// Last update Thu Apr 21 04:12:51 2016 sayavong frederic
//

#include <map>
#include <vector>
#include <iostream>
#include "Xor.hpp"
#include "OrderInfo.hpp"
#include <cstdlib>

XorCipher::XorCipher()
{}

XorCipher::~XorCipher()
{}

std::map<int, int>	&XorCipher::getKeys()
{
  return (this->xor_keys);
}

std::multimap<int, std::string>		&XorCipher::possibilities()
{
  return (this->xor_possibilities);
}

void		XorCipher::Union_xor_changes(const std::string &line, std::string &tmp, const int &key)
{
  union		{short value; char letter[2];};
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      letter[0] = line[i];
      if (line[i + 1] != '\0')
	letter[1] = line[i + 1];
      value = value ^ key;
      tmp += letter[0];
      i = i + 1;
      if (line[i] != '\0')
	{
	  tmp += letter[1];
	  i = i + 1;
	}
    }
}

bool		XorCipher::make_changes(const std::string &line, std::string &to_copy, const int &key, const t_info &info)
{
  int		i;
  std::string	tmp;

  i = 0;
  if (key < 256)
    {
      while (line[i] != '\0')
	{
	  tmp += line[i] ^ key;
	  ++i;
	}
    }
  else
    this->Union_xor_changes(line, tmp, key);
  return (check_regex(tmp, info, to_copy));
}

bool		XorCipher::no_match_check(const t_info &info, const std::string &line)
{
  std::string	to_copy;
  int		i;

  i = 1;
  while (i < 513)
    {
      if (make_changes(line, to_copy, i, info) == true)
	{
	  xor_possibilities.insert(std::pair<int, std::string>(i, to_copy));
	  if (xor_keys.find(i) == xor_keys.end())
	    xor_keys.insert(std::pair<int, int>(i, 1));
	}
      ++i;
    }
  return (true);
}

void		XorCipher::check_on_map(const t_info &info, const std::string &line)
{
  std::map<int, int>::iterator	it;
  std::string	to_copy;

  it = xor_keys.begin();
  while (it != xor_keys.end())
    {
      if (make_changes(line, to_copy, (*it).first, info) == true)
	{
	  xor_possibilities.insert(std::pair<int, std::string>((*it).first, to_copy));
	  xor_keys[(*it).first] = xor_keys[(*it).first] + 1;
	}
      ++it;
    }
}

void		XorCipher::decipherLine(const t_info &info, const std::string &line)
{
  if (!this->getKeys().empty())
    this->check_on_map(info, line);
  else
    this->no_match_check(info, line);
}
