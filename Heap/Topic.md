优先队列(priority queue)可以在O(1)时间内获取最大值,并且在0(logn)时间内取出最大值或插入任意值.
优先队列常常用堆(heap)来实现,堆是一个完全二叉树,其每个节点的值总是大于等于或小于等于子节点的值.实际
实现堆时,通常用一个数组而不是指针建立一盒树.这是因为堆是完全二叉树,所以利用数组表示时,
(1)若根节点的位置为0,则位置i的节点的父节点一定为(i-1)/2,而它的两个字节点的位置一定为2i+1和2i+2.
(2)若根节点的位置为1,则位置i的节点的父节点一定为i/2,而它的两个字节点的位置一定为2i和2i+1.
堆的实现方式为:
如果一个节点有两个子节点,总是交换最大的子节点.
(1)上浮
如果一个节点比父节点大,那么需要交换这两个节点,交换后还可能比它新的父节点大,因此需要不断地进行比较和交换
操作.
(2)下浮
类似地,如果一个节点比父节点小,也需要不断地向下进行比较和交换操作.

make_heap函数默认最大堆,less<int>(),利用vector实现最大堆