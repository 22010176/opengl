#include <iostream>
#include <string>
#include <vector>

#include <glad.h>
#include <SDL.h>

using namespace std;

// Globals
int gScreenHeight = 480, gScreenWidth = 640;

SDL_Window* gGraphicApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

void Initialize() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    cout << "Could not initial SDL" << endl;
    exit(1);
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  gGraphicApplicationWindow = SDL_CreateWindow("", 50, 50, gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
  if (gGraphicApplicationWindow == nullptr) {
    cout << "Could not create window!" << endl;
    exit(1);
  }

  gOpenGLContext = SDL_GL_CreateContext(gGraphicApplicationWindow);
  if (gOpenGLContext == nullptr) {
    cout << "OpenGL isnot available" << endl;
    exit(1);
  }
}

void Input() {
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      std::cout << "Goodbye" << endl;
      gQuit = true;
    }
  }
}
void PreDraw() {}
void Draw() {}

void MainLoop() {
  while (!gQuit) {
    Input();

    PreDraw();
    Draw();

    SDL_GL_SwapWindow(gGraphicApplicationWindow);
  }
}

void CleanUp() {
  SDL_DestroyWindow(gGraphicApplicationWindow);
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  srand((uint32_t)time(NULL));

  Initialize();
  MainLoop();
  CleanUp();

  return 0;
}