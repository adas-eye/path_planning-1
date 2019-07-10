#include "test_utils.cpp"

TEST(PathPlanningTest, Test1) {
  int n = 8;
  std::vector<std::vector<int>> grid_1(n);
  std::vector<int> tmp(n);
  for (int i = 0; i < n; i++){
    grid_1[i] = tmp;
  }
  MakeGrid(grid_1);
  std::vector<std::vector<int>> grid_2 = grid_1;
  std::vector<std::vector<int>> grid_3 = grid_1;
  std::vector<std::vector<int>> grid_4 = grid_1;
  std::vector<std::vector<int>> grid_5 = grid_1;
  std::vector<std::vector<int>> grid_6 = grid_1;
  std::vector<std::vector<int>> grid_7 = grid_1;
  std::vector<std::vector<int>> grid_8 = grid_1;

  ASSERT_EQ(run_test(grid_1, "dijkstra"), run_test(grid_2, "a_star"));
  ASSERT_EQ(run_test(grid_3, "lpa_star"), run_test(grid_4, "a_star"));
  ASSERT_EQ(run_test(grid_5, "d_star_lite"), run_test(grid_6, "a_star"));
  ASSERT_GE(abs(run_test(grid_7, "a_star")*1.2), abs(run_test(grid_8, "ant_colony")));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
