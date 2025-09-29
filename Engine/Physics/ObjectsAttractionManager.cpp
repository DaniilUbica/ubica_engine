#include "ObjectsAttractionManager.h"

#include "Constants.h"

using namespace game_engine;
using namespace physics;

ObjectsAttractionManager::ObjectsAttractionManager() {}

ObjectsAttractionManager:: ObjectsAttractionManager(gravity_obj_t target) {
    m_target = target;
}

void ObjectsAttractionManager::Update(float time) {
    if (!m_target) {
        assert(false);
        return;
    }

    const auto targetPos = m_target->getPosition();
    for (auto data : m_attractionObjectsData) {
        const auto objPosition = data.object->getPosition();
        auto direction = targetPos - objPosition;
        const auto distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance > MIN_ATTRACTION_DISTANCE && distance < MAX_ATTRACTION_DISTANCE) {
            direction /= distance;

            const auto speed = calculateSpeed(distance) * time;
            data.velocity = direction * speed;
            data.object->setPosition(objPosition + data.velocity);
        }
        else {
            data.velocity = { 0.f, 0.f };
        }
    }
}

void ObjectsAttractionManager::addAttractionObject(gravity_obj_t object) {
    const AttractionObjectData data = { object, { 0.f, 0.f }};
    m_attractionObjectsData.insert(data);
}

void ObjectsAttractionManager::removeAttractionObject(gravity_obj_t object) {
    const auto iter = std::find_if(m_attractionObjectsData.begin(), m_attractionObjectsData.end(), [object](const auto& objectData) {
        return objectData.object == object;
    });

    if (iter != m_attractionObjectsData.end()) {
        m_attractionObjectsData.erase(iter);
    }
}

float ObjectsAttractionManager::calculateSpeed(float distance) const {
    float speed = (1.0f - distance / MAX_ATTRACTION_DISTANCE) * MAX_ATTRACTION_SPEED;

    speed = std::max(speed, MIN_ATTRACTION_SPEED);
    speed = std::min(speed, MAX_ATTRACTION_SPEED);

    return speed;
}
