#include "raycaster_flat.h"

int main(int argc, char *argv[])
{
    double posX = 22, posY = 12;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
    
    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    double cameraX;
    double rayDirX;
    double rayDirY;

    screen(screenWidth, screenHeight, 0, "Raycaster");  //화면 출력하기
    while (!done())
    {
        for (int x = 0; x < w; x++)
        {
            cameraX = 2 * x / double(w) - 1;
            rayDirX = dirX + planeX * cameraX;
            rayDirY = dirY + planeY * cameraX;
        }
    }










    return (0);
}