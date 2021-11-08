//对链表进行插入排序
/**
* struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//head为链表头
struct ListNode* insertionSortList(struct ListNode* head)
{
	if(head == NULL)
	{
		return head;
	}
	struct ListNode* beforeHead = (struct ListNode*)malloc(sizeof(struct ListNode));  //在表头前在建一个表来存放小于表头的数
	beforeHead->val = 0;
	beforeHead->next = head;
	struct ListNode* lastNode = head;  //排好序链表的最后一个
	struct ListNode* currNode = head->next;  //未排序链表的第一个
	while(currNode->val != NULL)  //当还有未排好序的链表时继续
	{
		if(lastNode->val <= currNode->val)  // 排好序链表的最后一个小于未排序链表的第一个时，将后者放进排序链表的最后
		{
			lastNode = lastNode->next;
		}
		else
		{
			struct ListNode* preNode = beforeHead;  //在表头前建一个指针通过遍历找到将要放入的链表对应位置的前一位
			while(preNode->next->val <= currNode->val)  //找到未排序链表要放入的对应位置
			{
				preNode = preNode->next;
			}
			lastNode->next = currNode->next;  //将链表插入对应位置
			currNode->next = preNode->next;
			preNode->next = currNode;
		}
		currNode = lastNode->next;  // 找到下一个未排序链表
	}
	return beforeHead->next;
}