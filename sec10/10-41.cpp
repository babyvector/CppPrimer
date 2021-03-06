Q：仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作？
A：replace(beg,end,old_val,new_val);
   将迭代器beg和end范围内的所有old_val值替换成为new_val值
   replace_if(beg,end,pred,new_val);
   将迭代器beg和end之间的符合一元谓词pred的值替换为new_val
   replace_copy(beg,end,dest,old_val,new_val);
   将迭代器beg和end之间的值拷贝到dest位置，并且在拷贝的时候将等于old_val的值替换为new_val
   replace_copy_if(beg,end,dest,pred,new_val);
   将迭代器beg和end之间的值拷贝到dest位置，并且在拷贝过程中将使谓词pred成立的值替换为new_val再拷贝过去