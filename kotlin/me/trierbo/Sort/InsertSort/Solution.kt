package me.trierbo.Sort.InsertSort

fun main(args: Array<String>) {
    val nums = arrayOf(1, 2, 5, 4, 2, 9, 7, 8, 4, 5, 6, 7, 8, 5, 4, 1, 0)
    insertSort(nums)
    nums.map { print(it) }
}

fun insertSort(nums: Array<Int>) {
    for (i in 1..(nums.size - 1)) {
        val tmp = nums[i]
        for (j in (i - 1).downTo(0)) {
            if (tmp < nums[j]) {
                nums[j + 1] = nums[j]
                if(j == 0)
                    nums[j] = tmp
            } else {
                nums[j + 1] = tmp
                break
            }
        }
    }
}
