
// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2
// generalised format : compiler(clang or gcc) file_name -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including)

// C++ Standard library
#include <iostream>

// SDL2 file
#include <SDL.h> // For linux or windows use <SDL2/SDL.h>


int main(int argc, char *argv[])
{
  // Create a window data type
  // This pointer will point to the window that is allocated from SDL_CreateWindow
  SDL_Window* window = nullptr;  
  
  if (SDL_Init(SDL_INIT_VIDEO)<0)
  {
    std::cout << "SDL initialization error " << SDL_GetError() << std::endl;
    return 1;
  }
  else
  {
    std::cout << "SDL Video successfully initialized \n";
  }
  //  Request a window to be created for our platform
  //  Parameters are : title, x_position, y_position, width, height and optional flag
  window = SDL_CreateWindow(
      "2D Render",
      20, 20,
      640, 480,
      SDL_WINDOW_SHOWN
  );

  // Create Renderer object
  SDL_Renderer* renderer;
  // syntax for SDL_CreateRenderer : SDL_CreateRenderer(SDL_Window*, driver_to_use (pass -1 to select first available driver), SDL_RENDERE_FLAG);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // creating a rectangle 
  SDL_Rect rectangle;
  rectangle.x = 100;
  rectangle.y = 150;
  rectangle.w = 100;
  rectangle.h = 100;

  // Create a infinite loop for out applciation
  bool quit = false;
  while(!quit)
  {
    SDL_Event event; // Capture SDL events
    
    // (1) Handle Input
    // Start event loop
    while (SDL_PollEvent(&event)) // Loop over the event 
    {
      // Handling Specific Events
      if(event.type == SDL_QUIT) // If event type is equal to program quit
      {
        quit = true;
      }
    }
    // (2) Handle Updates

    // (3) Clear and Draw the Screen
    // Gives us clear 'canvas'
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);  // Set Default renderer draw color
    SDL_RenderClear(renderer);

    // Do our Drawing
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE); // Set Renderer Draw Color
    SDL_RenderDrawLine(renderer, 5, 5, 100, 120);
    
    // Draw rectangle
    SDL_RenderDrawRect(renderer, &rectangle); 

    // Finally show what we have drawn
    SDL_RenderPresent(renderer);
  }  

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
