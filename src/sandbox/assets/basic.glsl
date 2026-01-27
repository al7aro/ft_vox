.vertex
#version 460 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec2 a_tex_coords;
layout (location = 2) in vec4 a_col;

uniform mat4 u_proj = mat4(1.0);
uniform mat4 u_view = mat4(1.0);
uniform mat4 u_model = mat4(1.0);

uniform vec3 u_offset;

out vec4 v_col;
out vec2 v_tex_coords;

void main()
{
    v_col = a_col;
    v_tex_coords = a_tex_coords;
    gl_Position = u_proj * u_view * u_model * vec4(a_pos + u_offset, 1.0);
}

.fragment
#version 460 core

uniform sampler2D u_texture;

in vec4 v_col;
in vec2 v_tex_coords;

out vec4 frag_color;

void main()
{
    frag_color = texture(u_texture, v_tex_coords);
}