##单词搜索
给定一个二维的字符数组board，和一个字符串s，查找s是否在board。在搜索过程中，只能水平或者垂直进行搜索，并且每个元素只能使用一次。  

##算法(递归回溯)
在搜索的过程中存在一个细节，那就是要标记已经使用过的字符，本程序使用字符#标记本次搜索过程中已经使用过的字符。    
递归函数bool search(vector< vector< char> > &tmp,int i,int j,string word,int size)。  
参数说明：tmp要搜索的二维数组。i，j：本次搜索的位置。word：要匹配的字符串。size：已经匹配的个数。  
递归的具体过程如下：  
1、递归的出口：i >= board.size() || j >= board[i].size() || i < 0 || j < 0 || tmp[i,j] == '#' || tmp[i,j] != word[size]。  
2、如果，搜过过程中size == word.size()-1，已经匹配到最后一个字符，并且已经步骤1之后，最后一个也匹配成功，那么 return true。否则，进行以下步骤。  
3、利用变量保存当前board[i,j],标记board[i,j]已经使用过(#),匹配word的下一个字符(++size),水平或者垂直匹配。search(tmp,i+1,j,word,size) || search(tmp,i-1,j,word,size) || search(tmp,i,j-1,word,size) || search(tmp,i,j+1,word,size)。如果匹配成功，那么返回true。否则  
4、利用变量恢复board[i,j],本次匹配失败，return false。
