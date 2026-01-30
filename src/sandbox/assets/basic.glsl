.vertex
#version 460 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec2 a_tex_coords;
layout (location = 2) in vec4 a_col;
layout (location = 3) in vec3 a_normal;
layout (location = 4) in float a_material_id;

uniform mat4 u_proj = mat4(1.0);
uniform mat4 u_view = mat4(1.0);
uniform mat4 u_model = mat4(1.0);

uniform vec3 u_offset;

out vec4 v_col;
out vec2 v_tex_coords;
out float v_material_id;

void main()
{
    v_col = a_col;
    v_tex_coords = a_tex_coords;
    v_material_id = a_material_id;
    gl_Position = u_proj * u_view * u_model * vec4(a_pos + u_offset, 1.0);
}

.fragment
#version 460 core

struct Material
{
    vec3 Ka;    /* ambient */
    vec3 Kd;    /* diffuse */
    vec3 Ks;    /* specular */
    float d;    /* shinyness */

    vec2 diffuse_map_id;
    vec2 specular_map_id;
    vec2 bump_map_id;
};

uniform Material u_material[8];

uniform sampler2DArray u_texture;

in vec4 v_col;
in vec2 v_tex_coords;
in float v_material_id;

out vec4 frag_color;

void main()
{
    int mat_id = int(v_material_id + 0.5);
    Material mat = u_material[int(mat_id)];
    frag_color = texture(u_texture, vec3(v_tex_coords, int(mat.diffuse_map_id.y))) * vec4(mat.Kd, 1.0);
}