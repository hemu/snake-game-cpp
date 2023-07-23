#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;
uniform int unique_id;
uniform vec2 TexCoord;

vec3 offset_pos;
float offset;
float rand_noise;

float rand(float n){return fract(sin(n) * 43758.5453123);}

void main()
{
    rand_noise = rand(float(unique_id));
    offset = abs(sin(2*time + rand_noise)) * 0.3;
    offset_pos = vec3(aPos.x + sign(aPos.x) * offset, aPos.y + sign(aPos.y)*offset, aPos.z);
    gl_Position = projection * view * model * vec4(offset_pos, 1.0);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}

// ------------------------------ 

#shader fragment
#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, TexCoord);
}


