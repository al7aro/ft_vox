#include <iostream>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../engine/ft_engine.hpp"

int main(void)
{
    if (!glfwInit())
        return (-1);    
    ft::Window win("ft_vox", 500, 500);
    auto wasd = std::make_shared<ft::KeyHandler>(std::vector<int>({ GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D, GLFW_KEY_SPACE, GLFW_KEY_LEFT_SHIFT }));
    auto mouse = std::make_shared<ft::MouseHandler>(std::vector<int>({GLFW_MOUSE_BUTTON_RIGHT, GLFW_MOUSE_BUTTON_LEFT}));
    win.AddListenTo(wasd);
    win.AddListenTo(mouse);

    ft::Timer timer, aux_timer;
    float delta_time = 0.0f;

    std::shared_ptr<ft::FPSCamera> cam = std::make_shared<ft::FPSCamera>();
    float cam_speed = 1.0;
    cam->SetPosition(glm::vec3(0.0, 0.0, 1.0));

    ft::ResourceManager res_manager;
    ft::VoxelBatchRenderer renderer;

    /* CREATE RENDER DATA */
    unsigned int sh = res_manager.CreateShader(SANDBOX_DIRECTORY"/assets/basic.glsl");
    unsigned int grass_mat = res_manager.CreateMaterial(glm::vec4(1.0), SANDBOX_DIRECTORY"/assets/grass_texture.png");
    res_manager.AddMaterialProperty(grass_mat, ft::Material::KD, glm::vec3(0.75));
    unsigned int test_mat = res_manager.CreateMaterial(glm::vec4(1.0), SANDBOX_DIRECTORY"/assets/test_texture.png");

    /* FILL RENDER DATA */
    ft::RenderData render_data;
    render_data.shader = res_manager.GetShader(sh);
    render_data.textures = res_manager.GetTexture(grass_mat);
    render_data.materials.push_back(res_manager.GetMaterial(grass_mat));
    render_data.materials.push_back(res_manager.GetMaterial(test_mat));

    glClearColor(0.9, 0.1, 0.35, 1.0);
    while (!win.IsRunning())
    {
        timer.Restart();
        win.PollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/* ****************** BASIC TEST MOVEMENT ****************** */
        glm::vec2 cursor_dir = mouse->GetCursorDir();
        if (wasd->IsKeyDown(GLFW_KEY_W))
            cam->Move(glm::vec3(0.0, 0.0, -1.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_S))
            cam->Move(glm::vec3(0.0, 0.0, 1.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_A))
            cam->Move(glm::vec3(-1.0, 0.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_D))
            cam->Move(glm::vec3(1.0, 0.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
            cam->Move(glm::vec3(0.0, -1.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_SPACE))
            cam->Move(glm::vec3(0.0, 1.0, 0.0) * delta_time * cam_speed);
        if (mouse->IsButtonDown(GLFW_MOUSE_BUTTON_LEFT))
        {
            win.SetCursorMode(GLFW_CURSOR_DISABLED);
            cam->Yaw(-cursor_dir.x * delta_time);
            cam->Pitch(-cursor_dir.y * delta_time);
        }
        else
            win.SetCursorMode(GLFW_CURSOR_NORMAL);
        cam_speed = 10.0 + mouse->GetScrollOffset().y / 10.0;
/* ********************************************************* */
    
/* *********************** RENDERING *********************** */
        renderer.Begin(render_data);
        render_data.shader->SetUniform("u_proj", cam->GetProjectionMat());
        render_data.shader->SetUniform("u_view", cam->GetViewMat());
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (glm::abs(i + j) % 2)
                    renderer.DrawVoxel(glm::vec3(i, 0, j), grass_mat);
                else
                    renderer.DrawVoxel(glm::vec3(i, 0, j), test_mat);
            }
        }
        renderer.End();
/* ********************************************************* */

        win.SwapBuffers();
        delta_time = timer.EllapsedSeconds();
        if (aux_timer.EllapsedSeconds() > 0.5)
        {
            win.SetTitleSuffix(" [" + std::to_string(delta_time) + "s | " + std::to_string(1.0/delta_time) + "fps] ["
                + std::to_string(renderer.GetBatchCount()) + " batches]");
            aux_timer.Restart();
        }
    }
    win.Destroy();
    glfwTerminate();
    return (0);
}