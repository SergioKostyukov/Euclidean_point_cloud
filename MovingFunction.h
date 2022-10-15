#ifndef MAIN_CPP_MOVINGFUNCTION_H
#define MAIN_CPP_MOVINGFUNCTION_H

#include "DiscreteFunction.h"

class MovingFunction : public DiscreteFunction {
public:
    // Constructor
    /*!Constructs a MovingFunction object with given parameters:
        \param t1 - start time value
        \param t2 - end time value
        \param delta_ - discrete step
        \param Start - start point of sphere move
        \param x - x coord of finish point
        \param y - y coord of finish point
        \param z - z coord of finish point
    */
    MovingFunction(const double &t1, const double &t2, const double &delta_, point3d &Start, const double &x,
                   const double &y, const double &z);

    ~MovingFunction() override {
        delete MovingVector;
        delete StartPoint;
        delete FinishPoint;
        delete PointCurvature;
    }

    // Evaluate function
    /*!Point coords changing function with given parameters:
        \param t - current time value
        \param point - point object
    */
    point3d &Evaluate(const double &t, point3d &point) const override;

    point3d &GetMovingVector() {
        return *MovingVector;
    }

private:
    point3d *MovingVector;
    point3d *StartPoint;
    point3d *FinishPoint;
    point3d *PointCurvature;

    // MovingFunction
    /*!Function to realise interpolation of points. With given parameters:
        \param point1 - first point
        \param point2 - second point
        \param t - current time
    */
    static MovingFunction::point3d &LinearInterpolate(MovingFunction::point3d &point1,
                                                      MovingFunction::point3d &point2,
                                                      const double &t);
};


#endif //MAIN_CPP_MOVINGFUNCTION_H
