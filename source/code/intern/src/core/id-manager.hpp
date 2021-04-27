#pragma once

#include "core/uncopyable.hpp"
#include <map>
#include <string>
#include <vector>

namespace core {

class IdManager : private Uncopyable {
  public:
    typedef const std::string IdString; // easier for humans
    typedef unsigned int Id;            // used by the computer for efficency

    IdManager();
    ~IdManager();

    Id add(IdString &id);
    void clear();

    bool hasId(IdString &id) const;
    bool hasId(Id id) const;

    Id getId(IdString &id) const;
    IdString &getId(Id id) const;

    unsigned int size() const;

  private:
    typedef std::pair<IdString, Id> MapEntry;

    std::map<IdString, Id> mapIdStringToId_;
    std::vector<std::string> idStrings_;
};

} // namespace core