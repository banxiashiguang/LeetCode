# 比较版本大小
给定两个字符串version1和version2,比较两个版本的大小，如果version1大于version2,返回1,等于返回0,小于返回-1。  

## 算法
利用字符串处理函数find以"."为分割符将字符串分割，然后substr去的分割的子字符串，stoi将分割的子字符串转换成整数，将相应的位进行比较。  
注意细节：如果一个字符串的分割完毕，而另一个有剩余，将剩余的也进行上述的处理。  
