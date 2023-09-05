#include "raylib.h"
#include <unistd.h> 

int main()
{
    // window settings
    InitWindow(1536, 906, "AXE GAME");
    SetWindowPosition(0, 0);

    // circle coordinates
    int circle_x{768};
    int circle_y{453};
    int circle_radius{75};
    // circle edges
    int left_circle_x{circle_x - circle_radius};
    int right_circle_x{circle_x + circle_radius};
    int top_circle_y{circle_y - circle_radius};
    int bottom_circle_y{circle_y + circle_radius};

    // axe
    int axe_x{0};
    int axe_y{0};
    int axe_width{150};
    int axe_height{150};
    // axe edges
    int left_axe_x{axe_x};
    int right_axe_x{axe_x + axe_width};
    int top_axe_y{axe_y};
    int bottom_axe_y{axe_y + axe_height};

    int direction{1};

    bool game_over =
        (bottom_axe_y >= top_circle_y) &&
        (bottom_circle_y >= top_axe_y) &&
        (right_axe_x >= left_circle_x) &&
        (right_circle_x >= left_axe_x);
    
    // SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLUE); // avoid double flickering canvas

            if (!game_over)
            {
                // game logic start
                // update edges
                left_circle_x = circle_x - circle_radius;
                right_circle_x = circle_x + circle_radius;
                top_circle_y = circle_y - circle_radius;
                bottom_circle_y = circle_y + circle_radius;
                left_axe_x = axe_x;
                right_axe_x = axe_x + axe_width;
                top_axe_y = axe_y;
                bottom_axe_y = axe_y + axe_height;
                game_over =
                    (bottom_axe_y >= top_circle_y) &&
                    (bottom_circle_y >= top_axe_y) &&
                    (right_axe_x >= left_circle_x) &&
                    (right_circle_x >= left_axe_x);

                DrawCircle(circle_x, circle_y, circle_radius, ORANGE);
                DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

                // axe movement
                axe_y += direction;

                if (axe_y > GetScreenHeight() || axe_y < 0)
                {
                    direction = -direction;
                }

                if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && circle_x < GetScreenWidth() - 75)
                {
                    circle_x += 1;
                } else if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && circle_x > 75)
                {
                    circle_x -= 1;
                } else if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && circle_y > 75)
                {
                    circle_y -= 1;
                } else if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && circle_y < GetScreenHeight() - 75)
                {
                    circle_y += 1;
                }
            }
            else
            {
                DrawText("GAME OVER!", 259, 453, 150, RED);
            }
        // game logic end
        EndDrawing();
    }

    CloseWindow();
    return 0;
}