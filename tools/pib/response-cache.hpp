/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2015,  Regents of the University of California.
 *
 * This file is part of ndn-tools (Named Data Networking Essential Tools).
 * See AUTHORS.md for complete list of ndn-tools authors and contributors.
 *
 * ndn-tools is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndn-tools is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndn-tools, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Yingdi Yu <yingdi@cs.ucla.edu>
 */


#ifndef NDN_TOOLS_PIB_RESPONSE_CACHE_HPP
#define NDN_TOOLS_PIB_RESPONSE_CACHE_HPP

#include <ndn-cxx/data.hpp>
#include <map>


namespace ndn {
namespace pib {

/**
 * @brief ResponseCache is an abstraction of a cache of response made before
 *
 * ResponseCache is used to reduce the number of PibDb lookup and Data signing
 * operations.
 *
 * Eventually, it should be replaced by a formal application level cache. This
 * one is only a temporary module and is used for test.
 */
class ResponseCache : noncopyable
{
public:
  ResponseCache();

  shared_ptr<const Data>
  find(const Name& dataName, bool hasVersion = false) const;

  /**
   * @brief Insert a data packet into cache
   *
   * Name of the inserted data must end with a version component
   *
   * @param data Data to insert. It MUST have been created with make_shared.
   */
  void
  insert(const Data& data);

  void
  erase(const Name& dataNameWithoutVersion);

  void
  clear();

private:
  typedef std::map<Name, shared_ptr<const Data> > Storage;

  Storage m_storage;
};

} // namespace ndn
} // namespace pib

#endif // NDN_TOOLS_PIB_RESPONSE_CACHE_HPP
