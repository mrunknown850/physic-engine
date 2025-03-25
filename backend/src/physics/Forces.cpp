#include "Forces.hpp"

Force::Force(Vec3 origin, Vec3 pointing_vector, float duration) : origin(origin), pointing_vector(pointing_vector), duration(duration) {}
Force Force::operator+(const Force &other) const { return Force(origin, pointing_vector + other.pointing_vector, duration); }
Force Force::operator-(const Force &other) const { return Force(origin, pointing_vector - other.pointing_vector, duration); }
Force &Force::operator+=(const Force &other)
{
    pointing_vector += other.pointing_vector;
    return *this;
}
