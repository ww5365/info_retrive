/*
 *  Created on: Apr 24, 2017
 *  Author: ww5365@163.com
 *  comment:信息检索导论，第三章中涉及主要理论点的实现，包括：
 *
 *  1、编辑距离实现
 *
 */

#include "all.h"
#include "3.hpp"
#include <iostream>

using namespace std;


int test_3(){

    string str1 = "wang";
    string str2 = "wei";
    solution s;

    std::cout<< "the two string edit distance:"<<endl;
    std::cout << edit_distance(str1,str2) <<std::endl;//自己的实现
    std::cout << s.minDistance (str1,str2) <<std::endl; //参考别人的实现
}


////////////////////////////////////////////////////////////////////////

/*
 * 功能：计算两个字符串：str1 和 str2的编辑距离
 * 算法：动态规划
 * s[i,j]:字符串str1前i字符，变成str2前j个字符，最少变更的字符数(即编辑距离)。
 * s[i,j] = min{s[i-1,j-1]+0/1, s[i,j-1]+1, s[i-1,j]+1}  //这是精髓。
 *
 * 应用：纠错服务
 */


//下面自己的实现，纠错?

int edit_distance(std::string str1,std::string str2){

    //cout << "begin to caculate edit distance!" <<endl;

    //vector<vector<int> > dis;   //定义后，如何分配空间？？
    vector<vector<int> > dis(str1.size()+1,vector<int>(str2.size()+1,0));
    int tmp_dis = 0;

    if (str1.empty()){//str1为空
        return str2.length();
    }
    if (str2.empty()){//str2为空
        return str1.length();
    }

    for (int i = 0;i <= str1.size();i++){

        for (int j = 0;j <= str2.size();j++){

            if (i == 0){//初始化，相当于str1为空串
                dis[i][j] = j;
                continue;
            }
            if(j == 0){//初始化，相当于str2为空串
                dis[i][j] = i;
                continue;
            }

            if (i > 0 && j > 0){
                if(str1.at(i-1) == str2.at(j-1)){
                    tmp_dis = dis[i-1][j-1];
                }else{
                    tmp_dis = dis[i-1][j-1] + 1;
                }
                int d1 = dis[i-1][j] + 1;
                int d2 = dis[i][j-1] + 1;
                dis[i][j] = min3(tmp_dis,d1,d2);
            }
            //if ((i == str1.length() - 1) && (j == str2.length() - 1))
            //    return dis[i][j];
        }//end for j

    }//end for i

    return dis.back().back();

}

/*
 * 计算三个值中最小的，并返回；
 */

static int min3(int dis1,int dis2,int dis3){

    int tmp = dis1;
    if (tmp > dis2){
        tmp = dis2;
    }
    if (tmp > dis3){
        tmp = dis3;
    }
    return tmp;
}



// 参考3.hpp 中class solution中minDistance别人的实现;纠正自己错误；


////////////////////////////////////////////////////////////////////////////////////////






