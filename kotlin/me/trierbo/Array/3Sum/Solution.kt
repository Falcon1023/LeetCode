package me.trierbo.Array.`3Sum`

import java.util.*

/**
 * Description:
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ?
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4} .
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */

/**
 * 先排序后左右加逼 O(n^2)
 */

fun main(args:Array<String>){
    val nums=arrayOf(-1,0,1,2,-1,-4)
    val list= threeSum(nums)
    list.map { print(it[0])
               print(it[1])
               print(it[2])
               println() }
}

fun threeSum(nums:Array<Int>):List<Array<Int>>{
    Arrays.sort(nums)
    val list = mutableListOf<Array<Int>>()
    var j:Int
    var k:Int
    for (i in 0..nums.size-2){
        if(i>0&&nums[i-1]==nums[i])
            continue
        j=i+1
        k=nums.size-1
        while (j<k){
            if(nums[i]+nums[j]+nums[k]==0) {
                list.add(arrayOf(nums[i], nums[j], nums[k]))
                j++
                while (nums[j]==nums[j-1]&&j<k)
                    j++
                k--
                while (nums[k]==nums[k+1]&&j<k)
                    k--
            }
            else if (nums[i]+nums[j]+nums[k]<0){
                j++
                while (nums[j]==nums[j-1]&&j<k)
                    j++
            }else{
                k--
                while (nums[k]==nums[k+1]&&j<k)
                    k--
            }
        }
    }
    return list
}