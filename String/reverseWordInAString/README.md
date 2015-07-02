# reverse words in a string
Given an input string, reverse the string word by word. For example: Given s = "the sky is blue", return s = "blue is sky the".  

## algrithm 
利用istringstream读入字符串s，然后在输出。

## 细节
如果s由空格构成，那么将返回空字符串。  
如果单词之间由多个空格构成压缩成一个空格。  
