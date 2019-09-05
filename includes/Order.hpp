//
// Order.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Mon Apr 11 11:23:12 2016 Victor Le
// Last update Wed Apr 13 18:31:47 2016 Steven Loo Fat
//

#ifndef AORDER_HPP_
# define AORDER_HPP_

# include <vector>
# include <string>
# include "OrderInfo.hpp"
# include "typedefs.hpp"

/// Order class.
class	Order
{
public:
  /// Constructor.
  Order(void);

  /// Destructor.
  ~Order(void);

  /// Copy constructor.
  /**
     \param order The order to copy.
  */
  Order(const Order &order);

  /// Copy assignment.
  /**
     \param order The order to copy.
     \return The current object.
  */
  Order	&operator=(const Order &order);

  /// Add a file where to search informations.
  /**
     \param filename A file.
   */
  void		addFile(const std::string &filename);

  /// Set the information type to search.
  /**
     \param infoType The new type to search.
  */
  void		setInfoType(const t_info &infoType);

  /// Access the array of files this order treat.
  /**
     \return A constant reference on the array.
  */
  const t_VFile	&getFiles(void) const;

  /// Get the type of the information to search.
  /**
     \return The information to search.
  */
  const t_info	&getInfoType(void) const;

  /// Indicate if this order is a "null" order.
  /**
     It means that the order search for NO_INFO in an empty set of file.
     \return True if the order is "null", else false.
  */
  bool		isNullOrder(void) const;

  /// Clear the order.
  /**
0     The order becomes "null".
  */
  void		cleanOrder(void);

private:
  t_info	m_infoType; /**< Information this order should retrieve, it's an enum */
  t_VFile	m_files; /**< Files where to search informations, vector of string*/
};

#endif /* !AORDER_HPP_ */
