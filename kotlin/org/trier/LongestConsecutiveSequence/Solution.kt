package org.trier.LongestConsecutiveSequence

import java.util.*

/**
 * Created by trier on 2017/6/1.
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