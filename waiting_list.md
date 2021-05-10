# Wait to be seen problems
## 2021 (jan-mar) vo interview:  

一共四轮，每轮都花二十五分钟问BQ。
1. OO design linux find command. 题目要求和讨论在https://leetcode.com/discuss/int ... -Linux-Find-Command。建议把所有的讨论都看一遍，里面有follow up questions。
2. 实现rate limiter.
3. system design. user can upload videos and watch videos. 需要考虑CDN, scalibilty, durability, load balance, cache.
4. leetcod 漆散尔。但是被包装成发电用电。

## 2021 (4-6) oa:  
1. shopping options
2. items in containers

## 2021 (1-3) VO:  
Coding: LC陆玖贰  
Coding：LC壹肆贰玖  
OOP：酒店预约系统  
SDI：类似Ins一样的服务，重点讨论生成feed  

LP问题问的很细，result方面能提供量化的结果最好。
## 2021 5 sde2 VO:  
之前，与team manager电话以及第一轮电话面试的经历已经写了（[面试经验] 2021.04 Amazon电面 ）
在这里，特别感谢srigter的干货贴，里面指导了作者是如何准备Amazon Behavior Questions：（[面试经验] 【干货贴】我是如何准备系统设计的）

虽然，已经有很多人强调了Amazon Principle Questions的重要性，我还是得再重申一下。我觉得这个再怎么强调也不会过分的。我被考到的是：
- Customer Obsession
- Ownership
- Dive Deep
- Have Backbone; Disagree and Commit
- Deliver Results
有些principle甚至被2个的interviewers问到（加粗）。所以这些重要的，得准备两个例子。而且有些例子可以被用在不同的问题，只要你调整一下说法。我个人总共准备了10个例子。
还有一个typical behavior question：Tell me when you failed. 这个问题是我的bar raiser问的。很多Youtube Videos（Amazon Interview: how to prepare the failure stories (12 examples)）谈到了Bar Raiser喜欢问这个问题，很重要，好好准备。

我的电面和VO之间隔了大概一个月，我可以有时间刷system design， Object-Oriented Design，和 multi-threading。

说了一大堆BQ，现在说下我视频面试的流程吧。因为我在leetcode没找到原题，我只能给出题目大概难度，类型。我面的是Amazon Aurora，有四轮，分两天：
第一天，
第一轮，和我面试的是我在上个帖子提到的中国大叔，他是组里的大manager。两道BQ和一个leetcode medium的slide window -- max product of subarray of size K (注意，corner case 0)。
第二轮，一个印度大叔面试，他是组里的小manager，一个白人大叔shadow，组里的senior。没有太多刁难，两道BQ和一个multi-threading的问题。这是一道典型的producer/consumer的multi-threading，做出来了，而且感觉设计得还行，但没时间检查和跑test。如果跪了，应该就是在这里了。教训是：回答BQ的时候稍微简洁一些，不要超时，要不之后技术面试时间会不够。
第二天，
第三轮，一个白人大叔面，Amazon Pharmacy的senior manager（唯一一个Aurora之外的面试官，所以我猜是bar raiser），一个印度大叔shadow。 两道BQ和一个easy的array。这个又超时了。。。后面一个面试官来晚了，而且白人大叔愿意在超时后，让我优化，跑测试，提问。
第四轮，一个韩国大叔面，因为我们面试开始得晚（晚了8min），所以他很好心地只问了一道BQ，给我留了足够的时间做system design。让设计一个类似 database metric publisher/receiver system。

### 总结一下：
1. Behavior Question真的很重要 -- 每轮面试你都在用一半的时间回答BQ。准备它们，你只需要10小时左右，你再找不到性价比更高的准备了。
2. 和谷歌爸爸比，amazon算法面真的不难，毕竟你只有20-25分钟去解题，run through code。我第二天的同时电面谷歌，45min，直接一道hard，让我跪得明明白白，会在另一个帖子详述。
3. 好好和面试官交流。这次VO，我并没有碰到刁难的面试官。当他们觉得想和你工作，他们会给你提示，给你easy question，或者起码给你一个好脸色。比如，我的第三轮，已经是easy的题了，最后优化的时候，白人大叔还是不断给hints。如果跪了，真的有点愧对了。
4. System design对大多数人来说都很陌生。比如我工作时，主要设计low-level driver和一些kernel的东西，从来没有设计过distributed system.  
5. 掌握好时间。当你答题时，语速不要太快，面试官得typing你的回答，但你要把握好你自己的时间。
### system design 
- 第一个，当然是经典的system design课程（Grokking the System Design Interview，注：我没收到educative.io的一分钱赞助），这个课程，我刷了3遍，虽然还是很多东西记不住，但很多概念以及设计的流程模板，你都能熟悉。
- 第二个，youtube上很多system design mock interviews，你有了足够的知识之后，一边follow别人的设计，一边自己想设计，帮助真的很大。贴一个例子（Youtube: Google Systems Design Interview With An Ex-Googler）
- 第三个，大多数时候，你都碰不上原题，这时候，别慌，顺着设计流程模板。比如我面system design的时候，刚开始就一脸懵B，不知道面试官到底想要什么。这时候，问你的面试官问题：functional and non-functional的要求，你的assumption是不是对的，具体focus在哪个部分，这个系统的scale是多少。等你这些问题问得差不多的时候，你心里大概就知道该怎么设计了。
### 题外话一下：
当你已经和team manager聊过之后，主要准备他让你准备的东西。如果之后，时间还够，再准备其他的。我和中国大叔开始的时候就聊过，他让我准备：
- 算法
- multi-threading
- system design
- Principle
**全考了**，multi-threading，我没花很多时间，所以拉跨了点。我自己在网上找到的：
- OO design (花了好多时间T.T)
没有考。


好了，立帖赞人品，求亚麻妈妈的offer。
## 2021 4-6 
前几天看到地里有个帖子说得很有道理，我等老年人就不要去凑热闹了，真的是去找虐。BQ问题太多，一天下来嗓子都要废了。

Round 1. system design,设计一个monitor/alert系统，比较常见的题目了，follow up聊了聊metric pull/push，alert escalation,，，，

Round 2. implement a range lock,

lock [100, 200] TRUE
lock [300, 400] TRUE
lock [150, 250] FALSE
unlock [100, 200] TRUE
lock [150, 250] TRUE
一开始range作为一个整体,要求lock是LOG(N)，followup如果可以拆分range

Round 3
Given a binary tree, return the min sum change to make the sum of any path equals, only increase, not decrease value
```
           1
     /        \
   2          3
/  \           \

3   4           5
the return is [3], which has the updated tree as
           1
     /        \
  [4]         3
/    \           \
[4]   4           5
```
Round 4.



Round 5. HM继续聊BQ
## 2021 4-6 VO SDE1
+ 第一轮 三姐manager 蠡口要司令 我用dfs loop string面试官不太满意 她比较想loop Wordlist 虽然我觉得没什么本质区别。。。
+ 第二轮 两个白人 设计一个class来判断board game是否胜利 follow up是如果要随时增减获胜条件怎么办
+ 第三轮 白人manager 设计个amazon locker 实现存取快递 比较坑的地方是最好先写个locker class 然后不同的locker extend这个class 我一开始给了locker一个size 后面也没时间改了
+ 第四轮 印度manager 人特好上来说了一堆放轻松把前三轮忘掉blabla 蠡口贰酒屋 follow up是有timestamp怎么办 没时间写了

bq：
- 对teammate不满意
- Step outside your responsibility
- Overcome unexpected obstacles
- mistake you made
- 讲一下你需要学新技术并在工作中应用  

大概差不多这些，2个hard 2个OOD，BQ基本上每轮都有点重复，第一轮印度大姐还不停的打断我说这个例子不太行你能换一个吗。。。跪的话八成跪在第一轮了

## 2021 4-6 oa:
1. transaction logs 链接里的做法就能过所有test cases
https://leetcode.com/discuss/int ... or-Transaction-logs

2. Items In Containers
https://leetcode.com/discuss/int ... ontainers-amazon-oa
链接里的做法可以参考一下

## 2021 4-6 vo 亚麻新鲜VO 温哥华组 sde1
1. 中国小哥好像临时换的面试官 本来是个俄罗斯大哥的 BQ+file filter OOD 小哥一直在忙着干啥并没咋搭理我
2. HM 人很好一直笑呵呵 OOD设计评分系统+BQ
3. 中国小姐姐 人很好 BQ+ LRC
4. bar raiser 天竺小哥 人也很好 BQ + 计算器1-3
楼主OOD准备的不好 大家加油
Recruiter prep call 直接放了我鸽子 后来告诉我安排错了啥的 然后又告诉我不考系统设计和OOD一上来俩道都是OOD我当时心里那个悔不当初呀
anyway move on了

## 2021 (4-6) 亚麻VO+终面挂经

VO Merge Intervals

终面
第一轮 纯BQ
第二轮 BQ + linux find
第三轮 BQ + LRU cache
第四轮 BQ + merge k sorted list

第二轮没答好，语言用的Java，问我怎么实现Java function和terminal之间的input/output交互，没仔细研究过这方面于是卡了半天，最后系统设计也没做完，果然挂了。

## 2021 4-6 [面试经验] 雨林VO
谢谢地里的同学帮忙内推，最近刚进行了VO。就不加分数限制了。

第一题比较简单，考的就是map的存储，而且比较了hashmap和treemap的区别。

第二题是二维矩阵的BFS

第三题系统设计，网上书店

第四题OOD，设计图书馆（主要功能就是借书还书）

BQ就是比较常规的negative feedback，challenging project之类的

希望能帮助到大家，也给自己攒攒人品。

另外在亚麻网站看到自己深的职位还是under consideration但是职位link已经失效了。。地里的同学有遇到类似的情况么。。

## 2021 4-6 热带雨林VO
1. find kth cloest，三种做法
2. 寻找list中的屏蔽词，最优解应该是DFA
3. 一道数学题， input 是array 代表机器的生产一个item的时间，算一起工作多久能生成目标单位的item
4. 纯bq

## 2021 4-6 [面试经验] 雨林SDE2虚拟表演
1. 白人 SDEIII
20 min BQ + 35 min coding
题目形似迩灞锍，用BFS

2. 烙印 SDEII
25 min BQ + 30 min OOD
LRU + follow up about eviction policy

3. 亚裔SDEII
25 min BQ + 30 min coding
芜焐+咝诬

4. 烙印 SDM
30 min BQ + 30 min System Design
Amazon bookstore

## [面试经验] Amazon OA 面经

今天做了亚麻的OA，第一道题网上也有，但是没有明确的解法：A customer wants to buy a pair of jeans, a pair of shoes, a skirt, and a top but has a limited budget in dollars. Given different pricing options for each product, determine how many options our customer has to buy 1 of each product. You cannot spend more money than the budgeted amount.
Example
priceOfJeans = [2, 3]
priceOfShoes = [4]
priceOfSkirts = [2, 3]
priceOfTops = [1, 2]
budgeted = 10
The customer must buy shoes for 4 dollars since there is only one option. This leaves 6 dollars to spend on the other 3 items. Combinations of prices paid for jeans, skirts, and tops respectively that add up to 6 dollars or less are [2, 2, 2], [2, 2, 1], [3, 2, 1], [2, 3, 1]. There are 4 ways the customer can purchase all 4 items.
Function Description
Complete the getNumberOfOptions function in the editor below. The function must return an integer which represents the number of options present to buy the four items.
getNumberOfOptions has 5 parameters:
int[] priceOfJeans: An integer array, which contains the prices of the pairs of jeans available.
int[] priceOfShoes: An integer array, which contains the prices of the pairs of shoes available.
int[] priceOfSkirts: An integer array, which contains the prices of the skirts available.
int[] priceOfTops: An integer array, which contains the prices of the tops available.
int dollars: the total number of dollars available to shop with.
Constraints
1 ≤ a, b, c, d ≤ 10^3
1 ≤ dollars ≤ 10^9
1 ≤ price of each item ≤ 10^9
Note: a, b, c and d are the sizes of the four price arrays

我做了两个解法，第一个是用DFS，然后二维数组 memoization： visited[dollars][4], dollars是customer手里的钱。可是这样有bad allocation的错误。估计是dollars可以很大导致了space limit exceeded。

后来又参考了 454. 4Sum II， 可是因为这个是小于等于dollars都可以，所以不能达到O(n^2)，会超时。

所以大家知不知道这道题的正确解法？

谢谢

## 2021 4-6 SDE2 [面试经验] 亚麻onsite面经sde2 

几年前面过亚麻，收到邮件问要不要再试一试，做了oa之后就是onsite了，云计算的租
1. 系统设计，insgram，侧重于照片的上传下载存储
2. 简单的hashmap题，有具体的情景，这里就不细说了，是简单题，感觉大家都能做出来
3. 刷题网站 妖耳肆
4. oop，涉及到多态，具体题目不记得了，我也没答好，感觉面试官不满意
整体感觉难度中等偏上
求加米看面经，谢谢！