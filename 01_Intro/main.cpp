// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2
// generalised format : compiler(clang or gcc) file_name -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including)

// C++ Standard library
#include <iostream>

// SDL2 file
#include <SDL.h> // For linux or windows use <SDL2/SDL.h>

int main(int argc, char* argv[])
{
  // this program check if SDL has been properly installed and included into your project
  // SDL_Init - used to initialise the SDL Objects
  // There are various SDL objects such as SDL_VIDEO, SDL_AUDIO, etc
  // SDL_GetError() function return SDL Errors that occur in the program
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialised " << SDL_GetError() << std::endl;
  }
  else
  {
  std::cout << "SDL video system is ready to go \n";
  }
  return 0;
}
