# pat
准备2019.9.8pat甲级

1.pat甲级的题目重新刷一遍，记录一下经验教训。
2.对题目做个分类，方便进行针对性练习。

## 图

### 图概念题
- 1122 Hamiltonian Cycle (25) 哈密顿图
- 1126 Eulerian Path (25) 欧拉图
- 1134 Vertex Cover (25) 点覆盖
- 1142 Maximal Clique (25)
- 1150 Travelling Salesman Problem (25)
- 1154 Vertex Coloring (25)

### 拓扑排序
1146 Topological Order (25)

### 关键路径


### 连通分量
- 1013 Battle Over Cities (25)
- 1021 Deepest Root (25)

### 最短路径(Dijkstra及其常规变型)
- 1003 Emergency (25)
- 1072 Gas Station (30)
- 1111 Online Map (30)


### 广度优先搜索
- 1076 Forwards on Weibo (30)
- 1091 Acute Stroke (30) //dfs会爆栈

### 深度优先搜索
- 1018 Public Bike Management (30)
- 1030 Travel Plan (30)
- 1034 Head of a Gang (30)
- 1045 Favorite Color Stripe (30)
- 1068 Find More Coins (30) //理解状态
- 1087 All Roads Lead to Rome (30)
- 1103 Integer Factorization (30) //1.将一些在搜索中被重复计算的值，提前算好存在数组中；2.剪枝最关键。
- 1131 Subway Map (30) //将 v1 * 10000 + v2 存入unorder_map 用于查询一段区间属于哪条线路
- 1139 First Contact (30) // 对于四个数字的id要注意 0000 ，特别是还要带正负号时 正数读入-0和+0时结果都是+0，要用字符串读入

## 树

### 遍历：前、中、后序，层次，建树
- 1004 Counting Leaves (30)
- 1020 Tree Traversals (25)
- 1053 Path of Equal Weight (30)
- 1079 Total Sales of Supply Chain (25)
- 1086 Tree Traversals Again (25)
- 1090 Highest Price in Supply Chain (25)
- 1094 The Largest Generation (25)
- 1102 Invert a Binary Tree (25)
- 1106 Lowest Price in Supply Chain (25)
- 1119 Pre- and Post-order Traversals (30)
- 1127 ZigZagging on a Tree (30)
- 1130 Infix Expression (25)
- 1135 Is It A Red-Black Tree (30)
- 1138 Postorder Traversal (25)
- 1159 Structure of a Binary Tree (30)

### 堆
- 1147 Heaps (30)
- 1155 Heap Paths (30)

### 完全二叉树
- 1110 Complete Binary Tree (25) 完全二叉树的判断

### 二叉搜素树
- 1043 Is It a Binary Search Tree (25)
- 1064 Complete Binary Search Tree (30)
- 1099 Build A Binary Search Tree (30)
- 1115 Counting Nodes in a BST (30)

### 平衡二叉树
- 1066 Root of AVL Tree (25) * 插入与左右旋
- 1123 Is It a Complete AVL Tree (30)  插入、完全二叉树的判断
- 平衡二叉树的删除

### 并查集
- 1107 Social Clusters (30)
- 1118 Birds in Forest (25)
- 1114 Family Property (25)
- 1158 Telefraud Detection (25)

### 最小公共祖先
- 1143 Lowest Common Ancestor (30)
- 1151 LCA in a Binary Tree (30)

### 哈夫曼树、最佳归并
- 1125 Chain the Ropes (25)

## 贪心
- 1070 Mooncake (25)
- 1033 To Fill or Not to Fill (25) *

## 模拟题
- 1014 Waiting in Line (30)
- 1016 Phone Bills (25)
- 1017 Queueing at Bank (25)
- 1026 Table Tennis (30)
- 1080 Graduate Admission (30)
- 1095 Cars on Campus (30)


## 动态规划
- 1007 Maximum Subsequence Sum (25)
- 1049 Counting Ones (30)

## 哈希表
- 1078 Hashing (25)
- 1145 Hashing - Average Search Time (25) 平方探测，只有正数项，1^2,2^2,...(m-1)^2,最后一项是m-1,不是包含正负项时的m/2

## 查找
- 1022 Digital Library (30) * //auto it 可以代替 map <string, int>::iterator it
- 1039 Course List for Student (25)
- 1047 Student List for Course (25)
- 1149 Dangerous Goods Packaging (25)
- 1055 The World's Richest (25)
- 1057 Stack (30)
- 1063 Set Similarity (25)
- 1129 Recommendation System (25)

## 排序原理题
- 1089 Insert or Merge (25)
- 1098 Insertion or Heap Sort (25)

## 应用排序题
- 1012 The Best Rank (25)
- 1025 PAT Ranking (25)
- 1028 List Sorting (25)
- 1036 Boys vs Girls (25)
- 1038 Recover the Smallest Number (30)
- 1062 Talent and Virtue (25)
- 1075 PAT Judge (25)
- 1083 List Grades (25)
- 1137 Final Grading (25)
- 1141 PAT Ranking of Institutions (25)
- 1153 Decode Registration Card of PAT (25)
- 1157 Anniversary (25)


## 链表题 （有结点不在链表上，为了卡不用链表的）
- 1032 Sharing (25)
- 1052 Linked List Sorting (25)
- 1074 Reversing Linked List (25)
- 1097 Deduplication on a Linked List (25)
- 1133 Splitting A Linked List (25)

## 栈
- 1051 Pop Sequence (25)

## 双指针
- 1044 Shopping in Mars (25)

## 二分查找
- 1085 Perfect Sequence (25)

## 递归
- 1056 Mice and Rice (25)
- 1105 Spiral Matrix (25)

## 需要用到数组来统计元素次数的
- 1048 Find Coins (25)
- 1050 String Subtraction (20)

## 整数运算溢出
- 1065 A+B and C (64bit) (20)

## 其他
- 1001 A+B Format (20)
- 1002 A+B for Polynomials (25)
- 1005 Spell It Right (20)
- 1006 Sign In and Sign Out (25)
- 1008 Elevator (20)
- 1009 Product of Polynomials (25)
- 1010 Radix (25) *
- 1011 World Cup Betting (20)
- 1015 Reversible Primes (20)
- 1019 General Palindromic Number (20)
- 1023 Have Fun with Numbers (20)
- 1024 Palindromic Number (25)
- 1027 Colors in Mars (20)
- 1029 Median (25)
- 1031 Hello World for U (20)
- 1035 Password (20)
- 1037 Magic Coupon (25)
- 1040 Longest Symmetric String (25)
- 1041 Be Unique (20)
- 1042 Shuffling Machine (20)
- 1046 Shortest Distance (20)
- 1048 Find Coins (25)
- 1054 The Dominant Color (20)
- 1058 A+B in Hogwarts (20)
- 1059 Prime Factors (25)
- 1060 Are They Equal (25)
- 1061 Dating (20)
- 1067 Sort with Swap(0, i) (25)
- 1069 The Black Hole of Numbers (20)
- 1071 Speech Patterns (25)
- 1073 Scientific Notation (20)
- 1077 Kuchiguse (20)
- 1081 Rational Sum (20)
- 1082 Read Number in Chinese (25)
- 1084 Broken Keyboard (20)
- 1088 Rational Arithmetic (20)
- 1092 To Buy or Not to Buy (20)
- 1093 Count PAT's (25)
- 1096 Consecutive Factors (20) *
- 1100 Mars Numbers (20)
- 1101 Quick Sort (25)
- 1104 Sum of Number Segments (20)
- 1108 Finding Average (20)
- 1109 Group Photo (25)
- 1112 Stucked Keyboard (20)
- 1113 Integer Set Partition (25) //408真题
- 1116 Come on! Let's C (20)
- 1117 Eddington Number (25)
- 1120 Friend Numbers (20)
- 1121 Damn Single (25)
- 1124 Raffle for Weibo Followers (20)
- 1128 N Queens Puzzle (20)
- 1132 Cut Integer (20)
- 1136 A Delayed Palindrome (20) 字符串加法（高精度整数）
- 1140 Look-and-say Sequence (20)
- 1144 The Missing Number (20)
- 1148 Werewolf - Simple Version (20)
- 1152 Google Recruitment (20)
- 1156 Sexy Primes (20)
