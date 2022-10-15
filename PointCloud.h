#ifndef MAIN_CPP_POINTCLOUD_H
#define MAIN_CPP_POINTCLOUD_H

#include "Point3D.h"

#include <vector>
#include <iostream>
#include <cmath>

namespace Cloud {
    class PointCloud {
    public:
        // Default constructor
        PointCloud() : max_x(100), max_y(100), max_z(100), delta(1.) {
            ReferencePoint = new point::Point3D<point::coords_type>(0, 0, 0);
        }

        // Constructor
        /*!Constructs a PointCloud object with given parameters:
            \param referencePoint - output file name
            \param x - max x coord
            \param y - max y coord
            \param z - max z coord
            \param d - distance grid
        */
        PointCloud(const point::Point3D<point::coords_type> &referencePoint, unsigned long x, unsigned long y,
                   unsigned long z, point::coords_type d) : max_x(x), max_y(y), max_z(z), delta(d) {
            ReferencePoint = new point::Point3D<point::coords_type>(referencePoint);
        }

        ~PointCloud() {
            delete ReferencePoint;
            point_cloud.clear();
        }

        // CreateCloud function
        // filling cloud by 'true'(it`s mean that point is exist) values
        void CreateCloud() {
            std::vector<bool> cloud_layer_;
            for (int i = 0; i < max_z; i++) {
                for (int j = 0; j < max_x; j++) {
                    for (int k = 0; k < max_y; k++) {
                        cloud_layer_.push_back(true);
                    }
                }
                point_cloud.push_back(cloud_layer_);
                cloud_layer_.clear();
            }
        }

        // Find_depth function
        /*!Function to find the highest existing point. With given parameters:
            \param pos - point coords in layer
        */
        point::coords_type Find_depth(const unsigned int &pos) {
            unsigned long z = max_z - 1;

            while (z >= 0 && !point_cloud[z][pos]) {
                z--;
            }

            return z;
        }

        // PointsIntersecting function
        /*!Function to check intersect cloud points by moving object. With given parameters:
            \param SphereCenter - point of sphere center
            \param SphereRad - value of the sphere radius
            \param function - function to change the SphereCenter point
        */
        void PointsIntersecting(point::Point3D<point::coords_type> &SphereCenter, const int &SphereRad,
                                 MovingFunction &function) {
            point::Point3D<point::coords_type> CurrentPoint(*ReferencePoint);
            point::Point3D<point::coords_type> Vector;
            double len;

            // changing ReferencePoint coords
            for (int i = 0; i < max_x; i++) {
                CurrentPoint.Set_X(ReferencePoint->Get_X() + i);
                for (int j = 0; j < max_y; j++) {
                    CurrentPoint.Set_Y(ReferencePoint->Get_Y() + j);
                    for (int k = 0; k < max_z; k++) {
                        CurrentPoint.Set_Z(ReferencePoint->Get_Z() + k);

                        // finding vector between CurrentPoint and SphereCenter
                        Vector = CurrentPoint-SphereCenter;

                        // if dot product of MovingVector and CurrentPoint >= 0 it means that CurrentPoint can be deleted by the Sphere
                        if(Vector*function.GetMovingVector() >= 0){
                            // if the distance to the point is less than the radius of the sphere
                            len = ~Vector*delta;
                            if(len <= SphereRad){
                                point_cloud[k][i * max_y + j] = false;
                            }
                        }
                    }
                }
            }
        }

        // Is_alive function
        /*!Function to check point status. With given parameters:
            \param z - layer value
            \param pos - point coords in layer
        */
        bool Is_alive(const unsigned int &z, const unsigned int &pos) {
            return point_cloud[z][pos];
        }

        unsigned long &Get_Max_X() {
            return max_x;
        }

        unsigned long &Get_Max_Y() {
            return max_y;
        }

        unsigned long &Get_Max_Z() {
            return max_z;
        }

        point::Point3D<point::coords_type>& GetReferencePoint() const {
            return *ReferencePoint;
        }

        point::coords_type& GetDelta(){
            return delta;
        }

    private:
        point::Point3D<point::coords_type> *ReferencePoint;
        std::vector<std::vector<bool>> point_cloud;
        unsigned long max_x;
        unsigned long max_y;
        unsigned long max_z;
        point::coords_type delta;
    };
}

#endif //MAIN_CPP_POINTCLOUD_H
