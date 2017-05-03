/*
 * 3.hpp
 *
 *  Created on: May 3, 2017
 *      Author: wangwei69
 */

#ifndef _HPP_
#define _HPP_

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

static int min3(int,int,int);
int edit_distance(string,string);

//参考别人的实现：编辑距离

class solution{

public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        if (size1 == 0) return size2;
        if (size2 == 0) return size1;

        //使用vector定义二维数组。学习了。
        vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (int i = 0; i <= size1; i++)
            dp[i][0] = i;
        for (int j = 0; j <= size2; j++)
            dp[0][j] = j;
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                int replace = word1[i - 1] == word2[j - 1] ?
                                dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                // insert: dp[i][j - 1], which means we use the steps from word1[0..i] to word[0..j]
                // delete: dp[i - 1][j], same as the previous one
                // and dont forget + 1;
                int ins_del = std::min(static_cast<int>(dp[i][j - 1]),
                        static_cast<int>(dp[i - 1][j])) + 1;
                //不加static_cast编译器总提示错误，但能运行。
                dp[i][j] = std::min(replace, ins_del);
            }
        }

        return dp.back().back();//back返回最后一个元素的引用
    }
};




#endif /* 3_HPP_ */
