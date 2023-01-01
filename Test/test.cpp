#include "pch.h"

#include "../SnakeGame/World.h"

TEST(WorldTest, GetCellCoordSize1)
{
    World world{10, 10, 1};

    EXPECT_EQ(world.GetCellCoord(0, 0), Coord(0, 0));

    EXPECT_EQ(world.GetCellCoord(0.4, 0), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(0.5, 0), Coord(1, 0));
    EXPECT_EQ(world.GetCellCoord(0.6, 0), Coord(1, 0));

    EXPECT_EQ(world.GetCellCoord(0, 0.4), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(0, 0.5), Coord(0, 1));
    EXPECT_EQ(world.GetCellCoord(0, 0.6), Coord(0, 1));

    EXPECT_EQ(world.GetCellCoord(-0.4, 0), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(-0.5, 0), Coord(-1, 0));
    EXPECT_EQ(world.GetCellCoord(-0.6, 0), Coord(-1, 0));

    EXPECT_EQ(world.GetCellCoord(0, -0.4), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(0, -0.5), Coord(0, -1));
    EXPECT_EQ(world.GetCellCoord(0, -0.6), Coord(0, -1));

    EXPECT_EQ(world.GetCellCoord(2.6, 3.4), Coord(3, 3));
    EXPECT_EQ(world.GetCellCoord(-2.6, -3.4), Coord(-3, -3));
}

TEST(WorldTest, GetCellCoordSize3)
{
    World world{10, 10, 3};

    EXPECT_EQ(world.GetCellCoord(1.4, 0), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(1.5, 0), Coord(1, 0));
    EXPECT_EQ(world.GetCellCoord(1.6, 0), Coord(1, 0));

    EXPECT_EQ(world.GetCellCoord(0, 1.4), Coord(0, 0));
    EXPECT_EQ(world.GetCellCoord(0, 1.5), Coord(0, 1));
    EXPECT_EQ(world.GetCellCoord(0, 1.6), Coord(0, 1));

    EXPECT_EQ(world.GetCellCoord(9.4, 0), Coord(3, 0));
    EXPECT_EQ(world.GetCellCoord(10.5, 0), Coord(4, 0));
    EXPECT_EQ(world.GetCellCoord(10.6, 0), Coord(4, 0));

    EXPECT_EQ(world.GetCellCoord(0, 9.4), Coord(0, 3));
    EXPECT_EQ(world.GetCellCoord(0, 10.5), Coord(0, 4));
    EXPECT_EQ(world.GetCellCoord(0, 10.6), Coord(0, 4));
}

TEST(WorldTest, GetWorldPos)
{
    World world{10, 10, 3};

    EXPECT_EQ(world.GetWorldPos(Coord(0, 0)), glm::vec3(0.0f, 0.0f, 0.0f));
    EXPECT_EQ(world.GetWorldPos(Coord(2, 2)), glm::vec3(6.0f, 6.0f, 0.0f));
    EXPECT_EQ(world.GetWorldPos(Coord(-2, 1)), glm::vec3(-6.0f, 3.0f, 0.0f));
}