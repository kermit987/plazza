//
// SerialData.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Tue Apr 12 11:37:58 2016 Victor Le
// Last update Sun Apr 24 14:48:34 2016 Victor Le
//

#ifndef SERIALDATA_HPP_
# define SERIALDATA_HPP_

# include <sstream>
# include "Order.hpp"

/// Class which serialize and unserialize objects.
class	SerialData
{
public:
  /// Constructor.
  SerialData(void);

  /// Destructor.
  ~SerialData(void);

  /// Get the stream of data of the object.
  /**
     \return The current stream of this object.
  */
  const std::stringstream	&getStream(void) const;

  /// Operator<< overload. Serialize Order object.
  /**
     \param order The order to serialize.
     \return The current SerialData object.
  */
  SerialData	&operator<<(const Order &order);

  /// Operator>> overload. Unserialize Order object.
  /**
     Exception unsafe: 'm_stream' will discard the current data and make next one available, if any.
     Exception safe: 'order' will not be modified on error.

     \param order The order to fill with serialized data.
     \return The current SerialData object.
  */
  SerialData	&operator>>(Order &order);

  /// Operator<< overload. Serialize String object.
  /**
     \param str The string to serialize.
     \return The current SerialData object.
  */
  SerialData	&operator<<(const std::string &str);

  /// Operator>> overload. Unserialize String object.
  /**
     Exception unsafe: 'm_stream' will discard the current data and make next one available, if any.
     Exception safe: 'order' will not be modified on error.

     \param str The string to fill with serialized data.
     \return The current SerialData object.
  */
  SerialData	&operator>>(std::string &str);

  /// Operator<< overload. Unserialize an array of string.
  /**
     \param array The array to fill with serialized data.
     \return The current SerialData object.
   */
  SerialData	&operator<<(const std::vector<std::string> &array);

  /// Operator>> overload. Unserialize an array of string.
  /**
     Exception unsafe: 'm_stream' will discard the current data and make next one available, if any.
     Exception safe: 'order' will not be modified on error.

     \param array The string to fill with serialized data.
     \return The current SerialData object.
  */
  SerialData	&operator>>(std::vector<std::string> &array);

  /// Operator<< overload. Receive raw data from a file.
  /**
     Exception unsafe: 'file' will discard the data it reads.

     \param file The file from where to get raw data.
     \return The current SerialData object.
   */
  SerialData	&operator<<(std::stringstream &file);

private:
  std::stringstream	m_stream; /**< The stream of data. */

  /// Check if the SerialData start correctly.
  /**
     \param line The line which should have the start of the SerialData.
     Throw SerializeError on error.
  */
  void	checkStartOfSerialData(const std::string &ilne) const;

  /// Check if the SerialData is on the start of an array of data.
  /**
     \param line The line which should have the start of an array.
     Throw SerializeError on error.
  */
  void	checkStartOfArray(const std::string &line) const;

  /// Check if the SerialData end correctly.
  /**
     \param line The line which should have the end of the SerialData.
     Throw SerializeError on error.
  */
  void	checkEndOfSerialData(const std::string &ilne) const;

  /// Check if the SerialData is on the end of an array of data.
  /**
     \param line The line which should have the end of an array.
     Throw SerializeError on error.
  */
  void	checkEndOfArray(const std::string &line) const;

  /// Check if the stream is still valid after data extraction.
  /**
     Throw SerializeError on error.
  */
  void	checkDataValidity(void) const;
};

#endif /* !SERIALDATA_HPP_ */
