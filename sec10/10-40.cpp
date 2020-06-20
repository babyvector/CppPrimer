Q：你认为copy上的迭代器属于哪类？reverse和unique呢？
A：copy(a,b,c)  a,b要求是至少为前向迭代器，c可以是输出迭代器
A：reverse(a,b)  a,b要求是双向迭代器
A：unique();函数中的前后两个参量至少应该是前向迭代器