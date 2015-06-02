# 给定一个字符串，按照zigzag型打印。
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)  
P   A   H   N  
A P L S I I G  
Y   I   R  
And then read line by line: "PAHNAPLSIIGYIR"  

## 算法
可以分成两个部分：首、尾行和其他的行。  
1、首尾行的上一个元素(i)和下一个元素(j)之间的间隔:j=i+2 * (numRows-1),其中numRows为指定行数。  
2、其余的行，在打印元素(i)之后还需要打印i右边的元素k(小于i+2×(numRows-1)的位置),他们之间的关系为:k=i+2×(numRows-i-1)。  
