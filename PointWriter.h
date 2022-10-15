#ifndef MAIN_CPP_POINTWRITER_H
#define MAIN_CPP_POINTWRITER_H

#include "PointCloud.h"

#include <fstream>

class PointWriter {
public:
    // Default constructor
    PointWriter() {
        file = nullptr;
    }

    // Constructor
    /*!Constructs a PointWriter object with given parameter:
        \param file_name - output file name
    */
    explicit PointWriter(const std::string &file_name) {
        file.open(file_name, std::ios::out);
    }

    // Destructor
    ~PointWriter() {
        file.close();
    }

    // OutLayer function
    /*!writes the top layer points to a file:
        \param obj - points cloud
    */
    void OutLayer(Cloud::PointCloud &obj) {
        point::coords_type point[3] = {0., 0., 0.};
        for (int i = 0; i < obj.Get_Max_X(); i++) {
            for (int j = 0; j < obj.Get_Max_Y(); j++) {
                point[0] = i;
                point[1] = j;
                point[2] = obj.Find_depth(i * obj.Get_Max_Y() + j);
                if (point[2] != -1.) {
                    this->OutPoint(point);
                }
            }
        }
    }

    // OutputCloud function
    /*!writes saved cloud points to a file:
        \param obj - points cloud
    */
    void OutCloud(Cloud::PointCloud &obj) {
        point::coords_type point[3] = {0, 0, 0};
        for (int i = 0; i < obj.Get_Max_X(); i++) {
            for (int j = 0; j < obj.Get_Max_Y(); j++) {
                for (int k = 0; k < obj.Get_Max_Z(); k++) {
                    if (obj.Is_alive(k, i * obj.Get_Max_Y() + j)) {
                        point[0] = (obj.GetReferencePoint().Get_X() + i) * obj.GetDelta();
                        point[1] = (obj.GetReferencePoint().Get_Y() + j) * obj.GetDelta();
                        point[2] = (obj.GetReferencePoint().Get_Z() + k) * obj.GetDelta();
                        this->OutPoint(point);
                    }
                }
            }
        }
    }

private:
    // OutputPoint function
    /*!writes simple point to a file:
        \param point - point coords
    */
    void OutPoint(point::coords_type point[3]) {
        file << point[0] << " " << point[1] << " " << point[2] << std::endl;
    }

    std::fstream file;
};

#endif //MAIN_CPP_POINTWRITER_H
