package org.trier.Array.LongestConsecutiveSequence

import java.util.*

/**
 * Description:
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example, Given [100, 4, 200, 1, 3, 2] , The longest consecutive elements sequence is [1, 2,
 * 3, 4] . Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */
fun longestConsecutive(nums:Array<Int>):Int{
    var set=HashSet<Int>()
    nums.map { set.add(it) }
    var longest=0
    nums.map {
        var length=1
        var i=it-1
        while (set.contains(i)){
            i--
            length++
        }
        i=it+1
        while (set.contains(i)){
            i++
            length++
        }
        if (length>longest)
            longest=length
    }
    return longest
}

fun main(args:Array<String>){
    val scanner=Scanner(System.`in`)
    val num=scanner.nextInt()
    var nums=Array(num,{0})
    for(i in 0 until num){
        nums[i]=scanner.nextInt()
    }
    val longest=longestConsecutive(nums)
    println(longest)
}