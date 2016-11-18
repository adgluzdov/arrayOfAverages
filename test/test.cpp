#include <gtest/gtest.h>
#include "MassAverage.h"
#include <cstdlib> // Для работы с функцией system()

using namespace std;

TEST(sred, null_array) {
	int *a = 0;
	ASSERT_ANY_THROW(sred(a, 1, 2));
}
TEST(sred, negative_number_of_terms) {
	int a[3] = {1,2,3};
	ASSERT_ANY_THROW(sred(a, 1, -1));
}


TEST(sred, null_window) {
	int a[3] = {1,2,3};
	ASSERT_ANY_THROW(sred(a, 0, 5));
}

TEST(sred, negative_window) {
	int a[3] = {1,2,3};
	ASSERT_ANY_THROW(sred(a, -1, 1));
}


TEST(sred, can_work) {
	int a[3] = {1,1};
	int *res = new int[1];
	res = sred(a, 1, 2);
	EXPECT_EQ(res[0],1);
}

int main(int ac, char* av[]) {
	testing::InitGoogleTest(&ac, av);
	int returnable = RUN_ALL_TESTS();
	system("pause");
	return returnable;
}