#pragma once

#include <common.h>

namespace Entities
{
    class Point
    {
        public: 
            double longitude;
            double latitude;

            Point()
            {
                longitude = 0.0;
                latitude = 0.0;
            }

            Point(double x, double y) : longitude(x), latitude(y) {}

            ~Point() { }

            bool operator==(const Point& other) const 
            {
                return (longitude == other.longitude && latitude == other.latitude);
            }
    };
}
