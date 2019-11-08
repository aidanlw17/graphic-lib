#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "vectors.h"

void render() {
    const int w = 1024;
    const int h = 768;
    std::vector<Vec3f> framebuffer(w * h);

    // Building a framebuffer
    for (size_t i=0; i<h; i++){
        for (size_t j=0; j<w; j++){
            framebuffer[j + i * w] = Vec3f(i / float(h), j / float(w), 0);
        }
    }

    // Saving framebuffer to file
    std::ofstream ofs;
    ofs.open("./out.ppm");
    ofs << "P6\n" << w << " " << h << "\n255\n";
    for (size_t i=0; i<h*w; ++i) {
        for (size_t j=0; j<3; j++){
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    render();

    return 0;
}
