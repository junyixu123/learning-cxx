#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    // int size =
    int size = std::accumulate(
        std::begin(shape),          // 数组起始迭代器
        std::end(shape),            // 数组结束迭代器
        static_cast<int>(sizeof(DataType)),  // 初始值：单个float的字节数（4）
        [](int acc, int val) {      // 累加函数：acc * val（乘积逻辑）
            return acc * val;
        }
    );
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
