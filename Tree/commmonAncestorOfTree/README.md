#树中两个节点最近的公共节点。数据结构用邻接矩阵表示
树的结构使用邻接矩阵matrix表示，两个节点分别使用indexA,indexB表示。

##思想
如果matrix[indexA,indexB] 等于1,那么最近的公共节点为(indexA < indexB)? indexA:indexB。否则进行以下步骤:  
1、求出indexA,indexB距离树的根节点的距离，分别用depthA，depthB表示。  
2、让depthA,depthB较大的节点先走|depthA-depthB|步，使indexA和indexB距离根节点相同。设走完之后的节点为tmpNode1，另一个节点为tmpNode2。  
3、tmpNode1和tmpNode2同时向上走，如果在走的过程中发现matrix [tmpNode1,i] == matrix[tmpNode2,j] == 1，并且i == j,那么i就为公共节点。否则,tmpNode1 = i,tmpNode2 = j。
