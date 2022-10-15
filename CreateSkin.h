#ifndef MODULEWORKS_TEST_TASK_CREATESKIN_H
#define MODULEWORKS_TEST_TASK_CREATESKIN_H

#include "MovingFunction.h"
#include "PointWriter.h"
#include "PointCloud.h"

void CreateSkin(const point::Point3D<point::coords_type> &, const unsigned int &, const unsigned int &, const unsigned int &,
           const point::coords_type &, MovingFunction &, point::Point3D<point::coords_type> &, const int &,
           const std::string &);

#endif //MODULEWORKS_TEST_TASK_CREATESKIN_H
