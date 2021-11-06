//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//l1为链表1，l2为链表2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;  //链表开头
	struct ListNode* tail = NULL;  //链表结尾
	int carry = 0;  //进位
	while(l1 || l2)  //以最长链表的末尾为结束标志
	{
		int num1 = l1 ? l1->val : 0;  //存放l1链表的数值，若为空则为0
		int num2 = l2 ? l2->val : 0;  //存放l2链表的数值，若为空则为0
		int sum = l1 + l2 + carry;  // 对应两链表的数值之和加进位
		if(!head)  //当为第一个链表首部时
		{
			head = tail = malloc(sizeof(struct ListNode));
			tail->val = sum % 10;  //只存放个位上的数
			tail->next = NULL;
		}
		else  // 不为表头时
		{
			tail->next = malloc(sizeof(struct ListNode));
			tail->next->val = sum % 10;
			tail->next->next = NULL;
			tail = tail->next;
		}
		carry = sum / 10;  // 存放进位
		if(l1)  // l1表不为空时指向下一个表
		{
			l1 = l1->next;
		}
		if(l2)  // l2表不为空时指向下一个表
		{
			l2 = l2->next;
		}
	}
	if(carry > 0)  // 当最长链表的表尾有进位时
	{
		tail->next = malloc(sizeof(struct ListNode));  // 再创建一个表存放进位
		tail->next->val = carry;
		tail->next->next = NULL;
	}
	return head;
}