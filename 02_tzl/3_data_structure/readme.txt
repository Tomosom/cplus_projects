1.main文件版本说明


遗留尚未完善的部分：
1.
2.用share_pointer替换link_list中的原生指针
3.用内核链表实现的双向循环链表实现约瑟夫环的问题
4.No.33 双向循环链表课后思考习题

	struct Node : public Object {
		list_head head;
		T value;
	};

	Node node;
	list_head *ld = &node.head;

	Node *pn1 = reinterpret_cast<Node*>(ld);
	Node *pn2 = list_entry(ld, Node, head);

	上面的pn1和pn2是否相等，为什么?



directory
08_template  
09_智能指针  
10_c++异常简介 
11_异常类构建    
12_顶层父类的创建 
13_类族结构的进化  
14~18_线性表 
19~20_数组类  
21~24_链表 
25~26_静态单链表       
27~28_智能指针应用于链表 
29_循环链表   
30_双向链表   
31~33_内核链表_双向循环链表  
34~38_栈与队列的概念及实现
39~42_字符串类
