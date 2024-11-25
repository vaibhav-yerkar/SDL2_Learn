
// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2
// generalised format : compiler(clang or gcc) file_name -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including)

// C++ Standard library
#include <iostream>

// SDL2 file
#include <SDL.h> //For linux and windows use <SDL2/SDL.h>

// This function will modify the pixel value of the screen based on the event trigger
void SetPixel(SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
  SDL_LockSurface(surface); // Locking Surface before performing modification
  
  uint8_t* pixelArray = (uint8_t*) surface->pixels; // retrieving surface pixel data ase unit8
  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel+0] = b; //modifying pixel data 
  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel+1] = g;
  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel+2] = r;
  
  SDL_UnlockSurface(surface);  // Unlocking Surface after modification 
}

int main(int argc, char *argv[])
{
  // Create a window data type
  // This pointer will point to the window that is allocated from SDL_CreateWindow
  SDL_Window* window = nullptr;  
  
  // Grab the window surface 
  SDL_Surface *screen;
  
  //  Request a window to be created for our platform
  //  Parameters are : title, x_position, y_position, width, height and optional flag
  window = SDL_CreateWindow(
      "Surfaces",
      20, 20,
      640, 480,
      SDL_WINDOW_SHOWN);

  screen = SDL_GetWindowSurface(window);
  
  // Clear the window surface to black
  SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_UpdateWindowSurface(window);
  
  // Create a infinite loop for out applciation
  bool quit = false;
  while(!quit)
  {
    SDL_Event event; // Capture SDL events
    
    int x,y;
    Uint32 button;
    button = SDL_GetMouseState(&x, &y);

    while (SDL_PollEvent(&event)) // Loop over the event 
    {
      // Handling Specific Events
      if(event.type == SDL_QUIT) // If event type is equal to program quit
      {
        quit = true;
      }
      if(event.button.button == SDL_BUTTON_LEFT) // Left mouse click even
      {
        std::cout << "left mouse was pressed (" << x << "," << y << ")\n" ;
        SetPixel(screen, x, y, 255, 0, 0); // the pixel at mouse cursor position is set to rgb value (255,0,0)
      }
      if(event.button.button == SDL_BUTTON_RIGHT) // Right Mouse CLick event
      {
        std::cout << "rightmouse was pressed (" << x << "," << y << ")\n" ;
        SetPixel(screen, x, y, 0, 0, 255); //pixel at mouse cursor position is set to rgb vale (0, 0, 255)
      }    
    }
    SDL_UpdateWindowSurface(window); //Update window to display the changes
  }  

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
