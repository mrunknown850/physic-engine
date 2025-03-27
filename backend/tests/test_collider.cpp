#include <gtest/gtest.h>
#include "Colliders.hpp"

TEST(CircleCollisionTest, CirclesShouldCollide)
{
    Body b1(Point3(5, 5, 0), 4, Vec3(), false);
    Body b2(Point3(7, 5, 0), 4, Vec3(), false);

    SphereCollider c1(&b1, 3);
    SphereCollider c2(&b2, 4);
    EXPECT_TRUE(c1.CollidesWith(c2));
    EXPECT_TRUE(c2.CollidesWith(c1));
}

TEST(CircleCollisionTest, CirclesShouldNotCollide)
{
    Body b1(Point3(5, 5, 0), 4, Vec3(), false);
    Body b2(Point3(10, 5, 0), 4, Vec3(), false);

    SphereCollider c1(&b1, 2);
    SphereCollider c2(&b2, 2);
    EXPECT_FALSE(c1.CollidesWith(c2));
    EXPECT_FALSE(c2.CollidesWith(c1));
}

TEST(RectCollisionTest, RectanglesShouldCollide)
{
    Body b1(Point3(2, 2, 0), 4, Vec3(), false);
    Body b2(Point3(3, 3, 0), 4, Vec3(), false);

    BoxCollider s1(&b1, Vec3(4, 4, 4));
    BoxCollider s2(&b2, Vec3(4, 4, 4));
    EXPECT_TRUE(s1.CollidesWith(s2));
    EXPECT_TRUE(s2.CollidesWith(s1));
}

TEST(RectCollisionTest, RectanglesShouldNotCollide)
{
    Body b1(Point3(0, 0, 0), 4, Vec3(), false);
    Body b2(Point3(5, 5, 0), 4, Vec3(), false);

    BoxCollider s1(&b1, Vec3(2, 2, 2));
    BoxCollider s2(&b2, Vec3(2, 2, 2));
    EXPECT_FALSE(s1.CollidesWith(s2));
    EXPECT_FALSE(s2.CollidesWith(s1));
}

TEST(MixedCollisionTest, BoxCollideSphere) {
    Body b1(Point3(0, 0, 0), 4, Vec3(), false);
    Body b2(Point3(5, 5, 0), 4, Vec3(), false);

    BoxCollider s1(&b1, Vec3(2, 2, 2));
    SphereCollider s2(&b2, 100);
    EXPECT_TRUE(s1.CollidesWith(s2));
    EXPECT_TRUE(s2.CollidesWith(s1));
}

TEST(MixedCollisionTest, BoxNotCollideSphere) {
    Body b1(Point3(0, 0, 0), 4, Vec3(), false);
    Body b2(Point3(5, 5, 0), 4, Vec3(), false);

    BoxCollider s1(&b1, Vec3(2, 2, 2));
    SphereCollider s2(&b2, 1);
    EXPECT_FALSE(s1.CollidesWith(s2));
    EXPECT_FALSE(s2.CollidesWith(s1));
}
