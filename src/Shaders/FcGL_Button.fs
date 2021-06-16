#version 110

uniform sampler2D  controlID;

varying vec2 fWindow;
varying vec4 fMouse;

void main() {
    float scale = 1.0 / min(fragment_window.x, fragment_window.y);
	gl_FragColor = vec4(0,1,1,1);
}
