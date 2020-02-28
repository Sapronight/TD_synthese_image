cmake_minimum_required(VERSION 3.15)
project(TD_image_synth)

set(CMAKE_CXX_STANDARD 20)

add_executable(TD_image_synth main.cpp header/Bmpfile.h header/Vector3d.h src/Bmpfile.cpp src/Vector3d.cpp src/Scene.cpp header/Scene.h header/main.h src/Ray.cpp header/Ray.h src/Sphere.cpp header/Sphere.h src/Object3d.cpp header/Object3d.h src/Color.cpp header/Color.h header/Light.h src/Light.cpp header/dirLight.h src/dirLight.cpp)