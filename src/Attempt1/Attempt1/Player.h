#pragma once

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <InputEvent.hpp>
#include <Viewport.hpp>
#include <Camera.hpp>

namespace godot {
	class Player : public KinematicBody {
		GODOT_CLASS(Player, KinematicBody)
	private:
		Vector3 target;
	public:
		//Camera* pCamera;
		float move_speed = 100;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _unhandled_input(InputEvent* event);

		Player();
		~Player();
	};
}