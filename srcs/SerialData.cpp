//
// SerialData.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Tue Apr 12 11:41:38 2016 Victor Le
// Last update Sun Apr 24 16:38:46 2016 Victor Le
//

#include "SerialData.hpp"
#include "SerializeError.hpp"

SerialData::SerialData(void)
{}

SerialData::~SerialData(void)
{}

const std::stringstream	&SerialData::getStream(void) const
{
  return (m_stream);
}

SerialData	&SerialData::operator<<(const Order &order)
{
  t_VFile::const_iterator	it(order.getFiles().begin());
  t_VFile::const_iterator	itEnd(order.getFiles().end());

  m_stream << '{' << std::endl;
  m_stream << static_cast<int>(order.getInfoType()) << std::endl;
  m_stream << '[' << std::endl;
  while (it != itEnd)
    {
      m_stream << *it << std::endl;
      ++it;
    }
  m_stream << ']' << std::endl;
  m_stream << '}' << std::endl;
  return (*this);
}

SerialData	&SerialData::operator>>(Order &order)
{
  int		infoType;
  std::string	line;
  Order		tmpOrder;

  try
    {
      std::getline(m_stream, line);
      checkStartOfSerialData(line);

      m_stream >> infoType;
      checkDataValidity();
      tmpOrder.setInfoType(static_cast<t_info>(infoType));
      m_stream.ignore(1, '\n');

      std::getline(m_stream, line);
      checkStartOfArray(line);

      std::getline(m_stream, line);
      while (m_stream && line != "]")
	{
	  if (!line.empty())
	    tmpOrder.addFile(line);
	  std::getline(m_stream, line);
	}

      if (!m_stream)
	throw SerializeError("Internal error during unserialization.");

      checkEndOfArray(line);
      std::getline(m_stream, line);
      checkEndOfSerialData(line);
    }
  catch (const SerializeError &e)
    {
      m_stream.clear();
      while (m_stream && line != "}")
	std::getline(m_stream, line);
      if (e.needRethrow())
	throw ;
    }
  order = tmpOrder;
  return (*this);
}

SerialData	&SerialData::operator<<(const std::string &str)
{
  m_stream << "{" << std::endl;
  m_stream << str << std::endl;
  m_stream << "}" << std::endl;
  return (*this);
}

SerialData	&SerialData::operator>>(std::string &str)
{
  std::string	tmp;
  std::string	line;

  try
    {
      std::getline(m_stream, line);
      checkStartOfSerialData(line);

      std::getline(m_stream, tmp);

      std::getline(m_stream, line);
      checkEndOfSerialData(line);
    }
  catch (const SerializeError &e)
    {
      m_stream.clear();
      while (m_stream && line != "}")
	std::getline(m_stream, line);
      if (e.needRethrow())
	throw ;
    }
  str = tmp;
  return (*this);
}

SerialData	&SerialData::operator<<(const std::vector<std::string> &array)
{
  std::vector<std::string>::const_iterator		it(array.begin());
  const std::vector<std::string>::const_iterator	itEnd(array.end());

  m_stream << "{" << std::endl << "[" << std::endl;
  while (it != itEnd)
    {
      m_stream << *it << std::endl;
      ++it;
    }
  m_stream << "]" << std::endl << "}" << std::endl;
  return (*this);
}

SerialData	&SerialData::operator>>(std::vector<std::string> &array)
{
  std::string			line;
  std::vector<std::string>	tmp;

  try
    {
      std::getline(m_stream, line);
      checkStartOfSerialData(line);
      std::getline(m_stream, line);
      checkStartOfArray(line);

      std::getline(m_stream, line);
      while (m_stream && line != "]")
	{
	  if (!line.empty())
	    tmp.push_back(line);
	  std::getline(m_stream, line);
	}

      checkEndOfArray(line);
      std::getline(m_stream, line);
      checkEndOfSerialData(line);
    }
  catch (const SerializeError &e)
    {
      m_stream.clear();
      while (m_stream && line != "}")
	std::getline(m_stream, line);
      if (e.needRethrow())
	throw ;
    }
  array = tmp;
  return (*this);
}

SerialData	&SerialData::operator<<(std::stringstream &ss)
{
  std::string	line;

  while (ss && line != "}")
    {
      std::getline(ss, line);
      m_stream << line << std::endl;
    }
  if (!ss)
    ss.clear();
  if (line == "}")
    m_stream << line << std::endl;
  return (*this);
}

//Private
void	SerialData::checkStartOfSerialData(const std::string &line) const
{
  if (line != "{")
    throw SerializeError("Data corruption: Missing '{' at start of object data.", false);
}

void	SerialData::checkStartOfArray(const std::string &line) const
{
  if (line != "[")
    throw SerializeError("Data corruption: Missing'[' at start of array data");
}

void	SerialData::checkEndOfSerialData(const std::string &line) const
{
  if (line != "}")
    throw SerializeError("Data corruption: Missing '}' at end of object data.");
}

void	SerialData::checkEndOfArray(const std::string &line) const
{
  if (line != "]")
    throw SerializeError("Data corruption: Missing']' at end of array data");
}

void	SerialData::checkDataValidity(void) const
{
  if (!m_stream)
    throw SerializeError("Bad format: Serialized data and filled object have different type");
}
