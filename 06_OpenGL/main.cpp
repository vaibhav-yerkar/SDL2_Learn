// based on your sdl2 library location you will have to modify your compilation command
// e.g, for me as i am on mac and have installed sdl2 via homebrew i will use following commang
// clang++ main.cpp glad/src/glad.c -o main -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2 -I./glad/include -ldl
// generalised format : compiler(clang or gcc) file_name glad.c_file_path -o output_file_name -I include_folder_path -L folder_path_for_linker_library -l linker_name(the name for folder you including) -I glad_include_folder_path -ldl

// C++ standard library 
#include <iostream>
// SDL library 
#include <SDL.h> // For linux or windows use <SDL2/SDL.h>
// Glad Library
// GLAD manages function pointers for OpenGL. It is useful becuase OpenGL is only really a standard/specification it is up to the driver manufacturer to implement the specification to a driver that the specific graphics card supports.
// This glad folder was generated from https://glad.dav1d.de based on your device and requirement 
#include <glad/glad.h>

int main()
{
  // Create a window data type
  // This pointer will point to the window that is allocated from SDL_CreateWindow
  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }
  else
  {
    std::cout << "SDL video system is ready to go \n";
  }
  // Before we create our window, specify OpenGL version 
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  
  //  Request a window to be created for our platform
  //  Parameters are : title, x_position, y_position, width, height and optional flag
  window = SDL_CreateWindow(
    "SDL Background Example",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800, 600,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
  );
  
  // OpenGL setup the graphics context
  SDL_GLContext context;
  context = SDL_GL_CreateContext(window);

  // Setup our function pointers
  gladLoadGLLoader(SDL_GL_GetProcAddress);
 
  // Infinite loop for our application
  bool quit = false;
  while (!quit)
  {
    glViewport(0, 0, 800, 600); // Setting up openGL viewport , must be equal to our window
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

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
  }

  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}
