void reverse() 
    { 
        Node* current = head; 
        Node *prev = NULL; 
  
        while (current != NULL) 
		{ 
            next = current->next; 
			current->next = prev;
			prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
