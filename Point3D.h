#ifndef MAIN_CPP_POINT3D_H
#define MAIN_CPP_POINT3D_H

#include "IdxRangeException.h"
#include <cmath>

namespace point {
    using coords_type = double;

    template<typename T>
    class Point3D {
    public:
        // Default constructor
        explicit Point3D() {
            coords[0] = 0;
            coords[1] = 0;
            coords[2] = 0;
        }

        // Constructor
        /*!Constructs a Point3D object with given parameters:
            \param x - x point coord
            \param y - y point coord
            \param z - z point coord
        */
        explicit Point3D(const T &x, const T &y, const T &z) {
            coords[0] = x;
            coords[1] = y;
            coords[2] = z;
        }

        // Copy constructor
        /*!Constructs a Point3D object with given parameters:
            \param other - Point3D object to copy values
        */
        Point3D(const Point3D &other) {
            coords[0] = other.coords[0];
            coords[1] = other.coords[1];
            coords[2] = other.coords[2];
        }

        // Constructor
        /*!Constructs a Point3D object with given parameters:
            \param other - const array with coords values
        */
        explicit Point3D(const T other[]) {
            coords[0] = other[0];
            coords[1] = other[1];
            coords[2] = other[2];
        }

        inline const T &Get_X() const {
            return coords[0];
        }

        inline const T &Get_Y() const {
            return coords[1];
        }

        inline const T &Get_Z() const {
            return coords[2];
        }

        inline void Set_X(const T &x) {
            coords[0] = x;
        }

        inline void Set_Y(const T &y) {
            coords[1] = y;
        }

        inline void Set_Z(const T &z) {
            coords[2] = z;
        }

        // Operators
        inline const Point3D &operator=(const Point3D<point::coords_type> &other) {
            coords[0] = other.coords[0];
            coords[1] = other.coords[1];
            coords[2] = other.coords[2];

            return *this;
        };

        const T &operator[](const unsigned short id) {
            if (id > 2)
                throw misc::IdxRangeException(2, id);
            return coords[id];
        };

        inline void operator+=(const Point3D<point::coords_type> &other) {
            coords[0] += other.coords[0];
            coords[1] += other.coords[1];
            coords[2] += other.coords[2];
        };

        inline double operator~() const {
            return std::sqrt(coords[0] * coords[0] +
                             coords[1] * coords[1] +
                             coords[2] * coords[2]);
        };

        inline void operator/=(const double &Factor) {
            coords[0] /= Factor;
            coords[1] /= Factor;
            coords[2] /= Factor;
        };

        inline void operator!() {
            (*this) /= ~(*this);
        };

    private:
        T coords[3];
    };

    template<typename T>
    inline Point3D<T> operator-(
            const Point3D<T> &first, const Point3D<T> &second) {
        return Point3D<T>(first.Get_X() - second.Get_X(),
                          first.Get_Y() - second.Get_Y(),
                          first.Get_Z() - second.Get_Z());
    };

    template<typename T>
    inline T operator*(Point3D<T> &first, Point3D<T> &second) {
        return first.Get_X() * second.Get_X() +
               first.Get_Y() * second.Get_Y() +
               first.Get_Z() * second.Get_Z();
    };
}

#endif //MAIN_CPP_POINT3D_H
