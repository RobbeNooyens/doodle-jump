//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H


class Camera {
public:
    [[nodiscard]] double getHeight() const;
    void setHeight(double h);
    void addHeight(double h);

    // Singleton specific
    static Camera& getInstance();
    Camera(Camera()) = delete;
    void operator=(Camera const&) = delete;

private:
    Camera();

    double height = 0;
};


#endif //DOODLEJUMP_CAMERA_H
