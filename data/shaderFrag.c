#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect tex_0; // default参照先 is texture buffer[0]
uniform sampler2DRect tex_1;
uniform sampler2DRect tex_2;

uniform float id;


void main(){
	vec2 pos = gl_TexCoord[0].xy;
	
	vec4 color;
	if(id == 0)			color = texture2DRect(tex_0, pos);
	else if(id == 1)	color = texture2DRect(tex_1, pos);
	else				color = texture2DRect(tex_2, pos);
	
	gl_FragColor = color;
}
