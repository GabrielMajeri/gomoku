#include "version.hpp"

Version Version::compiled() {
    Version ver;
    SDL_VERSION(&ver);
    return ver;
}

Version Version::linked() {
    Version ver;
    SDL_GetVersion(&ver);
    return ver;
}

std::ostream& operator<<(std::ostream& os, const Version& ver) {
    return os << int(ver.major) << '.' << int(ver.minor) << '.'
              << int(ver.patch);
}
