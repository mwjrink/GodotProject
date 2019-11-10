extends Camera

# Declare member variables here. Examples:
export var height = 24;
export var lock = false;
export var camera_speed = 5;
var target = Vector3(0,0,0);
var pan_left = false;
var pan_right = false;
var pan_up = false;
var pan_down = false;

# Called when the node enters the scene tree for the first time.
func _ready():
	set_physics_process(true);
	set_as_toplevel(true);
	Input.set_mouse_mode(Input.MOUSE_MODE_CONFINED);
	set_current(true);
	
func _physics_process(delta):
	if lock:
		target = get_parent().transform.origin;
	else:
		if pan_left:
			target.x -= camera_speed;
		if pan_right:
			target.x += camera_speed;
		if pan_up:
			target.z += camera_speed;
		if pan_down:
			target.z -= camera_speed;
	
	to_target(target);
	
func _input(event):
	if event.is_action_pressed("zoom_in"):
		if(height <= 5):
			height = 5
		else:
			height -= 1
	elif event.is_action_pressed("zoom_out"):
		if(height > 24):
			height = 24
		else:
			height += 1
	elif event is InputEventMouseMotion:
		pan_camera(event.position);
	elif event.is_action_pressed("camera_to_player"):
		target = get_parent().transform.origin;
		to_target(target);
		lock = true;
	elif event.is_action_released("camera_to_player"):
		lock = false;

func to_target(target):
	var pos = target + Vector3(0, height, height*0.66667);
	var up = Vector3(0,1,0);
	
	look_at_from_position(pos, target, up);

func pan_camera(position):
	pan_right = position.x > get_viewport().size.x - 3;
	pan_left = position.x < 3;
	pan_up = position.y > get_viewport().size.y - 3;
	pan_down = position.y < 3;

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
