#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QCameraInfo>


class Camera
{
public:
    Camera();

    QCamera *camera;
};

#endif // CAMERA_H
