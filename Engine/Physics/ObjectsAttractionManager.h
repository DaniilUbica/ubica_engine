#pragma once

#include "Base/TransformableObject.h"

#include <set>

namespace game_engine {
namespace physics {

namespace {
    using gravity_obj_t = std::shared_ptr<TransformableObject>;
}

class ObjectsAttractionManager {
public:
    ObjectsAttractionManager();
    ObjectsAttractionManager(gravity_obj_t target);

    void Update(float time);
    void addAttractionObject(gravity_obj_t object);
    void removeAttractionObject(gravity_obj_t object);

    void setTarget(gravity_obj_t target) { m_target = target; };

private:

    float calculateSpeed(float distance) const;

    struct AttractionObjectData {
        gravity_obj_t object;
        primitives::Vector2f velocity = { 0.f, 0.f };

        bool operator<(const AttractionObjectData& other) const {
            return object < other.object;
        }
    };

    std::set<AttractionObjectData> m_attractionObjectsData;
    gravity_obj_t m_target;
};

}
}
