void reverse(struct node* p)
{
	if (p->next!=NULL)
	{
	    head = p;
	    return;
	}
	
	reverse(p->next);
	struct node* q = p->next;
	q->next = p;
	p->next = NULL;
}
