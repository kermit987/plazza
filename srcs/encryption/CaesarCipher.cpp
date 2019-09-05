//
// Caesar.cpp for plazza in /home/sayavo_f/Desktop/algo/chiffrage/srcs
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Sun Apr 17 02:04:32 2016 sayavong frederic
// Last update Sat Apr 23 09:02:45 2016 Victor Le
//

#include "Caesar.hpp"

CaesarCipher::CaesarCipher()
{}

CaesarCipher::~CaesarCipher()
{}

std::map<int, int>	&CaesarCipher::getKeys()
{
  return (this->caesar_keys);
}

std::multimap<int, std::string>	&CaesarCipher::possibilities()
{
  return (this->caesar_possibilities);
}

void		CaesarCipher::check_caesar_right(const std::string &line, const int &crypt, const t_info &info, std::string &sentence)
{
  std::string   str;
  int           i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] >= 'A' && line[i] <= 'Z' && (line[i] + crypt) > 'Z')
	str += (64 + (line[i] + crypt - 'Z'));
      else if (line[i] >= 'a' && line[i] <= 'z' && (line[i] + crypt) > 'z')
	str += (96 + (line[i] + crypt - 'z'));
      else
	{
	  if (line[i] >= 'A' && line[i] <= 'Z')
	    str += line[i] + crypt;
	  else if (line[i] >= 'a' && line[i] <= 'z')
	    str += line[i] + crypt;
	  else
	    str += line[i];
	}
      ++i;
    }
  if (check_regex(str, info, sentence) == false)
    sentence.clear();
}

bool		CaesarCipher::make_changes(const std::string &line, std::string &to_copy, const int &key, const t_info &info)
{
  check_caesar_right(line, key, info, to_copy);
  return (!to_copy.empty());
}

bool		CaesarCipher::no_match_check(const t_info &info, const std::string &line)
{
  int		i;
  std::string	to_copy;

  i = 1;
  while (i < 27)
    {
      if (make_changes(line, to_copy, i, info) == true)
	{
	  caesar_possibilities.insert(std::pair<int, std::string>(i, to_copy));
	  if (caesar_keys.find(i) == caesar_keys.end())
	    caesar_keys.insert(std::pair<int, int>(i, 1));
	}
      i = i + 1;
    }
  return (true);
}

void		CaesarCipher::check_on_map(const t_info &info, const std::string &line)
{
  std::map<int, int>::iterator  it;
  std::string   to_copy;

  it = caesar_keys.begin();
  while (it != caesar_keys.end())
    {
      if (make_changes(line, to_copy, (*it).first, info) == true)
	{
	  caesar_possibilities.insert(std::pair<int, std::string>((*it).first, to_copy));
	  caesar_keys[(*it).first] = caesar_keys[(*it).first] + 1;
	}
      ++it;
    }
}

void		CaesarCipher::decipherLine(const t_info &info, const std::string &line)
{
  if (!this->getKeys().empty())
    this->check_on_map(info, line);
  else
    this->no_match_check(info, line);
}
