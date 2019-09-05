//
// Order.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Mon Apr 11 11:25:11 2016 Victor Le
// Last update Tue Apr 12 11:58:17 2016 Victor Le
//

#include "Order.hpp"
#include "SerializeError.hpp"

Order::Order(void):
  m_infoType(NO_INFO), m_files()
{}

Order::~Order(void)
{}

Order::Order(const Order &order):
  m_infoType(order.m_infoType), m_files(order.m_files)
{}

Order	&Order::operator=(const Order &order)
{
  t_VFile::const_iterator	it;

  if (this != &order)
    {
      this->m_infoType = order.m_infoType;
      this->m_files = order.m_files;
    }
  return (*this);
}

void	Order::addFile(const std::string &filename)
{
  m_files.push_back(filename);
}

void	Order::setInfoType(const t_info &infoType)
{
  m_infoType = infoType;
}

const t_VFile	&Order::getFiles(void) const
{
  return (m_files);
}

const t_info	&Order::getInfoType(void) const
{
  return (m_infoType);
}

bool		Order::isNullOrder(void) const
{
  return (m_infoType == NO_INFO && m_files.empty());
}

void		Order::cleanOrder(void)
{
  m_infoType = NO_INFO;
  m_files.clear();
}
