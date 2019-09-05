//
// Caesar.hpp for plazza in /home/sayavo_f/test/plazza/include
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Tue Apr 12 19:34:25 2016 sayavong frederic
// Last update Tue Apr 19 18:41:46 2016 sayavong frederic
//

#ifndef CAESAR_H_
# define CAESAR_H_

# include <string>
# include <map>
# include "AEncryption.hpp"
# include "Encryption.hpp"
# include "OrderInfo.hpp"

class	CaesarCipher : public AEncryption
{
public:
  CaesarCipher();
  virtual ~CaesarCipher();
  virtual void		decipherLine(const t_info &info, const std::string &line);
  virtual std::map<int, int>	&getKeys();
  virtual std::multimap<int, std::string>	&possibilities();
  virtual bool	no_match_check(const t_info &info, const std::string &line);
  virtual void	check_on_map(const t_info &info, const std::string &line);

  void		check_caesar_right(const std::string &file, const int &crypt, const t_info &info, std::string &sentence);
private:
  std::map<int, int>			caesar_keys;
  std::multimap<int, std::string>	caesar_possibilities;

  bool		make_changes(const std::string &line, std::string &to_copy, const int &key, const t_info &info);
};

#endif /* !CAESAR_H_ */
