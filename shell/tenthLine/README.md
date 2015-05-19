#head和tail用法
##head用法
head -n (+)number filename:从filename文件开头将前nuber行输出，如果没有指定行,默认是10行。  
haed -n -number filename:输出除了尾部number行之外的所有行。  

##tail用法
tail -n (-)number filename:输出文件尾部开始的前number行，默认是10行。  
tail -n +number filename:输出从开头的第number到尾部的所有行。  
