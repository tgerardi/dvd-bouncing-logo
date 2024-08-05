#include "dvd.h"

int main(void) {

    InitWindow(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()), "DVD Bouncing Logo!");

    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    Texture2D dvdTexture = LoadTexture("static/dvd-logo.png");
    Vector2 dvdPos = { screenWidth/2.0f - dvdTexture.width/2.0f, screenHeight/2.0f - dvdTexture.height/2.0f };
    Vector2 dvdSpeed = { 200.0f, 150.0f };

    ToggleFullscreen();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        dvdPos.x += dvdSpeed.x * GetFrameTime();
        dvdPos.y += dvdSpeed.y * GetFrameTime();

        if (dvdPos.x <= 0 || dvdPos.x + dvdTexture.width >= screenWidth) dvdSpeed.x *= -1;
        if (dvdPos.y <= 0 || dvdPos.y + dvdTexture.height >= screenHeight) dvdSpeed.y *= -1;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(dvdTexture, (int)dvdPos.x, (int)dvdPos.y, WHITE);
        EndDrawing();
    }

    UnloadTexture(dvdTexture);

    CloseWindow();

    return 0;
}