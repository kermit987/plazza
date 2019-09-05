//
// open_file.cpp for plazza in /home/sayavo_f/test/plazza/src
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Thu Apr  7 09:11:26 2016 sayavong frederic
// Last update Sun Apr 24 14:57:34 2016 Victor Le
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Encryption.hpp"
#include "OrderInfo.hpp"
#include "Caesar.hpp"
#include "Xor.hpp"
#include "NoEncryption.hpp"
#include "FileError.hpp"

Encryption::Encryption() : tab(), deciphers()
{
  deciphers[0] = new NoEncryption;
  deciphers[1] = new XorCipher;
  deciphers[2] = new CaesarCipher;
  deciphers[3] = NULL;
}

Encryption::~Encryption()
{
  delete deciphers[0];
  delete deciphers[1];
  delete deciphers[2];
}

int				Encryption::check_occ(std::map<int, int> &map)
{
  int				i;
  int				value;
  std::map<int, int>::iterator	it;

  it = map.begin();
  value = (*it).second;
  i = (*it).first;
  while (it != map.end())
    {
      if (value < (*it).second)
	{
	  value = (*it).second;
	  i = (*it).first;
	}
      ++it;
    }
  return (i);
}

int				Encryption::max_value(std::map<int, int> &map)
{
  std::map<int, int>::iterator	it = map.begin();
  int				value;

  value = (*it).second;
  while (it != map.end())
    {
      if (value < (*it).second)
	value = (*it).second;
      ++it;
    }
  return (value);
}

void						Encryption::more_keys(std::multimap<int, std::string> &map, int more_occ)
{
  std::multimap<int, std::string>::iterator	it = map.begin();

  while (it != map.end())
    {
      if ((*it).first == more_occ)
	this->final_map.push_back((*it).second);
      ++it;
    }
}

std::vector<std::string>	&Encryption::create_map(IEncryption **deciphers)
{
  int				_normal;
  int				_xor;
  int				_cipher;

  _normal = max_value(deciphers[0]->getKeys());
  _xor = max_value(deciphers[1]->getKeys());
  _cipher = max_value(deciphers[2]->getKeys());
  if (_normal >= _xor && _normal >= _cipher)
    more_keys(deciphers[0]->possibilities(), check_occ(deciphers[0]->getKeys()));
  else if (_xor >= _normal && _xor >= _cipher)
    more_keys(deciphers[1]->possibilities(), check_occ(deciphers[1]->getKeys()));
  else
    more_keys(deciphers[2]->possibilities(), check_occ(deciphers[2]->getKeys()));
  return (this->final_map);
}

std::vector<std::string>	&Encryption::decipherFile(const std::string &file, t_info info)
{
  std::ifstream			open_filed(file.c_str());
  std::string			line;

  if (!open_filed)
    throw FileError();
  while (open_filed && getline(open_filed, line))
    {
      deciphers[0]->decipherLine(info, line);
      deciphers[1]->decipherLine(info, line);
      deciphers[2]->decipherLine(info, line);
    }
  if (!open_filed && !open_filed.eof())
    throw FileError();
  create_map(deciphers);
  open_filed.close();
  return (this->final_map);
}
