#### 被围绕的区域(LintCode 477)

-- 题目: 给一个二维的矩阵，包含 'X' 和 'O', 找到所有被 'X' 围绕的区域，并用 'X' 填充满。

-- 解答:

--- 1. 边界条件：小于两行两列的直接不考虑，不可能包围

--- 2. 从四条边开始做深度优先搜索，所有与边上的'O'连接的'O'全用特殊标志位代替

--- 3. 最后搜索没有被代替的置为'X'

-- 注意：

--- 行和列不要搞串了

--- DFS的思想一定要理解到位