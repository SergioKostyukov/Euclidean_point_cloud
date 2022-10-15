#include "MovingFunction.h"

MovingFunction::MovingFunction(const double &t1, const double &t2, const double &delta_, point3d &Start,
                               const double &x, const double &y, const double &z)
        : DiscreteFunction(t1, t2, delta_) {
    StartPoint = new point3d(Start);
    FinishPoint = new point3d(x, y, z);
    PointCurvature = new point3d(50, 0, z);

    MovingFunction::point3d Vector;
    Vector = (*PointCurvature) - (*StartPoint);
    !Vector;
    MovingVector = new point3d(Vector);
};

MovingFunction::point3d &
MovingFunction::LinearInterpolate(MovingFunction::point3d &point1, MovingFunction::point3d &point2, const double &t) {
    auto res = new MovingFunction::point3d;

    // interpolation is a method of finding a point between two points at a certain time
    // (t = 0 is the start point, t = 1 is the finish point, all in between them is interpolation)
    res->Set_X(point1.Get_X() + (point2.Get_X() - point1.Get_X()) * t);
    res->Set_Y(point1.Get_Y() + (point2.Get_Y() - point1.Get_Y()) * t);
    res->Set_Z(point1.Get_Z() + (point2.Get_Z() - point1.Get_Z()) * t);

    return *res;
}

MovingFunction::point3d &MovingFunction::Evaluate(const double &t, point3d &point) const {
    DiscreteFunction::Evaluate(t, point);

    // interpolate points between StartPoint-PointCurvature and PointCurvature-FinishPoint
    point3d point1 = LinearInterpolate(*StartPoint, *PointCurvature, t);
    point3d point2 = LinearInterpolate(*PointCurvature, *FinishPoint, t);

    // save the coordinate value of the point before the step
    point3d point_before_step = point;

    // interpolate point between point1-point2
    point = LinearInterpolate(point1, point2, t);

    // update the displacement vector as the difference between the point before and after the step
    *MovingVector = point - point_before_step;

    return point;
}

