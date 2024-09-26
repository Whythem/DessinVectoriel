cmake_minimum_required(VERSION 3.29)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp
        Format/CBitmap.h
        Format/CBitmap.cpp
        Image/CImage.h
        Image/CImage.cpp
        Image/CLigne.h
        Image/CLigne.cpp
        Image/CPixel.h
        Image/CPixel.cpp
        Forms/Point.h
        Forms/Point.cpp
        Forms/Ligne.h
        Forms/Ligne.cpp
        Forms/Cercle.h
        Forms/Cercle.cpp
        Forms/CercleS.h
        Forms/CercleS.cpp
        Forms/Rectangle.h
        Forms/Rectangle.cpp
        Forms/RectangleS.h
        Forms/RectangleS.cpp
        Forms/Point.h
        Forms/Carre.cpp
        Forms/Carre.h
        Forms/CarreS.cpp
        Forms/CarreS.h
        Formes.cpp
        Formes.h
        Forms/Triangle.cpp
        Forms/Triangle.h)
