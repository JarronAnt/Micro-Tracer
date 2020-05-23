#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "core.h"
#include <algorithm>

void render() {
	//window size
	const int width = 1024;
	const int height = 768;
	std::vector<Vec3f> framebuffer(width*height);

	//set each pixel of the framebuffer to a (r,g,b) val contained in a vec3 
	for (size_t j = 0; j < height; j++) {
		for (size_t i = 0; i < width; i++) {
			framebuffer[i + j * width] = Vec3f(j / float(height), i / float(width), 0);
		}
	}

	std::ofstream ofs; // save the framebuffer to file
	ofs.open("./out.ppm");
	ofs << "P6\n" << width << " " << height << "\n255\n";
	//render
	for (size_t i = 0; i < height*width; ++i) {
		for (size_t j = 0; j < 3; j++) {
			ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
		}
	}
	ofs.close();
}

int main() {
	render();
	return 0;
}