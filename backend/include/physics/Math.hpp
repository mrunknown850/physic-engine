#ifndef MATH_HPP
#define MATH_HPP

/**
 * @class Vector3
 * @brief A data structure for representing the mathematical concept of vectors in 3D space.
 */
class Vec3
{
public:
    double x, y, z;

    /**
     * @brief Define vector zero. v(0, 0, 0).
     */
    Vec3();

    /**
     * @brief Define a vector.
     * @param x X-coordinate of the vector.
     * @param y Y-coordinate of the vector.
     * @param z Z-coordinate of the vector.
     */
    Vec3(double x, double y, double z);

    /**
     * @brief Vector addition.
     * @param other The vector to be added to.
     * @return The summation of the two vectors.
     */
    Vec3 operator+(const Vec3 &other) const;

    /**
     * @brief Vector subtraction.
     * @param other The vector to be subtracted to.
     * @return The difference of the two vectors.
     */
    Vec3 operator-(const Vec3 &other) const;

    /**
     * @brief Vector dot product.
     * @param other The vector to be multiplied with.
     * @return The dot product of the two vectors.
     */
    double operator*(const Vec3 &other) const;

    /**
     * @brief Vector scalling.
     * @param scalar The number to which the vector will be scaled.
     * @return The scaled vector.
     */
    Vec3 operator*(double scalar) const;

    Vec3 &operator+=(const Vec3 &other);

    /**
     * @brief Vector's length squared.
     * @return The squared length of the given vector.
     */
    double LengthSquared() const;
};

/**
 * @class Point3
 * @brief A data structure for representing the mathematical concept of three dimensional point.
 */
class Point3
{
public:
    double x, y, z;

    /**
     * @brief Define a center point. O(0,0,0)
     */
    Point3();

    /**
     * @brief Define a point in 3D space.
     * @param x X-Coordinate
     * @param y Y-Coordinate
     * @param z Z-Coordinate
     */
    Point3(double x, double y, double z);

    /**
     * @brief Move a point by a vector.
     * @param other Displacement vector.
     * @return A point displaced by the given vector.
     */
    Point3 operator+(const Vec3 &other) const;

    /**
     * @brief Difference between two points.
     * @param other Point number 2.
     * @return The vector that is the difference of the two points.
     */
    Vec3 operator-(const Point3 &other) const;
};

/**
 * @brief Find the distance between two point squared.
 * @param p1 First point.
 * @param p2 Second point.
 * @return The distance between p1 and p2 squared.
 */
double PointDistanceSquared(const Point3 &p1, const Point3 &p2);

#endif