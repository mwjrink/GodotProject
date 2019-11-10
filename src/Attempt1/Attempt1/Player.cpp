#include "Player.h"

using namespace godot;

void Player::_register_methods() {
	register_method((char*)"_process", &Player::_process);
	register_method((char*)"_unhandled_key_input", &Player::_unhandled_input);
}

Player::Player() {
	target = Vector3(0, 0, 0);
}

Player::~Player() {

}

// needed in all c++ otherwise wont work as of 3.1
void Player::_init() {

}

void Player::_process(float delta) {

	//velocity.normalize();
	auto position = get_translation();
	auto velocity = target - position;
	auto distance = velocity.length();
	if (distance < 0.1) {
		target = position;
		velocity = Vector3(0, 0, 0);
	}
	else {
		velocity.normalize();
		move_and_slide(move_speed * velocity);
	}
}

void Player::_unhandled_input(InputEvent* e) {
	//velocity = Vector3(0, 0, 0);
	//e->is_action
	//e->is_action_pressed
	//if (e->is_action_pressed("ui_up")) {
	//	velocity.z -= 1;
	//}

	//if (e->is_action_pressed("ui_down")) {
	//	velocity.z += 1;
	//}

	//if (e->is_action_pressed("ui_left")) {
	//	velocity.x -= 1;
	//}

	//if (e->is_action_pressed("ui_right")) {
	//	velocity.x += 1;
	//}

	if (e->is_action_pressed("move_to_pointer")) {
		auto mouse_position = get_viewport()->get_mouse_position();
		auto ray_origin = get_viewport()->get_camera()->project_ray_origin(mouse_position);
		auto ray_dir = get_viewport()->get_camera()->project_ray_normal(mouse_position);

		target = (abs((ray_origin.y) / ray_dir.y)) * ray_dir + ray_origin;
	}
}