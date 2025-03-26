#include "Forces.hpp"

Force::Force(Vec3 offset, Vec3 pointing_vector, float duration) : offset(offset), pointing_vector(pointing_vector), duration(duration) {}
Force Force::operator+(const Force &other) const { return Force(offset, pointing_vector + other.pointing_vector, duration); }
Force Force::operator-(const Force &other) const { return Force(offset, pointing_vector - other.pointing_vector, duration); }
Force &Force::operator+=(const Force &other)
{
    pointing_vector += other.pointing_vector;
    return *this;
}
