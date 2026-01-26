#include <iostream>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../engine/ft_engine.hpp"

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
    float loop_time = 0.0f;

    ft::FPSCamera cam;
    float cam_speed = 1.0;
    cam.SetPosition(glm::vec3(0.0, 0.0, 1.0));
    ft::ShaderSource sh_src = ft::read_shader_file(SANDBOX_DIRECTORY"/assets/basic.glsl");

    ft::VoxelBatchRenderer renderer;

    /* SHADERS */
    std::shared_ptr<ft::Shader> sh = std::make_shared<ft::Shader>(sh_src);

    glClearColor(0.9, 0.1, 0.35, 1.0);
    while (!win.IsRunning())
    {
        timer.Restart();
        win.PollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/* ****************** BASIC TEST MOVEMENT ****************** */
        glm::vec2 cursor_dir = mouse->GetCursorDir();
        if (wasd->IsKeyDown(GLFW_KEY_W))
            cam.Move(glm::vec3(0.0, 0.0, -1.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_S))
            cam.Move(glm::vec3(0.0, 0.0, 1.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_A))
            cam.Move(glm::vec3(-1.0, 0.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_D))
            cam.Move(glm::vec3(1.0, 0.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
            cam.Move(glm::vec3(0.0, -1.0, 0.0) * delta_time * cam_speed);
        if (wasd->IsKeyDown(GLFW_KEY_SPACE))
            cam.Move(glm::vec3(0.0, 1.0, 0.0) * delta_time * cam_speed);
        if (mouse->IsButtonDown(GLFW_MOUSE_BUTTON_LEFT))
        {
            win.SetCursorMode(GLFW_CURSOR_DISABLED);
            cam.Yaw(-cursor_dir.x * delta_time);
            cam.Pitch(-cursor_dir.y * delta_time);
        }
        else
            win.SetCursorMode(GLFW_CURSOR_NORMAL);
        cam_speed = 10.0 + mouse->GetScrollOffset().y / 10.0;
/* ********************************************************* */
    
        renderer.Begin(sh);
        sh->SetUniform("u_proj", cam.GetProjectionMat());
        sh->SetUniform("u_view", cam.GetViewMat());
        ft::Timer timer_loop;
        for (int i = -50; i <= 50; i++)
            for (int j = -50; j <= 50; j++)
                renderer.DrawVoxel(glm::vec3(i, (glm::cos(i) + glm::sin(j)), j), glm::vec4(glm::cos(i) + glm::sin(j)));
        loop_time = timer_loop.EllapsedSeconds();
        renderer.End();

        win.SwapBuffers();
        delta_time = timer.EllapsedSeconds();
        if (aux_timer.EllapsedSeconds() > 0.5)
        {
            win.SetTitleSuffix(" [" + std::to_string(delta_time) + "s | " + std::to_string(1.0/delta_time) + "fps] ["
                + std::to_string(renderer.GetBatchCount()) + " batches]");
            aux_timer.Restart();
            std::cout << "Loop Time: " << std::to_string(100 * loop_time / delta_time) + "%\n";
        }
    }
    win.Destroy();
    glfwTerminate();
    return (0);
}