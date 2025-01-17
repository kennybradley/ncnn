// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "layer/swish.h"
#include "testutil.h"

static int test_swish(const ncnn::Mat& a)
{
    ncnn::ParamDict pd;

    std::vector<ncnn::Mat> weights(0);

    int ret = test_layer<ncnn::Swish>("Swish", pd, weights, a);
    if (ret != 0)
    {
        fprintf(stderr, "test_swish failed a.dims=%d a=(%d %d %d %d)\n", a.dims, a.w, a.h, a.d, a.c);
    }

    return ret;
}

static int test_swish_0()
{
    return 0
           || test_swish(RandomMat(5, 6, 7, 24))
           || test_swish(RandomMat(5, 6, 7, 24))
           || test_swish(RandomMat(7, 8, 9, 12))
           || test_swish(RandomMat(7, 8, 9, 12))
           || test_swish(RandomMat(3, 4, 5, 13))
           || test_swish(RandomMat(3, 4, 5, 13));
}

static int test_swish_1()
{
    return 0
           || test_swish(RandomMat(5, 7, 24))
           || test_swish(RandomMat(7, 9, 12))
           || test_swish(RandomMat(3, 5, 13));
}

static int test_swish_2()
{
    return 0
           || test_swish(RandomMat(15, 24))
           || test_swish(RandomMat(17, 12))
           || test_swish(RandomMat(19, 15));
}

static int test_swish_3()
{
    return 0
           || test_swish(RandomMat(128))
           || test_swish(RandomMat(124))
           || test_swish(RandomMat(127));
}

int main()
{
    SRAND(7767517);

    return 0
           || test_swish_0()
           || test_swish_1()
           || test_swish_2()
           || test_swish_3();
}
