#pragma once

#include "core/uncopyable.hpp"
#include "pool.h"
#include <assert.h>
#include <vector>

namespace core {

template <class T> class ItemManager : private Uncopyable {
  public:
    typedef unsigned int Id;

    ItemManager() : pool_(), mapIdToItem_() {}
    ~ItemManager() {}

    T &create(Id id) {
        if (id < mapIdToItem_.size() && mapIdToItem_[id] != nullptr) {
            return *mapIdToItem_[id];
        }

        T &item = pool_.AllocateItem();
        if (id < mapIdToItem_.size()) {
            mapIdToItem_[id] = &item;
        } else {
            mapIdToItem_.push_back(&item);
        }

        return item;
    }
    void remove(Id id) {
        assert(id < mapIdToItem_.size());
        auto item = mapIdToItem_[id];
        pool_.FreeItem(*item);
        mapIdToItem_[id] = nullptr;
    }

    T &get(Id id) {
        assert(id < mapIdToItem_.size());
        return *mapIdToItem_[id];
    }
    const T &get(Id id) const {
        assert(id < mapIdToItem_.size());
        return *mapIdToItem_[id];
    }

    void clear() {
        auto end = mapIdToItem_.end();
        auto iterator = mapIdToItem_.begin();
        for (; iterator != end; ++iterator) {
            auto item = *iterator;
            if (item != nullptr) {
                pool_.FreeItem(*item);
            }
        }
        mapIdToItem_.clear();
    }

  private:
    sahm::CPool<T, 64 * sizeof(T)> pool_;
    std::vector<T *> mapIdToItem_;
};

} // namespace core