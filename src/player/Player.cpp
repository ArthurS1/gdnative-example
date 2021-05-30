#include "Player.hpp"
#include "Input.hpp"

void godot::Player::_register_methods() {
    register_method("_process", &Player::_process);
    register_method("_physics_process", &Player::_physics_process);
    register_property<Player, float>("speed", &Player::speed, 14);
    register_property<Player, float>("jumpImpulse", &Player::jumpImpulse, 20);
    register_property<Player, float>("fallAcceleration", &Player::fallAcceleration, 75);
}

godot::Player::Player() {
    Godot::print("Player is created ! (yay)");
}

godot::Player::~Player() {
    Godot::print("Player is destroyed !");
}

void godot::Player::_init() {
    speed = 14;
    jumpImpulse = 20;
    fallAcceleration = 75;
    _velocity = Vector3::ZERO;
}

void godot::Player::_process(float delta) {
}

void godot::Player::_physics_process(float delta) {
    auto direction = Vector3::ZERO;
    Input *const input = Input::get_singleton();

    if (input->is_action_pressed("game_up")) {
        Godot::print("Up !");
        direction.z -= 1;
    }
    if (input->is_action_pressed("game_down")) {
        Godot::print("Down !");
        direction.z += 1;
    }
    if (input->is_action_pressed("game_right")) {
        Godot::print("Right !");
        direction.x += 1;
    }
    if (input->is_action_pressed("game_left")) {
        Godot::print("Left !");
        direction.x -= 1;
    }

    if (direction != Vector3::ZERO) {
        direction.normalize();
        look_at(get_translation() + direction, Vector3::UP);
    }

    _velocity.x = direction.x * speed;
    _velocity.z = direction.z * speed;

    _velocity = move_and_slide(_velocity, Vector3::UP);
}
