# 判断一个字符串中的括号是否匹配
给定一个字符串，里面只含(){}[],现判断字符串中的扩哈是否匹配。  
## 算法
利用栈保存每个括号符号的左半部分，若出现右半部分栈顶元素出栈，进行匹配。  
最后，判断栈中是否还有剩余括号。  