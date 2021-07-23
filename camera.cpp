#include "camera.h"

Camera::Camera()
{
    camera = new QCamera(QCameraInfo::defaultCamera());

}
