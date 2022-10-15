#ifndef MAIN_CPP_DISCRETEFUNCTION_H
#define MAIN_CPP_DISCRETEFUNCTION_H

#include "Point3D.h"

class DiscreteFunction {
public:
    using point3d = point::Point3D<point::coords_type>;

    inline DiscreteFunction(const double &t1, const double &t2, const double& delta_)
            : T_Begin(t1), T_End(t2), delta(delta_) {
    };

    inline virtual ~DiscreteFunction() = default;

    inline virtual point3d& Evaluate(const double &t, point3d& point) const {
        if (t < T_Begin || t > T_End)
            throw misc::Exception(0, "T is out of range");

        return point;
    };

    inline double GetBeginParameter() const {
        return T_Begin;
    };

    inline double GetEndParameter() const {
        return T_End;
    };

    inline double GetDeltaParameter() const {
        return delta;
    };
private:
    double T_Begin;
    double T_End;
    double delta;
};

#endif //MAIN_CPP_DISCRETEFUNCTION_H
