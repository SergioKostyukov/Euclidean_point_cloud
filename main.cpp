#include "CreateSkin.h"

/* +----------------------------------------------------------------+
 * Classes create:
 * 1. Point3D class (for reference point and sphere center point)   .done
 * 2. PointCloud class (3D model of bool values)                    .done
 * 3. Moving function class (consist object center point, additional
      parameters, moving vectors)                                   .done
 * 4. Discrete moving function class (t1 and t2)                    .done
 * 5. Exception classes                                             .done
 * 6. PointerWriter class (changing values to ASCII data format
      and push to the result file)                                  .done
 * +----------------------------------------------------------------+
 * Math functions implement:
 * 1. Sphere moving formula                                         .done
 * 2. The intersection of the cloud with a moving sphere            .done
 * +----------------------------------------------------------------+
 * Documentation:
 * 1. Small documentation(1 page with 2 pictures) to present
      the mathematical approach of the sphere move point intersection.
      It should clearly communicate the mathematical approach
      and how the mathematical code is generated from that.         .-
 * 2. Briefly in 4-5 sentences what problems can arise by using
      a discrete stepping ∆t                                        .-
 * 3. Add comments                                                  .done
 * +----------------------------------------------------------------+
 * */

int main(int argc, char* argv[]) {

    //Point cloud reference point at 0, 0, 0
    point::Point3D<point::coords_type> referencePoint(0., 0., 0.);

    // Number of points in x direction
    const unsigned int max_x = 50;

    // Number of points in y direction
    const unsigned int max_y = 50;

    // Number of points in z direction
    const unsigned int max_z = 40;

    // Distance between points in the point grid (same fo x, y and z directions)
    const point::coords_type delta = 1.;

    // Discrete step for move function calculation
    const double deltaT = 0.01;

    // Radius of the sphere
    const int sphereRad = 10;

    // Create sphere center point
    point::Point3D<point::coords_type> SphereCenter(max_x, max_y, max_z);

    // Create sphere center moving function (move only on the top layer)
    MovingFunction function(0., 1., deltaT, SphereCenter, 0, 0, max_z);

    //Create sphere center moving function (move through the entire cloud)
    // MovingFunction function(0., 1., deltaT, SphereCenter, 0, 0, 0);

    // Determine result file name
    const std::string FileName("Result.txt");

    // Calling the create skin function
    CreateSkin(referencePoint, max_x, max_y, max_z, delta, function, SphereCenter, sphereRad, FileName);

    return 0;
}
