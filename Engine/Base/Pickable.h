#pragma once

#include "GameObject.h"

namespace game_engine {

class Pickable : public GameObject {
protected:
    bool m_picked = false;

    void commonPicked();

public:
    virtual void onPicked() = 0;

    bool getPicked();
};

}
