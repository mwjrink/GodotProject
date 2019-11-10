#include "Root.h"
//
//using namespace godot;
//
////Player* Root::pPlayer;
////Node* Root::pInnerWallContainerNode;
//
//void Root::_register_methods() {
//	//register_method((char*)"_input", &Root::HandleInputEvent);
//	//register_method((char*)"_ready", &Player::_ready);
//}
//
//Root::Root() {
//
//}
//
//Root::~Root() {
//
//}
//
//void Root::_init() {
//
//}
//
//
////void Root::HandleInputEvent(Variant v) {
////	Object* o = v;
////	InputEvent* e = (InputEvent*)0;
////
////	const godot::String gsIEMB = "InputEventMouseButton";
////	godot::String gsClass = e->get_class();
////	if (gsClass == gsIEMB) {
////		ProcessMWheel((InputEventMouseButton*)o);
////	}
////}
////
////void Root::ProcessMWheel(InputEventMouseButton* e) {
////	//int64_t buttonIndex = e->get_button_index();
////	//if (e->is_pressed()) {
////	//	auto v = pPlayer->pCamera->get_fov();
////	//	if (buttonIndex == GlobalConstants::BUTTON_WHEEL_DOWN) {
////	//		v = (v * 10.0 / 9.0);
////	//		if (v > 1.25) {
////	//			v = 1.25;
////	//		}
////	//		pPlayer->pCamera->set_fov(v);
////	//	}
////	//	else if (buttonIndex == GlobalConstants::BUTTON_WHEEL_UP) {
////	//		v = (v * 0.9);
////	//		if (v < 0.75) {
////	//			v = 0.75;
////	//		}
////	//		pPlayer->pCamera->set_fov(v);
////	//	}
////	//}
////}
