#include "CreateSkin.h"

void IntersectingBySphere(Cloud::PointCloud &cloud, MovingFunction &function,
                          point::Point3D<point::coords_type> &SphereCenter, const int &SphereRad) {
    // While is not the end of interval t1-t2
    double t = function.GetBeginParameter();

    while (t <= function.GetEndParameter()) {
        // check the cloud points at this time moment (are they erased or not)
        cloud.PointsIntersecting(SphereCenter, SphereRad, function);

        // change SphereCenter coords by function
        function.Evaluate(t, SphereCenter);

        // updating t parameter
        t += function.GetDeltaParameter();
    }
}

void CreateSkin(const point::Point3D<point::coords_type> &referencePoint, const unsigned int &max_x,
                const unsigned int &max_y,
                const unsigned int &max_z, const point::coords_type &delta, MovingFunction &function,
                point::Point3D<point::coords_type> &SphereCenter, const int &SphereRad,
                const std::string &File_name) {
    // Create cloud
    Cloud::PointCloud Cloud(referencePoint, max_x, max_y, max_z, delta);
    Cloud.CreateCloud();

    // intersecting by a move of sphere
    IntersectingBySphere(Cloud, function, SphereCenter, SphereRad);

    // out the results to a file
    PointWriter OutFile(File_name);

    // Out all cloud points
    //OutFile.OutCloud(Cloud);

    // Out only top layer cloud points
    OutFile.OutLayer(Cloud);
}



