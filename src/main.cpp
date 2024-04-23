#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool sdl2Check()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    else {
        std::cout << "SDL initialization successful." << std::endl;
    }

    // Find SDL2
    if (!SDL_GetCurrentVideoDriver()) {
        std::cerr << "SDL2 library not found." << std::endl;
        return false;
    }
    else {
        std::cout << "SDL2 library found." << std::endl;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image initialization failed: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    else {
        std::cout << "SDL_image initialization successful." << std::endl;
    }

    // Check if SDL_image loaded PNG support
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image failed to load PNG support: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    else {
        std::cout << "SDL_image loaded PNG support." << std::endl;
    }

    // Check if SDL_image loaded JPG support
    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)) {
        std::cerr << "SDL_image failed to load JPG support: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    else {
        std::cout << "SDL_image loaded JPG support." << std::endl;
    }

    // Print SDL version information
    SDL_version compiled;
    SDL_VERSION(&compiled);

    std::cout << "The program compiled against SDL version " << static_cast<int>(compiled.major) << "."
              << static_cast<int>(compiled.minor) << "." << static_cast<int>(compiled.patch) << " ...\n";

    SDL_version linked;
    SDL_GetVersion(&linked);
    std::cout << "The program are linking against SDL version " << static_cast<int>(linked.major) << "."
              << static_cast<int>(linked.minor) << "." << static_cast<int>(linked.patch) << ".\n";

    // Check if compiled and linked SDL versions match
    if (compiled.major != linked.major || compiled.minor != linked.minor || compiled.patch != linked.patch) {
        std::cerr << "Warning: Compiled and linked SDL versions are different!" << std::endl;
    }
	else{
		std::cout << "Compiled and linked SDL versions match." << std::endl;
	}

    // Print SDL_image version information
    const SDL_version* imgCompiled = IMG_Linked_Version();
    std::cout << "The program compiled against SDL_image version " << static_cast<int>(imgCompiled->major) << "."
              << static_cast<int>(imgCompiled->minor) << "." << static_cast<int>(imgCompiled->patch) << " ...\n";

    const SDL_version* imgLinked = IMG_Linked_Version();
    std::cout << "The program are linking against SDL_image version " << static_cast<int>(imgLinked->major) << "."
              << static_cast<int>(imgLinked->minor) << "." << static_cast<int>(imgLinked->patch) << ".\n";

    // Check if compiled and linked SDL_image versions match
    if (imgCompiled->major != imgLinked->major || imgCompiled->minor != imgLinked->minor || imgCompiled->patch != imgLinked->patch) {
        std::cerr << "Warning: Compiled and linked SDL_image versions are different!" << std::endl;
    }
	else{
		std::cout << "Compiled and linked SDL_image versions match." << std::endl;
	}

    // Quit SDL and SDL_image
    IMG_Quit();
    SDL_Quit();

    return true;
}

int main() {
    if (!sdl2Check()) {
        return 1;
    }

    return 0;
}
