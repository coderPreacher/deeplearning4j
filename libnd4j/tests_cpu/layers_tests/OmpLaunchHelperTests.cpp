//
// Created by raver119 on 30.06.18.
//

#include "testlayers.h"
#include <NDArray.h>
#include <OmpLaunchHelper.h>


using namespace nd4j;
using namespace nd4j::graph;

class OmpLaunchHelperTests : public testing::Test {
private:
    int ewt = 0;
public:
    OmpLaunchHelperTests() {
        this->ewt = Environment::getInstance()->elementwiseThreshold();
        Environment::getInstance()->setElementwiseThreshold(1000);
    };

    ~OmpLaunchHelperTests() {
        Environment::getInstance()->setElementwiseThreshold(this->ewt);
    }
};

TEST_F(OmpLaunchHelperTests, Test_BetterSpan_1) {
    auto span = OmpLaunchHelper::betterSpan(1000, 4);
    ASSERT_EQ(250, span);
}

TEST_F(OmpLaunchHelperTests, Test_BetterSpan_2) {
    auto span = OmpLaunchHelper::betterSpan(1001, 4);
    ASSERT_EQ(251, span);
}

TEST_F(OmpLaunchHelperTests, Test_BetterSpan_3) {
    auto span = OmpLaunchHelper::betterSpan(1002, 4);
    ASSERT_EQ(251, span);
}

TEST_F(OmpLaunchHelperTests, Test_BetterSpan_5) {
    auto span = OmpLaunchHelper::betterSpan(1003, 4);
    ASSERT_EQ(251, span);
}

TEST_F(OmpLaunchHelperTests, Test_BetterSpan_6) {
    auto span = OmpLaunchHelper::betterSpan(1004, 4);
    ASSERT_EQ(251, span);
}


TEST_F(OmpLaunchHelperTests, Test_BetterThreads_1) {
    auto n = OmpLaunchHelper::betterThreads(4000, 6);
    ASSERT_EQ(4, n);
}

TEST_F(OmpLaunchHelperTests, Test_BetterThreads_2) {
    auto n = OmpLaunchHelper::betterThreads(12000, 6);
    ASSERT_EQ(6, n);
}

TEST_F(OmpLaunchHelperTests, Test_BetterThreads_3) {
    auto n = OmpLaunchHelper::betterThreads(899, 6);
    ASSERT_EQ(1, n);
}