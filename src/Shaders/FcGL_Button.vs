#version 110

attribute vec2 positions;

uniform vec2 window;
uniform vec4 mouse;

varying vec2 fWindow;
varying vec4 fMouse;

void main() {
	gl_Position = vec4(positions, 0, 1);
	fWindow = window;
	fMouse = mouse;
}
