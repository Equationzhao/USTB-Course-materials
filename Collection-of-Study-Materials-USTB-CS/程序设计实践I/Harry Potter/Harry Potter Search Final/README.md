# Harry Potter Search

​																																											赵方程 Equationzhao

##注意事项

​	1.大小写敏感

​	2.空格敏感

##语法

​	search NAME      搜索人名/地名

​	goto N				  查询第N条记录

​    clear					清空屏幕

​	help					 显示提示

​	info					  显示软件信息

​	exit					   退出

##改进

- **已完成**//如果能在读取的文件时候生成一个表,记录每个章节和页码对应的起始和末尾行数,这样查询页码和章节的时间复杂度就能降为O(1)//


- 多线程查找

## 关于

​	网上的资料也不多,我都是将各个功能拆分开来进行搜索的.

​	有什么疑问请发邮件equationzhao@foxmail.com

​	[Blog](https://www.equationzhao.space/others/blogshtml/HarryPotter/Harry Potter Search.html)

##issues

​	没有查找时使用 goto 命令会在显示无记录后提示语法错误

