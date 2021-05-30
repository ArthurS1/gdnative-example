#ifndef PLAYER_H_
#define PLAYER_H_

#include <Godot.hpp>
#include <KinematicBody.hpp>

namespace godot {

class Player : public KinematicBody {
    GODOT_CLASS(Player, KinematicBody)

private:
    float speed;
    float jumpImpulse;
    float fallAcceleration;
    Vector3 _velocity;

public:
    static void _register_methods();

    Player();
    ~Player();

    void _init();
    void _process(float delta);
    void _physics_process(float delta);
};

}

#endif /* !PLAYER_H_ */
