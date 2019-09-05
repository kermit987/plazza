//
// Encryption.hpp for plazza in /home/sayavo_f/test/plazza
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Tue Apr 12 20:38:15 2016 sayavong frederic
// Last update Sun Apr 24 14:57:31 2016 Victor Le
//

#ifndef ENCRYPTION_H_
# define ENCRYPTION_H_

# include <vector>
# include <string>
# include <map>
# include "IEncryption.hpp"
# include "OrderInfo.hpp"

class	Encryption
{
public:
  Encryption();
  virtual ~Encryption();
  std::vector<std::string>	&decipherFile(const std::string &file, t_info);
  std::vector<std::string>	&giveFinalMap(IEncryption **deciphers);
  int				check_normal_poss(std::map<int, int> &);
private:
  std::vector<std::string>	tab;
  IEncryption			*deciphers[4];
  std::vector<std::string>	&create_map(IEncryption **deciphers);
  int				check_occ(std::map<int, int> &map);
  int				max_value(std::map<int, int> &map);
  void				more_keys(std::multimap<int, std::string> &map, int more_occ);
  std::vector<std::string>	final_map;
  std::map<int, std::string>	possibilities;
};

#endif /* !ENCRYPTION_H_ */
