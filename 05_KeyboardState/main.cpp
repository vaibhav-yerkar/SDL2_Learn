// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2
// generalised format : compiler(clang or gcc) file_name -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including)

// C++ Standard library
#include <iostream>

// SDL2 file
#include <SDL.h> // For linux an winodws <SDL2/SDL.h>

int main(int argc, char* argv[])
{
  // Create a window data type
  // This pointer will point to the window that is allocated from SDL_CreateWindow
  SDL_Window* window;

  // Initialise Video Subsystem, if return value is <1, error will berecieved
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialised " << SDL_GetError() << std::endl;
  }
  else
  {
  std::cout << "SDL video system is ready to go \n";
  }

  //  Request a window to be created for our platform
  //  Parameters are : title, x_position, y_position, width, height and optional flag
  window = SDL_CreateWindow(
    "SDL Window",
    100, 100,
    640, 480,
    SDL_WINDOW_SHOWN
  );

  // Create a infinite loop for out applciation
  bool quit = false;
  while(!quit)
  {
    SDL_Event event; // Capture SDL events
    while (SDL_PollEvent(&event)) // Loop over the event 
    {
      // Handling Specific Events
      if(event.type == SDL_QUIT) // If event type is equal to program quit
      {
        quit = true;
      }
      if (event.type == SDL_MOUSEMOTION) // Capture mouse motion
      {
        std::cout << "mouse has been moved\n";
      }
      if (event.type == SDL_KEYDOWN)  // Capture Key down/ key press event
      {
        std::cout << "A key has been pressed \n";
        if (event.key.keysym.sym == SDLK_0) // Capture specific key press
        {
          std::cout << "0 was pressed\n";
        }
        else
        {
          std::cout << "0 was not pressed\n";
        }
      }

      // Retrieve the state of all the keys
      // Then we can query the scan code of one or more keys at a time
      const Uint8* state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_RIGHT]) // Right arrow button
      {
        std::cout << "Right arrow key was pressed \n";  
      }
    }
  }

  SDL_DestroyWindow(window);
  // Then we uninitilaise the SDL2, that is we are taking down the subsystem here before we exit the program
  SDL_Quit();

  return 0;
}
