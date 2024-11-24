// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2
// generalised format : compiler(clang or gcc) file_name -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including)

// C++ Standard library
#include <iostream>

// SDL2 file
#include <SDL.h>

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

  // We add delapy to see our window and the delete the created winodw
  // NOTE: In mac system the program will not render the window unless we run it in a continuous loop, though the winodw object will be created and the program will be successfully compiled
  // we will see how to use the loop on winodw object in next program.
  SDL_Delay(3000); //Delay of 3 sec
  // We destroy our window by passing the window object pointer to free the allocated memory in our system
  SDL_DestroyWindow(window);
  // Then we uninitilaise the SDL2, that is we are taking down the subsystem here before we exit the program
  SDL_Quit();

  return 0;
}
