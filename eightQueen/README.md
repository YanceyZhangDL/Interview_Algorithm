#### N皇后问题

##### 原始未优化版本(Queen.cpp)

-- 1. 因为所有的皇后都不在同一行，所以按行遍历每个点。

-- 2. 访问到每行的每个点的时候，判断此点和前面所有的点比较是否符合要求

-- 3. 符合要求的标准：横坐标不相同，纵坐标差的绝对值不等于横坐标差的绝对值
