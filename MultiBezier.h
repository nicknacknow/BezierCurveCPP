#pragma once
#include <SFML/System.hpp>
#include <vector>

using namespace sf;

Vector2f MutliBezier(float t, std::vector<Vector2f> vec) {
	float x = 0, y = 0, z = 0;

	for (int i = vec.size() - 1; i >= 0; i--) {
		int index = vec.size() - i - 1;

		float brackets = powf((1.f - t), i);
		float coefficent = ((i == 0 || i == vec.size() - 1) ? 1 : vec.size() - 1) * (powf(t, index));
		
		x = x + coefficent * brackets * vec[index].x;
		y += coefficent * brackets * vec[index].y;
		//z += coefficent * brackets * vec[index].z;
	}

	return Vector2f(x, y);
}