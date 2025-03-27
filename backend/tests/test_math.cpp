#include <gtest/gtest.h>
#include "Math.hpp"

constexpr double epsilon = 1e-6;  // Allowable error margin

// Testing vectors
TEST(VectorOperations, VectorAdditionTest)
{
    Vec3 v1(1.5, 2.6, 3.87);
    Vec3 v2(5.4, 7.3, 1.2);
    Vec3 v3 = v1 + v2;
    EXPECT_NEAR(v3.x, v1.x + v2.x, epsilon);
    EXPECT_NEAR(v3.y, v1.y + v2.y, epsilon);
    EXPECT_NEAR(v3.z, v1.z + v2.z, epsilon);
}

TEST(VectorOperations, VectorSubtractionTest)
{
    Vec3 v1(1.5, 2.6, 3.87);
    Vec3 v2(5.4, 7.3, 1.2);
    Vec3 v3 = v1 - v2;
    EXPECT_NEAR(v3.x, v1.x - v2.x, epsilon);
    EXPECT_NEAR(v3.y, v1.y - v2.y, epsilon);
    EXPECT_NEAR(v3.z, v1.z - v2.z, epsilon);
}

TEST(VectorOperations, VectorDotProductTest)
{
    Vec3 v1(1.5, 2.6, 3.87);
    Vec3 v2(5.4, 7.3, 1.2);
    float v3 = v1 * v2;
    EXPECT_NEAR(v3, (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z), epsilon);
}

TEST(VectorOperations, VectorLengthSquaredTest)
{
    Vec3 v1(1.5, 2.6, 3.87);
    EXPECT_NEAR(v1.LengthSquared(), 1.5 * 1.5 + 2.6 * 2.6 + 3.87 * 3.87, epsilon);
    EXPECT_NEAR(v1.LengthSquared(), v1 * v1, epsilon);
}

// Testing points
TEST(PointOperations, PointDisplacementTest) {
    Point3 p(1, 5, 2);
    Vec3 v(0, 5, 2);
    Point3 ps = p + v;
    EXPECT_NEAR(ps.x, p.x + v.x, epsilon);
    EXPECT_NEAR(ps.y, p.y + v.y, epsilon);
    EXPECT_NEAR(ps.z, p.z + v.z, epsilon);
}

TEST(PointOperations, VectorDifferenceTest) {
    Point3 p1(1, 5, 2);
    Point3 p2(0, 5, 2);
    Vec3 vs = p1 - p2;
    EXPECT_NEAR(vs.x, p1.x - p2.x, epsilon);
    EXPECT_NEAR(vs.y, p1.y - p2.y, epsilon);
    EXPECT_NEAR(vs.z, p1.z - p2.z, epsilon);
}

TEST(PointOperations, PointDistanceTest) {
    Point3 p1(1, 5, 2);
    Point3 p2(0, 5, 2);
    double d = PointDistanceSquared(p1, p2);
    EXPECT_NEAR(d, 1, epsilon);
}
